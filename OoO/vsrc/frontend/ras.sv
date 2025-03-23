// return address stack
module ras
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input ras_update_t ras_update,
    output ras_predict_t ras_predict
);
  localparam int RasDepth = 4;
  ras_predict_t [RasDepth-1:0] stack_d, stack_q;

  assign ras_predict = stack_q[0];

  always_comb begin
    stack_d = stack_q;

    if (ras_update.push) begin
      stack_d[0].ra = ras_update.ra;
      stack_d[0].valid = 1'b1;
      stack_d[RasDepth-1:1] = stack_q[RasDepth-2:0];
    end

    if (ras_update.pop) begin
      stack_d[RasDepth-2:0] = stack_q[RasDepth-1:1];
      stack_d[RasDepth-1].valid = 1'b0;
      stack_d[RasDepth-1].ra = 32'b0;
    end

    if (ras_update.pop && ras_update.push) begin
      stack_d = stack_q;
      stack_d[0].ra = ras_update.ra;
      stack_d[0].valid = 1'b1;
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      stack_q <= '0;
    end else begin
      stack_q <= stack_d;
    end
  end

endmodule
