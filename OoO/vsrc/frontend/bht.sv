// branch history table - 2 bit saturation counter
module bht
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic [31:0] pc,
    input bht_update_t bht_update,
    output bht_predict_t bht_predict
);

  localparam NR_ROWS = 32;
  localparam PREDICTION_BITS = $clog2(NR_ROWS) + 2;

  struct packed {
    logic       valid;
    logic [1:0] saturation_counter;
  }
      bht_d[NR_ROWS-1:0], bht_q[NR_ROWS-1:0];

  logic [$clog2(NR_ROWS)-1:0] index, update_pc;

  assign index     = pc[PREDICTION_BITS-1:2];
  assign update_pc = bht_update.pc[PREDICTION_BITS-1:2];

  logic [1:0] saturation_counter;

  assign bht_predict.valid = bht_q[index].valid;
  assign bht_predict.taken = bht_q[index].saturation_counter[1] == 1'b1;

  always_comb begin
    bht_d = bht_q;
    saturation_counter = bht_q[update_pc].saturation_counter;

    if (bht_update.valid) begin
      bht_d[update_pc].valid = 1'b1;

      if (saturation_counter == 2'b11) begin
        if (!bht_update.taken) bht_d[update_pc].saturation_counter = saturation_counter - 2'b01;
      end else if (saturation_counter == 2'b00) begin
        if (bht_update.taken) bht_d[update_pc].saturation_counter = saturation_counter + 2'b01;
      end else begin
        if (bht_update.taken) bht_d[update_pc].saturation_counter = saturation_counter + 2'b01;
        else bht_d[update_pc].saturation_counter = saturation_counter - 2'b01;
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      for (int unsigned i = 0; i < NR_ROWS; i++) begin
        bht_q[i] <= '0;
      end
    end else begin
      bht_q <= bht_d;
    end
  end

endmodule
