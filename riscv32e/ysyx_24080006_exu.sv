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

    always_ff @ (posedge clock) begin//fsm 3 for control
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

    logic [31:0] alu_out, alu_res; //TODO not_zero will be merged into alu
    ysyx_24080006_alu ALU(
        .src1(idu.alu_src1),
        .src2(idu.alu_src2),
        .ctrl(idu.alu_ctrl),
        .res(alu_out));
        
    logic  not_zero;
    assign not_zero = |alu_out;
    logic branch;
    always_comb begin //fsm 2 for alu_res

        unique case (idu.alu_set)
            2'b00: alu_res = alu_out;
            2'b01: alu_res = {31'b0, ~not_zero};
            2'b10: alu_res = {31'b0,  not_zero};
            2'b11: alu_res = {31'b0, ~alu_out[0]};
        endcase

        if (idu.branch == 1'b1 && alu_res[0] == 1) begin //check branch cond
            branch = 1'b1;
        end
        else begin
            branch = 1'b0;
        end

    end

`ifdef SIM_MODE
import "DPI-C" function void EXU_CNT();
`endif
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
            lsu.pc <= '0;
        end
        else if (curr == IDLE && idu.valid) begin
            lsu.dnpc <= idu.dnpc;
            lsu.sdata <= idu.sdata;
            lsu.rd_addr <= idu.rd_addr;
            lsu.alu_res <= alu_res;
            lsu.funct3 <= idu.funct3;
            lsu.load <= idu.load;
            lsu.store <= idu.store;
            lsu.wb <= idu.wb;
            lsu.jump <= idu.jump; //may be merged
            lsu.branch <= branch; //^^^^^^^^^^^^^
            lsu.csr_addr <= idu.csr_addr;
            lsu.csr_we <= idu.csr_we;
            lsu.csr_wdata <= idu.csr_wdata;
            lsu.ecall <= idu.ecall;
            lsu.pc <= idu.pc;
            `ifdef SIM_MODE
            EXU_CNT();
            `endif
        end

    end


endmodule
