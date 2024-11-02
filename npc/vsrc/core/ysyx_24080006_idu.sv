module ysyx_24080006_idu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic [ 4:0] rs1_addr,
    output logic [ 4:0] rs2_addr,
    input  logic [31:0] rs1_val,
    input  logic [31:0] rs2_val,

    output logic [11:0] csr_addr,
    input  logic [31:0] csr_rdata,

    output logic [31:0] mepc_val,  //for ecall
    output logic        mepc_en,

    input  logic   exu2idu_ready,
    output logic   idu2ifu_ready,
    input  stage_t ifu2idu,
    output stage_t idu2exu
);


  fsm_e curr, next;

  assign mepc_val = ifu2idu.pc;
  assign mepc_en  = ifu2idu.inst == 32'b0000000_00000_00000_000_00000_11100_11;


  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (ifu2idu.valid) next = EXEC;
        else next = IDLE;
      end
      EXEC, WAIT: begin
        if (exu2idu_ready) next = IDLE;
        else next = WAIT;
      end
    endcase
  end

  always_ff @(posedge clock) begin  //fsm 3 for control
    unique if (reset) begin
      idu2ifu_ready <= 1;
      idu2exu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2idu.valid) begin
            idu2ifu_ready <= 0;
            idu2exu.valid <= 1;
          end else begin
            idu2ifu_ready <= 1;
            idu2exu.valid <= 0;
          end
        end
        EXEC, WAIT: begin
          if (exu2idu_ready) begin
            idu2ifu_ready <= 1;
            idu2exu.valid <= 0;
          end else begin
            idu2ifu_ready <= 0;
            idu2exu.valid <= 1;
          end
        end
      endcase
    end
  end


  logic [31:0] immB, immI, immJ, immS, immU;
  assign immB = {
    {20{ifu2idu.inst[31]}}, ifu2idu.inst[7], ifu2idu.inst[30:25], ifu2idu.inst[11:8], 1'b0
  };
  assign immI = {{20{ifu2idu.inst[31]}}, ifu2idu.inst[31:20]};
  assign immJ = {
    {12{ifu2idu.inst[31]}}, ifu2idu.inst[19:12], ifu2idu.inst[20], ifu2idu.inst[30:21], 1'b0
  };
  assign immS = {{20{ifu2idu.inst[31]}}, ifu2idu.inst[31:25], ifu2idu.inst[11:7]};
  assign immU = {ifu2idu.inst[31:12], 12'b0};

  inst_op_e inst_op;
  logic [2:0] funct3;
  logic [4:0] rd_addr;

  assign inst_op = inst_op_e'(ifu2idu.inst[6:0]);
  assign funct3 = ifu2idu.inst[14:12];
  assign rs1_addr = ifu2idu.inst[19:15];
  assign rs2_addr = ifu2idu.inst[24:20];
  assign rd_addr = ifu2idu.inst[11:7];

  assign csr_addr = ( ifu2idu.inst == 32'b0000000_00000_00000_000_00000_11100_11 ) ? 12'h305 : // ecall mtvec
      (ifu2idu.inst == 32'b0011000_00010_00000_000_00000_11100_11) ? 12'h341 :  // mret mepc
      ifu2idu.inst[31:20];

  logic [31:0] alu_src1, alu_src2;
  alu_op_e alu_op;
  //logic [1:0] alu_set;

  always_comb begin  //fsm 2 for decode alu_src1
    unique case (inst_op)
      Jal, Jalr, Auipc: alu_src1 = ifu2idu.pc;
      Lui:              alu_src1 = '0;
      default:          alu_src1 = rs1_val;  //other cases
    endcase
  end

  always_comb begin  //fsm 2 for decode alu_src2
    unique case (inst_op)
      Auipc, Lui: alu_src2 = immU;
      Store: alu_src2 = immS;
      Load, I_type: alu_src2 = immI;
      Branch, R_type: alu_src2 = rs2_val;  //B, R
      Jal, Jalr: alu_src2 = 32'h4;  //Jal, Jalr
      System:
      if (funct3 == 3'b010) alu_src2 = csr_rdata;
      else alu_src2 = '0;
      default: alu_src2 = '0;
    endcase
  end

  always_comb begin  //fsm 2 for decode alu_ctrl
    alu_op = ADD;
    unique case (inst_op)
      Branch:
      unique case (funct3)
        3'b000:  alu_op = BEQ;
        3'b001:  alu_op = BNE;
        3'b100:  alu_op = BLT;
        3'b101:  alu_op = BGE;
        3'b110:  alu_op = BLTU;
        3'b111:  alu_op = BGEU;
        default: ;
      endcase
      I_type:
      unique case (funct3)
        3'b000:  alu_op = ADD;
        3'b001:  alu_op = SLL;
        3'b010:  alu_op = SLT;
        3'b011:  alu_op = SLTU;
        3'b100:  alu_op = XOR;
        3'b101:  if (!ifu2idu.inst[30]) alu_op = SRL;
 else alu_op = SRA;
        3'b110:  alu_op = OR;
        3'b111:  alu_op = AND;
        default: ;
      endcase
      R_type:
      unique case (funct3)
        3'b000:  if (!ifu2idu.inst[30]) alu_op = ADD;
 else alu_op = SUB;
        3'b001:  alu_op = SLL;
        3'b010:  alu_op = SLT;
        3'b011:  alu_op = SLTU;
        3'b100:  alu_op = XOR;
        3'b101:  if (!ifu2idu.inst[30]) alu_op = SRL;
 else alu_op = SRA;
        3'b110:  alu_op = OR;
        3'b111:  alu_op = AND;
        default: ;
      endcase
      Jal, Jalr, Lui, Auipc, Load, Store: alu_op = ADD;
      System:
      if (funct3 == 3'b010) alu_op = OR;
      else alu_op = ADD;
      default: ;
    endcase
  end

  logic [31:0] dnpc;
  always_comb begin
    unique case (inst_op)
      Jal: dnpc = ifu2idu.pc + immJ;
      Jalr: dnpc = (rs1_val + immI) & 32'hffff_fffe;
      Branch: dnpc = ifu2idu.pc + immB;
      System: dnpc = csr_rdata;
      default: dnpc = csr_rdata;
    endcase
  end

  logic csr_we;
  always_comb begin
    if (inst_op == System && (funct3 != 3'b0)) csr_we = 1;
    else csr_we = 0;
  end

  always_ff @(posedge clock) begin  //fsm 3 for decode alu
    if (reset) begin
      idu2exu.alu_src1 <= '0;
      idu2exu.alu_src2 <= '0;
      idu2exu.alu_op <= ADD;
      idu2exu.rd_addr <= '0;
      idu2exu.dnpc <= '0;
      idu2exu.sdata <= '0;
      idu2exu.csr_addr <= '0;
      idu2exu.csr_we <= '0;
      idu2exu.csr_wdata <= '0;
    end else if (curr == IDLE && ifu2idu.valid) begin
      idu2exu.alu_src1 <= alu_src1;
      idu2exu.alu_src2 <= alu_src2;
      idu2exu.alu_op <= alu_op;
      idu2exu.rd_addr <= rd_addr;
      idu2exu.dnpc <= dnpc;
      idu2exu.sdata <= rs2_val;
      idu2exu.csr_addr <= csr_addr;
      idu2exu.csr_we <= csr_we;
      idu2exu.csr_wdata <= csr_rdata;
    end
  end

  //logic Load, store, wb, jump, branch;
  always_ff @(posedge clock) begin  //fsm 3 for decode alu
    if (reset) begin
      idu2exu.funct3 <= '0;
      idu2exu.load <= '0;
      idu2exu.store <= '0;
      idu2exu.wb <= '0;
      idu2exu.jump <= '0;
      idu2exu.branch <= '0;
      idu2exu.ecall <= '0;
      idu2exu.pc <= '0;
    end else if (curr == IDLE && ifu2idu.valid) begin
      idu2exu.funct3 <= funct3;
      idu2exu.load <= inst_op == Load;
      idu2exu.store <= inst_op == Store;
      idu2exu.wb <= inst_op inside {Auipc, Lui, Jal, Jalr, I_type, R_type, Load};
      idu2exu.jump <= (inst_op inside {Jal, Jalr}) || (inst_op == System && !csr_we);
      idu2exu.branch <= inst_op == Branch;
      idu2exu.ecall <= ifu2idu.inst == 32'b0000000_00000_00000_000_00000_11100_11;
      idu2exu.pc <= ifu2idu.pc;
    end
  end

`ifdef SIM_MODE
  import "DPI-C" function void ebreak();
  import "DPI-C" function void INST_CNT(input int type_code);
  always_ff @(posedge clock) begin
    if (curr == IDLE && ifu2idu.valid)
      case (inst_op)

        Auipc, Lui, R_type, I_type: INST_CNT(0);

        Load, Store: INST_CNT(1);

        System: begin
          INST_CNT(2);
          if (ifu2idu.inst == 32'b0000000_00001_00000_000_00000_11100_11) ebreak();
        end

        Branch: INST_CNT(3);

        Jal, Jalr: INST_CNT(4);

        default: begin
          $display("inst error 0x%08x", ifu2idu.inst);
          $finish;
        end
      endcase

`ifndef SOC_MODE
    if (curr == EXEC && (ifu2idu.pc < 32'h8000_0000 || ifu2idu.pc > 32'h9000_0000)) begin
      $display("addr error 0x%08x", ifu2idu.pc);
      $finish;
    end
`endif
  end
`endif

endmodule
