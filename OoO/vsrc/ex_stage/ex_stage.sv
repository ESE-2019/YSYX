`default_nettype none

module ex_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    // Fetch flush request - CONTROLLER
    input logic flush_i,
    // FU data useful to execute instruction - ISSUE_STAGE
    input fu_data_t fu_data,
    // PC of the current instruction - ISSUE_STAGE
    input logic [31:0] pc_i,
    // Report whether instruction is compressed - ISSUE_STAGE
    input logic is_rv16,
    // FLU is ready - ISSUE_STAGE
    output logic flu_ready_o,
    // ALU instruction is valid - ISSUE_STAGE
    input logic alu_valid_i,
    // Branch unit instruction is valid - ISSUE_STAGE
    input logic branch_valid_i,
    // Information of branch prediction - ISSUE_STAGE
    input branchpredict_sbe_t branch_predict_i,
    // The branch engine uses the write back from the ALU - several_modules
    output bp_resolve_t resolved_branch_o,
    // Signaling that we resolved the branch - ISSUE_STAGE
    output logic resolve_branch_o,
    // CSR instruction is valid - ISSUE_STAGE
    input logic csr_valid_i,
    // CSR address to write - COMMIT_STAGE
    output logic [11:0] csr_addr_o,
    // CSR commit - COMMIT_STAGE
    input logic csr_commit_i,
    // MULT instruction is valid - ISSUE_STAGE
    input logic mult_valid_i,
    // LSU is ready - ISSUE_STAGE
    output logic lsu_ready_o,
    // LSU instruction is valid - ISSUE_STAGE
    input logic lsu_valid_i,
    // Load result is valid - ISSUE_STAGE
    output logic load_valid_o,
    // Load result valid - ISSUE_STAGE
    output logic [31:0] load_result_o,
    // Load instruction ID - ISSUE_STAGE
    output logic [CVA6Cfg.TRANS_ID_BITS-1:0] load_trans_id_o,
    // Exception generated by load instruction - ISSUE_STAGE
    output exception_t load_exception_o,
    // Store result is valid - ISSUe_STAGE
    output logic store_valid_o,
    // Store result - ISSUE_STAGE
    output logic [CVA6Cfg.XLEN-1:0] store_result_o,
    // Store instruction ID - ISSUE_STAGE
    output logic [CVA6Cfg.TRANS_ID_BITS-1:0] store_trans_id_o,
    // Exception generated by store instruction - ISSUE_STAGE
    output exception_t store_exception_o,
    // LSU commit - COMMIT_STAGE
    input logic lsu_commit_i,
    // Commit queue ready to accept another commit request - COMMIT_STAGE
    output logic lsu_commit_ready_o,

    input  decoder_t        decoder,
    input  logic     [31:0] idu_dbg_inst,
    output logic     [31:0] exu_dbg_inst,

    output logic                reg_we,
    output logic [RegWidth-1:0] rd_addr,
    output logic [        31:0] rd_data,

    output logic ecall,
    output logic mret,
    output csr_set_t csr_set,
    output logic [31:0] csr_pc,

    output logic forward_en,
    output logic [31:0] forward_data,

    input logic [WriteBackPorts-1:0][ScoreboardIndex-1:0] wb_idx,
    input logic [WriteBackPorts-1:0][               31:0] wb_data,
    input logic [WriteBackPorts-1:0]                      wb_valid,

    output logic load_num,
    output logic load_cycle,
    output logic store_num,
    output logic store_cycle,

    input  logic   ifu2exu_ready,
    output logic   exu2idu_ready,
    input  stage_t idu2exu,
    output stage_t exu2ifu,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m
);

  logic mdu_valid, mdu_ready;
  mdu2alu_t mdu2alu;
  alu2mdu_t alu2mdu;
  logic exu2lsu_valid;
  logic exu2lsu_ready;
  logic lsu2exu_valid;
  logic lsu2exu_ready;
  assign exu2lsu_ready = 1'b1;
  wire [31:0] idu2exu_pc = idu2exu.pc;

  logic [31:0] alu_a, alu_b, alu_o, mdu_o;
  logic [31:0] dnpc, lsu_addr;
  logic [1:0] lsu_size;
  logic lsu_sext;
  logic lsu_write;
  logic [31:0] lsu_wdata;
  logic [31:0] lsu_rdata;
  logic [31:0] mdu_a, mdu_b;
  mdu_set_t mdu_set;

  assign alu_a = idu2exu.alu_a;
  assign alu_b = idu2exu.alu_b;
  always_comb begin
    unique case (1'b1)
      decoder.jal: dnpc = idu2exu.pc + decoder.imm;
      decoder.jalr: dnpc = (idu2exu.rs1_data + decoder.imm) & 32'hffff_fffe;
      decoder.branch: dnpc = idu2exu.pc + decoder.imm;
      decoder.ecall: dnpc = idu2exu.csr_rdata;
      decoder.mret: dnpc = idu2exu.csr_rdata;
      default: dnpc = idu2exu.pc;
    endcase
  end

  logic alu_branch_res;  // branch comparison result
  logic [CVA6Cfg.XLEN-1:0] alu_result, csr_result, mult_result;
  logic [CVA6Cfg.VLEN-1:0] branch_result;
  logic csr_ready, mult_ready;
  logic [CVA6Cfg.TRANS_ID_BITS-1:0] mult_trans_id;
  logic mult_valid;

  logic one_cycle_select;
  assign one_cycle_select = alu_valid_i | branch_valid_i | csr_valid_i;

  fu_data_t one_cycle_data;
  assign one_cycle_data = one_cycle_select ? fu_data : '0;

  //assign flu_valid_o = one_cycle_select | mult_valid;
  assign flu_ready_o = csr_ready & mult_ready;

  fu_data_t mult_data;
  assign mult_data = mult_valid_i ? fu_data : '0;

  fu_data_t lsu_data;
  assign lsu_data = lsu_valid_i ? fu_data : '0;



  always_comb begin
    // wb port 0 (flu)
    wb_data[0] = {31'b0, branch_result};
    wb_idx[0]  = one_cycle_data.trans_id;
    wb_valid[0] = one_cycle_select | mult_valid;
    if (alu_valid_i) begin
      wb_data[0] = alu_result;
    end else if (csr_valid_i) begin
      wb_data[0] = csr_result;
    end else if (mdu_valid) begin
      wb_data[0] = mdu_result;
      wb_idx[0]  = mdu_trans_id;
    end

    // wb port 1 (lsu)
    wb_data[1] = lsu_rdata;
    wb_idx[1]  = lsu_trans_id;
    wb_valid[1] = lsu2exu_valid;
  end



  ysyx_24080006_lsu LSU (.*);
  ysyx_24080006_alu ALU (
      .*,
      .alu_op(decoder.alu_set.alu_op)
  );
  ysyx_24080006_mdu MDU (.*);


`ifdef SIM_MODE
  import ysyx_24080006_sim_pkg::*;
  import "DPI-C" function void SKIP_DIFFTEST();
  import "DPI-C" function void LSU_CNT(
    input int load_en,
    input int cnt
  );
  int lsu_cnt = 0;
  always_ff @(posedge clock) begin
    if (curr == EX_IDLE) lsu_cnt = 1;
    else lsu_cnt++;
    if (curr == EX_LSU && lsu2exu_valid && lsu_write) begin
      //$display("[LSU] 0x%08x write [0x%08x] at pc 0x%08x", lsu_addr, lsu_wdata, idu2exu.pc);
      LSU_CNT(0, lsu_cnt);
      if (INSIDE_PERIP(lsu_addr)) SKIP_DIFFTEST();
      if (!INSIDE_STORE(lsu_addr)) begin
        $display("[LSU] store addr error 0x%08x at pc 0x%08x", lsu_addr, idu2exu.pc);
        $finish;
      end
    end
    if (curr == EX_LSU && lsu2exu_valid && !lsu_write) begin
      //$display("[LSU] 0x%08x  read [0x%08x] at pc 0x%08x", lsu_addr, lsu_rdata, idu2exu.pc);
      LSU_CNT(1, lsu_cnt);
      if (INSIDE_PERIP(lsu_addr)) SKIP_DIFFTEST();
      if (!INSIDE_LOAD(lsu_addr)) begin
        $display("[LSU] load addr error 0x%08x at pc 0x%08x", lsu_addr, idu2exu.pc);
        $finish;
      end
    end
  end
`endif
endmodule

`default_nettype wire
