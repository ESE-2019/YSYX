module ysyx_24080006_clint (
    input logic clock,
    input logic reset,
    ysyx_24080006_axi.slave axi_clint
);
  logic [31:0] mtime_low_d, mtime_low_q, mtime_high_d, mtime_high_q;
  assign {mtime_high_d, mtime_low_d} = {mtime_high_q, mtime_low_q} + 64'b1;
  logic [31:0] dout;
  always_ff @(posedge clock) begin
    if (reset) begin
      mtime_high_q <= 0;
      mtime_low_q  <= 0;
    end else begin
      mtime_high_q <= mtime_high_d;
      mtime_low_q  <= mtime_low_d;
    end
  end
  always_ff @(posedge clock) begin
    if (reset) begin
      axi_clint.awready <= 1;
      axi_clint.wready  <= 1;
      axi_clint.bvalid  <= 0;
      axi_clint.arready <= 1;
      axi_clint.rvalid  <= 0;
    end else begin

      if (axi_clint.awvalid && axi_clint.wvalid && axi_clint.awready && axi_clint.wready && !axi_clint.bvalid) begin
        axi_clint.awready <= 0;
        axi_clint.wready  <= 0;
        axi_clint.bvalid  <= 1;
        axi_clint.bresp   <= 2'b00;
      end else if (axi_clint.bready) begin
        axi_clint.awready <= 1;
        axi_clint.wready  <= 1;
        axi_clint.bvalid  <= 0;
      end

      if (axi_clint.arvalid && axi_clint.arready && !axi_clint.rvalid) begin
        axi_clint.arready <= 0;
        axi_clint.rdata   <= dout;
        axi_clint.rvalid  <= 1;
        axi_clint.rresp   <= 2'b00;
      end else if (axi_clint.rready) begin
        axi_clint.arready <= 1;
        axi_clint.rvalid  <= 0;
      end
    end

  end

  always_comb begin
    dout = '0;
    unique case (axi_clint.araddr[15:0])
      16'hBFF8: dout = mtime_low_q;
      16'hBFFc: dout = mtime_high_q;
      default:  ;
    endcase
  end
endmodule
