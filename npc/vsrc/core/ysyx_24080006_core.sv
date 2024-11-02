module ysyx_24080006_core (
    input logic clock,
    input logic reset,
    ysyx_24080006_axi.master axi
);
  import ysyx_24080006_pkg::*;
  stage_t ifu2idu, idu2exu, exu2lsu, lsu2wbu, wbu2ifu;
  logic ifu2wbu_ready, idu2ifu_ready, exu2idu_ready, lsu2exu_ready, wbu2lsu_ready;

  ysyx_24080006_axi axi_ifu (), axi_lsu ();
  ysyx_24080006_arb ARB (.*);

  logic        we;
  logic [ 4:0] rs1_addr;
  logic [ 4:0] rs2_addr;
  logic [ 4:0] rd;
  logic [31:0] wdata;
  logic [31:0] rs1_val;
  logic [31:0] rs2_val;

  logic        csr_we;
  logic [31:0] mepc_val;
  logic        mepc_en;
  logic [11:0] csr_addr;
  logic [11:0] csr_waddr;
  logic [31:0] csr_wdata;
  logic [31:0] csr_rdata;

  ysyx_24080006_reg REG (.*);

  ysyx_24080006_csr CSR (.*);

  ysyx_24080006_ifu IFU (.*);

  ysyx_24080006_idu IDU (.*);

  ysyx_24080006_exu EXU (.*);

  ysyx_24080006_lsu LSU (.*);

  ysyx_24080006_wbu WBU (.*);

endmodule
