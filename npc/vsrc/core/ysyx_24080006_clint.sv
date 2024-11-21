module ysyx_24080006_clint
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  axi_w_m2s_t clint_w_m2s,
    output axi_w_s2m_t clint_w_s2m,
    input  axi_r_m2s_t clint_r_m2s,
    output axi_r_s2m_t clint_r_s2m
);
  logic [31:0] mtime_low_d, mtime_low_q, mtime_high_d, mtime_high_q;
  assign {mtime_high_d, mtime_low_d} = {mtime_high_q, mtime_low_q} + 64'd1;
  logic [31:0] dout;
  always_ff @(posedge clock) begin
    if (reset) begin
      mtime_high_q <= 32'b0;
      mtime_low_q  <= 32'b0;
    end else begin
      mtime_high_q <= mtime_high_d;
      mtime_low_q  <= mtime_low_d;
    end
  end
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
        clint_r_s2m.rdata   <= dout;
        clint_r_s2m.rvalid  <= 1'b1;
      end else if (clint_r_m2s.rready) begin
        clint_r_s2m.arready <= 1'b1;
        clint_r_s2m.rvalid  <= 1'b0;
      end
    end

  end

  always_comb begin
    dout = 32'b0;
    unique case (clint_r_m2s.araddr[15:0])
      16'hBFF8: dout = mtime_low_q;
      16'hBFFc: dout = mtime_high_q;
      default:  ;
    endcase
  end
endmodule
