`default_nettype none

module ysyx_24080006_core
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic instr_req_o,
    output logic [31:0] instr_addr_o,
    input logic instr_gnt_i,
    input logic instr_rvalid_i,
    input logic [31:0] instr_rdata_i,

    output logic data_req_o,
    input  logic data_gnt_i,
    input  logic data_rvalid_i,

    output logic [31:0] data_addr_o,
    output logic        data_we_o,
    output logic [ 3:0] data_be_o,
    output logic [31:0] data_wdata_o,
    input  logic [31:0] data_rdata_i,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m,

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


  logic                            fencei;
  frontend_t                       frontend_data;

  logic       [              31:0] ifu_dbg_inst;

  logic                            backend_ready;
  logic                            frontend_valid;

  logic                            retire_valid;
  logic                            retire_cf;
  logic                            retire_jump;
  logic                            retire_branch;
  logic                            retire_is_rv16;
  logic       [              31:0] retire_pc;
  logic       [              31:0] retire_dnpc;


  decoder_t                        idu2isu_instr;

  logic                            isu2idu_ready;
  logic                            idu_valid;

  bpu_t                            bpu;
  bju_t                            bju;
  fu_data_t                        fu_data;
  logic                            is_rv16;
  logic                            flu_ready;
  logic                            alu_valid;
  logic                            bju_valid;
  logic                            mdu_valid;
  logic                            csr_valid;
  logic                            lsu_ready;
  logic                            lsu_valid;

  fu_op_e                          csr_op;
  logic       [              31:0] csr_wdata;
  logic       [              31:0] csr_rdata;
  logic                            commit_csr;
  logic                            commit_lsu;

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

  logic       [              31:0] mtvec_addr;
  logic                            mret_valid;
  logic       [              31:0] mepc_addr;

  logic                            flush_frontend;
  logic                            flush_unissued_instr;
  logic                            ex_valid;
  logic                            flush_id;

  frontend IFU (.*);
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
  flush_ctrl CONTROLLER (.*);
endmodule

`default_nettype wire
