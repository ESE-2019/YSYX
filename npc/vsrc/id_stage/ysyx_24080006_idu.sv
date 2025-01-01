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

      riscv_instr::LUI[6:0]: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = ALU_A_0;
        idu.alu_set.alu_b  = ALU_B_IMM;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
      end

      riscv_instr::AUIPC[6:0]: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_IMM;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
      end

      riscv_instr::ADD[6:0]: begin
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_RS2;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case ({
          inst[31:25], inst[14:12]
        })
          {
            riscv_instr::ADD[31:25], riscv_instr::ADD[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
          end

          {
            riscv_instr::SUB[31:25], riscv_instr::SUB[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_SUB;
          end

          {
            riscv_instr::SLL[31:25], riscv_instr::SLL[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_SLL;
          end

          {
            riscv_instr::SLT[31:25], riscv_instr::SLT[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LT;
          end

          {
            riscv_instr::SLTU[31:25], riscv_instr::SLTU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LTU;
          end

          {
            riscv_instr::XOR[31:25], riscv_instr::XOR[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_XOR;
          end

          {
            riscv_instr::SRL[31:25], riscv_instr::SRL[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_SRL;
          end

          {
            riscv_instr::SRA[31:25], riscv_instr::SRA[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_SRA;
          end

          {
            riscv_instr::OR[31:25], riscv_instr::OR[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_OR;
          end

          {
            riscv_instr::AND[31:25], riscv_instr::AND[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_AND;
          end

          {
            riscv_instr::MUL[31:25], riscv_instr::MUL[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULL;
          end

          {
            riscv_instr::MULH[31:25], riscv_instr::MULH[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_MULH;
          end

          {
            riscv_instr::MULHSU[31:25], riscv_instr::MULHSU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULH;
          end

          {
            riscv_instr::MULHU[31:25], riscv_instr::MULHU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_MULH;
          end

          {
            riscv_instr::DIV[31:25], riscv_instr::DIV[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_DIV;
          end

          {
            riscv_instr::DIVU[31:25], riscv_instr::DIVU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = ALU_DIV;
          end

          {
            riscv_instr::REM[31:25], riscv_instr::REM[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = ALU_REM;
          end

          {
            riscv_instr::REMU[31:25], riscv_instr::REMU[14:12]
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

      riscv_instr::ADDI[6:0]: begin
        idu.imm           = immI;
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_IMM;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        unique case (inst[14:12])
          {
            riscv_instr::ADDI[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_ADD;
          end

          {
            riscv_instr::SLTI[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LT;
          end

          {
            riscv_instr::SLTIU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LTU;
          end

          {
            riscv_instr::XORI[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_XOR;
          end

          {
            riscv_instr::ORI[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_OR;
          end

          {
            riscv_instr::ANDI[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_AND;
          end

          {
            riscv_instr::SLLI[14:12]
          } : begin
            unique case (inst[31:25])
              {
                riscv_instr::SLLI[31:25]
              } : begin
                idu.alu_set.alu_op = ALU_SLL;
              end

              default: inst_err = 1'b1;
            endcase
          end

          {
            riscv_instr::SRLI[14:12]
          } : begin
            unique case (inst[31:25])
              {
                riscv_instr::SRLI[31:25]
              } : begin
                idu.alu_set.alu_op = ALU_SRL;
              end

              {
                riscv_instr::SRAI[31:25]
              } : begin
                idu.alu_set.alu_op = ALU_SRA;
              end

              default: inst_err = 1'b1;
            endcase
          end

          default: inst_err = 1'b1;
        endcase
      end

      riscv_instr::LB[6:0]: begin
        idu.imm                = immI;
        idu.alu_set.alu_a      = ALU_A_RS1;
        idu.alu_set.alu_b      = ALU_B_IMM;
        idu.alu_set.alu_op     = ALU_ADD;
        idu.lsu_set.lsu_enable = 1'b1;
        idu.lsu_set.lsu_write  = 1'b0;
        idu.reg_we             = 1'b1;
        use_rs1                = 1'b1;
        unique case (inst[14:12])
          {
            riscv_instr::LB[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::LH[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::LW[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::LBU[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::LHU[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          default: inst_err = 1'b1;
        endcase
      end

      riscv_instr::SB[6:0]: begin
        idu.imm                = immS;
        idu.alu_set.alu_a      = ALU_A_RS1;
        idu.alu_set.alu_b      = ALU_B_IMM;
        idu.alu_set.alu_op     = ALU_ADD;
        idu.lsu_set.lsu_enable = 1'b1;
        idu.lsu_set.lsu_write  = 1'b1;
        use_rs1                = 1'b1;
        use_rs2                = 1'b1;
        unique case (inst[14:12])
          {
            riscv_instr::SB[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::SH[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          {
            riscv_instr::SW[14:12]
          } : begin
            {idu.lsu_set.lsu_sext, idu.lsu_set.lsu_size} = inst[14:12];
          end

          default: inst_err = 1'b1;
        endcase
      end

      riscv_instr::JAL[6:0]: begin
        idu.imm    = immJ;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_PC_INCR;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
        idu.jal    = 1'b1;
      end

      riscv_instr::JALR[6:0]: begin
        idu.imm    = immI;
        idu.alu_set.alu_a  = ALU_A_PC;
        idu.alu_set.alu_b  = ALU_B_PC_INCR;
        idu.alu_set.alu_op = ALU_ADD;
        idu.reg_we = 1'b1;
        idu.jalr   = 1'b1;
        if (inst[14:12] != riscv_instr::JALR[14:12]) inst_err = 1'b1;
        use_rs1 = 1'b1;
      end

      riscv_instr::BEQ[6:0]: begin
        idu.imm           = immB;
        idu.alu_set.alu_a = ALU_A_RS1;
        idu.alu_set.alu_b = ALU_B_RS2;
        idu.branch        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case (inst[14:12])
          {
            riscv_instr::BEQ[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_EQ;
          end

          {
            riscv_instr::BNE[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_NE;
          end

          {
            riscv_instr::BLT[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LT;
          end

          {
            riscv_instr::BGE[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_GE;
          end

          {
            riscv_instr::BLTU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_LTU;
          end

          {
            riscv_instr::BGEU[14:12]
          } : begin
            idu.alu_set.alu_op = ALU_GEU;
          end

          default: inst_err = 1'b1;
        endcase
      end

      riscv_instr::ECALL[6:0]: begin
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
            {
              riscv_instr::CSRRW[13:12]
            } : begin
              idu.csr_set.csr_op = CSR_WRITE;
            end

            {
              riscv_instr::CSRRS[13:12]
            } : begin
              idu.csr_set.csr_op = inst[19:15] == 5'b0 ? CSR_READ : CSR_SET;
            end

            {
              riscv_instr::CSRRC[13:12]
            } : begin
              idu.csr_set.csr_op = inst[19:15] == 5'b0 ? CSR_READ : CSR_CLEAR;
            end

            default: inst_err = 1'b1;
          endcase
        end
      end

      riscv_instr::FENCE[6:0]: begin
        unique case (inst[14:12])
          {
            riscv_instr::FENCE[14:12]
          } : begin
            // NOP
          end

          {
            riscv_instr::FENCE_I[14:12]
          } : begin
            fencei = 1'b1;
          end

          default: begin
            inst_err = 1'b1;
          end
        endcase
      end

      default: inst_err = 1'b1;
    endcase
    idu.rs1_addr = inst[15+:RegWidth] & {RegWidth{use_rs1}};
    idu.rs2_addr = inst[20+:RegWidth] & {RegWidth{use_rs2}};
    idu.rd_addr  = inst[7+:RegWidth] & {RegWidth{idu.reg_we}};
    if (idu.rd_addr == '0) idu.reg_we = 1'b0;
    if (RegWidth == 4) begin
      inst_err = inst_err | (use_rs1 & inst[19]) | (use_rs2 & inst[24]) | (idu.reg_we & inst[11]);
    end
  end

endmodule

`default_nettype wire
