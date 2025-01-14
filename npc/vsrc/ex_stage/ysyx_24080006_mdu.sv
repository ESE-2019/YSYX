`default_nettype none

module ysyx_24080006_mdu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output mdu2alu_t mdu2alu,
    input  alu2mdu_t alu2mdu,

    input logic [31:0] mdu_a,
    input logic [31:0] mdu_b,
    input mdu_set_t mdu_set,
    output logic [31:0] mdu_o,

    input  logic mdu_valid,
    output logic mdu_ready
);

  typedef enum logic [2:0] {
    MD_IDLE,
    MD_ABS_A,
    MD_ABS_B,
    MD_COMP,
    MD_LAST,
    MD_SIGN,
    MD_FINISH
  } mdu_fsm_e;
  mdu_fsm_e curr, next;

  logic [4:0] count_q, count_d;
  logic [32:0] shift_a_q, shift_a_d;
  logic [32:0] shift_b_q, shift_b_d;
  logic [31:0] dividend_q, dividend_d;
  logic [32:0] accumulator_q, accumulator_d;

  wire sign_a = mdu_a[31] & mdu_set.signed_a;
  wire sign_b = mdu_b[31] & mdu_set.signed_b;
  wire ge = accumulator_q[31] == shift_b_q[31] ? ~alu2mdu.res[32] : accumulator_q[31];
  wire change_sign = mdu_set.mdu_op == ALU_DIV ? (sign_a ^ sign_b) : sign_a;

  assign mdu_ready = curr == MD_FINISH;
  assign mdu_o = (mdu_set.mdu_op inside {ALU_MULL, ALU_MULH}) ? alu2mdu.res[31:0]
                 : accumulator_q[31:0];

  always_ff @(posedge clock) begin
    if (reset) begin
      curr          <= MD_IDLE;
      count_q       <= 5'h0;
      shift_a_q     <= 33'h0;
      shift_b_q     <= 33'h0;
      dividend_q    <= 32'h0;
      accumulator_q <= 33'h0;
    end else begin
      curr          <= next;
      count_q       <= count_d;
      shift_a_q     <= shift_a_d;
      shift_b_q     <= shift_b_d;
      dividend_q    <= dividend_d;
      accumulator_q <= accumulator_d;
    end
  end

  always_comb begin
    next          = curr;
    count_d       = count_q;
    shift_a_d     = shift_a_q;
    shift_b_d     = shift_b_q;
    dividend_d    = dividend_q;
    accumulator_d = accumulator_q;
    if (mdu_valid) begin
      unique case (curr)
        MD_IDLE: begin
          unique case (mdu_set.mdu_op)
            ALU_MULL: begin
              shift_a_d     = {sign_a, mdu_a} << 1;
              accumulator_d = {~(sign_a & mdu_b[0]), mdu_a & {32{mdu_b[0]}}};
              shift_b_d     = {sign_b, mdu_b} >> 1;
              next          = MD_COMP;
            end
            ALU_MULH: begin
              shift_a_d = {sign_a, mdu_a};
              accumulator_d = {1'b1, ~(sign_a & mdu_b[0]), mdu_a[31:1] & {31{mdu_b[0]}}};
              shift_b_d = {sign_b, mdu_b} >> 1;
              next = MD_COMP;
            end
            ALU_DIV, ALU_REM: begin
              accumulator_d[31:0] = mdu_set.mdu_op == ALU_DIV ? 32'hFFFF_FFFF : mdu_a;
              next = ~alu2mdu.not_zero ? MD_FINISH : MD_ABS_A;
            end
            default: ;
          endcase
          count_d = 5'd31;
        end

        MD_ABS_A: begin
          shift_a_d  = 33'h0;
          dividend_d = sign_a ? alu2mdu.res[32:1] : mdu_a;
          next       = MD_ABS_B;
        end

        MD_ABS_B: begin
          accumulator_d = {32'h0, dividend_q[31]};
          shift_b_d     = sign_b ? {1'b0, alu2mdu.res[32:1]} : {1'b0, mdu_b};
          next          = MD_COMP;
        end

        MD_COMP: begin
          count_d = count_q - 5'h1;
          unique case (mdu_set.mdu_op)
            ALU_MULL: begin
              accumulator_d = alu2mdu.res[32:0];
              shift_a_d = shift_a_q << 1;
              shift_b_d = shift_b_q >> 1;
              next = ((shift_b_d == 0) || (count_q == 5'd1)) ? MD_FINISH : MD_COMP;
            end
            ALU_MULH: begin
              accumulator_d = alu2mdu.res[33:1];
              shift_a_d     = shift_a_q;
              shift_b_d     = shift_b_q >> 1;
              next          = (count_q == 5'd1) ? MD_FINISH : MD_COMP;
            end
            ALU_DIV, ALU_REM: begin
              accumulator_d = {ge ? alu2mdu.res[32:1] : accumulator_q[31:0], dividend_q[count_d]};
              shift_a_d     = ge ? shift_a_q | (33'h1 << count_q) : shift_a_q;
              next          = (count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            default: ;
          endcase
        end

        MD_LAST: begin
          accumulator_d = mdu_set.mdu_op == ALU_DIV ?
                          (ge ? shift_a_q | (33'h1 << count_q) : shift_a_q) :
                          {1'b0, ge ? alu2mdu.res[32:1] : accumulator_q[31:0]};
          next = MD_SIGN;
        end

        MD_SIGN: begin
          next = MD_FINISH;
          accumulator_d = change_sign ? {1'b0, alu2mdu.res[32:1]} : accumulator_q;
        end

        MD_FINISH: begin
          next = MD_IDLE;
        end

        default: ;
      endcase
    end
  end

  always_comb begin
    mdu2alu.a = {accumulator_q[31:0], 1'b1};  // ALU_DIV
    mdu2alu.b = {~shift_b_q[31:0], 1'b1};

    unique case (mdu_set.mdu_op)

      ALU_MULL: begin
        mdu2alu.a = accumulator_q;
        mdu2alu.b = {~(shift_a_q[32] & shift_b_q[0]), (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      ALU_MULH: begin
        mdu2alu.a = accumulator_q;
        mdu2alu.b = curr == MD_FINISH ?
          { (shift_a_q[32] & shift_b_q[0]), ~(shift_a_q[31:0] & {32{shift_b_q[0]}})} :
          {~(shift_a_q[32] & shift_b_q[0]),  (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      ALU_DIV, ALU_REM: begin
        unique case (curr)
          MD_IDLE, MD_ABS_B: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~mdu_b, 1'b1};
          end
          MD_ABS_A: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~mdu_a, 1'b1};
          end
          MD_SIGN: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~accumulator_q[31:0], 1'b1};
          end
          default: ;
        endcase
      end

      default: ;
    endcase
  end

endmodule

`default_nettype wire
