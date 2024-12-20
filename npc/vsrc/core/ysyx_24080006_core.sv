module ysyx_24080006_core
  import ysyx_24080006_pkg::*;
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

  stage_t ifu2idu, idu2exu, exu2ifu;
  logic ifu2exu_ready, exu2idu_ready, idu2ifu_ready;

  logic            fencei;  //todo
  logic     [31:0] inst;

  logic            ecall;
  logic            mret;
  csr_set_t        csr_set;
  system_e         csr_name;
  logic     [31:0] csr_pc;
  logic     [31:0] csr_wdata;
  logic     [31:0] csr_rdata;

  decoder_t        decoder;
  logic            reg_we;
  logic [REG_WIDTH-1:0] rs1_addr, rs2_addr, rd_addr;
  logic [31:0] rs1_data, rs2_data, rd_data;

  logic        forward_en;
  logic [31:0] forward_data;

  logic [31:0] idu_dbg_inst;
  logic [31:0] exu_dbg_inst;

  logic        icache_hit;
  logic        icache_miss;
  logic        icache_skip;

  ysyx_24080006_ifu IFU (.*);
  ysyx_24080006_id_stage ID (.*);
  ysyx_24080006_ex_stage EX (.*);
  ysyx_24080006_reg REG (.*);
  ysyx_24080006_csr CS (
      .*,
      .instret(exu2ifu.valid & ifu2exu_ready)
  );
endmodule
