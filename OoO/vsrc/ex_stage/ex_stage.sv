`default_nettype none

module ex_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    //input logic flush,
    input fu_data_t fu_data,
    input logic [31:0] pc,
    input logic is_rv16,

    output logic flu_ready,
    input logic alu_valid,
    input logic bju_valid,
    input logic mdu_valid,
    input logic csr_valid,
    input bpu_t bpu,
    output bju_t bju,
    //output logic resolve_branch_o,
    output logic [11:0] csr_addr,
    input logic commit_csr,
    output logic lsu_ready,
    input logic lsu_valid,
    // output logic load_valid_o,
    // output exception_t load_exception_o,
    // output logic store_valid_o,
    // output logic [CVA6Cfg.XLEN-1:0] store_result_o,
    input logic commit_lsu,
    // output logic lsu_commit_ready_o,

    output writeback_t [WriteBackPorts-1:0] wb,
    output logic [31:0] branch_address,
    output logic branch_taken,

    output logic load_num,
    output logic load_cycle,
    output logic store_num,
    output logic store_cycle,

    output logic data_req_o,
    input  logic data_gnt_i,
    input  logic data_rvalid_i,

    output logic [31:0] data_addr_o,
    output logic        data_we_o,
    output logic [ 3:0] data_be_o,
    output logic [31:0] data_wdata_o,
    input  logic [31:0] data_rdata_i,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m
);

  logic mdu_finish, mdu_ready;
  logic exu2lsu_valid;
  logic exu2lsu_ready;
  logic lsu2exu_valid;
  logic lsu2exu_ready;
  assign exu2lsu_valid = lsu_valid;
  assign lsu_ready = lsu2exu_ready;
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
  logic [ScoreboardIndex-1:0] mdu_idx, lsu_idx;

  logic one_cycle_select;
  assign one_cycle_select = alu_valid | bju_valid | csr_valid;

  fu_data_t one_cycle_data;
  assign one_cycle_data = one_cycle_select ? fu_data : '0;

  assign flu_ready = csr_ready & mdu_ready;

  fu_data_t mdu_data;
  assign mdu_data = mdu_valid ? fu_data : '0;

  fu_data_t lsu_data;
  assign lsu_data = lsu_valid ? fu_data : '0;



  always_comb begin
    // wb port 0 (flu)
    wb[0].data  = branch_result;
    wb[0].idx   = one_cycle_data.idx;
    wb[0].valid = one_cycle_select | mdu_finish;
    if (alu_valid) begin
      wb[0].data = alu_result;
    end else if (csr_valid) begin
      wb[0].data = csr_result;
    end else if (mdu_finish) begin
      wb[0].data = mdu_result;
      wb[0].idx  = mdu_idx;
    end

    // wb port 1 (lsu)
    wb[1].data = lsu_rdata;
    wb[1].idx = lsu_idx;
    wb[1].valid = lsu2exu_valid;

    // used for dbg
    wb[0].dbg_pc_wdata = bju.target_address;
    wb[1].dbg_pc_wdata = 32'b0;
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
  wire [ScoreboardIndex-1:0] lsu_idx_i = fu_data.idx;


  lsu LSU (.*);
  bju BJU (.*);
  alu ALU (.*);
  mdu MDU (.*);
  dummy_csr DUMMY_CSR (.*);

endmodule

`default_nettype wire
