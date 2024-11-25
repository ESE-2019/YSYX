module npc_xbar
  import ysyx_24080006_pkg::*;
(
    input clock,
    input reset,

    input  axi_w_m2s_t imd_w_m2s,
    output axi_w_s2m_t imd_w_s2m,
    input  axi_r_m2s_t imd_r_m2s,
    output axi_r_s2m_t imd_r_s2m,

    output axi_w_m2s_t core_w_m2s,
    input  axi_w_s2m_t core_w_s2m,
    output axi_r_m2s_t core_r_m2s,
    input  axi_r_s2m_t core_r_s2m,

    output axi_w_m2s_t sram_w_m2s,
    input  axi_w_s2m_t sram_w_s2m,
    output axi_r_m2s_t sram_r_m2s,
    input  axi_r_s2m_t sram_r_s2m
);


  // write channel
  assign imd_w_s2m.awready = imd_w_m2s.awaddr >= 32'h8000_0000 ? sram_w_s2m.awready : core_w_s2m.awready;
  assign sram_w_m2s.awvalid = imd_w_m2s.awaddr >= 32'h8000_0000 ? imd_w_m2s.awvalid : 0;
  assign core_w_m2s.awvalid = imd_w_m2s.awaddr < 32'h8000_0000 ? imd_w_m2s.awvalid : 0;
  assign sram_w_m2s.awaddr = imd_w_m2s.awaddr;
  assign sram_w_m2s.awid = imd_w_m2s.awid;
  assign sram_w_m2s.awlen = imd_w_m2s.awlen;
  assign sram_w_m2s.awsize = imd_w_m2s.awsize;
  assign sram_w_m2s.awburst = imd_w_m2s.awburst;
  assign core_w_m2s.awaddr = imd_w_m2s.awaddr;
  assign core_w_m2s.awid = imd_w_m2s.awid;
  assign core_w_m2s.awlen = imd_w_m2s.awlen;
  assign core_w_m2s.awsize = imd_w_m2s.awsize;
  assign core_w_m2s.awburst = imd_w_m2s.awburst;

  assign imd_w_s2m.wready = imd_w_m2s.awaddr >= 32'h8000_0000 ? sram_w_s2m.wready : core_w_s2m.wready;
  assign sram_w_m2s.wvalid = imd_w_m2s.awaddr >= 32'h8000_0000 ? imd_w_m2s.wvalid : 0;
  assign core_w_m2s.wvalid = imd_w_m2s.awaddr < 32'h8000_0000 ? imd_w_m2s.wvalid : 0;
  assign sram_w_m2s.wdata = imd_w_m2s.wdata;
  assign sram_w_m2s.wstrb = imd_w_m2s.wstrb;
  assign sram_w_m2s.wlast = imd_w_m2s.wlast;
  assign core_w_m2s.wdata = imd_w_m2s.wdata;
  assign core_w_m2s.wstrb = imd_w_m2s.wstrb;
  assign core_w_m2s.wlast = imd_w_m2s.wlast;

  assign sram_w_m2s.bready = imd_w_m2s.awaddr >= 32'h8000_0000 ? imd_w_m2s.bready : 0;
  assign core_w_m2s.bready = imd_w_m2s.awaddr < 32'h8000_0000 ? imd_w_m2s.bready : 0;
  assign imd_w_s2m.bvalid = imd_w_m2s.awaddr >= 32'h8000_0000 ? sram_w_s2m.bvalid : core_w_s2m.bvalid;

  // read channel
  assign imd_r_s2m.arready = imd_r_m2s.araddr >= 32'h8000_0000 ? sram_r_s2m.arready : core_r_s2m.arready;
  assign sram_r_m2s.arvalid = imd_r_m2s.araddr >= 32'h8000_0000 ? imd_r_m2s.arvalid : 0;
  assign core_r_m2s.arvalid = imd_r_m2s.araddr < 32'h8000_0000 ? imd_r_m2s.arvalid : 0;
  assign sram_r_m2s.araddr = imd_r_m2s.araddr;
  assign sram_r_m2s.arid = imd_r_m2s.arid;
  assign sram_r_m2s.arlen = imd_r_m2s.arlen;
  assign sram_r_m2s.arsize = imd_r_m2s.arsize;
  assign sram_r_m2s.arburst = imd_r_m2s.arburst;
  assign core_r_m2s.araddr = imd_r_m2s.araddr;
  assign core_r_m2s.arid = imd_r_m2s.arid;
  assign core_r_m2s.arlen = imd_r_m2s.arlen;
  assign core_r_m2s.arsize = imd_r_m2s.arsize;
  assign core_r_m2s.arburst = imd_r_m2s.arburst;

  assign sram_r_m2s.rready = imd_r_m2s.araddr >= 32'h8000_0000 ? imd_r_m2s.rready : 0;
  assign core_r_m2s.rready = imd_r_m2s.araddr < 32'h8000_0000 ? imd_r_m2s.rready : 0;
  assign imd_r_s2m.rvalid = imd_r_m2s.araddr >= 32'h8000_0000 ? sram_r_s2m.rvalid : core_r_s2m.rvalid;
  assign imd_r_s2m.rdata = imd_r_m2s.araddr >= 32'h8000_0000 ? sram_r_s2m.rdata : core_r_s2m.rdata;
  assign imd_r_s2m.rlast = imd_r_m2s.araddr >= 32'h8000_0000 ? sram_r_s2m.rlast : core_r_s2m.rlast;

endmodule
