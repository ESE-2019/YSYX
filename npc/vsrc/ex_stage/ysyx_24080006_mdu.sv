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

  logic div_by_zero_d, div_by_zero_q;
  logic [4:0] multdiv_count_q, multdiv_count_d;
  logic [32:0] op_a_shift_q, op_a_shift_d;
  logic [32:0] op_b_shift_q, op_b_shift_d;
  logic [31:0] op_numerator_q, op_numerator_d;
  logic [32:0] accum_window_q, accum_window_d;

  wire sign_a = mdu_a[31] & mdu_set.signed_a;
  wire sign_b = mdu_b[31] & mdu_set.signed_b;
  wire ge = accum_window_q[31] == op_b_shift_q[31] ? ~alu2mdu.res_34[32] : accum_window_q[31];
  wire [32:0] next_quotient = ge ? op_a_shift_q | ({32'b0, 1'b1} << multdiv_count_q) : op_a_shift_q;
  wire [31:0] next_remainder = ge ? alu2mdu.res_34[32:1] : accum_window_q[31:0];
  wire change_sign = mdu_set.mdu_op == DIV ? (sign_a ^ sign_b) & ~div_by_zero_q : sign_a;

  assign valid_o = ((mdu_set.mdu_op inside {MULL, MULH}) && (curr == MD_LAST)) || (curr == MD_FINISH);
  assign mdu_c = (mdu_set.mdu_op inside {MULL, MULH}) ? alu2mdu.res_34[31:0] : accum_window_q[31:0];

  always_ff @(posedge clock) begin
    if (reset) begin
      curr            <= MD_IDLE;
      div_by_zero_q   <= 1'b0;
      multdiv_count_q <= 5'h0;
      op_a_shift_q    <= 33'h0;
      op_b_shift_q    <= 33'h0;
      op_numerator_q  <= 32'h0;
      accum_window_q  <= 33'h0;
    end else begin
      curr            <= next;
      div_by_zero_q   <= div_by_zero_d;
      multdiv_count_q <= multdiv_count_d;
      op_a_shift_q    <= op_a_shift_d;
      op_b_shift_q    <= op_b_shift_d;
      op_numerator_q  <= op_numerator_d;
      accum_window_q  <= accum_window_d;
    end
  end

  always_comb begin
    next            = curr;
    div_by_zero_d   = div_by_zero_q;
    multdiv_count_d = multdiv_count_q;
    op_a_shift_d    = op_a_shift_q;
    op_b_shift_d    = op_b_shift_q;
    op_numerator_d  = op_numerator_q;
    accum_window_d  = accum_window_q;
    if (valid_i) begin
      unique case (curr)
        MD_IDLE: begin
          unique case (mdu_set.mdu_op)
            MULL: begin
              op_a_shift_d   = {sign_a, mdu_a} << 1;
              accum_window_d = {~(sign_a & mdu_b[0]), mdu_a & {32{mdu_b[0]}}};
              op_b_shift_d   = {sign_b, mdu_b} >> 1;
              // Proceed with multiplication by 0/1 in data-independent time mode
              next           = (({sign_b, mdu_b} >> 1) == 0) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              op_a_shift_d = {sign_a, mdu_a};
              accum_window_d = {1'b1, ~(sign_a & mdu_b[0]), mdu_a[31:1] & {31{mdu_b[0]}}};
              op_b_shift_d = {sign_b, mdu_b} >> 1;
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
              div_by_zero_d  = ~alu2mdu.not_zero;
            end
            REM: begin
              // Check if the denominator is 0
              // remainder for division by 0 is specified to be the numerator (operand a)
              // Note with data-independent time option, the full divide operation will proceed as
              // normal and will naturally return operand a
              accum_window_d = {sign_a, mdu_a};
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
              accum_window_d = alu2mdu.res_34[32:0];
              op_a_shift_d = op_a_shift_q << 1;
              op_b_shift_d = op_b_shift_q >> 1;
              // Multiplication is complete once op_b is zero, unless in data_ind_timing mode where
              // the maximum possible shift-add operations will be completed regardless of op_b
              next = ((op_b_shift_d == 0) || (multdiv_count_q == 5'd1)) ? MD_LAST : MD_COMP;
            end
            MULH: begin
              accum_window_d = alu2mdu.res_34[33:1];
              op_a_shift_d   = op_a_shift_q;
              op_b_shift_d   = op_b_shift_q >> 1;
              next           = (multdiv_count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            DIV, REM: begin
              accum_window_d = {next_remainder, op_numerator_q[multdiv_count_d]};
              op_a_shift_d   = next_quotient;
              next           = (multdiv_count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            default: ;
          endcase
        end

        MD_LAST: begin
          unique case (mdu_set.mdu_op)
            MULL: begin
              accum_window_d = alu2mdu.res_34[32:0];
              next = MD_IDLE;
            end
            MULH: begin
              accum_window_d = alu2mdu.res_34[32:0];
              next           = MD_IDLE;
            end
            DIV: begin
              // this time we save the quotient in accum_window_q since we do not need anymore the
              // remainder
              accum_window_d = next_quotient;
              next           = MD_SIGN;
            end
            REM: begin
              // this time we do not save the quotient anymore since we need only the remainder
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
    mdu2alu.a = {accum_window_q[31:0], 1'b1};
    mdu2alu.b = {~op_b_shift_q[31:0], 1'b1};

    unique case (mdu_set.mdu_op)

      MULL: begin
        mdu2alu.a = accum_window_q;
        mdu2alu.b = {
          ~(op_a_shift_q[32] & op_b_shift_q[0]), (op_a_shift_q[31:0] & {32{op_b_shift_q[0]}})
        };
      end

      MULH: begin
        mdu2alu.a = accum_window_q;
        mdu2alu.b = curr == MD_LAST ? 
          { (op_a_shift_q[32] & op_b_shift_q[0]), ~(op_a_shift_q[31:0] & {32{op_b_shift_q[0]}})} : 
          {~(op_a_shift_q[32] & op_b_shift_q[0]),  (op_a_shift_q[31:0] & {32{op_b_shift_q[0]}})};
      end

      DIV, REM: begin
        unique case (curr)
          MD_IDLE: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~mdu_b, 1'b1};
          end
          MD_ABS_A: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~mdu_a, 1'b1};
          end
          MD_ABS_B: begin
            mdu2alu.a = 33'h1;
            mdu2alu.b = {~mdu_b, 1'b1};
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
