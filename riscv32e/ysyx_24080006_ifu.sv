module ysyx_24080006_ifu (
    input  logic        clock,
    input  logic        reset,

    ysyx_24080006_axi.master  axi_ifu,
    ysyx_24080006_uif.prev    wbu,
    ysyx_24080006_uif.next    idu
);

    logic [31:0] pc;
    `ifdef SOC_MODE
    localparam RST_ADDR = 32'h3000_0000 - 32'h4;
    `else
    localparam RST_ADDR = 32'h8000_0000 - 32'h4;
    `endif

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
`ifdef SIM_MODE
import "DPI-C" function void dbg(input int inst, input int pc, input int ft_pc);
logic [31:0] ftrace;
`endif

    always_ff @ (posedge clock) begin//fsm 3 for axi
        unique if (reset) begin
            axi_ifu.arvalid <= 0;
		    axi_ifu.rready  <= 0;
            idu.inst <= '0;
            pc <= RST_ADDR;
            `ifdef SIM_MODE
            ftrace <= RST_ADDR;
            `endif
            idu.pc <= '0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (wbu.valid) begin
				    axi_ifu.arvalid <= 1;
				    axi_ifu.rready  <= 0;
                    if (wbu.jump || wbu.branch)
                        pc <= wbu.dnpc;
                    else
                        pc <= pc + 32'h4;
                end
                else begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 0;
                end
            end
            EXEC: begin
                if (axi_ifu.arready)
                    axi_ifu.arvalid <= 0;
                if (axi_ifu.rvalid) begin                    
				    axi_ifu.rready  <= 1;
                    idu.inst <= axi_ifu.rdata;
                    `ifdef SIM_MODE
                    if (wbu.jump || wbu.branch)
                        ftrace <= wbu.dnpc;
                    else
                        ftrace <= ftrace + 32'h4;
                    dbg(axi_ifu.rdata, pc, (wbu.jump?ftrace:0));
                    `endif
                    idu.pc <= pc;
                end
            end
            WAIT: begin
                    axi_ifu.arvalid <= 0;
				    axi_ifu.rready  <= 0;
                end
        endcase
        end
    end

assign axi_ifu.arid    = 4'h0;
assign axi_ifu.arlen   = 8'h0;
assign axi_ifu.arsize  = 3'h2;
assign axi_ifu.arburst = 2'h1;

`ifdef SOC_MODE
    function automatic logic INSIDE (
        input logic [31:0] addr, left, right);
        INSIDE = addr >= left && addr <= right;
    endfunction

    function automatic logic INSIDE_MEM (input logic [31:0] addr);
        INSIDE_MEM =    INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) || // SRAM
                        //INSIDE(addr, 32'h2000_0000, 32'h2000_0fff) || // MROM
                        INSIDE(addr, 32'h3000_0000, 32'h300f_ffff) || // FLASH
                        INSIDE(addr, 32'h4000_0000, 32'hffff_ffff) || // OTHERS
                        0;
    endfunction
    always_ff @ (posedge clock) begin
        if (curr == EXEC && !INSIDE_MEM(pc)) begin
            $display("[IFU]addr error 0x%08x", pc);$finish;end
    end
`endif

endmodule
