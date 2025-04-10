`default_nettype none

module ysyx_24080006_alu
  import ysyx_24080006_pkg::*;
(
    input logic mdu_valid,
    input mdu2alu_t mdu2alu,
    output alu2mdu_t alu2mdu,

    input logic [31:0] alu_a,
    input logic [31:0] alu_b,
    input alu_op_e alu_op,
    output logic [31:0] alu_o
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
    if (mdu_valid) begin
      srcA = mdu2alu.a;
    end else begin
      srcA = {alu_a, 1'b1};
    end
  end

  logic [32:0] srcB;
  always_comb begin
    if (mdu_valid) begin
      srcB = mdu2alu.b;
    end else begin
      unique case (alu_op)
        ALU_ADD: srcB = {alu_b, 1'b0};
        ALU_SUB, ALU_LT, ALU_LTU, ALU_EQ, ALU_NE, ALU_GE, ALU_GEU: srcB = {~alu_b, 1'b1};
        default: srcB = {alu_b, 1'b0};
      endcase
    end
  end
  wire [33:0] add_res = {1'b0, srcA} + {1'b0, srcB};
  wire not_zero = |add_res[32:1];

  assign alu2mdu.res = add_res;
  assign alu2mdu.not_zero = not_zero;

  //comp
  logic comp_res;
  always_comb begin
    unique case (alu_op)
      ALU_LT, ALU_GE:
      comp_res = ((alu_a[31] == alu_b[31]) & add_res[32]) | (alu_a[31] & ~alu_b[31]);
      ALU_LTU, ALU_GEU: comp_res = !add_res[33];
      default: comp_res = !add_res[33];
    endcase
  end

  //shift
  wire  [ 4:0] shamt = alu_b[4:0];
  logic [32:0] shift_src;
  wire  [32:0] shift_entity = shift_src >> shamt;
  wire  [32:0] shift_mask = {33{shift_src[32]}} << (32 - shamt);
  wire  [32:0] shift_res = shift_mask | shift_entity;
  always_comb begin
    unique case (alu_op)
      ALU_SLL: shift_src = {1'b0, bit_revert(alu_a)};
      ALU_SRL: shift_src = {1'b0, alu_a};
      ALU_SRA: shift_src = {alu_a[31], alu_a};
      default: shift_src = {1'b0, alu_a};
    endcase
  end

  //and or xor
  logic [31:0] bit_res;
  always_comb begin
    unique case (alu_op)
      ALU_AND: bit_res = alu_a & alu_b;
      ALU_OR:  bit_res = alu_a | alu_b;
      ALU_XOR: bit_res = alu_a ^ alu_b;
      default: bit_res = alu_a & alu_b;
    endcase
  end

  always_comb begin
    unique case (alu_op)
      ALU_ADD, ALU_SUB: alu_o = add_res[32:1];
      ALU_EQ: alu_o = {31'b0, ~not_zero};
      ALU_NE: alu_o = {31'b0, not_zero};
      ALU_LT, ALU_LTU: alu_o = {31'b0, comp_res};
      ALU_GE, ALU_GEU: alu_o = {31'b0, ~comp_res};
      ALU_SLL: alu_o = bit_revert(shift_res[31:0]);
      ALU_SRL, ALU_SRA: alu_o = shift_res[31:0];
      ALU_AND, ALU_OR, ALU_XOR: alu_o = bit_res;
      default: alu_o = add_res[32:1];
    endcase
  end

endmodule

`default_nettype wire
