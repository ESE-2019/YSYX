module top(
input  logic clock, reset, io_interrupt,
     
    input  logic        io_master_awready,
    output logic        io_master_awvalid,
    output logic [31:0] io_master_awaddr,
    output logic [3:0]  io_master_awid,
    output logic [7:0]  io_master_awlen,
    output logic [2:0]  io_master_awsize,
    output logic [1:0]  io_master_awburst,

    input  logic        io_master_wready,
    output logic        io_master_wvalid,
    output logic [31:0] io_master_wdata,
    output logic [3:0]  io_master_wstrb,
    output logic        io_master_wlast,

    output logic        io_master_bready,
    input  logic        io_master_bvalid,
    input  logic [1:0]  io_master_bresp,
    input  logic [3:0]  io_master_bid,

    input  logic        io_master_arready,
    output logic        io_master_arvalid,
    output logic [31:0] io_master_araddr,
    output logic [3:0]  io_master_arid,
    output logic [7:0]  io_master_arlen,
    output logic [2:0]  io_master_arsize,
    output logic [1:0]  io_master_arburst,

    output logic        io_master_rready,
    input  logic        io_master_rvalid,
    input  logic [1:0]  io_master_rresp,
    input  logic [31:0] io_master_rdata,
    input  logic        io_master_rlast,
    input  logic [3:0]  io_master_rid,

     
    output logic        io_slave_awready,
    input  logic        io_slave_awvalid,
    input  logic [31:0] io_slave_awaddr,
    input  logic [3:0]  io_slave_awid,
    input  logic [7:0]  io_slave_awlen,
    input  logic [2:0]  io_slave_awsize,
    input  logic [1:0]  io_slave_awburst,

    output logic        io_slave_wready,
    input  logic        io_slave_wvalid,
    input  logic [31:0] io_slave_wdata,
    input  logic [3:0]  io_slave_wstrb,
    input  logic        io_slave_wlast,

    input  logic        io_slave_bready,
    output logic        io_slave_bvalid,
    output logic [1:0]  io_slave_bresp,
    output logic [3:0]  io_slave_bid,

    output logic        io_slave_arready,
    input  logic        io_slave_arvalid,
    input  logic [31:0] io_slave_araddr,
    input  logic [3:0]  io_slave_arid,
    input  logic [7:0]  io_slave_arlen,
    input  logic [2:0]  io_slave_arsize,
    input  logic [1:0]  io_slave_arburst,

    input  logic        io_slave_rready,
    output logic        io_slave_rvalid,
    output logic [1:0]  io_slave_rresp,
    output logic [31:0] io_slave_rdata,
    output logic        io_slave_rlast,
    output logic [3:0]  io_slave_rid
);

 
ysyx_24080006_axi axi ();
ysyx_24080006_core CORE( .* );

     
    assign axi.awready = io_master_awready;
    assign io_master_awvalid = axi.awvalid;
    assign io_master_awaddr = axi.awaddr;
    assign io_master_awid = axi.awid;
    assign io_master_awlen = axi.awlen;
    assign io_master_awsize = axi.awsize;
    assign io_master_awburst = axi.awburst;

    assign axi.wready = io_master_wready;
    assign io_master_wvalid = axi.wvalid;
    assign io_master_wdata = axi.wdata;
    assign io_master_wstrb = axi.wstrb;
    assign io_master_wlast = axi.wlast;

    assign io_master_bready = axi.bready;
    assign axi.bvalid = io_master_bvalid;
    assign axi.bresp = io_master_bresp;
    assign axi.bid = io_master_bid;

    assign axi.arready = io_master_arready;
    assign io_master_arvalid = axi.arvalid;
    assign io_master_araddr = axi.araddr;
    assign io_master_arid = axi.arid;
    assign io_master_arlen = axi.arlen;
    assign io_master_arsize = axi.arsize;
    assign io_master_arburst = axi.arburst;

    assign io_master_rready = axi.rready;
    assign axi.rvalid = io_master_rvalid;
    assign axi.rresp = io_master_rresp;
    assign axi.rdata = io_master_rdata;
    assign axi.rlast = io_master_rlast;
    assign axi.rid = io_master_rid;


endmodule

module ysyx_24080006_alu(
input logic [31:0] src1, src2,
input logic [3:0] ctrl,
output logic [31:0] res
);
localparam	ADD  = 4'b0000,
		SUB  = 4'b1000,
		SLL  = 4'b0001,
		SLT  = 4'b0010,
		SLTU = 4'b0011,
		XOR  = 4'b0100,
		SRL  = 4'b0101,
		SRA  = 4'b1101,
		OR   = 4'b0110,
		AND  = 4'b0111;
		
 
logic [33:0] add_res_t;
logic [32:0] srcA, srcB, srcB_t;
logic [31:0] add_res;
assign srcA   = {src1, 1'b1};
assign srcB_t = {src2, 1'b0};
always_comb begin
	srcB = srcB_t;
	case (ctrl)
		ADD : srcB =  srcB_t;
		SUB ,	
		SLT ,
		SLTU: srcB = ~srcB_t;
		default:;
	endcase
end
assign add_res_t = {1'b0, srcA} + {1'b0, srcB};
assign add_res = add_res_t[32:1];
 
logic comp_res;
always_comb begin
	comp_res = add_res_t[33];
	case (ctrl)
		SLT : comp_res =  add_res_t[32] ^  
			( ( ! srcA[32] &&   srcB_t[32] &&   add_res_t[32] ) || 
			  (   srcA[32] && ! srcB_t[32] && ! add_res_t[32] ) );
		SLTU: comp_res = !add_res_t[33]; 
		default:;
	endcase
end
 
logic [31:0] shift_res;
logic [4:0] shift;
assign shift = src2[4:0];

logic [31:0] shift_src;

always_comb begin
	shift_src = src1;
	case (ctrl)
		SLL: for(int i=0; i<32; i++) shift_src[i] = src1[31-i];
		SRL,
		SRA: shift_src = src1;
		default:;
        endcase
end

always_comb begin
	shift_res = src1 >> shift;
	case (ctrl)
		SLL,
		SRL: shift_res = shift_src >> shift;
		 
		SRA: shift_res = { 32 { src1[31] } } << (31 - shift) | src1 >> shift;
		default:;
        endcase
end

 
logic [31:0] bit_res;
always_comb begin
	bit_res = src1 & src2;
	case (ctrl)
		AND: bit_res = src1 & src2;
		OR : bit_res = src1 | src2;
		XOR: bit_res = src1 ^ src2;
		default:;
	endcase
end

always_comb begin
	res = add_res;
	case (ctrl)
		ADD ,
		SUB : res = add_res;
		SLT ,
		SLTU: res = {31'b0, comp_res};
		SLL : for(int i=0; i<32; i++) res[i] = shift_res[31-i];
		SRL ,
		SRA : res = shift_res;
		AND ,
		OR  ,
		XOR : res = bit_res;
		default:;
	endcase
end

endmodule

module ysyx_24080006_arb(
    input clock,
    input reset,
    ysyx_24080006_axi.slave  axi_ifu,
    ysyx_24080006_axi.slave  axi_lsu,
    ysyx_24080006_axi.master axi
    );

     
    assign axi_lsu.awready = axi.awready;
    assign axi.awvalid     = axi_lsu.awvalid;
    assign axi.awaddr      = axi_lsu.awaddr;
    assign axi.awid        = axi_lsu.awid;
    assign axi.awlen       = axi_lsu.awlen;
    assign axi.awsize      = axi_lsu.awsize;
    assign axi.awburst     = axi_lsu.awburst;

    assign axi_lsu.wready  = axi.wready;
    assign axi.wvalid      = axi_lsu.wvalid;
    assign axi.wdata       = axi_lsu.wdata;
    assign axi.wstrb       = axi_lsu.wstrb;
    assign axi.wlast       = axi_lsu.wlast;

    assign axi.bready      = axi_lsu.bready;
    assign axi_lsu.bvalid  = axi.bvalid;
    assign axi_lsu.bresp   = axi.bresp;
    assign axi_lsu.bid     = axi.bid;

     
    assign axi_ifu.rresp   = axi.rresp;
    assign axi_ifu.rdata   = axi.rdata;
    assign axi_ifu.rlast   = axi.rlast;
    assign axi_ifu.rid     = axi.rid;

    assign axi_lsu.rresp   = axi.rresp;
    assign axi_lsu.rdata   = axi.rdata;
    assign axi_lsu.rlast   = axi.rlast;
    assign axi_lsu.rid     = axi.rid;

    enum logic [1:0] {
        IDLE,
        IFUR,
        LSUR
    } curr, next;

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
        unique case (curr)
            IDLE: begin
                if (axi_lsu.arvalid || axi_lsu.rvalid)
                    next = LSUR;
                else if (axi_ifu.arvalid || axi_ifu.rvalid)
                    next = IFUR;
                else
                    next = IDLE;
            end
            LSUR: begin
                if (axi_lsu.rready && axi_lsu.rvalid)  
                    next = IDLE;
                else
                    next = LSUR;
            end
            IFUR: begin
                if (axi_ifu.rready && axi_ifu.rvalid)  
                    next = IDLE;
                else
                    next = IFUR;
            end
        endcase
    end

    assign axi_ifu.arready = curr == IFUR ? axi.arready : 0;
    assign axi_lsu.arready = curr == LSUR ? axi.arready : 0;
    assign axi_ifu.rvalid  = curr == IFUR ? axi.rvalid  : 0;
    assign axi_lsu.rvalid  = curr == LSUR ? axi.rvalid  : 0;
    always_comb begin
        unique case (curr)
            IDLE: begin
                axi.arvalid = 0;
                axi.rready  = 0;
            end
            LSUR: begin
                axi.arvalid = axi_lsu.arvalid;
                axi.rready  = axi_lsu.rready;
            end
            IFUR: begin
                axi.arvalid = axi_ifu.arvalid;
                axi.rready  = axi_ifu.rready;
            end
        endcase
    end

    assign axi.araddr  = curr == LSUR ? axi_lsu.araddr  : axi_ifu.araddr;
    assign axi.arid    = curr == LSUR ? axi_lsu.arid    : axi_ifu.arid  ;
    assign axi.arlen   = curr == LSUR ? axi_lsu.arlen   : axi_ifu.arlen ;
    assign axi.arsize  = curr == LSUR ? axi_lsu.arsize  : axi_ifu.arsize;
    assign axi.arburst = curr == LSUR ? axi_lsu.arburst : axi_ifu.arburst;

endmodule

interface ysyx_24080006_axi;

    logic 			awready;
    logic 			awvalid;
    logic [31:0]	awaddr;
    logic [ 3:0]	awid;
    logic [ 7:0]	awlen;
    logic [ 2:0]	awsize;
    logic [ 1:0]	awburst;

    logic			wready;
    logic			wvalid;
    logic [31:0]	wdata;
    logic [ 3:0]	wstrb;
    logic			wlast;

    logic			bready;
    logic			bvalid;
    logic [ 1:0]	bresp;
    logic [ 3:0]	bid;

    logic			arready;
    logic			arvalid;
    logic [31:0]	araddr;
    logic [ 3:0]	arid;
    logic [ 7:0]	arlen;
    logic [ 2:0]	arsize;
    logic [ 1:0]	arburst;

    logic			rready;
    logic			rvalid;
    logic [ 1:0]	rresp;
    logic [31:0]	rdata;
    logic			rlast;
    logic [ 3:0]	rid;

    modport master(

                input	awready,
                output	awvalid,
                output	awaddr,
                output	awid,
                output	awlen,
                output	awsize,
                output	awburst,

                input	wready,
                output	wvalid,
                output	wdata,
                output	wstrb,
                output	wlast,

                output	bready,
                input	bvalid,
                input	bresp,
                input	bid,

                input	arready,
                output	arvalid,
                output	araddr,
                output	arid,
                output	arlen,
                output	arsize,
                output	arburst,

                output	rready,
                input	rvalid,
                input	rresp,
                input	rdata,
                input	rlast,
                input	rid
            );

    modport slave (

                output awready,
                input  awvalid,
                input  awaddr,
                input  awid,
                input  awlen,
                input  awsize,
                input  awburst,

                output wready,
                input  wvalid,
                input  wdata,
                input  wstrb,
                input  wlast,

                input  bready,
                output bvalid,
                output bresp,
                output bid,

                output arready,
                input  arvalid,
                input  araddr,
                input  arid,
                input  arlen,
                input  arsize,
                input  arburst,

                input  rready,
                output rvalid,
                output rresp,
                output rdata,
                output rlast,
                output rid
            );

endinterface

module ysyx_24080006_core (
    input logic clock,
    input logic reset,
    ysyx_24080006_axi.master axi
);

ysyx_24080006_uif ifu2idu(), idu2exu(), exu2lsu(), lsu2wbu(), wbu2ifu();

ysyx_24080006_axi axi_ifu(), axi_lsu();
ysyx_24080006_arb ARB( .* );

logic we;
logic [4:0]  rs1_addr;
logic [4:0]  rs2_addr;
logic [4:0]  rd;
logic [31:0] wdata;
logic [31:0] rs1_val;
logic [31:0] rs2_val;

logic        csr_we;
logic [31:0] mepc_val;
logic        mepc_en;
logic [11:0] csr_addr;
logic [11:0] csr_waddr;
logic [31:0] csr_wdata;
logic [31:0] csr_rdata;

ysyx_24080006_reg REG ( .* );

ysyx_24080006_csr CSR ( .* );

ysyx_24080006_ifu IFU (
    .*,
    .wbu(wbu2ifu),
    .idu(ifu2idu)
);

ysyx_24080006_idu IDU (
    .*,
    .ifu(ifu2idu),
    .exu(idu2exu)
);

ysyx_24080006_exu EXU (
    .*,
    .idu(idu2exu),
    .lsu(exu2lsu)
);

ysyx_24080006_lsu LSU (
    .*,
    .exu(exu2lsu),
    .wbu(lsu2wbu)
);

ysyx_24080006_wbu WBU (
    .*,
    .lsu(lsu2wbu),
    .ifu(wbu2ifu)
);

endmodule

module ysyx_24080006_csr (
    input  logic        clock,
    input  logic        reset,
    input  logic        csr_we,

     
    input  logic [31:0] mepc_val,
    input  logic        mepc_en,

    input  logic [11:0] csr_addr,
    input  logic [11:0] csr_waddr,
    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

    logic [31:0] regfile [4];
    
    enum logic [1:0] {
        mstatus = 2'b00,
        mtvec   = 2'b01,
        mepc    = 2'b10,
        mcause  = 2'b11
    } csr_r, csr_w;
    
    always_comb begin
	unique case(csr_addr)
	12'h300: csr_r = mstatus;
	12'h305: csr_r = mtvec;
	12'h341: csr_r = mepc;
	12'h342: csr_r = mcause;
	default: csr_r = mstatus;
	endcase
    end

    always_comb begin
	unique case(csr_waddr)
	12'h300: csr_w = mstatus;
	12'h305: csr_w = mtvec;
	12'h341: csr_w = mepc;
	12'h342: csr_w = mcause;
	default: csr_w = mstatus;
	endcase
    end

    assign csr_rdata = regfile[csr_r];

    always_ff @(posedge clock) begin
        if (reset) begin
            regfile[0] <= 32'h1800;
            regfile[1] <= '0;
            regfile[2] <= '0;
            regfile[3] <= '0;
        end else if (csr_we) begin
            regfile[csr_w] <= csr_wdata;
        end else if (mepc_en) begin
            regfile[mepc] <= mepc_val;
        end
    end
     
     
     
     
     
     
     
endmodule

module ysyx_24080006_exu (
    input  logic        clock,
    input  logic        reset,

    ysyx_24080006_uif.prev    idu,
    ysyx_24080006_uif.next    lsu
);

    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT
    } curr, next;

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
        unique case (curr)
            IDLE: begin
                if (idu.valid)
                    next = EXEC;
                else
                    next = IDLE;
            end
            EXEC,
            WAIT: begin
                if (lsu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
        endcase
    end

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            idu.ready <= 1;
            lsu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (idu.valid) begin
                    idu.ready <= 0;
                    lsu.valid <= 1;
                end
                else begin
                    idu.ready <= 1;
                    lsu.valid <= 0;
                end
            end
            EXEC,
            WAIT: begin
                if (lsu.ready) begin
                    idu.ready <= 1;
                    lsu.valid <= 0;
                end
                else begin
                    idu.ready <= 0;
                    lsu.valid <= 1;
                end
            end
        endcase
        end
    end

    logic [31:0] alu_out, alu_res;  
    ysyx_24080006_alu ALU(
        .src1(idu.alu_src1),
        .src2(idu.alu_src2),
        .ctrl(idu.alu_ctrl),
        .res(alu_out));
        
    logic  not_zero;
    assign not_zero = |alu_out;
    logic branch;
    always_comb begin  

        unique case (idu.alu_set)
            2'b00: alu_res = alu_out;
            2'b01: alu_res = {31'b0, ~not_zero};
            2'b10: alu_res = {31'b0,  not_zero};
            2'b11: alu_res = {31'b0, ~alu_out[0]};
        endcase

        if (idu.branch == 1'b1 && alu_res[0] == 1) begin  
            branch = 1'b1;
        end
        else begin
            branch = 1'b0;
        end

    end

    always_ff @ (posedge clock) begin
        if (reset) begin
            lsu.dnpc <= '0;
            lsu.sdata <= '0;
            lsu.rd_addr <= '0;
            lsu.alu_res <= '0;
            lsu.funct3 <= '0;
            lsu.load <= '0;
            lsu.store <= '0;
            lsu.wb <= '0;
            lsu.jump <= '0;
            lsu.branch <= '0;
            lsu.csr_addr <= '0;
            lsu.csr_we <= '0;
            lsu.csr_wdata <= '0;
            lsu.ecall <= '0;
        end
        else begin
            lsu.dnpc <= idu.dnpc;
            lsu.sdata <= idu.sdata;
            lsu.rd_addr <= idu.rd_addr;
            lsu.alu_res <= alu_res;
            lsu.funct3 <= idu.funct3;
            lsu.load <= idu.load;
            lsu.store <= idu.store;
            lsu.wb <= idu.wb;
            lsu.jump <= idu.jump;  
            lsu.branch <= branch;  
            lsu.csr_addr <= idu.csr_addr;
            lsu.csr_we <= idu.csr_we;
            lsu.csr_wdata <= idu.csr_wdata;
            lsu.ecall <= idu.ecall;
        end

    end


endmodule

module ysyx_24080006_idu (
    input  logic        clock,
    input  logic        reset,

    output logic [4:0] rs1_addr,
    output logic [4:0] rs2_addr,
    input  logic [31:0] rs1_val,
    input  logic [31:0] rs2_val,

    output logic [11:0] csr_addr,
    input  logic [31:0] csr_rdata,

    output logic [31:0] mepc_val, 
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

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
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

    always_ff @ (posedge clock) begin 
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
                I_type	= 7'b0010011, 
                R_type	= 7'b0110011,
                S_type  = 7'b0100011,
                load    = 7'b0000011,
                jal	 	= 7'b1101111,
                jalr	= 7'b1100111,
                lui     = 7'b0110111,
                auipc   = 7'b0010111,
                system  = 7'b1110011; 

    logic [31:0] imm;
    ysyx_24080006_imm Imm(ifu.inst, imm);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [4:0] rd_addr;
    
    assign opcode = ifu.inst[6:0];
    assign funct3 = ifu.inst[14:12];
    assign rs1_addr = ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11 ? 5'd15 : ifu.inst[19:15];
    assign rs2_addr = ifu.inst[24:20];
    assign rd_addr = ifu.inst[11:7];

    assign csr_addr = ( ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11 ) ? 12'h305 :  
                        ( ifu.inst == 32'b0011000_00010_00000_000_00000_11100_11 ) ? 12'h341 :  
                            ifu.inst[31:20];

    logic [31:0] alu_src1, alu_src2;
    logic [3:0]  alu_ctrl;
    logic [1:0]  alu_set;

    always_comb begin 
        unique case (opcode)
            jal,
            jalr,
            auipc:   alu_src1 = ifu.pc;
            lui:     alu_src1 = '0;
            default: alu_src1 = rs1_val; 
        endcase
    end

    always_comb begin  
        unique case (opcode)
            auipc,
            lui,
            load,
            S_type,
            I_type:  alu_src2 = imm; 
            B_type,
            R_type:  alu_src2 = rs2_val; 
            jal,
            jalr:    alu_src2 = 32'h4; 
            system:
                if ( funct3 == 3'b010 )
                    alu_src2 = csr_rdata;
                else
                    alu_src2 = '0;
            default: alu_src2 = imm;
        endcase
    end

    always_comb begin  
        unique case (opcode)
            B_type:	if (funct3[2:1] == 2'b00) 
                        alu_ctrl = {  2'b10 , funct3[2:1]};
                    else
                        alu_ctrl = {  2'b00 , funct3[2:1]};
            I_type:	if (funct3[1:0] == 2'b01) 
                        alu_ctrl = {ifu.inst[30], funct3};
                    else
                        alu_ctrl = {  1'b0  , funct3};
            R_type:		alu_ctrl = {ifu.inst[30], funct3}; 
            jal,
            jalr,
            lui,
            auipc,
            load,
            S_type:		alu_ctrl = '0; 
            system:
                if ( funct3 == 3'b010 )
                    alu_ctrl = 4'b0110; 
                else
                    alu_ctrl = '0;
            default:    alu_ctrl = '0;
        endcase
    end

    always_comb begin  
        alu_set = '0;
	    if(opcode == B_type)
		unique case (funct3)
			3'b000: alu_set = 2'b01;  
			3'b001: alu_set = 2'b10;  
			3'b101,
			3'b111: alu_set = 2'b11;  
			default:;
		endcase
    end

    logic [31:0] dnpc;
    always_comb begin
        unique case (opcode)
            jalr: dnpc = (rs1_val + imm) & 32'hffff_fffe; 
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

    always_ff @ (posedge clock) begin 
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
            exu.imm <= imm;  
            exu.rd_addr <= rd_addr;
            exu.dnpc <= dnpc;
            exu.sdata <= rs2_val;
            exu.csr_addr <= csr_addr;
            exu.csr_we <= csr_we;
            exu.csr_wdata <= csr_rdata;
        end
    end

     
    always_ff @ (posedge clock) begin 
        if (reset) begin
            exu.funct3 <= '0;
            exu.load <= '0;
            exu.store <= '0;
            exu.wb <= '0;
            exu.jump <= '0;
            exu.branch <= '0;
            exu.ecall <= '0;
        end
        else if (curr == IDLE && ifu.valid) begin
            exu.funct3 <= funct3;
            exu.load <= opcode == load;
            exu.store <= opcode == S_type;
            exu.wb <= opcode inside {auipc, lui, jal, jalr, I_type, R_type, load};
            exu.jump <= (opcode inside {jal, jalr}) || (opcode == system && !csr_we);
            exu.branch <= opcode == B_type;   
            exu.ecall <= ifu.inst == 32'b0000000_00000_00000_000_00000_11100_11;
        end
    end

 
    
        
           
            
                    
             
    


endmodule

module ysyx_24080006_ifu (
    input  logic        clock,
    input  logic        reset,

    ysyx_24080006_axi.master  axi_ifu,
    ysyx_24080006_uif.prev    wbu,
    ysyx_24080006_uif.next    idu
);

    logic [31:0] pc;
    localparam RST_ADDR = 32'h8000_0000 - 32'h4;

    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT
    } curr, next;

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
        unique case (curr)
            IDLE: begin
                if (wbu.valid)
                    next = EXEC;
                else
                    next = IDLE;
            end
            EXEC: begin
                if (axi_ifu.rvalid)
                    next = WAIT;
                else
                    next = EXEC;
            end
            WAIT: begin
                if (idu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
        endcase
    end

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            wbu.ready <= 1;
            idu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (wbu.valid) begin
                    wbu.ready <= 0;
                    idu.valid <= 0;
                end
                else begin
                    wbu.ready <= 1;
                    idu.valid <= 0;
                end
            end
            EXEC: begin
                if (axi_ifu.rvalid) begin
                    wbu.ready <= 0;
                    idu.valid <= 1;
                end
                else begin
                    wbu.ready <= 0;
                    idu.valid <= 0;
                end
            end
            WAIT: begin
                if (idu.ready) begin
                    wbu.ready <= 1;
                    idu.valid <= 0;
                end
                else begin
                    wbu.ready <= 0;
                    idu.valid <= 1;
                end
            end
        endcase
        end
    end

assign axi_ifu.araddr = pc; 
 
            
  


    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            axi_ifu.arvalid <= 0;
		    axi_ifu.rready  <= 1;
            idu.inst <= '0;
            pc <= RST_ADDR;
             
              
            
            idu.pc <= '0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (wbu.valid) begin
				    axi_ifu.arvalid <= 1;
				    axi_ifu.rready  <= 1;
                    if (wbu.jump || wbu.branch)
                        pc <= wbu.dnpc;
                    else
                        pc <= pc + 32'h4;
                end
                else begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 1;
                end
            end
            EXEC: begin
                if (axi_ifu.rvalid) begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 0;
                    idu.inst <= axi_ifu.rdata;
                     
                       
                          
                    
                            
                      
                    
                    idu.pc <= pc;
                end
                else begin
                    axi_ifu.arvalid <= 1;
				    axi_ifu.rready  <= 1;
                end
            end
            WAIT: begin
                if (idu.ready) begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 0;
                end
                else begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 1;
                end
            end
        endcase
        end
    end

endmodule

module ysyx_24080006_imm(
input logic [31:0] inst,
output logic [31:0] imm
);

always_comb begin
	imm = {{20{inst[31]}}, inst[31:20]};
	unique case (inst[6:0])
		7'b0010011,
		7'b0000011,
		7'b1100111: imm = {{20{inst[31]}}, inst[31:20]}; 
		7'b0100011: imm = {{20{inst[31]}}, inst[31:25], inst[11:7]}; 
		7'b1100011: imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0}; 
		7'b0110111,
		7'b0010111: imm = {inst[31:12], 12'b0}; 
		7'b1101111: imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0}; 
		default:;
	endcase
end
endmodule

module ysyx_24080006_lsu (
    input  logic        clock,
    input  logic        reset,

    ysyx_24080006_axi.master  axi_lsu,
    ysyx_24080006_uif.prev    exu,
    ysyx_24080006_uif.next    wbu
);

    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT
    } curr, next;

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
        unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load || exu.store)
                        next = EXEC;
                    else
                        next = WAIT;
                end
                else
                    next = IDLE;
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid)
                    next = WAIT;
                else
                    next = EXEC;
            end
            WAIT: begin
                if (wbu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
        endcase
    end

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            exu.ready <= 1;
            wbu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load || exu.store) begin
                        exu.ready <= 0;
                        wbu.valid <= 0;
                    end
                    else begin  
                        exu.ready <= 0;
                        wbu.valid <= 1;
                    end
                end
                else begin
                    exu.ready <= 1;
                    wbu.valid <= 0;
                end
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid) begin
                    exu.ready <= 0;
                    wbu.valid <= 1;
                end
                else begin
                    exu.ready <= 0;
                    wbu.valid <= 0;
                end
            end
            WAIT: begin
                if (wbu.ready) begin
                    exu.ready <= 1;
                    wbu.valid <= 0;
                end
                else begin
                    exu.ready <= 0;
                    wbu.valid <= 1;
                end
            end
        endcase
        end
    end

    logic [31:0] alu_res, ldata;
    logic [4:0] rshamt;
    always_comb begin  

        case (exu.alu_res[1:0])
			2'b00: rshamt = 0;
			2'b01: rshamt = 8;
			2'b10: rshamt = 16;
			2'b11: rshamt = 24; 
		endcase

         
         
         
         
    end

function automatic logic [31:0] Mr(input logic [31:0] tmp, input logic [2:0] funct_3);
	unique case (funct_3)
		3'b000: Mr = { {24{tmp[7]}}, tmp[7:0]};
		3'b001: Mr = { {16{tmp[15]}}, tmp[15:0]};
		3'b010: Mr = tmp[31:0];
		3'b100: Mr = {24'b0, tmp[7:0]};
		3'b101: Mr = {16'b0, tmp[15:0]};
		default: begin Mr = 0; 
 
          

        end
	endcase
     
endfunction

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready  <= 1;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid  <= 0;
            axi_lsu.bready  <= 1;
            axi_lsu.araddr  <= 0;
            axi_lsu.awaddr  <= 0;
            axi_lsu.wdata   <= 0;
            axi_lsu.wstrb   <= 0;
            wbu.alu_res <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load) begin  
                        axi_lsu.arvalid <= 1;
                        axi_lsu.rready  <= 1;
                        axi_lsu.awvalid <= 0;
                        axi_lsu.wvalid  <= 0;
                        axi_lsu.bready  <= 0;
                        axi_lsu.araddr  <= exu.alu_res; 
                    end
                    else if (exu.store) begin  
                        axi_lsu.arvalid <= 0;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 1;
                        axi_lsu.wvalid  <= 1;
                        axi_lsu.bready  <= 1;
                        axi_lsu.awaddr  <= exu.alu_res; 
                        axi_lsu.wdata   <= exu.sdata;
                        axi_lsu.wstrb   <=  (exu.funct3==3'b000)?4'b0001:
                                            (exu.funct3==3'b001)?4'b0011:
                                            (exu.funct3==3'b010)?4'b1111:4'b0;
                    end
                    else begin  
                        axi_lsu.arvalid <= 0;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 0;
                        axi_lsu.wvalid  <= 0;
                        axi_lsu.bready  <= 0;
                        wbu.alu_res <= exu.alu_res;
                    end
                end
                else begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 1;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 1;
                end
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid) begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
                     
                    wbu.alu_res <= Mr(axi_lsu.rdata >> rshamt, exu.funct3);
                     
                end
                else
                    ;
            end
            WAIT: begin
                if (wbu.ready) begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 1;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 1;
                end
                else begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
                end
            end
        endcase
        end
    end

    

    always_ff @ (posedge clock) begin
        if (reset) begin
            wbu.dnpc <= '0;
            wbu.rd_addr <= '0;
             
            wbu.wb <= '0;
            wbu.jump <= '0;
            wbu.branch <= '0;
            wbu.csr_addr <= '0;
            wbu.csr_we <= '0;
            wbu.csr_wdata <= '0;
            wbu.ecall <= '0;
        end
        else begin
            wbu.dnpc <= exu.dnpc;
            wbu.rd_addr <= exu.rd_addr;
             
            wbu.wb <= exu.wb;
            wbu.jump <= exu.jump;  
            wbu.branch <= exu.branch;  
            wbu.csr_addr <= exu.csr_addr;
            wbu.csr_we <= exu.csr_we;
            wbu.csr_wdata <= exu.csr_wdata;
            wbu.ecall <= exu.ecall;
        end

    end


endmodule

module ysyx_24080006_reg (
    input  logic        clock,
    input  logic        reset,
    input  logic        we,
    input  logic [4:0]  rs1_addr,
    input  logic [4:0]  rs2_addr,
    input  logic [4:0]  rd,
    input  logic [31:0] wdata,
    output logic [31:0] rs1_val,
    output logic [31:0] rs2_val
);

    logic [31:0] regfile [32];

    always_ff @(posedge clock) begin  
        if (reset) begin
            foreach (regfile[i]) begin
                regfile[i] <= '0;
            end
        end else if (we && rd != 5'b0) begin
            regfile[rd] <= wdata;
        end
    end

     
     
     
     
     
     
     
     
     

        always_comb  begin  
        begin
            rs1_val = regfile[rs1_addr];
            rs2_val = regfile[rs2_addr];
        end
    end

endmodule

interface ysyx_24080006_uif;

logic valid;
logic ready;

logic [31:0] pc, inst, imm, dnpc;

logic [31:0] sdata;  

logic [31:0] alu_src1;
logic [31:0] alu_src2;
logic [3:0]  alu_ctrl; 
logic [1:0]  alu_set; 
logic [31:0] alu_res;

logic [4:0]  rd_addr;

logic [11:0] csr_addr;
logic        csr_we, ecall;
logic [31:0] csr_wdata;

logic [2:0] funct3; 
logic load, store, wb, jump, branch;

modport prev(
	input  valid,
	output ready,
	
	input  pc,
	input  inst,
	input  imm,
	input  dnpc,

	input  sdata,

	input  alu_src1,
	input  alu_src2,
	input  alu_ctrl,
	input  alu_set,
	input  alu_res,
	input  rd_addr,

	input  csr_addr, csr_we, ecall, csr_wdata,

	input  funct3,
	input  load, store, wb, jump, branch
	);

modport next(
	output valid,
	input  ready,
	
	output pc,
	output inst,
	output imm,
	output dnpc,

	output sdata,

	output alu_src1,
	output alu_src2,
	output alu_ctrl,
	output alu_set,
	output alu_res,
	output rd_addr,

	output csr_addr, csr_we, ecall, csr_wdata,

	output funct3,
	output load, store, wb, jump, branch
	);
	
endinterface

module ysyx_24080006_wbu (
    input  logic        clock,
    input  logic        reset,

    output logic [4:0]  rd,    
    output logic [31:0] wdata,
    output logic        we,

    output logic        csr_we,
    output logic [11:0] csr_waddr,
    output logic [31:0] csr_wdata,

    ysyx_24080006_uif.prev    lsu,
    ysyx_24080006_uif.next    ifu
);

    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT,
        RST
    } curr, next;

    always_ff @ (posedge clock) begin  
        if (reset) begin
            curr <= RST;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin  
        unique case (curr)
            IDLE: begin
                if (lsu.valid)
                    next = EXEC;
                else
                    next = IDLE;
            end
            EXEC,
            WAIT: begin
                if (ifu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
            RST:
                next = IDLE;
        endcase
    end

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            lsu.ready <= 0;
            ifu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (lsu.valid) begin
                    lsu.ready <= 0;
                    ifu.valid <= 1;
                end
                else begin
                    lsu.ready <= 1;
                    ifu.valid <= 0;
                end
            end
            EXEC,
            WAIT: begin
                if (ifu.ready) begin
                    lsu.ready <= 1;
                    ifu.valid <= 0;
                end
                else begin
                    lsu.ready <= 0;
                    ifu.valid <= 1;
                end
            end
            RST: begin
                lsu.ready <= 0;
                ifu.valid <= 1;
            end
        endcase
        end
    end

    always_ff @ (posedge clock) begin 
        unique if (reset) begin
            rd <= '0;
            wdata <= '0;
            we <= '0;
            csr_we <= '0;
            csr_waddr <= '0;
            csr_wdata <= '0;
        end
        else begin
            if (curr == IDLE && lsu.valid) begin
                if (lsu.wb) begin  
                    rd <= lsu.rd_addr;
                    wdata <= lsu.alu_res;
                    we <= lsu.wb;
                end
                else if (lsu.csr_we) begin
                    rd <= lsu.rd_addr;
                    wdata <= lsu.csr_wdata;
                    we <= 1'b1;
                    csr_we <= lsu.csr_we;
                    csr_waddr <= lsu.csr_addr;
                    csr_wdata <= lsu.alu_res;
                end
                else if (lsu.ecall) begin
                    csr_we <= 1'b1; 
                    csr_waddr <= 12'h342;
                    csr_wdata <= lsu.alu_res;
                end
                else begin
                    rd <= '0;
                    wdata <= '0;
                    we <= '0;
                    csr_we <= '0;
                    csr_waddr <= '0;
                    csr_wdata <= '0;
                end
            end
            else begin
                rd <= '0;
                wdata <= '0;
                we <= '0;
                csr_we <= '0;
                csr_waddr <= '0;
                csr_wdata <= '0;
            end
        end
    end

    always_ff @ (posedge clock) begin
        if (reset) begin
            ifu.dnpc <= '0;
            ifu.jump <= '0;
            ifu.branch <= '0;
        end
        else begin
            ifu.dnpc <= lsu.dnpc;
            ifu.jump <= lsu.jump;  
            ifu.branch <= lsu.branch;  
        end

    end

endmodule

