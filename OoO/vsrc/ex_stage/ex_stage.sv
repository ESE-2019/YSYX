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
    input logic bu_valid,
    input logic mdu_valid,
    input logic csr_valid,
    //input branchpredict_sbe_t branch_predict_i,
    //output bp_resolve_t resolved_branch_o,
    //output logic resolve_branch_o,
    output logic [11:0] csr_addr,
    input logic commit_csr,
    output logic lsu_ready,
    input logic lsu_valid,
    // output logic load_valid_o,
    // output exception_t load_exception_o,
    // output logic store_valid_o,
    // output logic [CVA6Cfg.XLEN-1:0] store_result_o,
    // input logic lsu_commit_i,
    // output logic lsu_commit_ready_o,

    output writeback_t [WriteBackPorts-1:0] wb,
    output logic [31:0] branch_address,
    output logic branch_taken,

    output logic load_num,
    output logic load_cycle,
    output logic store_num,
    output logic store_cycle,

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
  assign one_cycle_select = alu_valid | bu_valid | csr_valid;

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
    wb[1].data  = lsu_rdata;
    wb[1].idx   = lsu_idx;
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
  wire [ScoreboardIndex-1:0] lsu_idx_i = fu_data.idx;


  ysyx_24080006_lsu LSU (.*);
  bu BU (.*);
  alu ALU (.*);
  mdu MDU (.*);
  dummy_csr DUMMY_CSR (.*);


// `ifdef SIM_MODE
//   import ysyx_24080006_sim_pkg::*;
//   import "DPI-C" function void SKIP_DIFFTEST();
//   import "DPI-C" function void LSU_CNT(
//     input int load_en,
//     input int cnt
//   );
//   bit [31:0] lsu_cnt = 32'b0;
//   always_ff @(posedge clock) begin
//     if (curr == EX_IDLE) lsu_cnt <= 32'h1;
//     else lsu_cnt <= lsu_cnt + 32'h1;
//     if (curr == EX_LSU && lsu2exu_valid && lsu_write) begin
//       //$display("[LSU] 0x%08x write [0x%08x] at pc 0x%08x", lsu_addr, lsu_wdata, pc);
//       LSU_CNT(0, lsu_cnt);
//       if (INSIDE_PERIP(lsu_addr)) SKIP_DIFFTEST();
//       if (!INSIDE_STORE(lsu_addr)) begin
//         $display("[LSU] store addr error 0x%08x at pc 0x%08x", lsu_addr, pc);
//         $finish;
//       end
//     end
//     if (curr == EX_LSU && lsu2exu_valid && !lsu_write) begin
//       //$display("[LSU] 0x%08x  read [0x%08x] at pc 0x%08x", lsu_addr, lsu_rdata, pc);
//       LSU_CNT(1, lsu_cnt);
//       if (INSIDE_PERIP(lsu_addr)) SKIP_DIFFTEST();
//       if (!INSIDE_LOAD(lsu_addr)) begin
//         $display("[LSU] load addr error 0x%08x at pc 0x%08x", lsu_addr, pc);
//         $finish;
//       end
//     end
//   end
// `endif
endmodule

`default_nettype wire
