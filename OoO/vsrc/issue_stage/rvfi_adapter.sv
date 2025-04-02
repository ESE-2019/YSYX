module rvfi_adapter
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input decoder_t commit_instr,
    input logic commit_valid,

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

  assign rvfi_valid = commit_valid;
  logic [63:0] order_d, order_q;
  always_ff @(posedge clock) begin
    if (reset) begin
      order_q <= 64'b0;
    end else begin
      order_q <= order_d;
    end
  end
  always_comb begin
    order_d = order_q;
    if (rvfi_valid) order_d = order_q + 64'h1;
  end
  assign rvfi_order = order_d;
  assign rvfi_insn = commit_instr.dbg_insn;
  assign rvfi_trap = 1'b0;
  assign rvfi_halt = 1'b0;
  assign rvfi_intr = 1'b0;
  assign rvfi_mode = 2'b11;
  assign rvfi_rs1_addr = commit_instr.rs1;
  assign rvfi_rs2_addr = commit_instr.rs1;
  assign rvfi_rs1_rdata = |commit_instr.rs1 ? commit_instr.dbg_rs1 : 32'b0;
  assign rvfi_rs2_rdata = |commit_instr.rs2 ? commit_instr.dbg_rs2 : 32'b0;
  assign rvfi_rd_addr = commit_instr.rd;
  assign rvfi_rd_wdata = |commit_instr.rd ? commit_instr.result : 32'b0;
  assign rvfi_pc_rdata = commit_instr.pc;
  assign rvfi_pc_wdata = commit_instr.dbg_pc_wdata;

  always_comb begin
    rvfi_mem_addr = commit_instr.dbg_rs1 + commit_instr.dbg_imm;
    unique case (commit_instr.op)
      LSU_LB, LSU_LBU: rvfi_mem_rmask = 4'b0001 << {rvfi_mem_addr[1:0], 3'b0};
      LSU_LH, LSU_LHU: rvfi_mem_rmask = 4'b0011 << {rvfi_mem_addr[1:0], 3'b0};
      LSU_LW: rvfi_mem_rmask = 4'b1111;
      default: rvfi_mem_rmask = 4'b0000;
    endcase
    unique case (commit_instr.op)
      LSU_SB:  rvfi_mem_wmask = 4'b0001 << {rvfi_mem_addr[1:0], 3'b0};
      LSU_SH:  rvfi_mem_wmask = 4'b0011 << {rvfi_mem_addr[1:0], 3'b0};
      LSU_SW:  rvfi_mem_wmask = 4'b1111;
      default: rvfi_mem_wmask = 4'b0000;
    endcase
    rvfi_mem_rdata = commit_instr.result;
    rvfi_mem_wdata = commit_instr.dbg_rs2;
  end

  assign rvfi_mem_extamo = '0;

endmodule
