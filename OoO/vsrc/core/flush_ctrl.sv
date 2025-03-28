module flush_ctrl
  import OoO_pkg::*;
(
    input  bju_t bju,
    output logic flush_frontend,
    output logic flush_unissued_instr
);

  always_comb begin
    flush_frontend = 1'b1;
    flush_unissued_instr = 1'b1;
    if (bju.valid & bju.is_mispredict) begin
      flush_frontend       = 1'b1;
      flush_unissued_instr = 1'b1;
    end
  end

endmodule
