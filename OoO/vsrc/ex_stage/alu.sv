`default_nettype none

module alu
  import OoO_pkg::*;
(
    input fu_data_t fu_data,
    output logic [31:0] alu_result
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
    unique case (fu_data.operation)
      ALU_SH1ADD: srcA = {fu_data.operand_a[30:0], 2'b01};
      ALU_SH2ADD: srcA = {fu_data.operand_a[29:0], 3'b001};
      ALU_SH3ADD: srcA = {fu_data.operand_a[28:0], 4'b0001};
      default: srcA = {fu_data.operand_a, 1'b1};
    endcase
  end

  logic [32:0] srcB;
  always_comb begin
    unique case (fu_data.operation)
      ALU_ADD, ALU_SH1ADD, ALU_SH2ADD, ALU_SH3ADD: srcB = {fu_data.operand_b, 1'b0};
      default: srcB = {~fu_data.operand_b, 1'b1};
    endcase
  end
  wire [33:0] add_res = {1'b0, srcA} + {1'b0, srcB};
  wire not_zero = |add_res[32:1];

  //comp
  logic comp_res;
  always_comb begin
    unique case (fu_data.operation)
      ALU_LT, ALU_GE, ALU_MIN, ALU_MAX:
      comp_res = ((fu_data.operand_a[31] == fu_data.operand_b[31]) & add_res[32])
       | (fu_data.operand_a[31] & ~fu_data.operand_b[31]);
      ALU_LTU, ALU_GEU, ALU_MINU, ALU_MAXU: comp_res = !add_res[33];
      default: comp_res = !add_res[33];
    endcase
  end

  logic [31:0] minmax_res;
  always_comb begin
    unique case (fu_data.operation)
      ALU_MIN, ALU_MINU: minmax_res = comp_res ? fu_data.operand_a : fu_data.operand_b;
      ALU_MAX, ALU_MAXU: minmax_res = comp_res ? fu_data.operand_b : fu_data.operand_a;
      default: minmax_res = fu_data.operand_a;
    endcase
  end

  //shift
  // wire  [ 4:0] shamt = fu_data.operand_b[4:0];
  // logic [32:0] shift_src;
  // wire  [32:0] shift_entity = shift_src >> shamt;
  // wire  [32:0] shift_mask = {33{shift_src[32]}} << (32 - shamt);
  // wire  [32:0] shift_res = shift_mask | shift_entity;
  // always_comb begin
  //   unique case (fu_data.operation)
  //     ALU_SLL: shift_src = {1'b0, bit_revert(fu_data.operand_a)};
  //     ALU_SRL: shift_src = {1'b0, fu_data.operand_a};
  //     ALU_SRA: shift_src = {fu_data.operand_a[31], fu_data.operand_a};
  //     default: shift_src = {1'b0, fu_data.operand_a};
  //   endcase
  // end

  wire [4:0] shamt = fu_data.operand_b[4:0];
  logic [31:0] shift_src, shift_mask, cpop_src, cpop_res;
  wire [31:0] shift_entity = shift_src >> shamt;
  wire [31:0] shift_res = shift_mask | shift_entity;
  always_comb begin
    unique case (fu_data.operation)
      ALU_SLL, ALU_ROL, ALU_CLZ: shift_src = bit_revert(fu_data.operand_a);
      ALU_SRL, ALU_SRA, ALU_ROR, ALU_CTZ, ALU_CPOP: shift_src = fu_data.operand_a;
      default: shift_src = fu_data.operand_a;
    endcase

    unique case (fu_data.operation)
      ALU_SRA: shift_mask = {32{fu_data.operand_a[31]}} << (32 - shamt);
      ALU_ROL, ALU_ROR: shift_mask = shift_src << (32 - shamt);
      default: shift_mask = 32'b0;
    endcase

    unique case (fu_data.operation)
      ALU_CLZ, ALU_CTZ: cpop_src = (shift_src - 32'h1) & ~shift_src;
      ALU_CPOP: cpop_src = fu_data.operand_a;
      default: cpop_src = fu_data.operand_a;
    endcase
  end

  cpop CPOP (
      .datain (cpop_src),
      .dataout(cpop_res)
  );

  //and or xor
  logic [31:0] bit_res;
  always_comb begin
    unique case (fu_data.operation)
      ALU_AND:  bit_res = fu_data.operand_a & fu_data.operand_b;
      ALU_OR:   bit_res = fu_data.operand_a | fu_data.operand_b;
      ALU_XOR:  bit_res = fu_data.operand_a ^ fu_data.operand_b;
      ALU_ANDN: bit_res = fu_data.operand_a & ~fu_data.operand_b;
      ALU_ORN:  bit_res = fu_data.operand_a | ~fu_data.operand_b;
      ALU_XNOR: bit_res = fu_data.operand_a ^ ~fu_data.operand_b;
      default:  bit_res = fu_data.operand_a & fu_data.operand_b;
    endcase
  end

  wire [31:0] zbs_index = 32'h1 << (fu_data.operand_b & (32'd31));

  always_comb begin
    unique case (fu_data.operation)
      ALU_ADD, ALU_SUB, ALU_SH1ADD, ALU_SH2ADD, ALU_SH3ADD: alu_result = add_res[32:1];
      ALU_EQ: alu_result = {31'b0, ~not_zero};
      ALU_NE: alu_result = {31'b0, not_zero};
      ALU_LT, ALU_LTU: alu_result = {31'b0, comp_res};
      ALU_GE, ALU_GEU: alu_result = {31'b0, ~comp_res};
      ALU_MIN, ALU_MINU, ALU_MAX, ALU_MAXU: alu_result = minmax_res;
      ALU_SLL, ALU_ROL: alu_result = bit_revert(shift_res[31:0]);
      ALU_SRL, ALU_SRA, ALU_ROR: alu_result = shift_res[31:0];
      ALU_CLZ, ALU_CTZ, ALU_CPOP: alu_result = cpop_res;
      ALU_AND, ALU_OR, ALU_XOR, ALU_ANDN, ALU_ORN, ALU_XNOR: alu_result = bit_res;
      ALU_SEXTB: alu_result = {{24{fu_data.operand_a[7]}}, fu_data.operand_a[7:0]};
      ALU_SEXTH: alu_result = {{16{fu_data.operand_a[15]}}, fu_data.operand_a[15:0]};
      ALU_ZEXTH: alu_result = {{16{fu_data.operand_a[15]}}, fu_data.operand_a[15:0]};
      ALU_ORCB:
      alu_result = {
        {8{|fu_data.operand_a[31:24]}},
        {8{|fu_data.operand_a[23:16]}},
        {8{|fu_data.operand_a[15:8]}},
        {8{|fu_data.operand_a[7:0]}}
      };
      ALU_REV8:
      alu_result = {
        {fu_data.operand_a[7:0]},
        {fu_data.operand_a[15:8]},
        {fu_data.operand_a[23:16]},
        {fu_data.operand_a[31:24]}
      };
      ALU_BCLR: alu_result = fu_data.operand_a & ~zbs_index;
      ALU_BEXT: alu_result = {31'b0, |(fu_data.operand_a & zbs_index)};
      ALU_BINV: alu_result = fu_data.operand_a ^ zbs_index;
      ALU_BSET: alu_result = fu_data.operand_a | zbs_index;
      ALU_CZERO_EQZ: alu_result = (|fu_data.operand_b) ? fu_data.operand_a : '0;
      ALU_CZERO_NEZ: alu_result = (|fu_data.operand_b) ? '0 : fu_data.operand_a;
      default: alu_result = add_res[32:1];
    endcase
  end

endmodule

`default_nettype wire
