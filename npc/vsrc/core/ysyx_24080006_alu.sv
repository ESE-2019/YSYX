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
    srcA = {alu_a, 1'b1};
    if (mdu_enable) begin
      srcA = mdu2alu.a;
    end else begin
      case (alu_op)
        ADD, SUB, SLT, SLTU, BEQ, BNE, BLT, BGE, BLTU, BGEU, MIN, MINU, MAX, MAXU:
        srcA = {alu_a, 1'b1};
        SH1ADD: srcA = {alu_a[30:0], 2'b01};
        SH2ADD: srcA = {alu_a[29:0], 3'b001};
        SH3ADD: srcA = {alu_a[28:0], 4'b0001};
        default: ;
      endcase
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
        ADD, SH1ADD, SH2ADD, SH3ADD: srcB = srcB_tmp;
        SUB, SLT, SLTU, BEQ, BNE, BLT, BGE, BLTU, BGEU, MIN, MINU, MAX, MAXU: srcB = srcB_inv;
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
      SLT, BLT, BGE, MIN, MAX:
      comp_res = add_res_34[32] ^  //detect overflow
      ((!srcA[32] && srcB_tmp[32] && add_res_34[32]) || (srcA[32] && !srcB_tmp[32] && !add_res_34[32]));
      SLTU, BLTU, BGEU, MINU, MAXU: comp_res = !add_res_34[33];  //caution
      default: ;
    endcase
  end

  logic [31:0] minmax_res;
  always_comb begin
    unique case (alu_op)
      MIN, MINU: minmax_res = comp_res ? alu_a : alu_b;
      MAX, MAXU: minmax_res = comp_res ? alu_b : alu_a;
      default:   minmax_res = alu_a;
    endcase
  end

  //shift
  wire  [ 4:0] shamt = alu_b[4:0];
  logic [31:0] shift_src;
  always_comb begin
    shift_src = alu_a;
    case (alu_op)
      SLL, ROL, CTZ: for (int i = 0; i < 32; i++) shift_src[i] = alu_a[31-i];
      SRL, SRA, ROR, CLZ: shift_src = alu_a;
      default: ;
    endcase
  end
  // wire [32:0] shift_entity = {(alu_op == SRA) & shift_src[31], shift_src};
  // wire [32:0] shift_entity_res = ({33{shift_entity[32]}} << (32 - shamt)) | (shift_entity >> shamt);
  // wire [31:0] shift_res = shift_entity_res[31:0];

  wire  [31:0] srl_res = shift_src >> shamt;
  wire  [31:0] sra_mask = {32{alu_a[31]}}&(~(32'hffffffff >> shamt));
  wire  [31:0] ror_mask = shift_src << (32 - shamt);
  logic [31:0] shift_res;
  always_comb begin
    shift_res = srl_res;
    case (alu_op)
      SLL, SRL: shift_res = srl_res;
      ROL, ROR: shift_res = srl_res | ror_mask;
      SRA: shift_res = srl_res | sra_mask;
      default: ;
    endcase
  end

  //and or xor
  logic [31:0] bit_res, bit_srcB;
  assign bit_srcB = alu_op inside {ANDN, ORN, XNOR} ? srcB_inv[32:1] : alu_b;
  always_comb begin
    bit_res = alu_a & bit_srcB;
    case (alu_op)
      AND, ANDN: bit_res = alu_a & bit_srcB;
      OR, ORN: bit_res = alu_a | bit_srcB;
      XOR, XNOR: bit_res = alu_a ^ bit_srcB;
      default: ;
    endcase
  end

  logic [31:0] cpop_res;
  assign cpop_res[31:6] = '0;
  popcount #(
      .INPUT_WIDTH(32)
  ) POP (
      .data_i(alu_a),
      .popcount_o(cpop_res[5:0])
  );

  logic [4:0] lz_tz_count;
  logic lz_tz_empty;
  lzc #(
      .WIDTH(32),
      .MODE (1)
  ) LZC (
      .in_i(shift_src),
      .cnt_o(lz_tz_count),
      .empty_o(lz_tz_empty)
  );
  wire [31:0] lzc_res = lz_tz_empty ? {27'b0, lz_tz_count} + 32'b1 : {27'b0, lz_tz_count};
  wire [31:0] orcb_res = {
    {8{|alu_a[31:24]}}, {8{|alu_a[23:16]}}, {8{|alu_a[15:8]}}, {8{|alu_a[7:0]}}
  };
  wire [31:0] rev8_res = {{alu_a[7:0]}, {alu_a[15:8]}, {alu_a[23:16]}, {alu_a[31:24]}};

  always_comb begin
    alu_c = add_res_32;
    case (alu_op)
      ADD, SUB, SH1ADD, SH2ADD, SH3ADD: alu_c = add_res_32;
      BEQ: alu_c = {31'b0, ~not_zero};
      BNE: alu_c = {31'b0, not_zero};
      SLT, SLTU, BLT, BLTU: alu_c = {31'b0, comp_res};
      BGE, BGEU: alu_c = {31'b0, ~comp_res};
      SLL, ROL: for (int i = 0; i < 32; i++) alu_c[i] = shift_res[31-i];
      SRL, SRA, ROR: alu_c = shift_res;
      AND, OR, XOR, ANDN, ORN, XNOR: alu_c = bit_res;
      CLZ, CTZ: alu_c = lzc_res;
      CPOP: alu_c = cpop_res;
      MIN, MINU, MAX, MAXU: alu_c = minmax_res;
      SEXTB: alu_c = {{24{alu_a[7]}}, alu_a[7:0]};
      SEXTH: alu_c = {{16{alu_a[15]}}, alu_a[15:0]};
      ZEXTH: alu_c = {{16{alu_a[15]}}, alu_a[15:0]};
      ORCB: alu_c = orcb_res;
      REV8: alu_c = rev8_res;
      default: ;
    endcase
  end

endmodule
