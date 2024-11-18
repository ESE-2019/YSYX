module ysyx_24080006_alu
  import ysyx_24080006_pkg::*;
(
    input  logic     mdu_enable,
    input  mdu2alu_t mdu2alu,
    output alu2mdu_t alu2mdu,

    input logic [31:0] alu_a,
    input logic [31:0] alu_b,
    input alu_op_e alu_op,
    output logic [31:0] alu_c
);

  //add  
  logic [32:0] srcA;
  always_comb begin
    if (mdu_enable) begin
      srcA = mdu2alu.a;
    end else begin
      srcA = {alu_a, 1'b1};
    end
  end

  wire  [32:0] srcB_tmp = {alu_b, 1'b0};
  wire  [32:0] srcB_inv = ~srcB_tmp;
  logic [32:0] srcB;
  always_comb begin
    srcB = srcB_tmp;
    if (mdu_enable) begin
      srcB = mdu2alu.b;
    end else begin
      case (alu_op)
        ADD: srcB = srcB_tmp;
        SUB, LT, LTU, EQ, NE, GE, GEU: srcB = srcB_inv;
        default: ;
      endcase
    end
  end
  wire [33:0] add_res_34 = {1'b0, srcA} + {1'b0, srcB};
  wire [31:0] add_res_32 = add_res_34[32:1];
  wire not_zero = |add_res_32;

  assign alu2mdu.res_34   = add_res_34;
  assign alu2mdu.res_32   = add_res_32;
  assign alu2mdu.not_zero = not_zero;

  //comp
  logic comp_res;
  always_comb begin
    comp_res = add_res_34[33];
    case (alu_op)
      LT, GE:
      comp_res = add_res_34[32] ^  //detect overflow
      ((!srcA[32] && srcB_tmp[32] && add_res_34[32]) || (srcA[32] && !srcB_tmp[32] && !add_res_34[32]));
      LTU, GEU: comp_res = !add_res_34[33];  //caution
      default: ;
    endcase
  end

  //shift
  wire  [ 4:0] shamt = alu_b[4:0];
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
  wire [32:0] shift_entity_res = ({33{shift_entity[32]}} << (32 - shamt)) | (shift_entity >> shamt);
  wire [31:0] shift_res = shift_entity_res[31:0];

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

  always_comb begin
    alu_c = add_res_32;
    case (alu_op)
      ADD, SUB: alu_c = add_res_32;
      EQ: alu_c = {31'b0, ~not_zero};
      NE: alu_c = {31'b0, not_zero};
      LT, LTU: alu_c = {31'b0, comp_res};
      GE, GEU: alu_c = {31'b0, ~comp_res};
      SLL: for (int i = 0; i < 32; i++) alu_c[i] = shift_res[31-i];
      SRL, SRA: alu_c = shift_res;
      AND, OR, XOR: alu_c = bit_res;
      default: ;
    endcase
  end

endmodule
