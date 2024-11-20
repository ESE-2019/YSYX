module ysyx_24080006_core
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    ysyx_24080006_axi.master axi
);

  stage_t ifu2idu, idu2exu, exu2lsu, lsu2wbu, wbu2ifu;
  logic ifu2wbu_ready, idu2ifu_ready, exu2idu_ready, lsu2exu_ready, wbu2lsu_ready;

  logic fencei;  //todo
  logic [31:0] inst;
  logic exu2ifu_ready;
  logic ifu2exu_ready;
  stage_t exu2ifu;
  stage_t ifu2exu;

  logic ecall;
  logic mret;
  csr_set_t csr_set;
  csr_name_e csr_name;
  logic [31:0] csr_pc;
  logic [31:0] csr_wdata;
  logic [31:0] csr_rdata;

  ysyx_24080006_axi axi_ifu (), axi_lsu ();
  decoder_t decoder;
  logic     reg_we;
  logic [REG_WIDTH-1:0] rs1_addr, rs2_addr, rd_addr;
  logic [31:0] rs1_data, rs2_data, rd_data;

  ysyx_24080006_arb ARB (.*);
  ysyx_24080006_ifu IFU (.*);
  ysyx_24080006_id_stage ID (.*);
  ysyx_24080006_ex_stage EX (.*);
  ysyx_24080006_reg REG (.*);
  ysyx_24080006_csr CS (.*);
endmodule
