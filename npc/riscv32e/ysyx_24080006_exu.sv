module ysyx_24080006_wbu (
    input  logic        clock,
    input  logic        reset,
    input  logic [31:0] alu_result,
    input  logic [31:0] mem_rdata,
    input  logic [1:0]  wb_sel, // { mem , alu }
    input  logic [4:0]  rd,
    
    output logic [31:0] rd_data,
    output logic        rd_we,
    xxu_if.prev    lsu,
    xxu_if.next    ifu
);
//TODO use fsm
    enum logic [1:0] {
        IDLE
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
            rd_data <= '0;
            rd_we <= '0;
        end
        else begin
            if (curr == IDLE && lsu.valid) begin
                case (wb_sel)
                    2'b01: begin
                        rd_data <= alu_result;
                        rd_we <= 1'b1;
                    end
                    2'b10: begin
                        rd_data <= mem_rdata;
                        rd_we <= 1'b1;
                    end
                    default: begin
                        rd_data <= '0;
                        rd_we <= '0;
                    end
                endcase
            end
            else begin
                rd_data <= '0;
                rd_we <= '0;
            end
        end
    end

endmodule
