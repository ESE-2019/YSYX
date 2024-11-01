module ysyx_24080006_clint (
    input clock,
    reset,
    ysyx_24080006_axi.slave axi_clint
);
  logic [63:0] mtime;
  logic [31:0] dout;
  always_ff @(posedge clock) begin
    if (reset) begin
      mtime <= '0;
    end else begin
      mtime <= mtime + 64'b100;
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
      16'hBFF8: dout = mtime[31:0];
      16'hBFFc: dout = mtime[63:32];
      default:  ;
    endcase
  end
endmodule
