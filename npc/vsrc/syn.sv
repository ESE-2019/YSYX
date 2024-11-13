// use for syn
module top
  import ysyx_24080006_pkg::*;
(
    input  logic        clock,
    input  logic        reset,
    input  logic        io_interrupt,
    // AXI4 Master Interface
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

  //axi
  ysyx_24080006_axi axi (), axi_core (), axi_clint ();
  ysyx_24080006_core CORE (
      .*,
      .axi(axi_core)
  );
  ysyx_24080006_clint_xbar CLINT_XBAR (
      .axi(axi_core),
      .axi_soc(axi),
      .axi_clint(axi_clint)
  );
  ysyx_24080006_clint CLINT (.*);

  // Connect master signals to the AXI interface using assign statements
  assign axi.awready = io_master_awready;
  assign io_master_awvalid = axi.awvalid;
  assign io_master_awaddr = axi.awaddr;
  assign io_master_awid = axi.awid;
  assign io_master_awlen = axi.awlen;
  assign io_master_awsize = axi.awsize;
  assign io_master_awburst = axi.awburst;

  assign axi.wready = io_master_wready;
  assign io_master_wvalid = axi.wvalid;
  assign io_master_wdata = axi.wdata;
  assign io_master_wstrb = axi.wstrb;
  assign io_master_wlast = axi.wlast;

  assign io_master_bready = axi.bready;
  assign axi.bvalid = io_master_bvalid;
  assign axi.bresp = io_master_bresp;
  assign axi.bid = io_master_bid;

  assign axi.arready = io_master_arready;
  assign io_master_arvalid = axi.arvalid;
  assign io_master_araddr = axi.araddr;
  assign io_master_arid = axi.arid;
  assign io_master_arlen = axi.arlen;
  assign io_master_arsize = axi.arsize;
  assign io_master_arburst = axi.arburst;

  assign io_master_rready = axi.rready;
  assign axi.rvalid = io_master_rvalid;
  assign axi.rresp = io_master_rresp;
  assign axi.rdata = io_master_rdata;
  assign axi.rlast = io_master_rlast;
  assign axi.rid = io_master_rid;


endmodule
