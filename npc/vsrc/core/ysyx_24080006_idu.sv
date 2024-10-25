module ysyx_24080006_idu (
    input  logic        clock,
    input  logic        reset,

    output logic [4:0] rs1_addr,
    output logic [4:0] rs2_addr,
    input  logic [31:0] rs1_val,
    input  logic [31:0] rs2_val,

    output logic [11:0] csr_addr,
    input  logic [31:0] csr_rdata,

    output logic [31:0] mepc_val,//for ecall
    output logic        mepc_en,

    ysyx_24080006_uif.prev    ifu,
    ysyx_24080006_uif.next    exu
);
assign mepc_val = ifu.pc;
assign mepc_en = ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11;
    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT
    } curr, next;

    always_ff @ (posedge clock) begin //fsm 1
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin //fsm 2
        unique case (curr)
            IDLE: begin
                if (ifu.valid)
                    next = EXEC;
                else
                    next = IDLE;
            end
            EXEC,
            WAIT: begin
                if (exu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
        endcase
    end

    always_ff @ (posedge clock) begin//fsm 3 for control
        unique if (reset) begin
            ifu.ready <= 1;
            exu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (ifu.valid) begin
                    ifu.ready <= 0;
                    exu.valid <= 1;
                end
                else begin
                    ifu.ready <= 1;
                    exu.valid <= 0;
                end
            end
            EXEC,
            WAIT: begin
                if (exu.ready) begin
                    ifu.ready <= 1;
                    exu.valid <= 0;
                end
                else begin
                    ifu.ready <= 0;
                    exu.valid <= 1;
                end
            end
        endcase
        end
    end

    localparam	B_type	= 7'b1100011,
                I_type	= 7'b0010011,//except jalr and load
                R_type	= 7'b0110011,
                S_type  = 7'b0100011,
                load    = 7'b0000011,
                jal	 	= 7'b1101111,
                jalr	= 7'b1100111,
                lui     = 7'b0110111,
                auipc   = 7'b0010111,
                system  = 7'b1110011;//ebreak, ecall, csr

    logic [31:0] imm;
    ysyx_24080006_imm Imm(ifu.inst, imm);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [4:0] rd_addr;
    
    assign opcode = ifu.inst[6:0];
    assign funct3 = ifu.inst[14:12];
    assign rs1_addr = ifu.inst[19:15];
    assign rs2_addr = ifu.inst[24:20];
    assign rd_addr = ifu.inst[11:7];

    assign csr_addr = ( ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11 ) ? 12'h305 : // ecall mtvec
                        ( ifu.inst == 32'b0011000_00010_00000_000_00000_11100_11 ) ? 12'h341 : // mret mepc
                            ifu.inst[31:20];

    logic [31:0] alu_src1, alu_src2;
    logic [3:0]  alu_ctrl;
    logic [1:0]  alu_set;

    always_comb begin//fsm 2 for decode alu_src1
        unique case (opcode)
            jal,
            jalr,
            auipc:   alu_src1 = ifu.pc;
            lui:     alu_src1 = '0;
            default: alu_src1 = rs1_val;//other cases
        endcase
    end

    always_comb begin //fsm 2 for decode alu_src2
        unique case (opcode)
            auipc,
            lui,
            load,
            S_type,
            I_type:  alu_src2 = imm;//U, I (include load), S
            B_type,
            R_type:  alu_src2 = rs2_val;//B, R
            jal,
            jalr:    alu_src2 = 32'h4;//jal, jalr
            system:
                if ( funct3 == 3'b010 )
                    alu_src2 = csr_rdata;
                else
                    alu_src2 = '0;
            default: alu_src2 = imm;
        endcase
    end

    always_comb begin //fsm 2 for decode alu_ctrl
        unique case (opcode)
            B_type:	if (funct3[2:1] == 2'b00)//B
                        alu_ctrl = {  2'b10 , funct3[2:1]};
                    else
                        alu_ctrl = {  2'b00 , funct3[2:1]};
            I_type:	if (funct3[1:0] == 2'b01)//I
                        alu_ctrl = {ifu.inst[30], funct3};
                    else
                        alu_ctrl = {  1'b0  , funct3};
            R_type:		alu_ctrl = {ifu.inst[30], funct3};//R
            jal,
            jalr,
            lui,
            auipc,
            load,
            S_type:		alu_ctrl = '0;// (add)
            system:
                if ( funct3 == 3'b010 )
                    alu_ctrl = 4'b0110;// (or)
                else
                    alu_ctrl = '0;
            default:    alu_ctrl = '0;
        endcase
    end

    always_comb begin //fsm 2 for decode alu_set
        alu_set = '0;
	    if(opcode == B_type)
		unique case (funct3)
			3'b000: alu_set = 2'b01; //BEQ
			3'b001: alu_set = 2'b10; //BNE
			3'b101,
			3'b111: alu_set = 2'b11; //BGE
			default:;
		endcase
    end

    logic [31:0] dnpc;
    always_comb begin
        unique case (opcode)
            jalr: dnpc = (rs1_val + imm) & 32'hffff_fffe;//rs1_val + imm;
            system: dnpc = csr_rdata;
            default: dnpc = ifu.pc + imm;
        endcase
    end

    logic csr_we;
    always_comb begin
        if (opcode == system && (funct3 != 3'b0))
            csr_we = 1;
        else
            csr_we = 0;
    end

    always_ff @ (posedge clock) begin//fsm 3 for decode alu
        if (reset) begin
            exu.alu_src1 <= '0;
            exu.alu_src2 <= '0;
            exu.alu_ctrl <= '0;
            exu.alu_set <= '0;
            exu.imm <= '0;
            exu.rd_addr <= '0;
            exu.dnpc <= '0;
            exu.sdata <= '0;
            exu.csr_addr <= '0;
            exu.csr_we <= '0;
            exu.csr_wdata <= '0;
        end
        else if (curr == IDLE && ifu.valid) begin
            exu.alu_src1 <= alu_src1;
            exu.alu_src2 <= alu_src2;
            exu.alu_ctrl <= alu_ctrl;
            exu.alu_set <= alu_set; 
            exu.imm <= imm; //is useful? may be aborted
            exu.rd_addr <= rd_addr;
            exu.dnpc <= dnpc;
            exu.sdata <= rs2_val;
            exu.csr_addr <= csr_addr;
            exu.csr_we <= csr_we;
            exu.csr_wdata <= csr_rdata;
        end
    end

    //logic load, store, wb, jump, branch;
    always_ff @ (posedge clock) begin//fsm 3 for decode alu
        if (reset) begin
            exu.funct3 <= '0;
            exu.load <= '0;
            exu.store <= '0;
            exu.wb <= '0;
            exu.jump <= '0;
            exu.branch <= '0;
            exu.ecall <= '0;
            exu.pc <= '0;
        end
        else if (curr == IDLE && ifu.valid) begin
            exu.funct3 <= funct3;
            exu.load <= opcode == load;
            exu.store <= opcode == S_type;
            exu.wb <= opcode inside {auipc, lui, jal, jalr, I_type, R_type, load};
            exu.jump <= (opcode inside {jal, jalr}) || (opcode == system && !csr_we);
            exu.branch <= opcode == B_type;   
            exu.ecall <= ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11;
            exu.pc <= ifu.pc;
        end
    end

`ifdef SIM_MODE
import "DPI-C" function void ebreak();
import "DPI-C" function void INST_CNT(input int type_code);
    always_ff @ (posedge clock) begin
        if (curr == IDLE && ifu.valid)
            case(opcode)

            auipc,
            lui,
            R_type,
            I_type: INST_CNT(0);

            load,
            S_type: INST_CNT(1);

            system: begin
                INST_CNT(2);
                if (ifu.inst == 32'b0000000_00001_00000_000_00000_11100_11)
                    ebreak();
            end

            B_type: INST_CNT(3);
            
            jal,
            jalr:   INST_CNT(4);

            default: begin
                $display("inst error 0x%08x", ifu.inst);$finish;
            end
            endcase
        
        `ifndef SOC_MODE
        if (curr == EXEC && (ifu.pc < 32'h8000_0000 || ifu.pc > 32'h9000_0000)) begin
            $display("addr error 0x%08x", ifu.pc);$finish;end
        `endif
    end
`endif

endmodule
