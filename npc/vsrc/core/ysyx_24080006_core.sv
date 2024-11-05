module ysyx_24080006_core
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic    [IC_N-1:0] ic_index,
    input  icache_t            ic_rdata,
    output logic               ic_we,
    output icache_t            ic_wdata,

    ysyx_24080006_axi.master axi
);

  stage_t ifu2idu, idu2exu, exu2lsu, lsu2wbu, wbu2ifu;
  logic ifu2wbu_ready, idu2ifu_ready, exu2idu_ready, lsu2exu_ready, wbu2lsu_ready;

  logic   exu2ifu_ready;
  logic   ifu2exu_ready;
  stage_t exu2ifu;
  stage_t ifu2exu;

  ysyx_24080006_axi axi_ifu (), axi_icache (), axi_lsu ();
  // ysyx_24080006_arb ARB (
  //     .*,
  //     .axi_ifu(axi_icache)
  // );
  // ysyx_24080006_icache ICACHE (.*);

  ysyx_24080006_arb ARB (.*);
  ysyx_24080006_if_stage IF (.*);
  ysyx_24080006_ex_stage EX (.*);
  // logic                 reg_we;
  // logic [REG_WIDTH-1:0] rs1_addr;
  // logic [REG_WIDTH-1:0] rs2_addr;
  // logic [REG_WIDTH-1:0] rd;
  // logic [         31:0] wdata;
  // logic [         31:0] rs1_val;
  // logic [         31:0] rs2_val;

  // logic                 csr_we;
  // logic [         31:0] mepc_val;
  // logic                 mepc_en;
  // logic [         11:0] csr_addr;
  // logic [         11:0] csr_waddr;
  // logic [         31:0] csr_wdata;
  // logic [         31:0] csr_rdata;

  // ysyx_24080006_reg REG (.*);

  // ysyx_24080006_csr CSR (.*);

  // ysyx_24080006_idu IDU (.*);

  // ysyx_24080006_exu EXU (.*);

  // ysyx_24080006_lsu LSU (.*);

  // ysyx_24080006_wbu WBU (.*);


endmodule
