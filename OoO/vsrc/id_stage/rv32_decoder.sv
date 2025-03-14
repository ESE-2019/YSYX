`default_nettype none

module rv32_decoder
  import OoO_pkg::*;
(
    input logic [31:0] pc,
    input logic [31:0] instr,
    input logic is_rv16,
    input logic rv16_err,
    output decoder_t decoded_instr,
    output logic rv32_err
);

  import riscv_instr::*;

  wire [31:0] immU = {instr[31:12], 12'b0};
  wire [31:0] immI = {{20{instr[31]}}, instr[31:20]};
  wire [31:0] immS = {{20{instr[31]}}, instr[31:25], instr[11:7]};
  wire [31:0] immB = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
  wire [31:0] immJ = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};

  always_comb begin
    decoded_instr         = '0;
    decoded_instr.pc      = pc;
    decoded_instr.result  = immI;
    decoded_instr.is_rv16 = is_rv16;
    rv32_err              = rv16_err;
    unique case (instr[6:0])

      LUI[6:0]: begin
        decoded_instr.result  = immU;
        decoded_instr.use_imm = 1'b1;
        decoded_instr.fu      = FU_ALU;
        decoded_instr.op      = ALU_ADD;
        decoded_instr.rd      = instr[7+:RegWidth];
      end

      AUIPC[6:0]: begin
        decoded_instr.result  = immU;
        decoded_instr.use_pc  = 1'b1;
        decoded_instr.use_imm = 1'b1;
        decoded_instr.fu      = FU_ALU;
        decoded_instr.op      = ALU_ADD;
        decoded_instr.rd      = instr[7+:RegWidth];
      end

      ADD[6:0]: begin
        decoded_instr.fu  = instr[31:25] == MUL[31:25] ? FU_MDU : FU_ALU;
        decoded_instr.rs1 = instr[15+:RegWidth];
        decoded_instr.rs2 = instr[20+:RegWidth];
        decoded_instr.rd  = instr[7+:RegWidth];
        unique case ({
          instr[31:25], instr[14:12]
        })
          {ADD[31:25], ADD[14:12]} : decoded_instr.op = ALU_ADD;
          {SUB[31:25], SUB[14:12]} : decoded_instr.op = ALU_SUB;
          {SLL[31:25], SLL[14:12]} : decoded_instr.op = ALU_SLL;
          {SLT[31:25], SLT[14:12]} : decoded_instr.op = ALU_LT;
          {SLTU[31:25], SLTU[14:12]} : decoded_instr.op = ALU_LTU;
          {XOR[31:25], XOR[14:12]} : decoded_instr.op = ALU_XOR;
          {SRL[31:25], SRL[14:12]} : decoded_instr.op = ALU_SRL;
          {SRA[31:25], SRA[14:12]} : decoded_instr.op = ALU_SRA;
          {OR[31:25], OR[14:12]} : decoded_instr.op = ALU_OR;
          {AND[31:25], AND[14:12]} : decoded_instr.op = ALU_AND;
          {MUL[31:25], MUL[14:12]} : decoded_instr.op = MDU_MUL;
          {MULH[31:25], MULH[14:12]} : decoded_instr.op = MDU_MULH;
          {MULHSU[31:25], MULHSU[14:12]} : decoded_instr.op = MDU_MULHSU;
          {MULHU[31:25], MULHU[14:12]} : decoded_instr.op = MDU_MULHU;
          {DIV[31:25], DIV[14:12]} : decoded_instr.op = MDU_DIV;
          {DIVU[31:25], DIVU[14:12]} : decoded_instr.op = MDU_DIVU;
          {REM[31:25], REM[14:12]} : decoded_instr.op = MDU_REM;
          {REMU[31:25], REMU[14:12]} : decoded_instr.op = MDU_REMU;
          default: rv32_err = 1'b1;
        endcase
      end

      ADDI[6:0]: begin
        decoded_instr.result  = immI;
        decoded_instr.fu      = FU_ALU;
        decoded_instr.use_imm = 1'b1;
        decoded_instr.rs1     = instr[15+:RegWidth];
        decoded_instr.rd      = instr[7+:RegWidth];
        unique case (instr[14:12])
          ADDI[14:12]:  decoded_instr.op = ALU_ADD;
          SLTI[14:12]:  decoded_instr.op = ALU_LT;
          SLTIU[14:12]: decoded_instr.op = ALU_LTU;
          XORI[14:12]:  decoded_instr.op = ALU_XOR;
          ORI[14:12]:   decoded_instr.op = ALU_OR;
          ANDI[14:12]:  decoded_instr.op = ALU_AND;

          SLLI[14:12]:
          unique case (instr[31:25])
            SLLI[31:25]: decoded_instr.op = ALU_SLL;
            default: rv32_err = 1'b1;
          endcase

          SRLI[14:12]:
          unique case (instr[31:25])
            SRLI[31:25]: decoded_instr.op = ALU_SRL;
            SRAI[31:25]: decoded_instr.op = ALU_SRA;
            default: rv32_err = 1'b1;
          endcase

          default: rv32_err = 1'b1;
        endcase
      end

      LB[6:0]: begin
        decoded_instr.result = immI;
        decoded_instr.fu     = FU_LOAD;
        decoded_instr.rs1    = instr[15+:RegWidth];
        decoded_instr.rd     = instr[7+:RegWidth];
        unique case (instr[14:12])
          LB[14:12]: decoded_instr.op = LSU_LB;
          LH[14:12]: decoded_instr.op = LSU_LH;
          LW[14:12]: decoded_instr.op = LSU_LW;
          LBU[14:12]: decoded_instr.op = LSU_LBU;
          LHU[14:12]: decoded_instr.op = LSU_LHU;
          default: rv32_err = 1'b1;
        endcase
      end

      SB[6:0]: begin
        decoded_instr.result = immS;
        decoded_instr.fu     = FU_STORE;
        decoded_instr.rs1    = instr[15+:RegWidth];
        decoded_instr.rs2    = instr[20+:RegWidth];
        unique case (instr[14:12])
          SB[14:12]: decoded_instr.op = LSU_SB;
          SH[14:12]: decoded_instr.op = LSU_SH;
          SW[14:12]: decoded_instr.op = LSU_SW;
          default:   rv32_err = 1'b1;
        endcase
      end

      JAL[6:0]: begin
        decoded_instr.result = immJ;
        decoded_instr.fu     = FU_BU;
        decoded_instr.rd     = instr[7+:RegWidth];
      end

      JALR[6:0]: begin
        decoded_instr.result = immI;
        decoded_instr.fu     = FU_BU;
        decoded_instr.op     = CF_JALR;
        decoded_instr.rs1    = instr[15+:RegWidth];
        decoded_instr.rd     = instr[7+:RegWidth];
        if (instr[14:12] != JALR[14:12]) rv32_err = 1'b1;
      end

      BEQ[6:0]: begin
        decoded_instr.result = immB;
        decoded_instr.fu     = FU_BU;
        decoded_instr.rs1    = instr[15+:RegWidth];
        decoded_instr.rs2    = instr[20+:RegWidth];
        unique case (instr[14:12])
          BEQ[14:12]: decoded_instr.op = ALU_EQ;
          BNE[14:12]: decoded_instr.op = ALU_NE;
          BLT[14:12]: decoded_instr.op = ALU_LT;
          BGE[14:12]: decoded_instr.op = ALU_GE;
          BLTU[14:12]: decoded_instr.op = ALU_LTU;
          BGEU[14:12]: decoded_instr.op = ALU_GEU;
          default: rv32_err = 1'b1;
        endcase
      end

      ECALL[6:0]: begin
        decoded_instr.fu = FU_CSR;
        decoded_instr.result = immI;
        decoded_instr.rs1 = instr[15+:RegWidth];
        decoded_instr.rd = instr[7+:RegWidth];
        if (instr[14:12] == 3'b000) begin
          if ({instr[19:15], instr[11:7]} == '0) begin
            unique case (instr[31:20])
              ECALL[31:20]: begin
                decoded_instr.op = CF_ECALL;
                // decoded_instr.ex.valid = 1'b1;
                // decoded_instr.ex.cause = 32'd11;
              end
              EBREAK[31:20], WFI[31:20]: ;  // use DPI-C to end sim
              MRET[31:20]: begin
                decoded_instr.op = CF_MRET;
              end
              default: rv32_err = 1'b1;
            endcase
          end else begin
            rv32_err = 1'b1;
          end
        end else begin
          if (instr[14]) decoded_instr.use_zimm = 1'b1;
          unique case (instr[13:12])
            CSRRW[13:12]: decoded_instr.op = CSR_WRITE;
            CSRRS[13:12]: decoded_instr.op = instr[19:15] == 5'b0 ? CSR_READ : CSR_SET;
            CSRRC[13:12]: decoded_instr.op = instr[19:15] == 5'b0 ? CSR_READ : CSR_CLEAR;
            default: rv32_err = 1'b1;
          endcase
        end
      end

      FENCE[6:0]: begin
        unique case (instr[14:12])
          FENCE[14:12]: decoded_instr.op = CF_FENCE;
          FENCE_I[14:12]: decoded_instr.op = CF_FENCE_I;
          default: rv32_err = 1'b1;
        endcase
      end

      default: rv32_err = 1'b1;
    endcase
  end

endmodule

`default_nettype wire
