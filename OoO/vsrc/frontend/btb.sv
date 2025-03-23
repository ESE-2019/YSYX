// branch target buffer
module btb
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic [31:0] pc,
    input btb_update_t btb_update,
    output btb_prediction_t [0:0] btb_predict
);

  localparam NR_ROWS = 8;
  localparam PREDICTION_BITS = $clog2(NR_ROWS) + 2;

  logic [$clog2(NR_ROWS)-1:0] index, update_pc;

  assign index     = pc[PREDICTION_BITS-1:2];
  assign update_pc = btb_update.pc[PREDICTION_BITS-1:2];

  // typedef for all branch target entries
  // we may want to try to put a tag field that fills the rest of the PC in-order to mitigate aliasing effects
  btb_prediction_t [NR_ROWS-1:0] btb_d;
  btb_prediction_t [NR_ROWS-1:0] btb_q;


  assign btb_predict[0] = btb_q[index];

  // -------------------------
  // Update Branch Prediction
  // -------------------------
  // update on a mis-predict
  always_comb begin
    btb_d = btb_q;

    if (btb_update.valid) begin
      btb_d[update_pc].valid = 1'b1;
      // the target address is simply updated
      btb_d[update_pc].target_address = btb_update.target_address;
    end
  end

  // sequential process
  always_ff @(posedge clock) begin
    if (reset) begin
      btb_q <= '0;
    end else begin
      btb_q <= btb_d;
    end
  end

endmodule
