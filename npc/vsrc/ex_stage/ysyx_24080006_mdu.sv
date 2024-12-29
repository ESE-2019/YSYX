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
    output logic [31:0] mdu_c,

    input  logic valid_i,
    output logic valid_o
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

  logic div0_d, div0_q;
  logic [4:0] count_q, count_d;
  logic [32:0] shift_a_q, shift_a_d;
  logic [32:0] shift_b_q, shift_b_d;
  logic [31:0] op_numerator_q, op_numerator_d;
  logic [32:0] accum_window_q, accum_window_d;

  wire sign_a = mdu_a[31] & mdu_set.signed_a;
  wire sign_b = mdu_b[31] & mdu_set.signed_b;
  wire ge = accum_window_q[31] == shift_b_q[31] ? ~alu2mdu.res_34[32] : accum_window_q[31];
  wire [32:0] next_quotient = ge ? shift_a_q | (33'h1 << count_q) : shift_a_q;
  wire [31:0] next_remainder = ge ? alu2mdu.res_34[32:1] : accum_window_q[31:0];
  wire change_sign = mdu_set.mdu_op == DIV ? (sign_a ^ sign_b) & ~div0_q : sign_a;  // DIV : REM

  assign valid_o = ((mdu_set.mdu_op inside {MULL, MULH}) && (curr == MD_LAST))
                    ||  (curr == MD_FINISH);
  assign mdu_c = (mdu_set.mdu_op inside {MULL, MULH}) ? alu2mdu.res_34[31:0] : accum_window_q[31:0];

  always_ff @(posedge clock) begin
    if (reset) begin
      curr           <= MD_IDLE;
      div0_q         <= 1'b0;
      count_q        <= 5'h0;
      shift_a_q      <= 33'h0;
      shift_b_q      <= 33'h0;
      op_numerator_q <= 32'h0;
      accum_window_q <= 33'h0;
    end else begin
      curr           <= next;
      div0_q         <= div0_d;
      count_q        <= count_d;
      shift_a_q      <= shift_a_d;
      shift_b_q      <= shift_b_d;
      op_numerator_q <= op_numerator_d;
      accum_window_q <= accum_window_d;
    end
  end

  always_comb begin
    next           = curr;
    div0_d         = div0_q;
    count_d        = count_q;
    shift_a_d      = shift_a_q;
    shift_b_d      = shift_b_q;
    op_numerator_d = op_numerator_q;
    accum_window_d = accum_window_q;
    if (valid_i) begin
      unique case (curr)
        MD_IDLE: begin
          unique case (mdu_set.mdu_op)
            MULL: begin
              shift_a_d      = {sign_a, mdu_a} << 1;
              accum_window_d = {~(sign_a & mdu_b[0]), mdu_a & {32{mdu_b[0]}}};
              shift_b_d      = {sign_b, mdu_b} >> 1;
              next           = (({sign_b, mdu_b} >> 1) == 0) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              shift_a_d = {sign_a, mdu_a};
              accum_window_d = {1'b1, ~(sign_a & mdu_b[0]), mdu_a[31:1] & {31{mdu_b[0]}}};
              shift_b_d = {sign_b, mdu_b} >> 1;
              next = MD_COMP;
            end
            DIV: begin
              accum_window_d = {33{1'b1}};
              next           = ~alu2mdu.not_zero ? MD_FINISH : MD_ABS_A;
              div0_d         = ~alu2mdu.not_zero;
            end
            REM: begin
              accum_window_d = {sign_a, mdu_a};
              next           = ~alu2mdu.not_zero ? MD_FINISH : MD_ABS_A;
            end
            default: ;
          endcase
          count_d = 5'd31;
        end

        MD_ABS_A: begin
          shift_a_d      = 33'h0;
          op_numerator_d = sign_a ? alu2mdu.res_32 : mdu_a;
          next           = MD_ABS_B;
        end

        MD_ABS_B: begin
          accum_window_d = {32'h0, op_numerator_q[31]};
          shift_b_d      = sign_b ? {1'b0, alu2mdu.res_32} : {1'b0, mdu_b};
          next           = MD_COMP;
        end

        MD_COMP: begin
          count_d = count_q - 5'h1;
          unique case (mdu_set.mdu_op)
            MULL: begin
              accum_window_d = alu2mdu.res_34[32:0];
              shift_a_d = shift_a_q << 1;
              shift_b_d = shift_b_q >> 1;
              next = ((shift_b_d == 0) || (count_q == 5'd1)) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              accum_window_d = alu2mdu.res_34[33:1];
              shift_a_d      = shift_a_q;
              shift_b_d      = shift_b_q >> 1;
              next           = (count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            DIV, REM: begin
              accum_window_d = {next_remainder, op_numerator_q[count_d]};
              shift_a_d      = next_quotient;
              next           = (count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            default: ;
          endcase
        end

        MD_LAST: begin
          unique case (mdu_set.mdu_op)
            MULL, MULH: begin
              accum_window_d = alu2mdu.res_34[32:0];
              next           = MD_IDLE;
            end
            DIV: begin
              accum_window_d = next_quotient;
              next           = MD_SIGN;
            end
            REM: begin
              accum_window_d = {1'b0, next_remainder};
              next           = MD_SIGN;
            end
            default: ;
          endcase
        end

        MD_SIGN: begin
          next = MD_FINISH;
          accum_window_d = change_sign ? {1'b0, alu2mdu.res_32} : accum_window_q;
        end

        MD_FINISH: begin
          next = MD_IDLE;
        end

        default: ;
      endcase
    end
  end

  always_comb begin
    mdu2alu.a = {accum_window_q[31:0], 1'b1};  // DIV
    mdu2alu.b = {~shift_b_q[31:0], 1'b1};

    unique case (mdu_set.mdu_op)

      MULL: begin
        mdu2alu.a = accum_window_q;
        mdu2alu.b = {~(shift_a_q[32] & shift_b_q[0]), (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      MULH: begin
        mdu2alu.a = accum_window_q;
        mdu2alu.b = curr == MD_LAST ?
          { (shift_a_q[32] & shift_b_q[0]), ~(shift_a_q[31:0] & {32{shift_b_q[0]}})} :
          {~(shift_a_q[32] & shift_b_q[0]),  (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      DIV, REM: begin
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
            mdu2alu.b = {~accum_window_q[31:0], 1'b1};
          end
          default: ;
        endcase
      end

      default: ;
    endcase
  end

endmodule
