module ysyx_24080006_clint
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    // input  axi_w_m2s_t clint_w_m2s,
    // output axi_w_s2m_t clint_w_s2m,
    input  axi_r_m2s_t clint_r_m2s,
    output axi_r_s2m_t clint_r_s2m
);
  logic [31:0] mtime_high, mtime_low;
  logic [31:0] axi_rdata;
  logic illegal_addr;

  always_ff @(posedge clock) begin
    if (reset) begin
      // write deleted
      clint_r_s2m.arready <= 1'b1;
      clint_r_s2m.rvalid  <= 1'b0;
      clint_r_s2m.rlast   <= 1'b1;
    end else begin

      // write deleted

      if (clint_r_m2s.arvalid && clint_r_s2m.arready && !clint_r_s2m.rvalid) begin
        clint_r_s2m.arready <= 1'b0;
        clint_r_s2m.rdata   <= axi_rdata;
        clint_r_s2m.rvalid  <= 1'b1;
      end else if (clint_r_m2s.rready) begin
        clint_r_s2m.arready <= 1'b1;
        clint_r_s2m.rvalid  <= 1'b0;
      end
    end

  end

  always_comb begin
    axi_rdata = mtime_low;
    illegal_addr = 1'b0;
    unique case (clint_r_m2s.araddr[15:0])
      16'hBFF8: axi_rdata = mtime_low;
      16'hBFFc: axi_rdata = mtime_high;
      default:  illegal_addr = 1'b1;
    endcase
  end

  ysyx_24080006_counter CLINT_COUNTER (
      .clock             (clock),
      .reset             (reset),
      .counter_incr_en   (1'b1),
      .counter_high_we   (1'b0),
      .counter_low_we    (1'b0),
      .counter_wdata     (32'b0),
      .counter_high_rdata(mtime_high),
      .counter_low_rdata (mtime_low)
  );

endmodule
