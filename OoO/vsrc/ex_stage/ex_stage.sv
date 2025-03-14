`default_nettype none

module ex_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic flush_i,
    input fu_data_t fu_data,
    input logic [31:0] pc_i,
    input logic is_rv16,
    output logic flu_ready_o,
    input logic alu_valid_i,
    input logic branch_valid_i,
    input branchpredict_sbe_t branch_predict_i,
    output bp_resolve_t resolved_branch_o,
    output logic resolve_branch_o,
    input logic csr_valid_i,
    output logic [11:0] csr_addr_o,
    input logic csr_commit_i,
    input logic mdu_valid,
    output logic lsu_ready_o,
    input logic lsu_valid,
    output logic load_valid_o,
    output exception_t load_exception_o,
    output logic store_valid_o,
    output logic [CVA6Cfg.XLEN-1:0] store_result_o,
    input logic lsu_commit_i,
    output logic lsu_commit_ready_o,

    output writeback_t [WriteBackPorts-1:0] wb,

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
  logic exu2lsu_valid;
  logic exu2lsu_ready;
  logic lsu2exu_valid;
  logic lsu2exu_ready;
  assign exu2lsu_valid = lsu_valid;
  assign exu2lsu_ready = 1'b1;

  logic [31:0] dnpc, lsu_addr;
  logic [1:0] lsu_size;
  logic lsu_sext;
  logic lsu_write;
  logic [31:0] lsu_wdata;
  logic [31:0] lsu_rdata;

  logic [31:0] alu_result, csr_result, mdu_result;
  logic [31:0] branch_result;
  logic csr_ready;
  logic [ScoreboardDepth-1:0] mdu_trans_id;
  logic mult_valid;

  logic one_cycle_select;
  assign one_cycle_select = alu_valid_i | branch_valid_i | csr_valid_i;

  fu_data_t one_cycle_data;
  assign one_cycle_data = one_cycle_select ? fu_data : '0;

  //assign flu_valid_o = one_cycle_select | mult_valid;
  assign flu_ready_o = csr_ready & mdu_ready;

  fu_data_t mult_data;
  assign mult_data = mdu_valid ? fu_data : '0;

  fu_data_t lsu_data;
  assign lsu_data = lsu_valid ? fu_data : '0;



  always_comb begin
    // wb port 0 (flu)
    wb[0].data  = {31'b0, branch_result};
    wb[0].idx   = one_cycle_data.trans_id;
    wb[0].valid = one_cycle_select | mult_valid;
    if (alu_valid_i) begin
      wb[0].data = alu_result;
    end else if (csr_valid_i) begin
      wb[0].data = csr_result;
    end else if (mdu_valid) begin
      wb[0].data = mdu_result;
      wb[0].idx  = mdu_trans_id;
    end

    // wb port 1 (lsu)
    wb[1].data  = lsu_rdata;
    wb[1].idx   = lsu_trans_id;
    wb[1].valid = lsu2exu_valid;
  end

  always_comb begin
    lsu_addr  = fu_data.operand_a + fu_data.imm;
    lsu_sext  = fu_data.operation inside {LSU_LBU, LSU_LHU};
    lsu_write = fu_data.operation inside {LSU_SB, LSU_SH, LSU_SW};
    lsu_wdata = fu_data.operand_b;
    unique case (fu_data.operation)
      LSU_LB, LSU_LBU, LSU_SB: lsu_size = 2'b00;
      LSU_LH, LSU_LHU, LSU_SH: lsu_size = 2'b01;
      LSU_LW, LSU_SW: lsu_size = 2'b10;
      default: lsu_size = 2'b11;
    endcase
  end


  ysyx_24080006_lsu LSU (.*);
  bu BU (.*);
  alu ALU (.*);
  mdu MDU (.*);
  dummy_csr DUMMY_CSR (.*);


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
