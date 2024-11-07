module ysyx_24080006_decoder
  import ysyx_24080006_pkg::*;
(
    input logic [31:0] inst,
    output decoder_t idu,
    output logic inst_err
);

  wire [31:0] uimm = {27'b0, inst[19:15]};
  wire [31:0] immU = {inst[31:12], 12'b0};
  wire [31:0] immI = {{20{inst[31]}}, inst[31:20]};
  wire [31:0] immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  wire [31:0] immB = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
  wire [31:0] immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};

  assign idu.rs1_addr = ifu2exu.inst[15+:REG_WIDTH];
  assign idu.rs2_addr = ifu2exu.inst[20+:REG_WIDTH];
  assign idu.rd_addr  = ifu2exu.inst[7+:REG_WIDTH];

  always_comb begin
    idu.imm      = immI;
    idu.alu_a    = RS1;
    idu.alu_b    = IMM;
    idu.alu_op   = ADD;
    idu.csr_en   = 0;
    idu.csr_uimm = 0;
    idu.csr      = MARCHID;
    idu.csr_op   = READ;
    idu.load     = 0;
    idu.store    = 0;
    idu.strb     = 0;
    idu.sext     = 0;
    idu.reg_we   = 0;
    idu.jal      = 0;
    idu.jal      = 0;
    idu.branch   = 0;
    idu.ecall    = 0;
    idu.mret     = 0;
    inst_err    = 0;
    unique case (inst[6:0])

      LUI: begin
        idu.imm    = immU;
        idu.alu_a  = CONST0;
        idu.alu_b  = IMM;
        idu.alu_op = ADD;
        idu.reg_we = 1;
      end

      AUIPC: begin
        idu.imm    = immU;
        idu.alu_a  = PC;
        idu.alu_b  = IMM;
        idu.alu_op = ADD;
        idu.reg_we = 1;
      end

      OP: begin
        idu.alu_a  = RS1;
        idu.alu_b  = RS2;
        idu.reg_we = 1;
        unique case ({
          inst[31:25], inst[14:12]
        })
          {7'b0000000, 3'b000} : idu.alu_op = ADD;
          {7'b0100000, 3'b000} : idu.alu_op = SUB;
          {7'b0000000, 3'b001} : idu.alu_op = SLL;
          {7'b0000000, 3'b010} : idu.alu_op = SLT;
          {7'b0000000, 3'b011} : idu.alu_op = SLTU;
          {7'b0000000, 3'b100} : idu.alu_op = XOR;
          {7'b0000000, 3'b101} : idu.alu_op = SRL;
          {7'b0100000, 3'b101} : idu.alu_op = SRA;
          {7'b0000000, 3'b110} : idu.alu_op = OR;
          {7'b0000000, 3'b111} : idu.alu_op = AND;
          default:               inst_err = 1;
        endcase
      end

      OP_IMM: begin
        idu.imm    = immI;
        idu.alu_a  = RS1;
        idu.alu_b  = IMM;
        idu.reg_we = 1;
        unique case (inst[14:12])
          3'b000:  idu.alu_op = ADD;
          3'b001:
          if (inst[31:25] == 7'b0000000) begin
            idu.alu_op = SLL;
          end else begin
            inst_err = 1;
          end
          3'b010:  idu.alu_op = SLT;
          3'b011:  idu.alu_op = SLTU;
          3'b100:  idu.alu_op = XOR;
          3'b101:
          if (inst[31:25] == 7'b0000000) begin
            idu.alu_op = SRL;
          end else if (inst[31:25] == 7'b0100000) begin
            idu.alu_op = SRA;
          end else begin
            inst_err = 1;
          end
          3'b110:  idu.alu_op = OR;
          3'b111:  idu.alu_op = AND;
          default: inst_err = 1;
        endcase
      end

      LOAD: begin
        idu.imm    = immI;
        idu.alu_a  = RS1;
        idu.alu_b  = IMM;
        idu.alu_op = ADD;
        idu.load   = 1;
        idu.reg_we = 1;
        unique case (inst[14:12])
          3'b000:  {idu.sext, idu.strb} = inst[14:12];
          3'b001:  {idu.sext, idu.strb} = inst[14:12];
          3'b010:  {idu.sext, idu.strb} = inst[14:12];
          3'b100:  {idu.sext, idu.strb} = inst[14:12];
          3'b101:  {idu.sext, idu.strb} = inst[14:12];
          default: inst_err = 1;
        endcase
      end

      STORE: begin
        idu.imm    = immS;
        idu.alu_a  = RS1;
        idu.alu_b  = IMM;
        idu.alu_op = ADD;
        idu.store  = 1;
        unique case (inst[14:12])
          3'b000:  {idu.sext, idu.strb} = inst[14:12];
          3'b001:  {idu.sext, idu.strb} = inst[14:12];
          3'b010:  {idu.sext, idu.strb} = inst[14:12];
          default: inst_err = 1;
        endcase
      end

      JAL: begin
        idu.imm    = immJ;
        idu.alu_a  = PC;
        idu.alu_b  = CONST4;
        idu.alu_op = ADD;
        idu.reg_we = 1;
        idu.jal    = 1;
      end

      JALR: begin
        idu.imm    = immI;
        idu.alu_a  = PC;
        idu.alu_b  = CONST4;
        idu.alu_op = ADD;
        idu.reg_we = 1;
        idu.jalr   = 1;
        if (inst[14:12] != 3'b000) inst_err = 1;
      end

      BRANCH: begin
        idu.imm    = immB;
        idu.alu_a  = RS1;
        idu.alu_b  = RS2;
        idu.branch = 1;
        unique case (inst[14:12])
          3'b000:  alu_op = BEQ;
          3'b001:  alu_op = BNE;
          3'b100:  alu_op = BLT;
          3'b101:  alu_op = BGE;
          3'b110:  alu_op = BLTU;
          3'b111:  alu_op = BGEU;
          default: inst_err = 1;
        endcase
      end

      SYSTEM: begin
        idu.imm    = zimm;
        idu.alu_a  = CONST0;
        idu.alu_b  = CSR;
        idu.alu_op = ADD;
        idu.reg_we = 1;
        if (inst[14:12] == 3'b000) begin
          if ({inst[19:15], inst[11:7]} == '0) begin
            unique case (inst[31:20])
              ECALL: idu.ecall = 1;
              EBREAK: inst_err = 1;  // use DPI-C to end sim
              MRET: idu.mret = 1;
              default: inst_err = 1;
            endcase
          end else begin
            inst_err = 1;
          end
        end else begin
          idu.csr_en = 1;
          if (inst[14]) idu.csr_uimm = 1;
          unique case (inst[13:12])
            2'b01:   idu.csr_op = WRITE;
            2'b10:   idu.csr_op = inst[19:15] == 5'b0 ? READ : SET;
            2'b11:   idu.csr_op = inst[19:15] == 5'b0 ? READ : CLEAR;
            default: inst_err = 1;
          endcase
          unique case (inst[31:20])
            MSTATUS: idu.csr = mstatus;
            MTVEC: idu.csr = mtvec;
            MEPC: idu.csr = mepc;
            MCAUSE: idu.csr = mcause;
            MVENDORID: idu.csr = mvendorid;
            MARCHID: idu.csr = marchid;
            default: inst_err = 1;
          endcase
        end
      end

      default: inst_err = 1;
    endcase
  end

endmodule
