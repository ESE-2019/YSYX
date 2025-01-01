`default_nettype none

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

  function automatic logic [31:0] bit_revert(logic [31:0] data_in);
    logic [31:0] data_out;
    for (int i = 0; i < 32; i++) begin
      data_out[i] = data_in[31-i];
    end
    return data_out;
  endfunction

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
    if (mdu_enable) begin
      srcB = mdu2alu.b;
    end else begin
      case (alu_op)
        ALU_ADD: srcB = srcB_tmp;
        ALU_SUB, ALU_LT, ALU_LTU, ALU_EQ, ALU_NE, ALU_GE, ALU_GEU: srcB = srcB_inv;
        default: srcB = srcB_tmp;
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
    case (alu_op)
      ALU_LT, ALU_GE:
      comp_res = add_res_34[32] ^  //detect overflow
      ((!srcA[32] && srcB_tmp[32] && add_res_34[32]) ||
      (srcA[32] && !srcB_tmp[32] && !add_res_34[32]));
      ALU_LTU, ALU_GEU: comp_res = !add_res_34[33];  //caution
      default: comp_res = !add_res_34[33];
    endcase
  end

  //shift
  wire  [ 4:0] shamt = alu_b[4:0];
  logic [31:0] shift_src;
  always_comb begin
    case (alu_op)
      ALU_SLL: shift_src = bit_revert(alu_a);
      ALU_SRL, ALU_SRA: shift_src = alu_a;
      default: shift_src = alu_a;
    endcase
  end
  wire [32:0] shift_entity = {(alu_op == ALU_SRA) & shift_src[31], shift_src};
  wire [32:0] shift_entity_res = ({33{shift_entity[32]}} << (32 - shamt)) | (shift_entity >> shamt);
  wire [31:0] shift_res = shift_entity_res[31:0];

  //and or xor
  logic [31:0] bit_res;
  always_comb begin
    case (alu_op)
      ALU_AND: bit_res = alu_a & alu_b;
      ALU_OR: bit_res = alu_a | alu_b;
      ALU_XOR: bit_res = alu_a ^ alu_b;
      default: bit_res = alu_a & alu_b;
    endcase
  end

  always_comb begin
    case (alu_op)
      ALU_ADD, ALU_SUB: alu_c = add_res_32;
      ALU_EQ: alu_c = {31'b0, ~not_zero};
      ALU_NE: alu_c = {31'b0, not_zero};
      ALU_LT, ALU_LTU: alu_c = {31'b0, comp_res};
      ALU_GE, ALU_GEU: alu_c = {31'b0, ~comp_res};
      ALU_SLL: alu_c = bit_revert(shift_res);
      ALU_SRL, ALU_SRA: alu_c = shift_res;
      ALU_AND, ALU_OR, ALU_XOR: alu_c = bit_res;
      default: alu_c = add_res_32;
    endcase
  end

endmodule

`default_nettype wire
