`default_nettype none

module mdu
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input fu_data_t fu_data,
    output logic [31:0] mdu_result,
    output logic [ScoreboardDepth-1:0] mdu_trans_id,

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

  typedef enum logic [1:0] {
    ALU_MULL,
    ALU_MULH,
    ALU_DIV,
    ALU_REM
  } mdu_op_e;
  mdu_op_e mdu_op;
  always_comb begin
    unique case (fu_data.operation)
      MDU_MUL: mdu_op = ALU_MULL;
      MDU_MULH, MDU_MULHU, MDU_MULHSU: mdu_op = ALU_MULH;
      MDU_DIV, MDU_DIVU: mdu_op = ALU_DIV;
      MDU_REM, MDU_REMU: mdu_op = ALU_REM;
      default: mdu_op = ALU_MULL;
    endcase
  end

  logic signed_a, signed_b;
  always_comb begin
    unique case (fu_data.operation)
      MDU_MUL: begin
        signed_a = 1'b0;
        signed_b = 1'b0;
      end
      MDU_MULH: begin
        signed_a = 1'b1;
        signed_b = 1'b1;
      end
      MDU_MULHU: begin
        signed_a = 1'b1;
        signed_b = 1'b0;
      end
      MDU_MULHSU: begin
        signed_a = 1'b0;
        signed_b = 1'b0;
      end
      MDU_DIV: begin
        signed_a = 1'b1;
        signed_b = 1'b1;
      end
      MDU_DIVU: begin
        signed_a = 1'b0;
        signed_b = 1'b0;
      end
      MDU_REM: begin
        signed_a = 1'b1;
        signed_b = 1'b1;
      end
      MDU_REMU: begin
        signed_a = 1'b0;
        signed_b = 1'b0;
      end
      default: begin
        signed_a = 1'b0;
        signed_b = 1'b0;
      end
    endcase
  end

  logic [4:0] count_q, count_d;
  logic [32:0] shift_a_q, shift_a_d;
  logic [32:0] shift_b_q, shift_b_d;
  logic [31:0] dividend_q, dividend_d;
  logic [32:0] accumulator_q, accumulator_d;

  logic [32:0] adder_a, adder_b;
  wire [33:0] adder_res = {1'b0, adder_a} + {1'b0 + adder_b};
  wire sign_a = fu_data.operand_a[31] & signed_a;
  wire sign_b = fu_data.operand_b[31] & signed_b;
  wire ge = accumulator_q[31] == shift_b_q[31] ? ~adder_res[32] : accumulator_q[31];
  wire change_sign = mdu_op == ALU_DIV ? (sign_a ^ sign_b) : sign_a;

  assign mdu_ready  = curr == MD_FINISH;
  assign mdu_result = mdu_op inside {ALU_MULL, ALU_MULH} ? adder_res[31:0] : accumulator_q[31:0];

  always_ff @(posedge clock) begin
    if (reset) begin
      curr          <= MD_IDLE;
      count_q       <= 5'h0;
      shift_a_q     <= 33'h0;
      shift_b_q     <= 33'h0;
      dividend_q    <= 32'h0;
      accumulator_q <= 33'h0;
      mdu_trans_id  <= '0;
    end else begin
      curr          <= next;
      count_q       <= count_d;
      shift_a_q     <= shift_a_d;
      shift_b_q     <= shift_b_d;
      dividend_q    <= dividend_d;
      accumulator_q <= accumulator_d;
      if (mdu_valid) mdu_trans_id <= fu_data.trans_id;
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
          unique case (mdu_op)
            ALU_MULL: begin
              shift_a_d = {sign_a, fu_data.operand_a} << 1;
              accumulator_d = {
                ~(sign_a & fu_data.operand_b[0]), fu_data.operand_a & {32{fu_data.operand_b[0]}}
              };
              shift_b_d = {sign_b, fu_data.operand_b} >> 1;
              next = MD_COMP;
            end
            ALU_MULH: begin
              shift_a_d = {sign_a, fu_data.operand_a};
              accumulator_d = {
                1'b1,
                ~(sign_a & fu_data.operand_b[0]),
                fu_data.operand_a[31:1] & {31{fu_data.operand_b[0]}}
              };
              shift_b_d = {sign_b, fu_data.operand_b} >> 1;
              next = MD_COMP;
            end
            ALU_DIV, ALU_REM: begin
              accumulator_d[31:0] = mdu_op == ALU_DIV ? 32'hFFFF_FFFF : fu_data.operand_a;
              next = ~|adder_res[32:1] ? MD_FINISH : MD_ABS_A;
            end
            default: ;
          endcase
          count_d = 5'd31;
        end

        MD_ABS_A: begin
          shift_a_d  = 33'h0;
          dividend_d = sign_a ? adder_res[32:1] : fu_data.operand_a;
          next       = MD_ABS_B;
        end

        MD_ABS_B: begin
          accumulator_d = {32'h0, dividend_q[31]};
          shift_b_d     = sign_b ? {1'b0, adder_res[32:1]} : {1'b0, fu_data.operand_b};
          next          = MD_COMP;
        end

        MD_COMP: begin
          count_d = count_q - 5'h1;
          unique case (mdu_op)
            ALU_MULL: begin
              accumulator_d = adder_res[32:0];
              shift_a_d = shift_a_q << 1;
              shift_b_d = shift_b_q >> 1;
              next = ((shift_b_d == 0) || (count_q == 5'd1)) ? MD_FINISH : MD_COMP;
            end
            ALU_MULH: begin
              accumulator_d = adder_res[33:1];
              shift_a_d     = shift_a_q;
              shift_b_d     = shift_b_q >> 1;
              next          = (count_q == 5'd1) ? MD_FINISH : MD_COMP;
            end
            ALU_DIV, ALU_REM: begin
              accumulator_d = {ge ? adder_res[32:1] : accumulator_q[31:0], dividend_q[count_d]};
              shift_a_d     = ge ? shift_a_q | (33'h1 << count_q) : shift_a_q;
              next          = (count_q == 5'd1) ? MD_LAST : MD_COMP;
            end
            default: ;
          endcase
        end

        MD_LAST: begin
          accumulator_d = mdu_op == ALU_DIV ?
                          (ge ? shift_a_q | (33'h1 << count_q) : shift_a_q) :
                          {1'b0, ge ? adder_res[32:1] : accumulator_q[31:0]};
          next = MD_SIGN;
        end

        MD_SIGN: begin
          next = MD_FINISH;
          accumulator_d = change_sign ? {1'b0, adder_res[32:1]} : accumulator_q;
        end

        MD_FINISH: begin
          next = MD_IDLE;
        end

        default: ;
      endcase
    end
  end

  always_comb begin
    adder_a = {accumulator_q[31:0], 1'b1};  // ALU_DIV
    adder_b = {~shift_b_q[31:0], 1'b1};

    unique case (mdu_op)

      ALU_MULL: begin
        adder_a = accumulator_q;
        adder_b = {~(shift_a_q[32] & shift_b_q[0]), (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      ALU_MULH: begin
        adder_a = accumulator_q;
        adder_b = curr == MD_FINISH ?
          { (shift_a_q[32] & shift_b_q[0]), ~(shift_a_q[31:0] & {32{shift_b_q[0]}})} :
          {~(shift_a_q[32] & shift_b_q[0]),  (shift_a_q[31:0] & {32{shift_b_q[0]}})};
      end

      ALU_DIV, ALU_REM: begin
        unique case (curr)
          MD_IDLE, MD_ABS_B: begin
            adder_a = 33'h1;
            adder_b = {~fu_data.operand_b, 1'b1};
          end
          MD_ABS_A: begin
            adder_a = 33'h1;
            adder_b = {~fu_data.operand_a, 1'b1};
          end
          MD_SIGN: begin
            adder_a = 33'h1;
            adder_b = {~accumulator_q[31:0], 1'b1};
          end
          default: ;
        endcase
      end

      default: ;
    endcase
  end

endmodule

`default_nettype wire
