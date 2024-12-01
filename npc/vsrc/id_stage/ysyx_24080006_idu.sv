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
    idu.csr_name = csr_name_e'(0);
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

      LUI: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = CONST0;
        idu.alu_set.alu_b  = IMM;
        idu.alu_set.alu_op = ADD;
        idu.reg_we = 1'b1;
      end

      AUIPC: begin
        idu.imm    = immU;
        idu.alu_set.alu_a  = PC;
        idu.alu_set.alu_b  = IMM;
        idu.alu_set.alu_op = ADD;
        idu.reg_we = 1'b1;
      end

      OP: begin
        idu.alu_set.alu_a = RS1;
        idu.alu_set.alu_b = RS2;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case ({
          inst[31:25], inst[14:12]
        })
          {7'b0000000, 3'b000} : idu.alu_set.alu_op = ADD;
          {7'b0100000, 3'b000} : idu.alu_set.alu_op = SUB;
          {7'b0000000, 3'b001} : idu.alu_set.alu_op = SLL;
          {7'b0000000, 3'b010} : idu.alu_set.alu_op = LT;
          {7'b0000000, 3'b011} : idu.alu_set.alu_op = LTU;
          {7'b0000000, 3'b100} : idu.alu_set.alu_op = XOR;
          {7'b0000000, 3'b101} : idu.alu_set.alu_op = SRL;
          {7'b0100000, 3'b101} : idu.alu_set.alu_op = SRA;
          {7'b0000000, 3'b110} : idu.alu_set.alu_op = OR;
          {7'b0000000, 3'b111} : idu.alu_set.alu_op = AND;
          {
            7'b0000001, 3'b000
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = MULL;
          end
          {
            7'b0000001, 3'b001
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = MULH;
          end
          {
            7'b0000001, 3'b010
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = MULH;
          end
          {
            7'b0000001, 3'b011
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = MULH;
          end
          {
            7'b0000001, 3'b100
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = DIV;
          end
          {
            7'b0000001, 3'b101
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = DIV;
          end
          {
            7'b0000001, 3'b110
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b1;
            idu.mdu_set.signed_b = 1'b1;
            idu.mdu_set.mdu_op = REM;
          end
          {
            7'b0000001, 3'b111
          } : begin
            idu.alu_set.alu_op = ADD;
            idu.mdu_set.mdu_enable = 1'b1;
            idu.mdu_set.signed_a = 1'b0;
            idu.mdu_set.signed_b = 1'b0;
            idu.mdu_set.mdu_op = REM;
          end

          default: inst_err = 1'b1;
        endcase
      end

      OP_IMM: begin
        idu.imm           = immI;
        idu.alu_set.alu_a = RS1;
        idu.alu_set.alu_b = IMM;
        idu.reg_we        = 1'b1;
        use_rs1           = 1'b1;
        unique case (inst[14:12])
          3'b000: idu.alu_set.alu_op = ADD;

          3'b001:
          unique case (inst[31:25])
            7'b0000000: idu.alu_set.alu_op = SLL;
            default: inst_err = 1'b1;
          endcase

          3'b010: idu.alu_set.alu_op = LT;
          3'b011: idu.alu_set.alu_op = LTU;
          3'b100: idu.alu_set.alu_op = XOR;

          3'b101:
          unique case (inst[31:25])
            7'b0000000: idu.alu_set.alu_op = SRL;
            7'b0100000: idu.alu_set.alu_op = SRA;
            default: inst_err = 1'b1;
          endcase

          3'b110:  idu.alu_set.alu_op = OR;
          3'b111:  idu.alu_set.alu_op = AND;
          default: inst_err = 1'b1;
        endcase
      end

      LOAD: begin
        idu.imm                = immI;
        idu.alu_set.alu_a      = RS1;
        idu.alu_set.alu_b      = IMM;
        idu.alu_set.alu_op     = ADD;
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

      STORE: begin
        idu.imm                = immS;
        idu.alu_set.alu_a      = RS1;
        idu.alu_set.alu_b      = IMM;
        idu.alu_set.alu_op     = ADD;
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

      JAL: begin
        idu.imm    = immJ;
        idu.alu_set.alu_a  = PC;
        idu.alu_set.alu_b  = PC_INCR;
        idu.alu_set.alu_op = ADD;
        idu.reg_we = 1'b1;
        idu.jal    = 1'b1;
      end

      JALR: begin
        idu.imm    = immI;
        idu.alu_set.alu_a  = PC;
        idu.alu_set.alu_b  = PC_INCR;
        idu.alu_set.alu_op = ADD;
        idu.reg_we = 1'b1;
        idu.jalr   = 1'b1;
        if (inst[14:12] != 3'b000) inst_err = 1'b1;
        use_rs1 = 1'b1;
      end

      BRANCH: begin
        idu.imm           = immB;
        idu.alu_set.alu_a = RS1;
        idu.alu_set.alu_b = RS2;
        idu.branch        = 1'b1;
        use_rs1           = 1'b1;
        use_rs2           = 1'b1;
        unique case (inst[14:12])
          3'b000:  idu.alu_set.alu_op = EQ;
          3'b001:  idu.alu_set.alu_op = NE;
          3'b100:  idu.alu_set.alu_op = LT;
          3'b101:  idu.alu_set.alu_op = GE;
          3'b110:  idu.alu_set.alu_op = LTU;
          3'b111:  idu.alu_set.alu_op = GEU;
          default: inst_err = 1'b1;
        endcase
      end

      SYSTEM: begin
        idu.imm    = uimm;
        idu.alu_set.alu_a  = CONST0;
        idu.alu_set.alu_b  = CSR;
        idu.alu_set.alu_op = ADD;
        idu.reg_we = 1'b1;
        if (inst[14:12] == 3'b000) begin
          if ({inst[19:15], inst[11:7]} == '0) begin
            unique case (inst[31:20])
              ECALL: begin
                idu.ecall = 1'b1;
                idu.csr_name = mtvec;
              end
              EBREAK:  inst_err = 1'b1;  // use DPI-C to end sim
              MRET: begin
                idu.mret = 1'b1;
                idu.csr_name = mepc;
              end
              default: inst_err = 1'b1;
            endcase
          end else begin
            inst_err = 1'b1;
          end
        end else begin
          idu.csr_set.csr_enable = 1'b1;
          if (inst[14]) begin
            idu.csr_set.csr_uimm = 1'b1;
          end else begin
            use_rs1 = 1'b1;
          end
          unique case (inst[13:12])
            2'b01:   idu.csr_set.csr_op = WRITE;
            2'b10:   idu.csr_set.csr_op = inst[19:15] == 5'b0 ? READ : SET;
            2'b11:   idu.csr_set.csr_op = inst[19:15] == 5'b0 ? READ : CLEAR;
            default: inst_err = 1'b1;
          endcase
          unique case (inst[31:20])
            MSTATUS: idu.csr_name = mstatus;
            MTVEC: idu.csr_name = mtvec;
            MEPC: idu.csr_name = mepc;
            MCAUSE: idu.csr_name = mcause;
            MVENDORID: idu.csr_name = mvendorid;
            MARCHID: idu.csr_name = marchid;
            default: inst_err = 1'b1;
          endcase
        end
      end

      MISC_MEM: begin
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
