module ysyx_24080006_alu
  import ysyx_24080006_pkg::*;
(
    input logic [31:0] alu_a,
    input logic [31:0] alu_b,
    input alu_op_e alu_op,
    output logic [31:0] alu_c
);

  //add
  logic [33:0] add_res_t;
  logic [32:0] srcA, srcB, srcB_t;
  logic [31:0] add_res;
  assign srcA   = {alu_a, 1'b1};
  assign srcB_t = {alu_b, 1'b0};
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
  assign shift = alu_b[4:0];
  logic [31:0] shift_src;
  always_comb begin
    shift_src = alu_a;
    case (alu_op)
      SLL: for (int i = 0; i < 32; i++) shift_src[i] = alu_a[31-i];
      SRL, SRA: shift_src = alu_a;
      default: ;
    endcase
  end
  wire [32:0] shift_entity = {(alu_op == SRA) & shift_src[31], shift_src};
  wire [32:0] shift_entity_res = ({33{shift_entity[32]}} << (32 - shift)) | (shift_entity >> shift);
  assign shift_res = shift_entity_res[31:0];

  //and or xor
  logic [31:0] bit_res;
  always_comb begin
    bit_res = alu_a & alu_b;
    case (alu_op)
      AND: bit_res = alu_a & alu_b;
      OR: bit_res = alu_a | alu_b;
      XOR: bit_res = alu_a ^ alu_b;
      default: ;
    endcase
  end

  wire not_zero = |add_res;

  always_comb begin
    alu_c = add_res;
    case (alu_op)
      ADD, SUB: alu_c = add_res;
      BEQ: alu_c = {31'b0, ~not_zero};
      BNE: alu_c = {31'b0, not_zero};
      SLT, SLTU, BLT, BLTU: alu_c = {31'b0, comp_res};
      BGE, BGEU: alu_c = {31'b0, ~comp_res};
      SLL: for (int i = 0; i < 32; i++) alu_c[i] = shift_res[31-i];
      SRL, SRA: alu_c = shift_res;
      AND, OR, XOR: alu_c = bit_res;
      default: ;
    endcase
  end

endmodule
