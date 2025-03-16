`default_nettype none

module ysyx_24080006_core
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m
);


  logic                            fencei;
  logic       [              31:0] inst;
  logic       [              31:0] id_pc;

  logic       [              31:0] ifu_dbg_inst;

  logic                            idu2ifu_ready;
  logic                            ifu2idu_valid;

  logic                            retire_valid;
  logic                            retire_cf;
  logic                            retire_jump;
  logic                            retire_branch;
  logic                            retire_is_rv16;
  logic       [              31:0] retire_pc;
  logic       [              31:0] retire_dnpc;


  decoder_t                        idu2isu_instr;

  logic                            isu2idu_ready;
  logic                            idu2isu_valid;

  fu_data_t                        fu_data;
  logic                            is_rv16;
  logic                            flu_ready;
  logic                            alu_valid;
  logic                            bu_valid;
  logic                            mdu_valid;
  logic                            csr_valid;
  logic                            lsu_ready;
  logic                            lsu_valid;

  fu_op_e                          csr_op;
  logic       [              31:0] csr_wdata;
  logic       [              31:0] csr_rdata;
  logic                            commit_csr;

  writeback_t [WriteBackPorts-1:0] wb;

  logic       [              11:0] csr_addr;

  logic                            ecall;
  logic                            mret;

  logic       [              31:0] ex_pc;
  logic       [              31:0] csr_pc;

  logic       [              31:0] branch_address;
  logic                            branch_taken;

  logic                            icache_hit;
  logic                            icache_miss;
  logic                            icache_skip;
  logic                            load_num;
  logic                            load_cycle;
  logic                            store_num;
  logic                            store_cycle;
  logic                            is_compressed;
  logic                            fetch_cycle;

  if_stage IFU (.*);
  id_stage IDU (.*);
  issue_stage ISU (
      .*,
      .pc(ex_pc)
  );
  ex_stage EX (
      .*,
      .pc(ex_pc)
  );
  csr_regfile CSRF (
      .*,
      .instret(retire_valid)  //exu2ifu.valid & ifu2exu_ready)
  );
endmodule

`default_nettype wire
