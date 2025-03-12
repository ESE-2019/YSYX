module top  // use for syn
(
    input logic clock,
    input logic reset,

    input  logic        io_master_awready,
    output logic        io_master_awvalid,
    output logic [31:0] io_master_awaddr,
    output logic [ 3:0] io_master_awid,
    output logic [ 7:0] io_master_awlen,
    output logic [ 2:0] io_master_awsize,
    output logic [ 1:0] io_master_awburst,

    input  logic        io_master_wready,
    output logic        io_master_wvalid,
    output logic [31:0] io_master_wdata,
    output logic [ 3:0] io_master_wstrb,
    output logic        io_master_wlast,

    output logic       io_master_bready,
    input  logic       io_master_bvalid,
    input  logic [1:0] io_master_bresp,
    input  logic [3:0] io_master_bid,

    input  logic        io_master_arready,
    output logic        io_master_arvalid,
    output logic [31:0] io_master_araddr,
    output logic [ 3:0] io_master_arid,
    output logic [ 7:0] io_master_arlen,
    output logic [ 2:0] io_master_arsize,
    output logic [ 1:0] io_master_arburst,

    output logic        io_master_rready,
    input  logic        io_master_rvalid,
    input  logic [ 1:0] io_master_rresp,
    input  logic [31:0] io_master_rdata,
    input  logic        io_master_rlast,
    input  logic [ 3:0] io_master_rid
);

  import OoO_pkg::*;

  axi_r_m2s_t ifu_r_m2s;
  axi_r_s2m_t ifu_r_s2m;

  axi_w_m2s_t lsu_w_m2s;
  axi_w_s2m_t lsu_w_s2m;
  axi_r_m2s_t lsu_r_m2s;
  axi_r_s2m_t lsu_r_s2m;

  axi_w_m2s_t clint_w_m2s;
  axi_w_s2m_t clint_w_s2m;
  axi_r_m2s_t clint_r_m2s;
  axi_r_s2m_t clint_r_s2m;

  axi_w_m2s_t core_w_m2s;
  axi_w_s2m_t core_w_s2m;
  axi_r_m2s_t core_r_m2s;
  axi_r_s2m_t core_r_s2m;

  ysyx_24080006_core CORE (.*);
  ysyx_24080006_interconnect ITCNT (.*);
  ysyx_24080006_clint CLINT (.*);

  assign core_w_s2m.awready = io_master_awready;
  assign io_master_awvalid = core_w_m2s.awvalid;
  assign io_master_awaddr = core_w_m2s.awaddr;
  assign io_master_awid = '0;  //core_w_m2s.awid;
  assign io_master_awlen = core_w_m2s.awlen;
  assign io_master_awsize = core_w_m2s.awsize;
  assign io_master_awburst = core_w_m2s.awburst;

  assign core_w_s2m.wready = io_master_wready;
  assign io_master_wvalid = core_w_m2s.wvalid;
  assign io_master_wdata = core_w_m2s.wdata;
  assign io_master_wstrb = core_w_m2s.wstrb;
  assign io_master_wlast = core_w_m2s.wlast;

  assign io_master_bready = core_w_m2s.bready;
  assign core_w_s2m.bvalid = io_master_bvalid;
  //assign core_w_s2m.bresp = io_master_bresp;
  //assign core_w_s2m.bid = io_master_bid;

  assign core_r_s2m.arready = io_master_arready;
  assign io_master_arvalid = core_r_m2s.arvalid;
  assign io_master_araddr = core_r_m2s.araddr;
  assign io_master_arid = '0;  //core_r_m2s.arid;
  assign io_master_arlen = core_r_m2s.arlen;
  assign io_master_arsize = core_r_m2s.arsize;
  assign io_master_arburst = core_r_m2s.arburst;

  assign io_master_rready = core_r_m2s.rready;
  assign core_r_s2m.rvalid = io_master_rvalid;
  //assign core_r_s2m.rresp = io_master_rresp;
  assign core_r_s2m.rdata = io_master_rdata;
  assign core_r_s2m.rlast = io_master_rlast;
  //assign core_r_s2m.rid = io_master_rid;

endmodule
