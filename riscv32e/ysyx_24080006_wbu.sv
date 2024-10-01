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

    always_ff @ (posedge clock) begin //fsm 1
        if (reset) begin
            curr <= RST;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin //fsm 2
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

    always_ff @ (posedge clock) begin//fsm 3 for control
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

    always_ff @ (posedge clock) begin//fsm 3 for exu output
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
                if (lsu.wb) begin // TODO unnecessary
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
                    csr_we <= 1'b1;//lsu.csr_we;
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
            ifu.jump <= lsu.jump; //may be merged
            ifu.branch <= lsu.branch; //^^^^^^^^^
        end

    end

endmodule
