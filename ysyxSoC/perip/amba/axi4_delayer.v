module axi4_delayer (
    input logic clock,
    input logic reset,

    output logic        in_arready,
    input  logic        in_arvalid,
    input  logic [ 3:0] in_arid,
    input  logic [31:0] in_araddr,
    input  logic [ 7:0] in_arlen,
    input  logic [ 2:0] in_arsize,
    input  logic [ 1:0] in_arburst,
    input  logic        in_rready,
    output logic        in_rvalid,
    output logic [ 3:0] in_rid,
    output logic [31:0] in_rdata,
    output logic [ 1:0] in_rresp,
    output logic        in_rlast,
    output logic        in_awready,
    input  logic        in_awvalid,
    input  logic [ 3:0] in_awid,
    input  logic [31:0] in_awaddr,
    input  logic [ 7:0] in_awlen,
    input  logic [ 2:0] in_awsize,
    input  logic [ 1:0] in_awburst,
    output logic        in_wready,
    input  logic        in_wvalid,
    input  logic [31:0] in_wdata,
    input  logic [ 3:0] in_wstrb,
    input  logic        in_wlast,
    input  logic        in_bready,
    output logic        in_bvalid,
    output logic [ 3:0] in_bid,
    output logic [ 1:0] in_bresp,

    input  logic        out_arready,
    output logic        out_arvalid,
    output logic [ 3:0] out_arid,
    output logic [31:0] out_araddr,
    output logic [ 7:0] out_arlen,
    output logic [ 2:0] out_arsize,
    output logic [ 1:0] out_arburst,
    output logic        out_rready,
    input  logic        out_rvalid,
    input  logic [ 3:0] out_rid,
    input  logic [31:0] out_rdata,
    input  logic [ 1:0] out_rresp,
    input  logic        out_rlast,
    input  logic        out_awready,
    output logic        out_awvalid,
    output logic [ 3:0] out_awid,
    output logic [31:0] out_awaddr,
    output logic [ 7:0] out_awlen,
    output logic [ 2:0] out_awsize,
    output logic [ 1:0] out_awburst,
    input  logic        out_wready,
    output logic        out_wvalid,
    output logic [31:0] out_wdata,
    output logic [ 3:0] out_wstrb,
    output logic        out_wlast,
    output logic        out_bready,
    input  logic        out_bvalid,
    input  logic [ 3:0] out_bid,
    input  logic [ 1:0] out_bresp
);
  import ysyx_24080006_pkg::*;
  localparam axi_s = 32'h100;  // ratio
  assign in_arready = out_arready;
  assign out_arvalid = in_arvalid;
  assign out_arid = in_arid;
  assign out_araddr = in_araddr;
  assign out_arlen = in_arlen;
  assign out_arsize = in_arsize;
  assign out_arburst = in_arburst;
  assign out_rready = in_rready;
  
  //assign in_rvalid = out_rvalid;
  assign in_rid = out_rid;
  assign in_rdata = out_rdata;
  assign in_rresp = out_rresp;
  assign in_rlast = out_rlast;
  assign in_awready = out_awready;
  assign out_awvalid = in_awvalid;
  assign out_awid = in_awid;
  assign out_awaddr = in_awaddr;
  assign out_awlen = in_awlen;
  assign out_awsize = in_awsize;
  assign out_awburst = in_awburst;
  assign in_wready = out_wready;
  assign out_wvalid = in_wvalid;
  assign out_wdata = in_wdata;
  assign out_wstrb = in_wstrb;
  assign out_wlast = in_wlast;
  assign out_bready = in_bready;
  
  //assign in_bvalid = out_bvalid;
  assign in_bid = out_bid;
  assign in_bresp = out_bresp;

`ifdef NPC_MODE
  assign in_rvalid = out_rvalid;
`else
  logic read;
  always_latch begin
    if (reset) read = 0;
    else if (in_arvalid) read = 1;
    else if (out_rvalid & in_rready & out_rlast) read = 0;
  end
  logic [31:0] cnt_before, cnt_after;
  always_ff @(posedge clock) begin
    if (reset) cnt_before <= 0;
    else if (read) begin
      if (out_rvalid & in_rready) cnt_before <= 1;
      else if (out_rvalid) cnt_before <= cnt_before;
      else cnt_before <= cnt_before + 1;
    end else cnt_before <= 0;
  end
  always_ff @(posedge clock) begin
    if (reset) begin
      cnt_after <= axi_s;
      in_rvalid <= 0;
    end else if (read & out_rvalid) begin
      if (in_rready) cnt_after <= axi_s;
      else cnt_after <= cnt_after + axi_s;
      if (in_rready) in_rvalid <= 0;
      else if (cnt_after >= cnt_before * (DELAYER - 1) * axi_s) in_rvalid <= 1;
      else in_rvalid <= 0;
    end else begin
      cnt_after <= axi_s;
      in_rvalid <= 0;
    end
  end
`endif

`ifdef NPC_MODE
  assign in_bvalid = out_bvalid;
`else
  logic write;
  always_latch begin
    if (reset) write = 0;
    else if (in_awvalid) write = 1;
    else if (out_bvalid & in_bready) write = 0;
  end

  logic [31:0] cnt_before_1, cnt_after_1;
  always_ff @(posedge clock) begin
    if (reset) cnt_before_1 <= 0;
    else if (write) begin
      if (out_bvalid) cnt_before_1 <= cnt_before_1;
      else cnt_before_1 <= cnt_before_1 + 1;
    end else cnt_before_1 <= 0;
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      cnt_after_1 <= axi_s;
      in_bvalid   <= 0;
    end else if (write & out_bvalid) begin
      cnt_after_1 <= cnt_after_1 + axi_s;
      if (cnt_after_1 >= cnt_before_1 * (DELAYER - 1) * axi_s) in_bvalid <= 1;
      else in_bvalid <= 0;
    end else begin
      cnt_after_1 <= axi_s;
      in_bvalid   <= 0;
    end
  end
`endif

endmodule
