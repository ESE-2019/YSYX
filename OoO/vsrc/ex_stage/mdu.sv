`default_nettype none

module mdu
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input fu_data_t mdu_data,
    output logic [31:0] mdu_result,
    output logic [ScoreboardIndex-1:0] mdu_idx,

    input  logic mdu_valid,
    output logic mdu_finish,
    output logic mdu_ready
);

  fu_data_t fu_data;
  assign mdu_idx = fu_data.idx;
  wire [31:0] a = fu_data.operand_a;
  wire [31:0] b = fu_data.operand_b;

  function automatic logic signed [31:0] div(logic signed [31:0] opa, opb);
    if (opa == 32'h8000_0000 && opb == 32'hFFFF_FFFF) return 32'h8000_0000;
    else if (opb == 32'h0) return 32'hFFFF_FFFF;
    else return opa / opb;
  endfunction

  function automatic logic signed [31:0] rem(logic signed [31:0] opa, opb);
    if (opa == 32'h8000_0000 && opb == 32'hFFFF_FFFF) return 32'h0;
    else if (opb == 32'h0) return opa;
    else return opa % opb;
  endfunction

  /* verilator lint_off WIDTHTRUNC */
  always_comb begin
    unique case (fu_data.operation)
      MDU_MUL: begin
        mdu_result = a * b;
      end
      MDU_MULH: begin
        mdu_result = ({{32{a[31]}}, a} * {{32{b[31]}}, b}) >> 32;
      end
      MDU_MULHU: begin
        mdu_result = ({32'b0, a} * {32'b0, b}) >> 32;
      end
      MDU_MULHSU: begin
        mdu_result = ({{32{a[31]}}, a} * {32'b0, b}) >> 32;
      end
      MDU_DIV: begin
        mdu_result = div(a, b);
      end
      MDU_DIVU: begin
        mdu_result = b == 32'b0 ? {32{1'b1}} : a / b;
      end
      MDU_REM: begin
        mdu_result = rem(a, b);
      end
      MDU_REMU: begin
        mdu_result = b == 32'b0 ? a : a % b;
      end
      default: begin
        mdu_result = 32'b0;
      end
    endcase
  end
  /* verilator lint_on WIDTHTRUNC */
  always_ff @(posedge clock) begin
    if (reset) begin
      fu_data <= '0;
      mdu_finish <= 1'b0;
      mdu_ready <= 1'b1;
    end else begin
      if (mdu_valid) begin
        fu_data <= mdu_data;
        mdu_finish <= 1'b1;
        mdu_ready <= 1'b0;
      end else begin
        mdu_finish <= 1'b0;
        mdu_ready  <= 1'b1;
      end
    end
  end

endmodule

`default_nettype wire
