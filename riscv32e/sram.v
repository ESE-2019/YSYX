module sram(
    input  logic        clock,
    input  logic        reset,
    ysyx_24080006_axi.slave axi);

import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input int wmask);

//clint begin
    logic [63:0] mtime;
    logic [31:0] dout;
    always_ff @(posedge clock) begin
        unique if (reset) begin
            mtime <= '0;
        end
        else begin
            mtime <= mtime + 64'b1;
        end
    end
    always_comb begin
    	dout = '0;
     	unique case(axi.araddr)
     	32'ha0000048:dout=mtime[31: 0];
     	32'ha000004c:dout=mtime[63:32];
     	default:;
     	endcase
    end
//clint end

    always_ff @(posedge clock) begin
        if (reset) begin
            axi.awready <= 1;
            axi.wready <= 1;
            axi.bvalid <= 0;
        end
        else begin

            if (axi.awvalid && axi.wvalid && axi.awready && axi.wready && !axi.bvalid) begin
                axi.awready <= 0;
                axi.wready <= 0;
                axi.bvalid <= 1;
                axi.bresp <= 2'b00;
                if(axi.awaddr == 32'ha00003F8) begin
                    $write("%c", axi.wdata[7:0]);
                end
                else begin
                    pmem_write(axi.awaddr, axi.wdata, {28'b0, axi.wstrb});
                end
            end
            else if (axi.bready) begin
                axi.awready <= 1;
                axi.wready <= 1;
                axi.bvalid <= 0;
            end
        end
    end

    always_ff @(posedge clock) begin
        if (reset) begin
            axi.arready <= 1;
            axi.rvalid <= 0;
        end
        else begin
            if (axi.arvalid && axi.arready && !axi.rvalid) begin
                axi.arready <= 0;
                axi.rdata   <= axi.araddr >= 32'ha0000000 ? dout : pmem_read(axi.araddr);
                axi.rvalid  <= 1;
                axi.rresp   <= 2'b00;
            end
            else if(axi.rready) begin
                axi.arready <= 1;
                axi.rvalid  <= 0;
            end
        end
    end
endmodule
