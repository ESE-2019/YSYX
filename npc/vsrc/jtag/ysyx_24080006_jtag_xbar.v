module ysyx_24080006_jtag_xbar (
    ysyx_24080006_axi.slave  axi,
    ysyx_24080006_axi.master axi_soc,
    ysyx_24080006_axi.master axi_jtag
);

  // write channel
  assign axi.awready = axi.awaddr >= 32'h0200_0000 ? axi_soc.awready : axi_jtag.awready;
  assign axi_soc.awvalid = axi.awaddr >= 32'h0200_0000 ? axi.awvalid : 0;
  assign axi_jtag.awvalid = axi.awaddr < 32'h0200_0000 ? axi.awvalid : 0;
  assign axi_soc.awaddr = axi.awaddr;
  assign axi_soc.awid = axi.awid;
  assign axi_soc.awlen = axi.awlen;
  assign axi_soc.awsize = axi.awsize;
  assign axi_soc.awburst = axi.awburst;
  assign axi_jtag.awaddr = axi.awaddr;
  assign axi_jtag.awid = axi.awid;
  assign axi_jtag.awlen = axi.awlen;
  assign axi_jtag.awsize = axi.awsize;
  assign axi_jtag.awburst = axi.awburst;

  assign axi.wready = axi.awaddr >= 32'h0200_0000 ? axi_soc.wready : axi_jtag.wready;
  assign axi_soc.wvalid = axi.awaddr >= 32'h0200_0000 ? axi.wvalid : 0;
  assign axi_jtag.wvalid = axi.awaddr < 32'h0200_0000 ? axi.wvalid : 0;
  assign axi_soc.wdata = axi.wdata;
  assign axi_soc.wstrb = axi.wstrb;
  assign axi_soc.wlast = axi.wlast;
  assign axi_jtag.wdata = axi.wdata;
  assign axi_jtag.wstrb = axi.wstrb;
  assign axi_jtag.wlast = axi.wlast;

  assign axi_soc.bready = axi.awaddr >= 32'h0200_0000 ? axi.bready : 0;
  assign axi_jtag.bready = axi.awaddr < 32'h0200_0000 ? axi.bready : 0;
  assign axi.bvalid = axi.awaddr >= 32'h0200_0000 ? axi_soc.bvalid : axi_jtag.bvalid;
  //assign axi.bresp = axi.bresp;
  //assign axi.bid = axi.bid;


  // read channel
  assign axi.rlast = axi.araddr >= 32'h0200_0000 ? axi_soc.rlast : axi_jtag.rlast;
  assign axi.arready = axi.araddr >= 32'h0200_0000 ? axi_soc.arready : axi_jtag.arready;
  assign axi_soc.arvalid = axi.araddr >= 32'h0200_0000 ? axi.arvalid : 0;
  assign axi_jtag.arvalid = axi.araddr < 32'h0200_0000 ? axi.arvalid : 0;
  assign axi_soc.araddr = axi.araddr;
  assign axi_soc.arid = axi.arid;
  assign axi_soc.arlen = axi.arlen;
  assign axi_soc.arsize = axi.arsize;
  assign axi_soc.arburst = axi.arburst;
  assign axi_jtag.araddr = axi.araddr;
  assign axi_jtag.arid = axi.arid;
  assign axi_jtag.arlen = axi.arlen;
  assign axi_jtag.arsize = axi.arsize;
  assign axi_jtag.arburst = axi.arburst;

  assign axi_soc.rready = axi.araddr >= 32'h0200_0000 ? axi.rready : 0;
  assign axi_jtag.rready = axi.araddr < 32'h0200_0000 ? axi.rready : 0;
  assign axi.rvalid = axi.araddr >= 32'h0200_0000 ? axi_soc.rvalid : axi_jtag.rvalid;
  assign axi.rdata = axi.araddr >= 32'h0200_0000 ? axi_soc.rdata : axi_jtag.rdata;

endmodule

// module ysyx_24080006_xbar(
//     input clock,
//     input reset,
//     ysyx_24080006_axi.slave  axi_ifu,
//     ysyx_24080006_axi.slave  axi_lsu,
//     ysyx_24080006_axi.master axi_soc,
//     ysyx_24080006_axi.master axi_jtag
//     );

//     //write channel
//     assign axi_lsu.awready = axi.awready;
//     assign axi.awvalid     = axi_lsu.awvalid;
//     assign axi.awaddr      = axi_lsu.awaddr;
//     assign axi.awid        = axi_lsu.awid;
//     assign axi.awlen       = axi_lsu.awlen;
//     assign axi.awsize      = axi_lsu.awsize;
//     assign axi.awburst     = axi_lsu.awburst;

//     assign axi_lsu.wready  = axi.wready;
//     assign axi.wvalid      = axi_lsu.wvalid;
//     assign axi.wdata       = axi_lsu.wdata;
//     assign axi.wstrb       = axi_lsu.wstrb;
//     assign axi.wlast       = axi_lsu.wlast;

//     assign axi.bready      = axi_lsu.bready;
//     assign axi_lsu.bvalid  = axi.bvalid;
//     assign axi_lsu.bresp   = axi.bresp;
//     assign axi_lsu.bid     = axi.bid;

//     //read channel
//     enum {
//         IDLE,
//         IFU_READ_SRAM,
//         LSU_READ_SRAM,
//         LSU_READ_SOC
//     } curr_read, next_read;

//     always_ff @ (posedge clock) begin //fsm 1
//         if (reset) begin
//             curr_read <= IDLE;
//         end
//         else begin
//             curr_read <= next_read;
//         end
//     end

//     always_comb begin // fsm 2
//         unique case (curr_read)
//             IDLE: begin
//                 if (axi_lsu.arvalid) begin //  || axi_lsu.rvalid
//                     if (axi_lsu.araddr >= 32'h0200_0000) begin
//                         next_read = LSU_READ_SRAM;
//                     end else begin
//                         next_read = LSU_READ_SOC;
//                     end
//                 end else if (axi_ifu.arvalid) begin //  || axi_ifu.rvalid
//                     next_read = IFU_READ_SRAM;
//                 end else begin
//                     next_read = IDLE;
//                 end
//             end
//             LSU_READ_SRAM,
//             LSU_READ_SOC: begin
//                 if (axi_lsu.rready && axi_lsu.rvalid) // && axi_lsu.rlast
//                     next_read = IDLE;
//                 else
//                     next_read = curr_read;
//             end
//             IFU_READ_SRAM: begin
//                 if (axi_ifu.rready && axi_ifu.rvalid) // && axi_ifu.rlast
//                     next_read = IDLE;
//                 else
//                     next_read = IFU_READ_SRAM;
//             end
//         endcase
//     end

//     always_comb begin
//         unique case (curr_read)
//             IDLE: begin
//                 axi.arvalid = 0;
//                 axi.rready  = 0;
//             end
//             LSUR: begin
//                 axi.arvalid = axi_lsu.arvalid;
//                 axi.rready  = axi_lsu.rready;
//             end
//             IFUR: begin
//                 axi.arvalid = axi_ifu.arvalid;
//                 axi.rready  = axi_ifu.rready;
//             end
//         endcase
//     end

//     assign axi_ifu.rresp   = axi.rresp;
//     assign axi_ifu.rdata   = axi.rdata;
//     assign axi_ifu.rlast   = axi.rlast;
//     assign axi_ifu.rid     = axi.rid;

//     assign axi_lsu.rresp   = axi.rresp;
//     assign axi_lsu.rdata   = axi.rdata;
//     assign axi_lsu.rlast   = axi.rlast;
//     assign axi_lsu.rid     = axi.rid;

// endmodule
