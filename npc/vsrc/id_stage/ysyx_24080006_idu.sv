`default_nettype none

module ysyx_24080006_idu
  import ysyx_24080006_pkg::*;
(
    input logic [31:0] inst,
    output logic fencei,
    output decoder_t idu,
    output logic inst_err
);

  wire [31:0] uimm = {27'b0, inst[19:15]};
  wire [31:0] immU = {inst[31:12], 12'b0};
  wire [31:0] immI = {{20{inst[31]}}, inst[31:20]};
  wire [31:0] immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  wire [31:0] immB = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
  wire [31:0] immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};

  logic use_rs1;
  logic use_rs2;

  always_comb begin
    idu.imm      = immI;
    idu.alu_set  = '0;
    idu.csr_set  = '0;
    idu.lsu_set  = '0;
    idu.mdu_set  = '0;
    idu.csr_name = 12'h0;
    idu.reg_we   = 1'b0;
    idu.jal      = 1'b0;
    idu.jalr     = 1'b0;
    idu.branch   = 1'b0;
    idu.ecall    = 1'b0;
    idu.mret     = 1'b0;
    inst_err     = 1'b0;
    fencei       = 1'b0;
    use_rs1      = 1'b0;
    use_rs2      = 1'b0;
    unique case (inst[6:0])

      OPCODE_LUI: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = ALU_A_0;
        idu.alu_set.alu_b  = ALU_B_IMM;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
      end

      OPCODE_AUIPC: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_IMM;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
      end

      OPCODE_OP: begin
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_RS2;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case ({
          inst[31:25], inst[14:12]
        })
          {7'b0000000, 3'b000} : idu.alu_set.alu_op = ALU_ADD;
          {7'b0100000, 3'b000} : idu.alu_set.alu_op = ALU_SUB;
          {7'b0000000, 3'b001} : idu.alu_set.alu_op = ALU_SLL;
          {7'b0000000, 3'b010} : idu.alu_set.alu_op = ALU_LT;
          {7'b0000000, 3'b011} : idu.alu_set.alu_op = ALU_LTU;
          {7'b0000000, 3'b100} : idu.alu_set.alu_op = ALU_XOR;
          {7'b0000000, 3'b101} : idu.alu_set.alu_op = ALU_SRL;
          {7'b0100000, 3'b101} : idu.alu_set.alu_op = ALU_SRA;
          {7'b0000000, 3'b110} : idu.alu_set.alu_op = ALU_OR;
          {7'b0000000, 3'b111} : idu.alu_set.alu_op = ALU_AND;
          {
            7'b0000001, 3'b000
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULL;
          end
          {
            7'b0000001, 3'b001
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_MULH;
          end
          {
            7'b0000001, 3'b010
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULH;
          end
          {
            7'b0000001, 3'b011
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULH;
          end
          {
            7'b0000001, 3'b100
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_DIV;
          end
          {
            7'b0000001, 3'b101
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_DIV;
          end
          {
            7'b0000001, 3'b110
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_REM;
          end
          {
            7'b0000001, 3'b111
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_REM;
          end

          default: inst_err = 1'b1;
        endcase
      end

      OPCODE_OPIMM: begin
        idu.imm           = immI;
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_IMM;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        unique case (inst[14:12])
          3'b000: idu.alu_set.alu_op = ALU_ADD;

          3'b001:
          unique case (inst[31:25])
            7'b0000000: idu.alu_set.alu_op = ALU_SLL;
            default: inst_err = 1'b1;
          endcase

          3'b010: idu.alu_set.alu_op = ALU_LT;
          3'b011: idu.alu_set.alu_op = ALU_LTU;
          3'b100: idu.alu_set.alu_op = ALU_XOR;

          3'b101:
          unique case (inst[31:25])
            7'b0000000: idu.alu_set.alu_op = ALU_SRL;
            7'b0100000: idu.alu_set.alu_op = ALU_SRA;
            default: inst_err = 1'b1;
          endcase

          3'b110:  idu.alu_set.alu_op = ALU_OR;
          3'b111:  idu.alu_set.alu_op = ALU_AND;
          default: inst_err = 1'b1;
        endcase
      end

      OPCODE_LOAD: begin
        idu.imm                = immI;
        idu.alu_set.alu_a      = ALU_A_RS1;
        idu.alu_set.alu_b      = ALU_B_IMM;
        idu.alu_set.alu_op     = ALU_ADD;
        idu.lsu_set.lsu_enable = 1'b1;
        idu.lsu_set.lsu_write  = 1'b0;
        idu.reg_we             = 1'b1;
        use_rs1                = 1'b1;
        unique case (inst[14:12])
          3'b000:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b001:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b010:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b100:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b101:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          default: inst_err = 1'b1;
        endcase
      end

      OPCODE_STORE: begin
        idu.imm                = immS;
        idu.alu_set.alu_a      = ALU_A_RS1;
        idu.alu_set.alu_b      = ALU_B_IMM;
        idu.alu_set.alu_op     = ALU_ADD;
        idu.lsu_set.lsu_enable = 1'b1;
        idu.lsu_set.lsu_write  = 1'b1;
        use_rs1                = 1'b1;
        use_rs2                = 1'b1;
        unique case (inst[14:12])
          3'b000:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b001:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          3'b010:  {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          default: inst_err = 1'b1;
        endcase
      end

      OPCODE_JAL: begin
        idu.imm    = immJ;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_PC_INCR;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
        idu.jal    = 1'b1;
      end

      OPCODE_JALR: begin
        idu.imm    = immI;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_PC_INCR;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
        idu.jalr   = 1'b1;
        if (inst[14:12] != 3'b000) inst_err = 1'b1;
        use_rs1 = 1'b1;
      end

      OPCODE_BRANCH: begin
        idu.imm           = immB;
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_RS2;
        idu.branch        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case (inst[14:12])
          3'b000:  idu.alu_set.alu_op = ALU_EQ;
          3'b001:  idu.alu_set.alu_op = ALU_NE;
          3'b100:  idu.alu_set.alu_op = ALU_LT;
          3'b101:  idu.alu_set.alu_op = ALU_GE;
          3'b110:  idu.alu_set.alu_op = ALU_LTU;
          3'b111:  idu.alu_set.alu_op = ALU_GEU;
          default: inst_err = 1'b1;
        endcase
      end

      OPCODE_SYSTEM: begin
        idu.imm    = uimm;
        idu.alu_set.alu_a  = ALU_A_0;
        idu.alu_set.alu_b  = ALU_B_CSR;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
        if (inst[14:12] == 3'b000) begin
          if ({inst[19:15], inst[11:7]} == '0) begin
            unique case (inst[31:20])
              riscv_instr::ECALL[31:20]: begin
                idu.ecall = 1'b1;
                idu.csr_name = riscv_instr::CSR_MTVEC;
              end
              riscv_instr::EBREAK[31:20]: ;  // use DPI-C to end sim
              riscv_instr::WFI[31:20]: ;
              riscv_instr::MRET[31:20]: begin
                idu.mret = 1'b1;
                idu.csr_name = riscv_instr::CSR_MEPC;
              end
              default: inst_err = 1'b1;
            endcase
          end else begin
            inst_err = 1'b1;
          end
        end else begin
          idu.csr_set.csr_enable = 1'b1;
          idu.csr_name = inst[31:20];
          if (inst[14]) begin
            idu.csr_set.csr_uimm = 1'b1;
          end else begin
            use_rs1 = 1'b1;
          end
          unique case (inst[13:12])
            2'b01:   idu.csr_set.csr_op = CSR_WRITE;
            2'b10:   idu.csr_set.csr_op = inst[19:15] == 5'b0 ? CSR_READ : CSR_SET;
            2'b11:   idu.csr_set.csr_op = inst[19:15] == 5'b0 ? CSR_READ : CSR_CLEAR;
            default: inst_err = 1'b1;
          endcase
        end
      end

      OPCODE_MISCMEM: begin
        unique case (inst[14:12])
          3'b000: begin
            // NOP
          end
          3'b001: begin
            fencei = 1'b1;
          end
          default: begin
            inst_err = 1'b1;
          end
        endcase
      end

      default: inst_err = 1'b1;
    endcase
    idu.rs1_addr = inst[15+:REG_WIDTH] & {REG_WIDTH{use_rs1}};
    idu.rs2_addr = inst[20+:REG_WIDTH] & {REG_WIDTH{use_rs2}};
    idu.rd_addr  = inst[7+:REG_WIDTH] & {REG_WIDTH{idu.reg_we}};
    if (idu.rd_addr == '0) idu.reg_we = 1'b0;
    if (REG_WIDTH == 4) begin
      inst_err = inst_err | (use_rs1 & inst[19]) | (use_rs2 & inst[24]) | (idu.reg_we & inst[11]);
    end
  end

endmodule

`default_nettype wire
