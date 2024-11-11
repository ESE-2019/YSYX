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
    MD_CHANGE_SIGN,
    MD_FINISH
  } mdu_fsm_e;
  mdu_fsm_e curr, next;

  logic [32:0] accum_window_q, accum_window_d;
  logic [32:0] res_adder_l, res_adder_h;
  logic [4:0] multdiv_count_q, multdiv_count_d;
  logic [32:0] op_b_shift_q, op_b_shift_d;
  logic [32:0] op_a_shift_q, op_a_shift_d;
  logic [32:0] op_a_ext, op_b_ext;
  logic [32:0] one_shift;
  logic [32:0] op_a_bw_pp, op_a_bw_last_pp;
  logic [31:0] b_0;
  logic sign_a, sign_b;
  logic [32:0] next_quotient;
  logic [31:0] next_remainder;
  logic [31:0] op_numerator_q, op_numerator_d;
  logic is_greater_equal;
  logic div_change_sign, rem_change_sign;
  logic div_by_zero_d, div_by_zero_q;

  // (accum_window_q + op_a_shift_q)
  assign res_adder_l = alu2mdu.res_34[32:0];
  // (accum_window_q + op_a_shift_q)>>1
  assign res_adder_h = alu2mdu.res_34[33:1];

  always_comb begin
    mdu2alu.a = accum_window_q;
    mdu2alu.b = {~op_b_shift_q[31:0], 1'b1};

    unique case (mdu_set.mdu_op)

      MULL: begin
        mdu2alu.b = op_a_bw_pp;
      end

      MULH: begin
        mdu2alu.b = (curr == MD_LAST) ? op_a_bw_last_pp : op_a_bw_pp;
      end

      DIV, REM: begin
        unique case (curr)
          MD_IDLE: begin
            // 0 - B = 0 iff B == 0
            mdu2alu.a = {32'h0, 1'b1};
            mdu2alu.b = {~mdu_b, 1'b1};
          end
          MD_ABS_A: begin
            // ABS(A) = 0 - A
            mdu2alu.a = {32'h0, 1'b1};
            mdu2alu.b = {~mdu_a, 1'b1};
          end
          MD_ABS_B: begin
            // ABS(B) = 0 - B
            mdu2alu.a = {32'h0, 1'b1};
            mdu2alu.b = {~mdu_b, 1'b1};
          end
          MD_CHANGE_SIGN: begin
            // ABS(Quotient) = 0 - Quotient (or Reminder)
            mdu2alu.a = {32'h0, 1'b1};
            mdu2alu.b = {~accum_window_q[31:0], 1'b1};
          end
          default: begin
            // Division
            mdu2alu.a = {accum_window_q[31:0], 1'b1};  // it contains the remainder
            mdu2alu.b = {~op_b_shift_q[31:0], 1'b1};  // -denominator two's compliment
          end
        endcase
      end
      default: begin
        mdu2alu.a = accum_window_q;
        mdu2alu.b = {~op_b_shift_q[31:0], 1'b1};
      end
    endcase
  end


  // Multiplier partial product calculation
  assign b_0 = {32{op_b_shift_q[0]}};
  assign op_a_bw_pp = {~(op_a_shift_q[32] & op_b_shift_q[0]), (op_a_shift_q[31:0] & b_0)};
  assign op_a_bw_last_pp = {(op_a_shift_q[32] & op_b_shift_q[0]), ~(op_a_shift_q[31:0] & b_0)};

  // Sign extend the input operands
  assign sign_a = mdu_a[31] & mdu_set.signed_a;
  assign sign_b = mdu_b[31] & mdu_set.signed_b;

  assign op_a_ext = {sign_a, mdu_a};
  assign op_b_ext = {sign_b, mdu_b};

  // Divider calculations

  // The adder in the ALU computes Remainder - Divisor. If Remainder - Divisor >= 0,
  // is_greater_equal is true, the next Remainder is the subtraction result and the Quotient
  // multdiv_count_q-th bit is set to 1.
  assign is_greater_equal = (accum_window_q[31] == op_b_shift_q[31]) ?
      ~res_adder_h[31] : accum_window_q[31];

  assign one_shift = {32'b0, 1'b1} << multdiv_count_q;

  assign next_remainder = is_greater_equal ? res_adder_h[31:0] : accum_window_q[31:0];
  assign next_quotient = is_greater_equal ? op_a_shift_q | one_shift : op_a_shift_q;

  assign div_change_sign = (sign_a ^ sign_b) & ~div_by_zero_q;
  assign rem_change_sign = sign_a;

  always_comb begin
    multdiv_count_d = multdiv_count_q;
    accum_window_d  = accum_window_q;
    op_b_shift_d    = op_b_shift_q;
    op_a_shift_d    = op_a_shift_q;
    op_numerator_d  = op_numerator_q;
    next            = curr;
    //multdiv_hold    = 1'b0;
    div_by_zero_d   = div_by_zero_q;
    if (valid_i) begin
      unique case (curr)
        MD_IDLE: begin
          unique case (mdu_set.mdu_op)
            MULL: begin
              op_a_shift_d   = op_a_ext << 1;
              accum_window_d = {~(op_a_ext[32] & mdu_b[0]), op_a_ext[31:0] & {32{mdu_b[0]}}};
              op_b_shift_d   = op_b_ext >> 1;
              // Proceed with multiplication by 0/1 in data-independent time mode
              // SEC_CM: CORE.DATA_REG_SW.SCA
              next           = ((op_b_ext >> 1) == 0) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              op_a_shift_d = op_a_ext;
              accum_window_d = {1'b1, ~(op_a_ext[32] & mdu_b[0]), op_a_ext[31:1] & {31{mdu_b[0]}}};
              op_b_shift_d = op_b_ext >> 1;
              next = MD_COMP;
            end
            DIV: begin
              // Check if the denominator is 0
              // quotient for division by 0 is specified to be -1
              // Note with data-independent time option, the full divide operation will proceed as
              // normal and will naturally return -1
              accum_window_d = {33{1'b1}};
              // SEC_CM: CORE.DATA_REG_SW.SCA
              next           = ~alu2mdu.not_zero ? MD_FINISH : MD_ABS_A;
              // Record that this is a div by zero to stop the sign change at the end of the
              // division (in data_ind_timing mode).
              div_by_zero_d  = ~alu2mdu.not_zero;
            end
            REM: begin
              // Check if the denominator is 0
              // remainder for division by 0 is specified to be the numerator (operand a)
              // Note with data-independent time option, the full divide operation will proceed as
              // normal and will naturally return operand a
              accum_window_d = op_a_ext;
              // SEC_CM: CORE.DATA_REG_SW.SCA
              next           = ~alu2mdu.not_zero ? MD_FINISH : MD_ABS_A;
            end
            default: ;
          endcase
          multdiv_count_d = 5'd31;
        end

        MD_ABS_A: begin
          // quotient
          op_a_shift_d   = '0;
          // A abs value
          op_numerator_d = sign_a ? alu2mdu.res_32 : mdu_a;
          next           = MD_ABS_B;
        end

        MD_ABS_B: begin
          // remainder
          accum_window_d = {32'h0, op_numerator_q[31]};
          // B abs value
          op_b_shift_d   = sign_b ? {1'b0, alu2mdu.res_32} : {1'b0, mdu_b};
          next           = MD_COMP;
        end

        MD_COMP: begin
          multdiv_count_d = multdiv_count_q - 5'h1;
          unique case (mdu_set.mdu_op)
            MULL: begin
              accum_window_d = res_adder_l;
              op_a_shift_d = op_a_shift_q << 1;
              op_b_shift_d = op_b_shift_q >> 1;
              // Multiplication is complete once op_b is zero, unless in data_ind_timing mode where
              // the maximum possible shift-add operations will be completed regardless of op_b
              // SEC_CM: CORE.DATA_REG_SW.SCA
              next = ((op_b_shift_d == 0) || (multdiv_count_q == 5'd1)) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              accum_window_d = res_adder_h;
              op_a_shift_d   = op_a_shift_q;
              op_b_shift_d   = op_b_shift_q >> 1;
              next           = (multdiv_count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            DIV, REM: begin
              accum_window_d = {next_remainder[31:0], op_numerator_q[multdiv_count_d]};
              op_a_shift_d   = next_quotient;
              next           = (multdiv_count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            default: ;
          endcase
        end

        MD_LAST: begin
          unique case (mdu_set.mdu_op)
            MULL: begin
              accum_window_d = res_adder_l;
              next = MD_IDLE;
            end
            MULH: begin
              accum_window_d = res_adder_l;
              next           = MD_IDLE;
            end
            DIV: begin
              // this time we save the quotient in accum_window_q since we do not need anymore the
              // remainder
              accum_window_d = next_quotient;
              next           = MD_CHANGE_SIGN;
            end
            REM: begin
              // this time we do not save the quotient anymore since we need only the remainder
              accum_window_d = {1'b0, next_remainder[31:0]};
              next           = MD_CHANGE_SIGN;
            end
            default: ;
          endcase
        end

        MD_CHANGE_SIGN: begin
          next = MD_FINISH;
          unique case (mdu_set.mdu_op)
            DIV: accum_window_d = div_change_sign ? {1'b0, alu2mdu.res_32} : accum_window_q;
            REM: accum_window_d = rem_change_sign ? {1'b0, alu2mdu.res_32} : accum_window_q;
            default: ;
          endcase
        end

        MD_FINISH: begin
          next = MD_IDLE;
        end

        default: begin
          next = MD_IDLE;
        end
      endcase  // curr
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      multdiv_count_q <= 5'h0;
      op_b_shift_q    <= 33'h0;
      op_a_shift_q    <= 33'h0;
      curr            <= MD_IDLE;
      div_by_zero_q   <= 1'b0;
      op_numerator_q  <= 32'h0;
      accum_window_q  <= 33'h0;
    end else begin
      multdiv_count_q <= multdiv_count_d;
      op_b_shift_q    <= op_b_shift_d;
      op_a_shift_q    <= op_a_shift_d;
      curr            <= next;
      div_by_zero_q   <= div_by_zero_d;
      op_numerator_q  <= op_numerator_d;
      accum_window_q  <= accum_window_d;
    end
  end

  wire is_mul = mdu_set.mdu_op inside {MULL, MULH};
  assign valid_o = (curr == MD_FINISH) | ((curr == MD_LAST) & is_mul);
  assign mdu_c   = is_mul ? res_adder_l[31:0] : accum_window_q[31:0];

endmodule
