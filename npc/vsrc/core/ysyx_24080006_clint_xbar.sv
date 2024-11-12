module ysyx_24080006_clint_xbar (
    ysyx_24080006_axi.slave  axi,
    ysyx_24080006_axi.master axi_soc,
    ysyx_24080006_axi.master axi_clint
);

  // write channel
  assign axi.awready = axi.awaddr >= 32'h0200_ffff ? axi_soc.awready : axi_clint.awready;
  assign axi_soc.awvalid = axi.awaddr >= 32'h0200_ffff ? axi.awvalid : 0;
  assign axi_clint.awvalid = axi.awaddr < 32'h0200_ffff ? axi.awvalid : 0;
  assign axi_soc.awaddr = axi.awaddr;
  assign axi_soc.awid = axi.awid;
  assign axi_soc.awlen = axi.awlen;
  assign axi_soc.awsize = axi.awsize;
  assign axi_soc.awburst = axi.awburst;
  assign axi_clint.awaddr = axi.awaddr;
  assign axi_clint.awid = axi.awid;
  assign axi_clint.awlen = axi.awlen;
  assign axi_clint.awsize = axi.awsize;
  assign axi_clint.awburst = axi.awburst;

  assign axi.wready = axi.awaddr >= 32'h0200_ffff ? axi_soc.wready : axi_clint.wready;
  assign axi_soc.wvalid = axi.awaddr >= 32'h0200_ffff ? axi.wvalid : 0;
  assign axi_clint.wvalid = axi.awaddr < 32'h0200_ffff ? axi.wvalid : 0;
  assign axi_soc.wdata = axi.wdata;
  assign axi_soc.wstrb = axi.wstrb;
  assign axi_soc.wlast = axi.wlast;
  assign axi_clint.wdata = axi.wdata;
  assign axi_clint.wstrb = axi.wstrb;
  assign axi_clint.wlast = axi.wlast;

  assign axi_soc.bready = axi.awaddr >= 32'h0200_ffff ? axi.bready : 0;
  assign axi_clint.bready = axi.awaddr < 32'h0200_ffff ? axi.bready : 0;
  assign axi.bvalid = axi.awaddr >= 32'h0200_ffff ? axi_soc.bvalid : axi_clint.bvalid;

  // read channel
  assign axi.arready = axi.araddr >= 32'h0200_ffff ? axi_soc.arready : axi_clint.arready;
  assign axi_soc.arvalid = axi.araddr >= 32'h0200_ffff ? axi.arvalid : 0;
  assign axi_clint.arvalid = axi.araddr < 32'h0200_ffff ? axi.arvalid : 0;
  assign axi_soc.araddr = axi.araddr;
  assign axi_soc.arid = axi.arid;
  assign axi_soc.arlen = axi.arlen;
  assign axi_soc.arsize = axi.arsize;
  assign axi_soc.arburst = axi.arburst;
  assign axi_clint.araddr = axi.araddr;
  assign axi_clint.arid = axi.arid;
  assign axi_clint.arlen = axi.arlen;
  assign axi_clint.arsize = axi.arsize;
  assign axi_clint.arburst = axi.arburst;

  assign axi_soc.rready = axi.araddr >= 32'h0200_ffff ? axi.rready : 0;
  assign axi_clint.rready = axi.araddr < 32'h0200_ffff ? axi.rready : 0;
  assign axi.rvalid = axi.araddr >= 32'h0200_ffff ? axi_soc.rvalid : axi_clint.rvalid;
  assign axi.rdata = axi.araddr >= 32'h0200_ffff ? axi_soc.rdata : axi_clint.rdata;
  assign axi.rlast = axi.araddr >= 32'h0200_ffff ? axi_soc.rlast : axi_clint.rlast;

endmodule
