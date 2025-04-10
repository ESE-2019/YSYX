`default_nettype none

module issue_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input  decoder_t idu2isu_instr,
    input  logic     idu_valid,
    output logic     isu2idu_ready,
    input  logic     flush_unissued_instr,

    output fu_data_t        fu_data,
    output logic     [31:0] pc,
    output logic            is_rv16,
    input  logic            flu_ready,
    output logic            alu_valid,
    output logic            bju_valid,
    output logic            mdu_valid,
    output logic            csr_valid,
    output bpu_t            bpu,
    input  logic            lsu_ready,
    output logic            lsu_valid,

    output fu_op_e csr_op,
    output logic [31:0] csr_wdata,
    input logic [31:0] csr_rdata,
    output logic commit_csr,
    output logic commit_lsu,

    output logic        retire_valid,
    output logic        retire_cf,
    output logic        retire_jump,
    output logic        retire_branch,
    output logic        retire_is_rv16,
    output logic [31:0] retire_pc,
    output logic [31:0] retire_dnpc,
    output logic [31:0] csr_pc,

    input writeback_t [WriteBackPorts-1:0] wb,
    input logic [31:0] branch_address,
    input logic branch_taken,

    output logic [ 0:0] rvfi_valid,
    output logic [63:0] rvfi_order,
    output logic [31:0] rvfi_insn,
    output logic [ 0:0] rvfi_trap,
    output logic [ 0:0] rvfi_halt,
    output logic [ 0:0] rvfi_intr,
    output logic [ 1:0] rvfi_mode,
    output logic [ 4:0] rvfi_rs1_addr,
    output logic [ 4:0] rvfi_rs2_addr,
    output logic [31:0] rvfi_rs1_rdata,
    output logic [31:0] rvfi_rs2_rdata,
    output logic [ 4:0] rvfi_rd_addr,
    output logic [31:0] rvfi_rd_wdata,
    output logic [31:0] rvfi_pc_rdata,
    output logic [31:0] rvfi_pc_wdata,
    output logic [31:0] rvfi_mem_addr,
    output logic [ 3:0] rvfi_mem_rmask,
    output logic [ 3:0] rvfi_mem_wmask,
    output logic [31:0] rvfi_mem_rdata,
    output logic [31:0] rvfi_mem_wdata,
    output logic [ 0:0] rvfi_mem_extamo
);


  forwarding_t        fwd;
  decoder_t           issue_instr;
  decoder_t           commit_instr;
  logic               commit_valid;
  logic               issue_valid;
  logic               issue_ready;
  logic        [ 4:0] gpr_waddr;
  logic        [31:0] gpr_wdata;
  logic               gpr_we;

  logic               branch_taken_q;
  assign retire_valid = commit_valid;
  assign retire_cf = commit_instr.fu inside {FU_CSR, FU_BJU};
  assign retire_jump = commit_instr.op inside {BJU_JAL, BJU_JALR};
  assign retire_branch = commit_instr.fu == FU_BJU &&
    commit_instr.op inside {ALU_EQ, ALU_NE, ALU_GE, ALU_GEU, ALU_LT, ALU_LTU} &&
    branch_taken_q;
  assign retire_is_rv16 = commit_instr.is_rv16;
  assign retire_pc = commit_instr.pc;
  assign csr_pc = commit_instr.pc;
  always_ff @(posedge clock) begin
    if (wb[0].valid) begin
      branch_taken_q <= branch_taken;
      retire_dnpc <= branch_address;
    end
  end
  fu_data_t dbg_data;
  issue ISSUE_UNIT (.*);
  scoreboard SCOREBOARD_UNIT (.*);
  commit COMMIT_UNIT (.*);
  rvfi_adapter RVFI_ADAPTER (.*);

`ifdef SIM_MODE
  import "DPI-C" function void retirement(
    input int pc,
    input int npc
  );
  logic difftest;
  logic [31:0] difftest_pc, difftest_npc;
  always_ff @(posedge clock) begin
    difftest <= retire_valid;
    difftest_pc <= commit_instr.pc;
    difftest_npc <= commit_instr.dbg_pc_wdata;
    if (difftest) retirement(difftest_pc, difftest_npc);
  end
`endif

endmodule

`default_nettype wire
