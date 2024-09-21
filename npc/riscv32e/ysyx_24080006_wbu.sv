module ysyx_24080006_wbu (
    input  logic        clock,
    input  logic        reset,

    output logic [4:0]  rd,    
    output logic [31:0] wdata,
    output logic        we,
    xxu_if.prev    lsu,
    xxu_if.next    ifu
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
        end
        else begin
            if (curr == IDLE && lsu.valid) begin
                if (lsu.wb) begin
                    rd <= lsu.rd_addr;
                    wdata <= lsu.alu_res;
                    we <= 1'b1;
                end
                else begin
                    rd <= '0;
                    wdata <= '0;
                    we <= '0;
                end
            end
            else begin
                rd <= '0;
                wdata <= '0;
                we <= '0;
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
