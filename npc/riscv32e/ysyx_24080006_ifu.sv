module ysyx_24080006_ifu (
    input  logic        clock,
    input  logic        reset,
    input  logic        pc,
    axi_if.master  axi_ifu,
    xxu_if.prev    wbu,
    xxu_if.next    idu
);

    enum logic [1:0] {
        IDLE
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

    always_ff @ (posedge clock) begin//fsm 3 for control
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

assign axi_ifu.araddr = pc;//TODO will be edited
    always_ff @ (posedge clock) begin//fsm 3 for axi
        unique if (reset) begin
            axi_ifu.arvalid <= 0;
		    axi_ifu.rready  <= 1;
            idu.inst <= '0;
            idu.pc <= '0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (wbu.valid) begin
				    axi_ifu.arvalid <= 1;
				    axi_ifu.rready  <= 1;
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
                    axi_ifu.arvalid <= 0;
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
