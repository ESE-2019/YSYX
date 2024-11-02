module ysyx_24080006_alu
  import ysyx_24080006_pkg::*;
(
    input logic [31:0] src1,
    input logic [31:0] src2,
    input alu_op_e alu_op,
    output logic [31:0] alu_res
);

  //add
  logic [33:0] add_res_t;
  logic [32:0] srcA, srcB, srcB_t;
  logic [31:0] add_res;
  assign srcA   = {src1, 1'b1};
  assign srcB_t = {src2, 1'b0};
  always_comb begin
    srcB = srcB_t;
    case (alu_op)
      ADD: srcB = srcB_t;
      SUB, SLT, SLTU, BEQ, BNE, BLT, BGE, BLTU, BGEU: srcB = ~srcB_t;
      default: ;
    endcase
  end
  assign add_res_t = {1'b0, srcA} + {1'b0, srcB};
  assign add_res   = add_res_t[32:1];
  //comp
  logic comp_res;
  always_comb begin
    comp_res = add_res_t[33];
    case (alu_op)
      SLT, BLT, BGE:
      comp_res = add_res_t[32] ^  //detect overflow
      ((!srcA[32] && srcB_t[32] && add_res_t[32]) || (srcA[32] && !srcB_t[32] && !add_res_t[32]));
      SLTU, BLTU, BGEU: comp_res = !add_res_t[33];  //caution
      default: ;
    endcase
  end
  //shift
  logic [31:0] shift_res;
  logic [ 4:0] shift;
  assign shift = src2[4:0];

  logic [31:0] shift_src;

  always_comb begin
    shift_src = src1;
    case (alu_op)
      SLL: for (int i = 0; i < 32; i++) shift_src[i] = src1[31-i];
      SRL, SRA: shift_src = src1;
      default: ;
    endcase
  end

  wire [32:0] shift_entity = {(alu_op == SRA) & shift_src[31], shift_src};
  wire [32:0] shift_entity_res = ({33{shift_entity[32]}} << (32 - shift)) | (shift_entity >> shift);
  assign shift_res = shift_entity_res[31:0];

  //and or xor
  logic [31:0] bit_res;
  always_comb begin
    bit_res = src1 & src2;
    case (alu_op)
      AND: bit_res = src1 & src2;
      OR: bit_res = src1 | src2;
      XOR: bit_res = src1 ^ src2;
      default: ;
    endcase
  end

  wire not_zero = |add_res;

  always_comb begin
    alu_res = add_res;
    case (alu_op)
      ADD, SUB: alu_res = add_res;
      BEQ: alu_res = {31'b0, ~not_zero};
      BNE: alu_res = {31'b0, not_zero};
      SLT, SLTU, BLT, BLTU: alu_res = {31'b0, comp_res};
      BGE, BGEU: alu_res = {31'b0, ~comp_res};
      SLL: for (int i = 0; i < 32; i++) alu_res[i] = shift_res[31-i];
      SRL, SRA: alu_res = shift_res;
      AND, OR, XOR: alu_res = bit_res;
      default: ;
    endcase
  end

endmodule
