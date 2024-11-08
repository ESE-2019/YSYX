module AXI4Xbar (
    input         clock,
    reset,
    output        auto_in_awready,
    input         auto_in_awvalid,
    input  [ 3:0] auto_in_awid,
    input  [31:0] auto_in_awaddr,
    input  [ 7:0] auto_in_awlen,
    input  [ 2:0] auto_in_awsize,
    input  [ 1:0] auto_in_awburst,
    output        auto_in_wready,
    input         auto_in_wvalid,
    input  [31:0] auto_in_wdata,
    input  [ 3:0] auto_in_wstrb,
    input         auto_in_wlast,
    auto_in_bready,
    output        auto_in_bvalid,
    output [ 3:0] auto_in_bid,
    output [ 1:0] auto_in_bresp,
    output        auto_in_arready,
    input         auto_in_arvalid,
    input  [ 3:0] auto_in_arid,
    input  [31:0] auto_in_araddr,
    input  [ 7:0] auto_in_arlen,
    input  [ 2:0] auto_in_arsize,
    input  [ 1:0] auto_in_arburst,
    input         auto_in_rready,
    output        auto_in_rvalid,
    output [ 3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [ 1:0] auto_in_rresp,
    output        auto_in_rlast,
    input         auto_out_awready,
    output        auto_out_awvalid,
    output [ 3:0] auto_out_awid,
    output [31:0] auto_out_awaddr,
    output [ 7:0] auto_out_awlen,
    output [ 2:0] auto_out_awsize,
    output [ 1:0] auto_out_awburst,
    input         auto_out_wready,
    output        auto_out_wvalid,
    output [31:0] auto_out_wdata,
    output [ 3:0] auto_out_wstrb,
    output        auto_out_wlast,
    auto_out_bready,
    input         auto_out_bvalid,
    input  [ 3:0] auto_out_bid,
    input  [ 1:0] auto_out_bresp,
    input         auto_out_arready,
    output        auto_out_arvalid,
    output [ 3:0] auto_out_arid,
    output [31:0] auto_out_araddr,
    output [ 7:0] auto_out_arlen,
    output [ 2:0] auto_out_arsize,
    output [ 1:0] auto_out_arburst,
    output        auto_out_rready,
    input         auto_out_rvalid,
    input  [ 3:0] auto_out_rid,
    input  [31:0] auto_out_rdata,
    input  [ 1:0] auto_out_rresp,
    input         auto_out_rlast
);
  assign auto_in_awready = auto_out_awready;
  assign auto_in_wready = auto_out_wready;
  assign auto_in_bvalid = auto_out_bvalid;
  assign auto_in_bid = auto_out_bid;
  assign auto_in_bresp = auto_out_bresp;
  assign auto_in_arready = auto_out_arready;
  assign auto_in_rvalid = auto_out_rvalid;
  assign auto_in_rid = auto_out_rid;
  assign auto_in_rdata = auto_out_rdata;
  assign auto_in_rresp = auto_out_rresp;
  assign auto_in_rlast = auto_out_rlast;
  assign auto_out_awvalid = auto_in_awvalid;
  assign auto_out_awid = auto_in_awid;
  assign auto_out_awaddr = auto_in_awaddr;
  assign auto_out_awlen = auto_in_awlen;
  assign auto_out_awsize = auto_in_awsize;
  assign auto_out_awburst = auto_in_awburst;
  assign auto_out_wvalid = auto_in_wvalid;
  assign auto_out_wdata = auto_in_wdata;
  assign auto_out_wstrb = auto_in_wstrb;
  assign auto_out_wlast = auto_in_wlast;
  assign auto_out_bready = auto_in_bready;
  assign auto_out_arvalid = auto_in_arvalid;
  assign auto_out_arid = auto_in_arid;
  assign auto_out_araddr = auto_in_araddr;
  assign auto_out_arlen = auto_in_arlen;
  assign auto_out_arsize = auto_in_arsize;
  assign auto_out_arburst = auto_in_arburst;
  assign auto_out_rready = auto_in_rready;
endmodule
module ram_2x2 (
    input        R0_addr,
    R0_en,
    R0_clk,
    output [1:0] R0_data,
    input        W0_addr,
    W0_en,
    W0_clk,
    input  [1:0] W0_data
);
  reg [1:0] Memory[0:1];
  always @(posedge W0_clk) begin
    if (W0_en & 1'h1) Memory[W0_addr] <= W0_data;
  end
  reg [31:0] _RANDOM_MEM;
  initial begin
  end
  assign R0_data = R0_en ? Memory[R0_addr] : 2'bx;
endmodule
module Queue2_UInt2 (
    input        clock,
    reset,
    output       io_enq_ready,
    input        io_enq_valid,
    input  [1:0] io_enq_bits,
    input        io_deq_ready,
    output       io_deq_valid,
    output [1:0] io_deq_bits
);
  wire [1:0] _ram_ext_R0_data;
  reg        wrap;
  reg        wrap_1;
  reg        maybe_full;
  wire       ptr_match = wrap == wrap_1;
  wire       empty = ptr_match & ~maybe_full;
  wire       full = ptr_match & maybe_full;
  wire       io_deq_valid_0 = io_enq_valid | ~empty;
  wire       do_deq = ~empty & io_deq_ready & io_deq_valid_0;
  wire       do_enq = ~(empty & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (reset) begin
      wrap <= 1'h0;
      wrap_1 <= 1'h0;
      maybe_full <= 1'h0;
    end else begin
      if (do_enq) wrap <= wrap - 1'h1;
      if (do_deq) wrap_1 <= wrap_1 - 1'h1;
      if (~(do_enq == do_deq)) maybe_full <= do_enq;
    end
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:0];
  end
  ram_2x2 ram_ext (
      .R0_addr(wrap_1),
      .R0_en  (1'h1),
      .R0_clk (clock),
      .R0_data(_ram_ext_R0_data),
      .W0_addr(wrap),
      .W0_en  (do_enq),
      .W0_clk (clock),
      .W0_data(io_enq_bits)
  );
  assign io_enq_ready = ~full;
  assign io_deq_valid = io_deq_valid_0;
  assign io_deq_bits  = empty ? io_enq_bits : _ram_ext_R0_data;
endmodule
module AXI4Xbar_1 (
    input clock,
    reset,
    output auto_in_awready,
    input auto_in_awvalid,
    input [3:0] auto_in_awid,
    input [31:0] auto_in_awaddr,
    input [2:0] auto_in_awsize,
    output auto_in_wready,
    input auto_in_wvalid,
    input [31:0] auto_in_wdata,
    input [3:0] auto_in_wstrb,
    input auto_in_wlast,
    auto_in_bready,
    output auto_in_bvalid,
    output [3:0] auto_in_bid,
    output [1:0] auto_in_bresp,
    output auto_in_arready,
    input auto_in_arvalid,
    input [3:0] auto_in_arid,
    input [31:0] auto_in_araddr,
    input [2:0] auto_in_arsize,
    input auto_in_rready,
    output auto_in_rvalid,
    output [3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [1:0] auto_in_rresp,
    output auto_in_rlast,
    input auto_out_1_awready,
    output auto_out_1_awvalid,
    output [3:0] auto_out_1_awid,
    output [27:0] auto_out_1_awaddr,
    input auto_out_1_wready,
    output auto_out_1_wvalid,
    output [31:0] auto_out_1_wdata,
    output [3:0] auto_out_1_wstrb,
    output auto_out_1_bready,
    input auto_out_1_bvalid,
    input [3:0] auto_out_1_bid,
    input [1:0] auto_out_1_bresp,
    input auto_out_1_arready,
    output auto_out_1_arvalid,
    output [3:0] auto_out_1_arid,
    output [27:0] auto_out_1_araddr,
    output auto_out_1_rready,
    input auto_out_1_rvalid,
    input [3:0] auto_out_1_rid,
    input [31:0] auto_out_1_rdata,
    input [1:0] auto_out_1_rresp,
    input auto_out_0_awready,
    output auto_out_0_awvalid,
    output [3:0] auto_out_0_awid,
    output [31:0] auto_out_0_awaddr,
    output [2:0] auto_out_0_awsize,
    input auto_out_0_wready,
    output auto_out_0_wvalid,
    output [31:0] auto_out_0_wdata,
    output [3:0] auto_out_0_wstrb,
    output auto_out_0_bready,
    input auto_out_0_bvalid,
    input [3:0] auto_out_0_bid,
    input [1:0] auto_out_0_bresp,
    input auto_out_0_arready,
    output auto_out_0_arvalid,
    output [3:0] auto_out_0_arid,
    output [31:0] auto_out_0_araddr,
    output [2:0] auto_out_0_arsize,
    output auto_out_0_rready,
    input auto_out_0_rvalid,
    input [3:0] auto_out_0_rid,
    input [31:0] auto_out_0_rdata,
    input [1:0] auto_out_0_rresp
);
  wire [3:0] _in_0_bT_5;
  wire       in_0_bvalid;
  wire [3:0] _in_0_rT_11;
  wire       _in_0_rT_2;
  wire       in_0_rvalid;
  wire       _portsWOI_in_0_wready_T_2;
  wire       _portsAWOI_in_0_awready_T_2;
  wire       _portsAROI_in_0_arready_T_2;
  wire       nodeIn_awready;
  wire       _awIn_0_io_enq_ready;
  wire       _awIn_0_io_deq_valid;
  wire [1:0] _awIn_0_io_deq_bits;
  wire       requestARIO_0_0 = ~(auto_in_araddr[27]) | auto_in_araddr[28];
  wire       requestARIO_0_1 = {auto_in_araddr[28], ~(auto_in_araddr[27])} == 2'h0;
  wire       requestAWIO_0_0 = ~(auto_in_awaddr[27]) | auto_in_awaddr[28];
  wire       requestAWIO_0_1 = {auto_in_awaddr[28], ~(auto_in_awaddr[27])} == 2'h0;
  wire       _arFIFOMap_15_T_1 = _portsAROI_in_0_arready_T_2 & auto_in_arvalid;
  wire       _arFIFOMap_0_T_2 = auto_in_arid == 4'h0 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_15_T_4 = auto_in_rready & in_0_rvalid;
  wire       _arFIFOMap_0_T_6 = _in_0_rT_11 == 4'h0 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_0_count;
  wire       _awFIFOMap_15_T_1 = nodeIn_awready & auto_in_awvalid;
  wire       _awFIFOMap_0_T_2 = auto_in_awid == 4'h0 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_15_T_4 = auto_in_bready & in_0_bvalid;
  wire       _awFIFOMap_0_T_5 = _in_0_bT_5 == 4'h0 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_0_count;
  wire       _arFIFOMap_1_T_2 = auto_in_arid == 4'h1 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_1_T_6 = _in_0_rT_11 == 4'h1 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_1_count;
  wire       _awFIFOMap_1_T_2 = auto_in_awid == 4'h1 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_1_T_5 = _in_0_bT_5 == 4'h1 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_1_count;
  wire       _arFIFOMap_2_T_2 = auto_in_arid == 4'h2 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_2_T_6 = _in_0_rT_11 == 4'h2 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_2_count;
  wire       _awFIFOMap_2_T_2 = auto_in_awid == 4'h2 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_2_T_5 = _in_0_bT_5 == 4'h2 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_2_count;
  wire       _arFIFOMap_3_T_2 = auto_in_arid == 4'h3 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_3_T_6 = _in_0_rT_11 == 4'h3 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_3_count;
  wire       _awFIFOMap_3_T_2 = auto_in_awid == 4'h3 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_3_T_5 = _in_0_bT_5 == 4'h3 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_3_count;
  wire       _arFIFOMap_4_T_2 = auto_in_arid == 4'h4 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_4_T_6 = _in_0_rT_11 == 4'h4 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_4_count;
  wire       _awFIFOMap_4_T_2 = auto_in_awid == 4'h4 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_4_T_5 = _in_0_bT_5 == 4'h4 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_4_count;
  wire       _arFIFOMap_5_T_2 = auto_in_arid == 4'h5 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_5_T_6 = _in_0_rT_11 == 4'h5 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_5_count;
  wire       _awFIFOMap_5_T_2 = auto_in_awid == 4'h5 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_5_T_5 = _in_0_bT_5 == 4'h5 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_5_count;
  wire       _arFIFOMap_6_T_2 = auto_in_arid == 4'h6 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_6_T_6 = _in_0_rT_11 == 4'h6 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_6_count;
  wire       _awFIFOMap_6_T_2 = auto_in_awid == 4'h6 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_6_T_5 = _in_0_bT_5 == 4'h6 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_6_count;
  wire       _arFIFOMap_7_T_2 = auto_in_arid == 4'h7 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_7_T_6 = _in_0_rT_11 == 4'h7 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_7_count;
  wire       _awFIFOMap_7_T_2 = auto_in_awid == 4'h7 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_7_T_5 = _in_0_bT_5 == 4'h7 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_7_count;
  wire       _arFIFOMap_8_T_2 = auto_in_arid == 4'h8 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_8_T_6 = _in_0_rT_11 == 4'h8 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_8_count;
  wire       _awFIFOMap_8_T_2 = auto_in_awid == 4'h8 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_8_T_5 = _in_0_bT_5 == 4'h8 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_8_count;
  wire       _arFIFOMap_9_T_2 = auto_in_arid == 4'h9 & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_9_T_6 = _in_0_rT_11 == 4'h9 & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_9_count;
  wire       _awFIFOMap_9_T_2 = auto_in_awid == 4'h9 & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_9_T_5 = _in_0_bT_5 == 4'h9 & _awFIFOMap_15_T_4;
  reg        awFIFOMap_9_count;
  wire       _arFIFOMap_10_T_2 = auto_in_arid == 4'hA & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_10_T_6 = _in_0_rT_11 == 4'hA & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_10_count;
  wire       _awFIFOMap_10_T_2 = auto_in_awid == 4'hA & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_10_T_5 = _in_0_bT_5 == 4'hA & _awFIFOMap_15_T_4;
  reg        awFIFOMap_10_count;
  wire       _arFIFOMap_11_T_2 = auto_in_arid == 4'hB & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_11_T_6 = _in_0_rT_11 == 4'hB & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_11_count;
  wire       _awFIFOMap_11_T_2 = auto_in_awid == 4'hB & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_11_T_5 = _in_0_bT_5 == 4'hB & _awFIFOMap_15_T_4;
  reg        awFIFOMap_11_count;
  wire       _arFIFOMap_12_T_2 = auto_in_arid == 4'hC & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_12_T_6 = _in_0_rT_11 == 4'hC & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_12_count;
  wire       _awFIFOMap_12_T_2 = auto_in_awid == 4'hC & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_12_T_5 = _in_0_bT_5 == 4'hC & _awFIFOMap_15_T_4;
  reg        awFIFOMap_12_count;
  wire       _arFIFOMap_13_T_2 = auto_in_arid == 4'hD & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_13_T_6 = _in_0_rT_11 == 4'hD & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_13_count;
  wire       _awFIFOMap_13_T_2 = auto_in_awid == 4'hD & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_13_T_5 = _in_0_bT_5 == 4'hD & _awFIFOMap_15_T_4;
  reg        awFIFOMap_13_count;
  wire       _arFIFOMap_14_T_2 = auto_in_arid == 4'hE & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_14_T_6 = _in_0_rT_11 == 4'hE & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_14_count;
  wire       _awFIFOMap_14_T_2 = auto_in_awid == 4'hE & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_14_T_5 = _in_0_bT_5 == 4'hE & _awFIFOMap_15_T_4;
  reg        awFIFOMap_14_count;
  wire       _arFIFOMap_15_T_2 = (&auto_in_arid) & _arFIFOMap_15_T_1;
  wire       _arFIFOMap_15_T_6 = (&_in_0_rT_11) & _arFIFOMap_15_T_4 & _in_0_rT_2;
  reg        arFIFOMap_15_count;
  wire       _awFIFOMap_15_T_2 = (&auto_in_awid) & _awFIFOMap_15_T_1;
  wire       _awFIFOMap_15_T_5 = (&_in_0_bT_5) & _awFIFOMap_15_T_4;
  reg        awFIFOMap_15_count;
  reg        latched;
  wire       _nodeIn_awready_T = latched | _awIn_0_io_enq_ready;
  wire       in_0_awvalid = auto_in_awvalid & _nodeIn_awready_T;
  assign nodeIn_awready = _portsAWOI_in_0_awready_T_2 & _nodeIn_awready_T;
  wire awIn_0_io_enq_valid = auto_in_awvalid & ~latched;
  wire in_0_wvalid = auto_in_wvalid & _awIn_0_io_deq_valid;
  assign _portsAROI_in_0_arready_T_2 =
    requestARIO_0_0 & auto_out_0_arready | requestARIO_0_1 & auto_out_1_arready;
  assign _portsAWOI_in_0_awready_T_2 =
    requestAWIO_0_0 & auto_out_0_awready | requestAWIO_0_1 & auto_out_1_awready;
  assign _portsWOI_in_0_wready_T_2 =
    _awIn_0_io_deq_bits[0] & auto_out_0_wready | _awIn_0_io_deq_bits[1]
    & auto_out_1_wready;
  reg idle_2;
  wire anyValid = auto_out_0_rvalid | auto_out_1_rvalid;
  wire [1:0] readys_valid = {auto_out_1_rvalid, auto_out_0_rvalid};
  reg [1:0] readys_mask;
  wire [1:0] _readys_filter_T_1 = readys_valid & ~readys_mask;
  wire [1:0] readys_readys =
    ~({readys_mask[1], _readys_filter_T_1[1] | readys_mask[0]}
      & ({_readys_filter_T_1[0], auto_out_1_rvalid} | _readys_filter_T_1));
  wire prefixOR_1 = readys_readys[0] & auto_out_0_rvalid;
  wire winner_2_1 = readys_readys[1] & auto_out_1_rvalid;
  reg state_2_0;
  reg state_2_1;
  wire muxState_2_0 = idle_2 ? prefixOR_1 : state_2_0;
  wire muxState_2_1 = idle_2 ? winner_2_1 : state_2_1;
  assign in_0_rvalid =
    idle_2 ? anyValid : state_2_0 & auto_out_0_rvalid | state_2_1 & auto_out_1_rvalid;
  assign _in_0_rT_2 = muxState_2_0 | muxState_2_1;
  assign _in_0_rT_11 =
    (muxState_2_0 ? auto_out_0_rid : 4'h0)
    | (muxState_2_1 ? auto_out_1_rid : 4'h0);
  reg idle_3;
  wire anyValid_1 = auto_out_0_bvalid | auto_out_1_bvalid;
  wire [1:0] readys_valid_1 = {auto_out_1_bvalid, auto_out_0_bvalid};
  reg [1:0] readys_mask_1;
  wire [1:0] _readys_filter_T_3 = readys_valid_1 & ~readys_mask_1;
  wire [1:0] readys_readys_1 =
    ~({readys_mask_1[1], _readys_filter_T_3[1] | readys_mask_1[0]}
      & ({_readys_filter_T_3[0], auto_out_1_bvalid} | _readys_filter_T_3));
  wire winner_3_0 = readys_readys_1[0] & auto_out_0_bvalid;
  wire winner_3_1 = readys_readys_1[1] & auto_out_1_bvalid;
  always @(posedge clock) begin
    if (~reset & ~(~_arFIFOMap_0_T_6 | arFIFOMap_0_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_0_T_2 | ~arFIFOMap_0_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_0_T_5 | awFIFOMap_0_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_0_T_2 | ~awFIFOMap_0_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_1_T_6 | arFIFOMap_1_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_1_T_2 | ~arFIFOMap_1_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_1_T_5 | awFIFOMap_1_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_1_T_2 | ~awFIFOMap_1_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_2_T_6 | arFIFOMap_2_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_2_T_2 | ~arFIFOMap_2_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_2_T_5 | awFIFOMap_2_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_2_T_2 | ~awFIFOMap_2_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_3_T_6 | arFIFOMap_3_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_3_T_2 | ~arFIFOMap_3_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_3_T_5 | awFIFOMap_3_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_3_T_2 | ~awFIFOMap_3_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_4_T_6 | arFIFOMap_4_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_4_T_2 | ~arFIFOMap_4_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_4_T_5 | awFIFOMap_4_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_4_T_2 | ~awFIFOMap_4_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_5_T_6 | arFIFOMap_5_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_5_T_2 | ~arFIFOMap_5_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_5_T_5 | awFIFOMap_5_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_5_T_2 | ~awFIFOMap_5_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_6_T_6 | arFIFOMap_6_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_6_T_2 | ~arFIFOMap_6_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_6_T_5 | awFIFOMap_6_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_6_T_2 | ~awFIFOMap_6_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_7_T_6 | arFIFOMap_7_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_7_T_2 | ~arFIFOMap_7_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_7_T_5 | awFIFOMap_7_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_7_T_2 | ~awFIFOMap_7_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_8_T_6 | arFIFOMap_8_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_8_T_2 | ~arFIFOMap_8_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_8_T_5 | awFIFOMap_8_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_8_T_2 | ~awFIFOMap_8_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_9_T_6 | arFIFOMap_9_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_9_T_2 | ~arFIFOMap_9_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_9_T_5 | awFIFOMap_9_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_9_T_2 | ~awFIFOMap_9_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_10_T_6 | arFIFOMap_10_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_10_T_2 | ~arFIFOMap_10_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_10_T_5 | awFIFOMap_10_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_10_T_2 | ~awFIFOMap_10_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_11_T_6 | arFIFOMap_11_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_11_T_2 | ~arFIFOMap_11_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_11_T_5 | awFIFOMap_11_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_11_T_2 | ~awFIFOMap_11_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_12_T_6 | arFIFOMap_12_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_12_T_2 | ~arFIFOMap_12_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_12_T_5 | awFIFOMap_12_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_12_T_2 | ~awFIFOMap_12_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_13_T_6 | arFIFOMap_13_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_13_T_2 | ~arFIFOMap_13_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_13_T_5 | awFIFOMap_13_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_13_T_2 | ~awFIFOMap_13_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_14_T_6 | arFIFOMap_14_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_14_T_2 | ~arFIFOMap_14_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_14_T_5 | awFIFOMap_14_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_14_T_2 | ~awFIFOMap_14_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_15_T_6 | arFIFOMap_15_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_arFIFOMap_15_T_2 | ~arFIFOMap_15_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_15_T_5 | awFIFOMap_15_count)) begin
      if (1)
        $error("Assertion failed\n    at Xbar.scala:122 assert (!resp_fire || count =/= 0.U)\n");
      if (1) $fatal;
    end
    if (~reset & ~(~_awFIFOMap_15_T_2 | ~awFIFOMap_15_count)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:123 assert (!req_fire  || count =/= flight.U)\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~prefixOR_1 | ~winner_2_1)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:275 assert((prefixOR zip winner) map { case (p,w) => !p || !w } reduce {_ && _})\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~anyValid | prefixOR_1 | winner_2_1)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:277 assert (!anyValid || winner.reduce(_||_))\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~winner_3_0 | ~winner_3_1)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:275 assert((prefixOR zip winner) map { case (p,w) => !p || !w } reduce {_ && _})\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~anyValid_1 | winner_3_0 | winner_3_1)) begin
      if (1)
        $error(
            "Assertion failed\n    at Xbar.scala:277 assert (!anyValid || winner.reduce(_||_))\n"
        );
      if (1) $fatal;
    end
  end
  reg  state_3_0;
  reg  state_3_1;
  wire muxState_3_0 = idle_3 ? winner_3_0 : state_3_0;
  wire muxState_3_1 = idle_3 ? winner_3_1 : state_3_1;
  assign in_0_bvalid =
    idle_3 ? anyValid_1 : state_3_0 & auto_out_0_bvalid | state_3_1 & auto_out_1_bvalid;
  assign _in_0_bT_5 =
    (muxState_3_0 ? auto_out_0_bid : 4'h0)
    | (muxState_3_1 ? auto_out_1_bid : 4'h0);
  always @(posedge clock) begin
    if (reset) begin
      arFIFOMap_0_count <= 1'h0;
      awFIFOMap_0_count <= 1'h0;
      arFIFOMap_1_count <= 1'h0;
      awFIFOMap_1_count <= 1'h0;
      arFIFOMap_2_count <= 1'h0;
      awFIFOMap_2_count <= 1'h0;
      arFIFOMap_3_count <= 1'h0;
      awFIFOMap_3_count <= 1'h0;
      arFIFOMap_4_count <= 1'h0;
      awFIFOMap_4_count <= 1'h0;
      arFIFOMap_5_count <= 1'h0;
      awFIFOMap_5_count <= 1'h0;
      arFIFOMap_6_count <= 1'h0;
      awFIFOMap_6_count <= 1'h0;
      arFIFOMap_7_count <= 1'h0;
      awFIFOMap_7_count <= 1'h0;
      arFIFOMap_8_count <= 1'h0;
      awFIFOMap_8_count <= 1'h0;
      arFIFOMap_9_count <= 1'h0;
      awFIFOMap_9_count <= 1'h0;
      arFIFOMap_10_count <= 1'h0;
      awFIFOMap_10_count <= 1'h0;
      arFIFOMap_11_count <= 1'h0;
      awFIFOMap_11_count <= 1'h0;
      arFIFOMap_12_count <= 1'h0;
      awFIFOMap_12_count <= 1'h0;
      arFIFOMap_13_count <= 1'h0;
      awFIFOMap_13_count <= 1'h0;
      arFIFOMap_14_count <= 1'h0;
      awFIFOMap_14_count <= 1'h0;
      arFIFOMap_15_count <= 1'h0;
      awFIFOMap_15_count <= 1'h0;
      latched <= 1'h0;
      idle_2 <= 1'h1;
      readys_mask <= 2'h3;
      state_2_0 <= 1'h0;
      state_2_1 <= 1'h0;
      idle_3 <= 1'h1;
      readys_mask_1 <= 2'h3;
      state_3_0 <= 1'h0;
      state_3_1 <= 1'h0;
    end else begin
      arFIFOMap_0_count <= arFIFOMap_0_count + _arFIFOMap_0_T_2 - _arFIFOMap_0_T_6;
      awFIFOMap_0_count <= awFIFOMap_0_count + _awFIFOMap_0_T_2 - _awFIFOMap_0_T_5;
      arFIFOMap_1_count <= arFIFOMap_1_count + _arFIFOMap_1_T_2 - _arFIFOMap_1_T_6;
      awFIFOMap_1_count <= awFIFOMap_1_count + _awFIFOMap_1_T_2 - _awFIFOMap_1_T_5;
      arFIFOMap_2_count <= arFIFOMap_2_count + _arFIFOMap_2_T_2 - _arFIFOMap_2_T_6;
      awFIFOMap_2_count <= awFIFOMap_2_count + _awFIFOMap_2_T_2 - _awFIFOMap_2_T_5;
      arFIFOMap_3_count <= arFIFOMap_3_count + _arFIFOMap_3_T_2 - _arFIFOMap_3_T_6;
      awFIFOMap_3_count <= awFIFOMap_3_count + _awFIFOMap_3_T_2 - _awFIFOMap_3_T_5;
      arFIFOMap_4_count <= arFIFOMap_4_count + _arFIFOMap_4_T_2 - _arFIFOMap_4_T_6;
      awFIFOMap_4_count <= awFIFOMap_4_count + _awFIFOMap_4_T_2 - _awFIFOMap_4_T_5;
      arFIFOMap_5_count <= arFIFOMap_5_count + _arFIFOMap_5_T_2 - _arFIFOMap_5_T_6;
      awFIFOMap_5_count <= awFIFOMap_5_count + _awFIFOMap_5_T_2 - _awFIFOMap_5_T_5;
      arFIFOMap_6_count <= arFIFOMap_6_count + _arFIFOMap_6_T_2 - _arFIFOMap_6_T_6;
      awFIFOMap_6_count <= awFIFOMap_6_count + _awFIFOMap_6_T_2 - _awFIFOMap_6_T_5;
      arFIFOMap_7_count <= arFIFOMap_7_count + _arFIFOMap_7_T_2 - _arFIFOMap_7_T_6;
      awFIFOMap_7_count <= awFIFOMap_7_count + _awFIFOMap_7_T_2 - _awFIFOMap_7_T_5;
      arFIFOMap_8_count <= arFIFOMap_8_count + _arFIFOMap_8_T_2 - _arFIFOMap_8_T_6;
      awFIFOMap_8_count <= awFIFOMap_8_count + _awFIFOMap_8_T_2 - _awFIFOMap_8_T_5;
      arFIFOMap_9_count <= arFIFOMap_9_count + _arFIFOMap_9_T_2 - _arFIFOMap_9_T_6;
      awFIFOMap_9_count <= awFIFOMap_9_count + _awFIFOMap_9_T_2 - _awFIFOMap_9_T_5;
      arFIFOMap_10_count <= arFIFOMap_10_count + _arFIFOMap_10_T_2 - _arFIFOMap_10_T_6;
      awFIFOMap_10_count <= awFIFOMap_10_count + _awFIFOMap_10_T_2 - _awFIFOMap_10_T_5;
      arFIFOMap_11_count <= arFIFOMap_11_count + _arFIFOMap_11_T_2 - _arFIFOMap_11_T_6;
      awFIFOMap_11_count <= awFIFOMap_11_count + _awFIFOMap_11_T_2 - _awFIFOMap_11_T_5;
      arFIFOMap_12_count <= arFIFOMap_12_count + _arFIFOMap_12_T_2 - _arFIFOMap_12_T_6;
      awFIFOMap_12_count <= awFIFOMap_12_count + _awFIFOMap_12_T_2 - _awFIFOMap_12_T_5;
      arFIFOMap_13_count <= arFIFOMap_13_count + _arFIFOMap_13_T_2 - _arFIFOMap_13_T_6;
      awFIFOMap_13_count <= awFIFOMap_13_count + _awFIFOMap_13_T_2 - _awFIFOMap_13_T_5;
      arFIFOMap_14_count <= arFIFOMap_14_count + _arFIFOMap_14_T_2 - _arFIFOMap_14_T_6;
      awFIFOMap_14_count <= awFIFOMap_14_count + _awFIFOMap_14_T_2 - _awFIFOMap_14_T_5;
      arFIFOMap_15_count <= arFIFOMap_15_count + _arFIFOMap_15_T_2 - _arFIFOMap_15_T_6;
      awFIFOMap_15_count <= awFIFOMap_15_count + _awFIFOMap_15_T_2 - _awFIFOMap_15_T_5;
      latched <=
        ~(_portsAWOI_in_0_awready_T_2 & in_0_awvalid)
        & (_awIn_0_io_enq_ready & awIn_0_io_enq_valid | latched);
      idle_2 <= auto_in_rready & in_0_rvalid | ~anyValid & idle_2;
      if (idle_2 & (|readys_valid)) begin
        automatic logic [1:0] _readys_mask_T = readys_readys & readys_valid;
        readys_mask <= _readys_mask_T | {_readys_mask_T[0], 1'h0};
      end
      if (idle_2) begin
        state_2_0 <= prefixOR_1;
        state_2_1 <= winner_2_1;
      end
      idle_3 <= auto_in_bready & in_0_bvalid | ~anyValid_1 & idle_3;
      if (idle_3 & (|readys_valid_1)) begin
        automatic logic [1:0] _readys_mask_T_5 = readys_readys_1 & readys_valid_1;
        readys_mask_1 <= _readys_mask_T_5 | {_readys_mask_T_5[0], 1'h0};
      end
      if (idle_3) begin
        state_3_0 <= winner_3_0;
        state_3_1 <= winner_3_1;
      end
    end
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:2];
  end
  Queue2_UInt2 awIn_0 (
      .clock(clock),
      .reset(reset),
      .io_enq_ready(_awIn_0_io_enq_ready),
      .io_enq_valid(awIn_0_io_enq_valid),
      .io_enq_bits({requestAWIO_0_1, requestAWIO_0_0}),
      .io_deq_ready(auto_in_wvalid & auto_in_wlast & _portsWOI_in_0_wready_T_2),
      .io_deq_valid(_awIn_0_io_deq_valid),
      .io_deq_bits(_awIn_0_io_deq_bits)
  );
  assign auto_in_awready = nodeIn_awready;
  assign auto_in_wready = _portsWOI_in_0_wready_T_2 & _awIn_0_io_deq_valid;
  assign auto_in_bvalid = in_0_bvalid;
  assign auto_in_bid = _in_0_bT_5;
  assign auto_in_bresp =
    (muxState_3_0 ? auto_out_0_bresp : 2'h0)
    | (muxState_3_1 ? auto_out_1_bresp : 2'h0);
  assign auto_in_arready = _portsAROI_in_0_arready_T_2;
  assign auto_in_rvalid = in_0_rvalid;
  assign auto_in_rid = _in_0_rT_11;
  assign auto_in_rdata =
    (muxState_2_0 ? auto_out_0_rdata : 32'h0)
    | (muxState_2_1 ? auto_out_1_rdata : 32'h0);
  assign auto_in_rresp =
    (muxState_2_0 ? auto_out_0_rresp : 2'h0)
    | (muxState_2_1 ? auto_out_1_rresp : 2'h0);
  assign auto_in_rlast = _in_0_rT_2;
  assign auto_out_1_awvalid = in_0_awvalid & requestAWIO_0_1;
  assign auto_out_1_awid = auto_in_awid;
  assign auto_out_1_awaddr = auto_in_awaddr[27:0];
  assign auto_out_1_wvalid = in_0_wvalid & _awIn_0_io_deq_bits[1];
  assign auto_out_1_wdata = auto_in_wdata;
  assign auto_out_1_wstrb = auto_in_wstrb;
  assign auto_out_1_bready = auto_in_bready & (idle_3 ? readys_readys_1[1] : state_3_1);
  assign auto_out_1_arvalid = auto_in_arvalid & requestARIO_0_1;
  assign auto_out_1_arid = auto_in_arid;
  assign auto_out_1_araddr = auto_in_araddr[27:0];
  assign auto_out_1_rready = auto_in_rready & (idle_2 ? readys_readys[1] : state_2_1);
  assign auto_out_0_awvalid = in_0_awvalid & requestAWIO_0_0;
  assign auto_out_0_awid = auto_in_awid;
  assign auto_out_0_awaddr = auto_in_awaddr;
  assign auto_out_0_awsize = auto_in_awsize;
  assign auto_out_0_wvalid = in_0_wvalid & _awIn_0_io_deq_bits[0];
  assign auto_out_0_wdata = auto_in_wdata;
  assign auto_out_0_wstrb = auto_in_wstrb;
  assign auto_out_0_bready = auto_in_bready & (idle_3 ? readys_readys_1[0] : state_3_0);
  assign auto_out_0_arvalid = auto_in_arvalid & requestARIO_0_0;
  assign auto_out_0_arid = auto_in_arid;
  assign auto_out_0_araddr = auto_in_araddr;
  assign auto_out_0_arsize = auto_in_arsize;
  assign auto_out_0_rready = auto_in_rready & (idle_2 ? readys_readys[0] : state_2_0);
endmodule
module APBFanout (
    input auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input [31:0] auto_in_paddr,
    input [2:0] auto_in_pprot,
    input [31:0] auto_in_pwdata,
    input [3:0] auto_in_pstrb,
    output auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    output auto_out_5_psel,
    auto_out_5_penable,
    auto_out_5_pwrite,
    output [31:0] auto_out_5_paddr,
    output [2:0] auto_out_5_pprot,
    output [31:0] auto_out_5_pwdata,
    output [3:0] auto_out_5_pstrb,
    input auto_out_5_pready,
    auto_out_5_pslverr,
    input [31:0] auto_out_5_prdata,
    output auto_out_4_psel,
    auto_out_4_penable,
    auto_out_4_pwrite,
    output [29:0] auto_out_4_paddr,
    output [2:0] auto_out_4_pprot,
    output [31:0] auto_out_4_pwdata,
    output [3:0] auto_out_4_pstrb,
    input auto_out_4_pready,
    auto_out_4_pslverr,
    input [31:0] auto_out_4_prdata,
    output auto_out_3_psel,
    auto_out_3_penable,
    auto_out_3_pwrite,
    output [28:0] auto_out_3_paddr,
    output [2:0] auto_out_3_pprot,
    output [31:0] auto_out_3_pwdata,
    output [3:0] auto_out_3_pstrb,
    input auto_out_3_pready,
    auto_out_3_pslverr,
    input [31:0] auto_out_3_prdata,
    output auto_out_2_psel,
    auto_out_2_penable,
    auto_out_2_pwrite,
    output [28:0] auto_out_2_paddr,
    output [2:0] auto_out_2_pprot,
    output [31:0] auto_out_2_pwdata,
    output [3:0] auto_out_2_pstrb,
    input auto_out_2_pready,
    auto_out_2_pslverr,
    input [31:0] auto_out_2_prdata,
    output auto_out_1_psel,
    auto_out_1_penable,
    auto_out_1_pwrite,
    output [28:0] auto_out_1_paddr,
    output [2:0] auto_out_1_pprot,
    output [31:0] auto_out_1_pwdata,
    output [3:0] auto_out_1_pstrb,
    input auto_out_1_pready,
    auto_out_1_pslverr,
    input [31:0] auto_out_1_prdata,
    output auto_out_0_psel,
    auto_out_0_penable,
    auto_out_0_pwrite,
    output [29:0] auto_out_0_paddr,
    output [2:0] auto_out_0_pprot,
    output [31:0] auto_out_0_pwdata,
    output [3:0] auto_out_0_pstrb,
    input auto_out_0_pready,
    auto_out_0_pslverr,
    input [31:0] auto_out_0_prdata
);
  wire [16:0] _GEN = auto_in_paddr[28:12] ^ 17'h10001;
  wire        sel_0 =
    {auto_in_paddr[29], _GEN[16], auto_in_paddr[16], _GEN[1:0]} == 5'h0
    | (&(auto_in_paddr[29:28]));
  wire        sel_1 =
    {auto_in_paddr[29],
     ~(auto_in_paddr[28]),
     auto_in_paddr[16],
     auto_in_paddr[13:12]} == 5'h0;
  wire [16:0] _GEN_0 = auto_in_paddr[28:12] ^ 17'h10002;
  wire sel_2 = {auto_in_paddr[29], _GEN_0[16], auto_in_paddr[16], _GEN_0[1:0]} == 5'h0;
  wire [16:0] _GEN_1 = auto_in_paddr[28:12] ^ 17'h10011;
  wire sel_3 = {auto_in_paddr[29], _GEN_1[16], _GEN_1[4], _GEN_1[1:0]} == 5'h0;
  wire sel_4 = auto_in_paddr[29:28] == 2'h2;
  wire sel_5 = auto_in_paddr[29:28] == 2'h0;
  assign auto_in_pready =
    ~(sel_0 & ~auto_out_0_pready | sel_1 & ~auto_out_1_pready | sel_2 & ~auto_out_2_pready
      | sel_3 & ~auto_out_3_pready | sel_4 & ~auto_out_4_pready | sel_5
      & ~auto_out_5_pready);
  assign auto_in_pslverr =
    sel_0 & auto_out_0_pslverr | sel_1 & auto_out_1_pslverr | sel_2 & auto_out_2_pslverr
    | sel_3 & auto_out_3_pslverr | sel_4 & auto_out_4_pslverr | sel_5
    & auto_out_5_pslverr;
  assign auto_in_prdata =
    (sel_0 ? auto_out_0_prdata : 32'h0) | (sel_1 ? auto_out_1_prdata : 32'h0)
    | (sel_2 ? auto_out_2_prdata : 32'h0) | (sel_3 ? auto_out_3_prdata : 32'h0)
    | (sel_4 ? auto_out_4_prdata : 32'h0) | (sel_5 ? auto_out_5_prdata : 32'h0);
  assign auto_out_5_psel = sel_5 & auto_in_psel;
  assign auto_out_5_penable = sel_5 & auto_in_penable;
  assign auto_out_5_pwrite = auto_in_pwrite;
  assign auto_out_5_paddr = auto_in_paddr;
  assign auto_out_5_pprot = auto_in_pprot;
  assign auto_out_5_pwdata = auto_in_pwdata;
  assign auto_out_5_pstrb = auto_in_pstrb;
  assign auto_out_4_psel = sel_4 & auto_in_psel;
  assign auto_out_4_penable = sel_4 & auto_in_penable;
  assign auto_out_4_pwrite = auto_in_pwrite;
  assign auto_out_4_paddr = auto_in_paddr[29:0];
  assign auto_out_4_pprot = auto_in_pprot;
  assign auto_out_4_pwdata = auto_in_pwdata;
  assign auto_out_4_pstrb = auto_in_pstrb;
  assign auto_out_3_psel = sel_3 & auto_in_psel;
  assign auto_out_3_penable = sel_3 & auto_in_penable;
  assign auto_out_3_pwrite = auto_in_pwrite;
  assign auto_out_3_paddr = auto_in_paddr[28:0];
  assign auto_out_3_pprot = auto_in_pprot;
  assign auto_out_3_pwdata = auto_in_pwdata;
  assign auto_out_3_pstrb = auto_in_pstrb;
  assign auto_out_2_psel = sel_2 & auto_in_psel;
  assign auto_out_2_penable = sel_2 & auto_in_penable;
  assign auto_out_2_pwrite = auto_in_pwrite;
  assign auto_out_2_paddr = auto_in_paddr[28:0];
  assign auto_out_2_pprot = auto_in_pprot;
  assign auto_out_2_pwdata = auto_in_pwdata;
  assign auto_out_2_pstrb = auto_in_pstrb;
  assign auto_out_1_psel = sel_1 & auto_in_psel;
  assign auto_out_1_penable = sel_1 & auto_in_penable;
  assign auto_out_1_pwrite = auto_in_pwrite;
  assign auto_out_1_paddr = auto_in_paddr[28:0];
  assign auto_out_1_pprot = auto_in_pprot;
  assign auto_out_1_pwdata = auto_in_pwdata;
  assign auto_out_1_pstrb = auto_in_pstrb;
  assign auto_out_0_psel = sel_0 & auto_in_psel;
  assign auto_out_0_penable = sel_0 & auto_in_penable;
  assign auto_out_0_pwrite = auto_in_pwrite;
  assign auto_out_0_paddr = auto_in_paddr[29:0];
  assign auto_out_0_pprot = auto_in_pprot;
  assign auto_out_0_pwdata = auto_in_pwdata;
  assign auto_out_0_pstrb = auto_in_pstrb;
endmodule
module CPU (
    input clock,
    reset,
    auto_master_out_awready,
    output auto_master_out_awvalid,
    output [3:0] auto_master_out_awid,
    output [31:0] auto_master_out_awaddr,
    output [7:0] auto_master_out_awlen,
    output [2:0] auto_master_out_awsize,
    output [1:0] auto_master_out_awburst,
    input auto_master_out_wready,
    output auto_master_out_wvalid,
    output [31:0] auto_master_out_wdata,
    output [3:0] auto_master_out_wstrb,
    output auto_master_out_wlast,
    auto_master_out_bready,
    input auto_master_out_bvalid,
    input [3:0] auto_master_out_bid,
    input [1:0] auto_master_out_bresp,
    input auto_master_out_arready,
    output auto_master_out_arvalid,
    output [3:0] auto_master_out_arid,
    output [31:0] auto_master_out_araddr,
    output [7:0] auto_master_out_arlen,
    output [2:0] auto_master_out_arsize,
    output [1:0] auto_master_out_arburst,
    output auto_master_out_rready,
    input auto_master_out_rvalid,
    input [3:0] auto_master_out_rid,
    input [31:0] auto_master_out_rdata,
    input [1:0] auto_master_out_rresp,
    input auto_master_out_rlast
);
  ysyx_24080006 cpu (
      .clock            (clock),
      .reset            (reset),
      .io_interrupt     (1'h0),
      .io_master_awready(auto_master_out_awready),
      .io_master_awvalid(auto_master_out_awvalid),
      .io_master_awid   (auto_master_out_awid),
      .io_master_awaddr (auto_master_out_awaddr),
      .io_master_awlen  (auto_master_out_awlen),
      .io_master_awsize (auto_master_out_awsize),
      .io_master_awburst(auto_master_out_awburst),
      .io_master_wready (auto_master_out_wready),
      .io_master_wvalid (auto_master_out_wvalid),
      .io_master_wdata  (auto_master_out_wdata),
      .io_master_wstrb  (auto_master_out_wstrb),
      .io_master_wlast  (auto_master_out_wlast),
      .io_master_bready (auto_master_out_bready),
      .io_master_bvalid (auto_master_out_bvalid),
      .io_master_bid    (auto_master_out_bid),
      .io_master_bresp  (auto_master_out_bresp),
      .io_master_arready(auto_master_out_arready),
      .io_master_arvalid(auto_master_out_arvalid),
      .io_master_arid   (auto_master_out_arid),
      .io_master_araddr (auto_master_out_araddr),
      .io_master_arlen  (auto_master_out_arlen),
      .io_master_arsize (auto_master_out_arsize),
      .io_master_arburst(auto_master_out_arburst),
      .io_master_rready (auto_master_out_rready),
      .io_master_rvalid (auto_master_out_rvalid),
      .io_master_rid    (auto_master_out_rid),
      .io_master_rdata  (auto_master_out_rdata),
      .io_master_rresp  (auto_master_out_rresp),
      .io_master_rlast  (auto_master_out_rlast),
      .io_slave_awready (),
      .io_slave_awvalid (1'h0),
      .io_slave_awid    (4'h0),
      .io_slave_awaddr  (32'h0),
      .io_slave_awlen   (8'h0),
      .io_slave_awsize  (3'h0),
      .io_slave_awburst (2'h0),
      .io_slave_wready  (),
      .io_slave_wvalid  (1'h0),
      .io_slave_wdata   (32'h0),
      .io_slave_wstrb   (4'h0),
      .io_slave_wlast   (1'h0),
      .io_slave_bready  (1'h0),
      .io_slave_bvalid  (),
      .io_slave_bid     (),
      .io_slave_bresp   (),
      .io_slave_arready (),
      .io_slave_arvalid (1'h0),
      .io_slave_arid    (4'h0),
      .io_slave_araddr  (32'h0),
      .io_slave_arlen   (8'h0),
      .io_slave_arsize  (3'h0),
      .io_slave_arburst (2'h0),
      .io_slave_rready  (1'h0),
      .io_slave_rvalid  (),
      .io_slave_rid     (),
      .io_slave_rdata   (),
      .io_slave_rresp   (),
      .io_slave_rlast   ()
  );
endmodule
module APBUart16550 (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [28:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    input         uart_rx,
    output        uart_tx
);
  uart_top_apb muart (
      .clock     (clock),
      .reset     (reset),
      .in_psel   (auto_in_psel),
      .in_penable(auto_in_penable),
      .in_pwrite (auto_in_pwrite),
      .in_paddr  ({3'h0, auto_in_paddr}),
      .in_pprot  (auto_in_pprot),
      .in_pwdata (auto_in_pwdata),
      .in_pstrb  (auto_in_pstrb),
      .in_pready (auto_in_pready),
      .in_pslverr(auto_in_pslverr),
      .in_prdata (auto_in_prdata),
      .uart_rx   (uart_rx),
      .uart_tx   (uart_tx)
  );
endmodule
module APBGPIO (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [28:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    output [15:0] gpio_bundle_out,
    input  [15:0] gpio_bundle_in,
    output [ 7:0] gpio_bundle_seg_0,
    gpio_bundle_seg_1,
    gpio_bundle_seg_2,
    gpio_bundle_seg_3,
    gpio_bundle_seg_4,
    gpio_bundle_seg_5,
    gpio_bundle_seg_6,
    gpio_bundle_seg_7
);
  gpio_top_apb mgpio (
      .clock     (clock),
      .reset     (reset),
      .in_psel   (auto_in_psel),
      .in_penable(auto_in_penable),
      .in_pwrite (auto_in_pwrite),
      .in_paddr  ({3'h0, auto_in_paddr}),
      .in_pprot  (auto_in_pprot),
      .in_pwdata (auto_in_pwdata),
      .in_pstrb  (auto_in_pstrb),
      .in_pready (auto_in_pready),
      .in_pslverr(auto_in_pslverr),
      .in_prdata (auto_in_prdata),
      .gpio_out  (gpio_bundle_out),
      .gpio_in   (gpio_bundle_in),
      .gpio_seg_0(gpio_bundle_seg_0),
      .gpio_seg_1(gpio_bundle_seg_1),
      .gpio_seg_2(gpio_bundle_seg_2),
      .gpio_seg_3(gpio_bundle_seg_3),
      .gpio_seg_4(gpio_bundle_seg_4),
      .gpio_seg_5(gpio_bundle_seg_5),
      .gpio_seg_6(gpio_bundle_seg_6),
      .gpio_seg_7(gpio_bundle_seg_7)
  );
endmodule
module APBKeyboard (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [28:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    input         ps2_bundle_clk,
    ps2_bundle_data
);
  ps2_top_apb mps2 (
      .clock     (clock),
      .reset     (reset),
      .in_psel   (auto_in_psel),
      .in_penable(auto_in_penable),
      .in_pwrite (auto_in_pwrite),
      .in_paddr  ({3'h0, auto_in_paddr}),
      .in_pprot  (auto_in_pprot),
      .in_pwdata (auto_in_pwdata),
      .in_pstrb  (auto_in_pstrb),
      .in_pready (auto_in_pready),
      .in_pslverr(auto_in_pslverr),
      .in_prdata (auto_in_prdata),
      .ps2_clk   (ps2_bundle_clk),
      .ps2_data  (ps2_bundle_data)
  );
endmodule
module APBVGA (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [29:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    output [ 7:0] vga_bundle_r,
    vga_bundle_g,
    vga_bundle_b,
    output        vga_bundle_hsync,
    vga_bundle_vsync,
    vga_bundle_valid
);
  vga_top_apb mvga (
      .clock     (clock),
      .reset     (reset),
      .in_psel   (auto_in_psel),
      .in_penable(auto_in_penable),
      .in_pwrite (auto_in_pwrite),
      .in_paddr  ({2'h0, auto_in_paddr}),
      .in_pprot  (auto_in_pprot),
      .in_pwdata (auto_in_pwdata),
      .in_pstrb  (auto_in_pstrb),
      .in_pready (auto_in_pready),
      .in_pslverr(auto_in_pslverr),
      .in_prdata (auto_in_prdata),
      .vga_r     (vga_bundle_r),
      .vga_g     (vga_bundle_g),
      .vga_b     (vga_bundle_b),
      .vga_hsync (vga_bundle_hsync),
      .vga_vsync (vga_bundle_vsync),
      .vga_valid (vga_bundle_valid)
  );
endmodule
module APBSPI (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [29:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    output        spi_bundle_sck,
    output [ 7:0] spi_bundle_ss,
    output        spi_bundle_mosi,
    input         spi_bundle_miso
);
  spi_top_apb mspi (
      .clock      (clock),
      .reset      (reset),
      .in_psel    (auto_in_psel),
      .in_penable (auto_in_penable),
      .in_pwrite  (auto_in_pwrite),
      .in_paddr   ({2'h0, auto_in_paddr}),
      .in_pprot   (auto_in_pprot),
      .in_pwdata  (auto_in_pwdata),
      .in_pstrb   (auto_in_pstrb),
      .in_pready  (auto_in_pready),
      .in_pslverr (auto_in_pslverr),
      .in_prdata  (auto_in_prdata),
      .spi_sck    (spi_bundle_sck),
      .spi_ss     (spi_bundle_ss),
      .spi_mosi   (spi_bundle_mosi),
      .spi_miso   (spi_bundle_miso),
      .spi_irq_out()
  );
endmodule
module mem_2048x32 (
    input  [10:0] R0_addr,
    input         R0_en,
    R0_clk,
    output [31:0] R0_data,
    input  [10:0] W0_addr,
    input         W0_en,
    W0_clk,
    input  [31:0] W0_data,
    input  [ 3:0] W0_mask
);
  reg [31:0] Memory[0:2047];
  reg _R0_en_d0;
  reg [10:0] _R0_addr_d0;
  always @(posedge R0_clk) begin
    _R0_en_d0   <= R0_en;
    _R0_addr_d0 <= R0_addr;
  end
  always @(posedge W0_clk) begin
    if (W0_en & W0_mask[0]) Memory[W0_addr][32'h0+:8] <= W0_data[7:0];
    if (W0_en & W0_mask[1]) Memory[W0_addr][32'h8+:8] <= W0_data[15:8];
    if (W0_en & W0_mask[2]) Memory[W0_addr][32'h10+:8] <= W0_data[23:16];
    if (W0_en & W0_mask[3]) Memory[W0_addr][32'h18+:8] <= W0_data[31:24];
  end
  reg [31:0] _RANDOM_MEM;
  initial begin
  end
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 32'bx;
endmodule
module AXI4RAM (
    input         clock,
    reset,
    output        auto_in_awready,
    input         auto_in_awvalid,
    input  [ 3:0] auto_in_awid,
    input  [27:0] auto_in_awaddr,
    output        auto_in_wready,
    input         auto_in_wvalid,
    input  [31:0] auto_in_wdata,
    input  [ 3:0] auto_in_wstrb,
    input         auto_in_bready,
    output        auto_in_bvalid,
    output [ 3:0] auto_in_bid,
    output [ 1:0] auto_in_bresp,
    output        auto_in_arready,
    input         auto_in_arvalid,
    input  [ 3:0] auto_in_arid,
    input  [27:0] auto_in_araddr,
    input         auto_in_rready,
    output        auto_in_rvalid,
    output [ 3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [ 1:0] auto_in_rresp
);
  wire        nodeIn_arready;
  wire        nodeIn_awready;
  wire [31:0] _mem_ext_R0_data;
  wire        w_sel0 = auto_in_awaddr[27:13] == 15'h7800;
  reg         w_full;
  reg  [ 3:0] w_id;
  reg         r_sel1;
  reg         w_sel1;
  wire        _GEN = nodeIn_awready & auto_in_awvalid;
  assign nodeIn_awready = auto_in_wvalid & (auto_in_bready | ~w_full);
  reg        r_full;
  reg  [3:0] r_id;
  wire       ren = nodeIn_arready & auto_in_arvalid;
  reg        rdata_REG;
  reg  [7:0] rdata_r0;
  reg  [7:0] rdata_r1;
  reg  [7:0] rdata_r2;
  reg  [7:0] rdata_r3;
  assign nodeIn_arready = auto_in_rready | ~r_full;
  always @(posedge clock) begin
    if (reset) begin
      w_full <= 1'h0;
      r_full <= 1'h0;
    end else begin
      w_full <= _GEN | ~(auto_in_bready & w_full) & w_full;
      r_full <= ren | ~(auto_in_rready & r_full) & r_full;
    end
    if (_GEN) w_id <= auto_in_awid;
    r_sel1 <= auto_in_araddr[27:13] == 15'h7800;
    w_sel1 <= w_sel0;
    if (ren) r_id <= auto_in_arid;
    rdata_REG <= ren;
    if (rdata_REG) begin
      rdata_r0 <= _mem_ext_R0_data[7:0];
      rdata_r1 <= _mem_ext_R0_data[15:8];
      rdata_r2 <= _mem_ext_R0_data[23:16];
      rdata_r3 <= _mem_ext_R0_data[31:24];
    end
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:1];
  end
  mem_2048x32 mem_ext (
      .R0_addr(auto_in_araddr[12:2]),
      .R0_en  (ren),
      .R0_clk (clock),
      .R0_data(_mem_ext_R0_data),
      .W0_addr(auto_in_awaddr[12:2]),
      .W0_en  (_GEN & w_sel0),
      .W0_clk (clock),
      .W0_data(auto_in_wdata),
      .W0_mask(auto_in_wstrb)
  );
  assign auto_in_awready = nodeIn_awready;
  assign auto_in_wready = auto_in_awvalid & (auto_in_bready | ~w_full);
  assign auto_in_bvalid = w_full;
  assign auto_in_bid = w_id;
  assign auto_in_bresp = w_sel1 ? 2'h0 : 2'h3;
  assign auto_in_arready = nodeIn_arready;
  assign auto_in_rvalid = r_full;
  assign auto_in_rid = r_id;
  assign auto_in_rdata = {
    rdata_REG ? _mem_ext_R0_data[31:24] : rdata_r3,
    rdata_REG ? _mem_ext_R0_data[23:16] : rdata_r2,
    rdata_REG ? _mem_ext_R0_data[15:8] : rdata_r1,
    rdata_REG ? _mem_ext_R0_data[7:0] : rdata_r0
  };
  assign auto_in_rresp = r_sel1 ? 2'h0 : 2'h3;
endmodule
module APBSDRAM (
    input         clock,
    reset,
    auto_in_psel,
    auto_in_penable,
    auto_in_pwrite,
    input  [31:0] auto_in_paddr,
    input  [ 2:0] auto_in_pprot,
    input  [31:0] auto_in_pwdata,
    input  [ 3:0] auto_in_pstrb,
    output        auto_in_pready,
    auto_in_pslverr,
    output [31:0] auto_in_prdata,
    output        sdram_bundle_clk,
    sdram_bundle_cke,
    sdram_bundle_cs,
    sdram_bundle_ras,
    sdram_bundle_cas,
    sdram_bundle_we,
    output [12:0] sdram_bundle_a,
    output [ 1:0] sdram_bundle_ba,
    output [ 3:0] sdram_bundle_dqm,
    inout  [31:0] sdram_bundle_dq
);
  sdram_top_apb msdram (
      .clock     (clock),
      .reset     (reset),
      .in_psel   (auto_in_psel),
      .in_penable(auto_in_penable),
      .in_pwrite (auto_in_pwrite),
      .in_paddr  (auto_in_paddr),
      .in_pprot  (auto_in_pprot),
      .in_pwdata (auto_in_pwdata),
      .in_pstrb  (auto_in_pstrb),
      .in_pready (auto_in_pready),
      .in_pslverr(auto_in_pslverr),
      .in_prdata (auto_in_prdata),
      .sdram_clk (sdram_bundle_clk),
      .sdram_cke (sdram_bundle_cke),
      .sdram_cs  (sdram_bundle_cs),
      .sdram_ras (sdram_bundle_ras),
      .sdram_cas (sdram_bundle_cas),
      .sdram_we  (sdram_bundle_we),
      .sdram_a   (sdram_bundle_a),
      .sdram_ba  (sdram_bundle_ba),
      .sdram_dqm (sdram_bundle_dqm),
      .sdram_dq  (sdram_bundle_dq)
  );
endmodule
module AXI4ToAPB (
    input         clock,
    reset,
    output        auto_in_awready,
    input         auto_in_awvalid,
    input  [ 3:0] auto_in_awid,
    input  [31:0] auto_in_awaddr,
    input  [ 2:0] auto_in_awsize,
    output        auto_in_wready,
    input         auto_in_wvalid,
    input  [31:0] auto_in_wdata,
    input  [ 3:0] auto_in_wstrb,
    input         auto_in_bready,
    output        auto_in_bvalid,
    output [ 3:0] auto_in_bid,
    output [ 1:0] auto_in_bresp,
    output        auto_in_arready,
    input         auto_in_arvalid,
    input  [ 3:0] auto_in_arid,
    input  [31:0] auto_in_araddr,
    input  [ 2:0] auto_in_arsize,
    input         auto_in_rready,
    output        auto_in_rvalid,
    output [ 3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [ 1:0] auto_in_rresp,
    output        auto_out_psel,
    auto_out_penable,
    auto_out_pwrite,
    output [31:0] auto_out_paddr,
    auto_out_pwdata,
    output [ 3:0] auto_out_pstrb,
    input         auto_out_pready,
    auto_out_pslverr,
    input  [31:0] auto_out_prdata
);
  wire       nodeOut_penable;
  reg  [1:0] state;
  wire       _is_write_T = state == 2'h0;
  wire       accept_read = _is_write_T & auto_in_arvalid;
  wire       accept_write = ~accept_read & _is_write_T & auto_in_awvalid & auto_in_wvalid;
  reg        is_write_r;
  wire       is_write = _is_write_T ? accept_write : is_write_r;
  always @(posedge clock) begin
    if (~reset & auto_in_arvalid & auto_in_arsize > 3'h2) begin
      if (1)
        $error(
            "Assertion failed\n    at AXI4ToAPB.scala:64 assert(!(ar.valid && ar.bits.size > \"b10\".U))\n"
        );
      if (1) $fatal;
    end
    if (~reset & auto_in_awvalid & auto_in_awsize > 3'h2) begin
      if (1)
        $error(
            "Assertion failed\n    at AXI4ToAPB.scala:65 assert(!(aw.valid && aw.bits.size > \"b10\".U))\n"
        );
      if (1) $fatal;
    end
  end
  reg [ 3:0] rid_reg;
  reg [ 3:0] bid_reg;
  reg [31:0] araddr_reg_r;
  reg [31:0] awaddr_reg_r;
  reg [31:0] wdata_reg_r;
  reg [ 3:0] wstrb_reg_r;
  assign nodeOut_penable = state == 2'h1;
  wire [ 1:0] resp = {auto_out_pslverr, 1'h0};
  reg  [ 1:0] resp_hold_r;
  wire [ 1:0] resp_hold = nodeOut_penable ? resp : resp_hold_r;
  wire        _nodeIn_bvalid_T_2 = state == 2'h2;
  wire        nodeIn_rvalid = ~is_write & (nodeOut_penable & auto_out_pready | _nodeIn_bvalid_T_2);
  reg  [31:0] nodeIn_rdata_r;
  wire        nodeIn_bvalid = is_write & (nodeOut_penable & auto_out_pready | _nodeIn_bvalid_T_2);
  always @(posedge clock) begin
    if (reset) state <= 2'h0;
    else begin
      automatic logic [3:0][1:0] _GEN;
      _GEN = {
        {state},
        {{~(auto_in_rready & nodeIn_rvalid | auto_in_bready & nodeIn_bvalid), 1'h0}},
        {
          auto_out_pready
            ? {~(auto_in_rready & nodeIn_rvalid | auto_in_bready & nodeIn_bvalid),
               1'h0}
            : 2'h1
        },
        {{1'h0, auto_in_arvalid | auto_in_awvalid & auto_in_wvalid}}
      };
      state <= _GEN[state];
    end
    if (_is_write_T) is_write_r <= accept_write;
    if (accept_read) begin
      rid_reg <= auto_in_arid;
      araddr_reg_r <= auto_in_araddr;
    end
    if (accept_write) begin
      bid_reg <= auto_in_awid;
      awaddr_reg_r <= auto_in_awaddr;
      wdata_reg_r <= auto_in_wdata;
      wstrb_reg_r <= auto_in_wstrb;
    end
    if (nodeOut_penable) begin
      resp_hold_r <= resp;
      nodeIn_rdata_r <= auto_out_prdata;
    end
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:4];
  end
  assign auto_in_awready = accept_write;
  assign auto_in_wready = accept_write;
  assign auto_in_bvalid = nodeIn_bvalid;
  assign auto_in_bid = bid_reg;
  assign auto_in_bresp = resp_hold;
  assign auto_in_arready = accept_read;
  assign auto_in_rvalid = nodeIn_rvalid;
  assign auto_in_rid = rid_reg;
  assign auto_in_rdata = nodeOut_penable ? auto_out_prdata : nodeIn_rdata_r;
  assign auto_in_rresp = resp_hold;
  assign auto_out_psel = accept_read | accept_write | nodeOut_penable;
  assign auto_out_penable = nodeOut_penable;
  assign auto_out_pwrite = is_write;
  assign auto_out_paddr =
    is_write
      ? (accept_write ? auto_in_awaddr : awaddr_reg_r)
      : accept_read ? auto_in_araddr : araddr_reg_r;
  assign auto_out_pwdata = accept_write ? auto_in_wdata : wdata_reg_r;
  assign auto_out_pstrb = is_write ? (accept_write ? auto_in_wstrb : wstrb_reg_r) : 4'h0;
endmodule
module Queue1_BundleMap (
    input  clock,
    reset,
    output io_enq_ready,
    input  io_enq_valid,
    io_enq_bits_real_last,
    io_deq_ready,
    output io_deq_valid,
    io_deq_bits_real_last
);
  reg ram_real_last;
  reg full;
  always @(posedge clock) begin
    automatic logic do_enq;
    do_enq = ~full & io_enq_valid;
    if (do_enq) ram_real_last <= io_enq_bits_real_last;
    if (reset) full <= 1'h0;
    else if (~(do_enq == (io_deq_ready & full))) full <= do_enq;
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:0];
  end
  assign io_enq_ready = ~full;
  assign io_deq_valid = full;
  assign io_deq_bits_real_last = ram_real_last;
endmodule
module AXI4UserYanker (
    input clock,
    reset,
    output auto_in_awready,
    input auto_in_awvalid,
    input [3:0] auto_in_awid,
    input [31:0] auto_in_awaddr,
    input [2:0] auto_in_awsize,
    input auto_in_awecho_real_last,
    output auto_in_wready,
    input auto_in_wvalid,
    input [31:0] auto_in_wdata,
    input [3:0] auto_in_wstrb,
    input auto_in_wlast,
    auto_in_bready,
    output auto_in_bvalid,
    output [3:0] auto_in_bid,
    output [1:0] auto_in_bresp,
    output auto_in_becho_real_last,
    auto_in_arready,
    input auto_in_arvalid,
    input [3:0] auto_in_arid,
    input [31:0] auto_in_araddr,
    input [2:0] auto_in_arsize,
    input auto_in_arecho_real_last,
    auto_in_rready,
    output auto_in_rvalid,
    output [3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [1:0] auto_in_rresp,
    output auto_in_recho_real_last,
    auto_in_rlast,
    input auto_out_awready,
    output auto_out_awvalid,
    output [3:0] auto_out_awid,
    output [31:0] auto_out_awaddr,
    output [2:0] auto_out_awsize,
    input auto_out_wready,
    output auto_out_wvalid,
    output [31:0] auto_out_wdata,
    output [3:0] auto_out_wstrb,
    output auto_out_wlast,
    auto_out_bready,
    input auto_out_bvalid,
    input [3:0] auto_out_bid,
    input [1:0] auto_out_bresp,
    input auto_out_arready,
    output auto_out_arvalid,
    output [3:0] auto_out_arid,
    output [31:0] auto_out_araddr,
    output [2:0] auto_out_arsize,
    output auto_out_rready,
    input auto_out_rvalid,
    input [3:0] auto_out_rid,
    input [31:0] auto_out_rdata,
    input [1:0] auto_out_rresp,
    input auto_out_rlast
);
  wire _Queue1_BundleMap_31_io_enq_ready;
  wire _Queue1_BundleMap_31_io_deq_valid;
  wire _Queue1_BundleMap_31_io_deq_bits_real_last;
  wire _Queue1_BundleMap_30_io_enq_ready;
  wire _Queue1_BundleMap_30_io_deq_valid;
  wire _Queue1_BundleMap_30_io_deq_bits_real_last;
  wire _Queue1_BundleMap_29_io_enq_ready;
  wire _Queue1_BundleMap_29_io_deq_valid;
  wire _Queue1_BundleMap_29_io_deq_bits_real_last;
  wire _Queue1_BundleMap_28_io_enq_ready;
  wire _Queue1_BundleMap_28_io_deq_valid;
  wire _Queue1_BundleMap_28_io_deq_bits_real_last;
  wire _Queue1_BundleMap_27_io_enq_ready;
  wire _Queue1_BundleMap_27_io_deq_valid;
  wire _Queue1_BundleMap_27_io_deq_bits_real_last;
  wire _Queue1_BundleMap_26_io_enq_ready;
  wire _Queue1_BundleMap_26_io_deq_valid;
  wire _Queue1_BundleMap_26_io_deq_bits_real_last;
  wire _Queue1_BundleMap_25_io_enq_ready;
  wire _Queue1_BundleMap_25_io_deq_valid;
  wire _Queue1_BundleMap_25_io_deq_bits_real_last;
  wire _Queue1_BundleMap_24_io_enq_ready;
  wire _Queue1_BundleMap_24_io_deq_valid;
  wire _Queue1_BundleMap_24_io_deq_bits_real_last;
  wire _Queue1_BundleMap_23_io_enq_ready;
  wire _Queue1_BundleMap_23_io_deq_valid;
  wire _Queue1_BundleMap_23_io_deq_bits_real_last;
  wire _Queue1_BundleMap_22_io_enq_ready;
  wire _Queue1_BundleMap_22_io_deq_valid;
  wire _Queue1_BundleMap_22_io_deq_bits_real_last;
  wire _Queue1_BundleMap_21_io_enq_ready;
  wire _Queue1_BundleMap_21_io_deq_valid;
  wire _Queue1_BundleMap_21_io_deq_bits_real_last;
  wire _Queue1_BundleMap_20_io_enq_ready;
  wire _Queue1_BundleMap_20_io_deq_valid;
  wire _Queue1_BundleMap_20_io_deq_bits_real_last;
  wire _Queue1_BundleMap_19_io_enq_ready;
  wire _Queue1_BundleMap_19_io_deq_valid;
  wire _Queue1_BundleMap_19_io_deq_bits_real_last;
  wire _Queue1_BundleMap_18_io_enq_ready;
  wire _Queue1_BundleMap_18_io_deq_valid;
  wire _Queue1_BundleMap_18_io_deq_bits_real_last;
  wire _Queue1_BundleMap_17_io_enq_ready;
  wire _Queue1_BundleMap_17_io_deq_valid;
  wire _Queue1_BundleMap_17_io_deq_bits_real_last;
  wire _Queue1_BundleMap_16_io_enq_ready;
  wire _Queue1_BundleMap_16_io_deq_valid;
  wire _Queue1_BundleMap_16_io_deq_bits_real_last;
  wire _Queue1_BundleMap_15_io_enq_ready;
  wire _Queue1_BundleMap_15_io_deq_valid;
  wire _Queue1_BundleMap_15_io_deq_bits_real_last;
  wire _Queue1_BundleMap_14_io_enq_ready;
  wire _Queue1_BundleMap_14_io_deq_valid;
  wire _Queue1_BundleMap_14_io_deq_bits_real_last;
  wire _Queue1_BundleMap_13_io_enq_ready;
  wire _Queue1_BundleMap_13_io_deq_valid;
  wire _Queue1_BundleMap_13_io_deq_bits_real_last;
  wire _Queue1_BundleMap_12_io_enq_ready;
  wire _Queue1_BundleMap_12_io_deq_valid;
  wire _Queue1_BundleMap_12_io_deq_bits_real_last;
  wire _Queue1_BundleMap_11_io_enq_ready;
  wire _Queue1_BundleMap_11_io_deq_valid;
  wire _Queue1_BundleMap_11_io_deq_bits_real_last;
  wire _Queue1_BundleMap_10_io_enq_ready;
  wire _Queue1_BundleMap_10_io_deq_valid;
  wire _Queue1_BundleMap_10_io_deq_bits_real_last;
  wire _Queue1_BundleMap_9_io_enq_ready;
  wire _Queue1_BundleMap_9_io_deq_valid;
  wire _Queue1_BundleMap_9_io_deq_bits_real_last;
  wire _Queue1_BundleMap_8_io_enq_ready;
  wire _Queue1_BundleMap_8_io_deq_valid;
  wire _Queue1_BundleMap_8_io_deq_bits_real_last;
  wire _Queue1_BundleMap_7_io_enq_ready;
  wire _Queue1_BundleMap_7_io_deq_valid;
  wire _Queue1_BundleMap_7_io_deq_bits_real_last;
  wire _Queue1_BundleMap_6_io_enq_ready;
  wire _Queue1_BundleMap_6_io_deq_valid;
  wire _Queue1_BundleMap_6_io_deq_bits_real_last;
  wire _Queue1_BundleMap_5_io_enq_ready;
  wire _Queue1_BundleMap_5_io_deq_valid;
  wire _Queue1_BundleMap_5_io_deq_bits_real_last;
  wire _Queue1_BundleMap_4_io_enq_ready;
  wire _Queue1_BundleMap_4_io_deq_valid;
  wire _Queue1_BundleMap_4_io_deq_bits_real_last;
  wire _Queue1_BundleMap_3_io_enq_ready;
  wire _Queue1_BundleMap_3_io_deq_valid;
  wire _Queue1_BundleMap_3_io_deq_bits_real_last;
  wire _Queue1_BundleMap_2_io_enq_ready;
  wire _Queue1_BundleMap_2_io_deq_valid;
  wire _Queue1_BundleMap_2_io_deq_bits_real_last;
  wire _Queue1_BundleMap_1_io_enq_ready;
  wire _Queue1_BundleMap_1_io_deq_valid;
  wire _Queue1_BundleMap_1_io_deq_bits_real_last;
  wire _Queue1_BundleMap_io_enq_ready;
  wire _Queue1_BundleMap_io_deq_valid;
  wire _Queue1_BundleMap_io_deq_bits_real_last;
  wire [15:0] _GEN = {
    {_Queue1_BundleMap_15_io_enq_ready},
    {_Queue1_BundleMap_14_io_enq_ready},
    {_Queue1_BundleMap_13_io_enq_ready},
    {_Queue1_BundleMap_12_io_enq_ready},
    {_Queue1_BundleMap_11_io_enq_ready},
    {_Queue1_BundleMap_10_io_enq_ready},
    {_Queue1_BundleMap_9_io_enq_ready},
    {_Queue1_BundleMap_8_io_enq_ready},
    {_Queue1_BundleMap_7_io_enq_ready},
    {_Queue1_BundleMap_6_io_enq_ready},
    {_Queue1_BundleMap_5_io_enq_ready},
    {_Queue1_BundleMap_4_io_enq_ready},
    {_Queue1_BundleMap_3_io_enq_ready},
    {_Queue1_BundleMap_2_io_enq_ready},
    {_Queue1_BundleMap_1_io_enq_ready},
    {_Queue1_BundleMap_io_enq_ready}
  };
  wire [15:0] _GEN_0 = {
    {_Queue1_BundleMap_15_io_deq_bits_real_last},
    {_Queue1_BundleMap_14_io_deq_bits_real_last},
    {_Queue1_BundleMap_13_io_deq_bits_real_last},
    {_Queue1_BundleMap_12_io_deq_bits_real_last},
    {_Queue1_BundleMap_11_io_deq_bits_real_last},
    {_Queue1_BundleMap_10_io_deq_bits_real_last},
    {_Queue1_BundleMap_9_io_deq_bits_real_last},
    {_Queue1_BundleMap_8_io_deq_bits_real_last},
    {_Queue1_BundleMap_7_io_deq_bits_real_last},
    {_Queue1_BundleMap_6_io_deq_bits_real_last},
    {_Queue1_BundleMap_5_io_deq_bits_real_last},
    {_Queue1_BundleMap_4_io_deq_bits_real_last},
    {_Queue1_BundleMap_3_io_deq_bits_real_last},
    {_Queue1_BundleMap_2_io_deq_bits_real_last},
    {_Queue1_BundleMap_1_io_deq_bits_real_last},
    {_Queue1_BundleMap_io_deq_bits_real_last}
  };
  wire _GEN_1 = auto_out_rvalid & auto_in_rready;
  wire _GEN_2 = auto_in_arvalid & auto_out_arready;
  wire [15:0] _GEN_3 = {
    {_Queue1_BundleMap_31_io_enq_ready},
    {_Queue1_BundleMap_30_io_enq_ready},
    {_Queue1_BundleMap_29_io_enq_ready},
    {_Queue1_BundleMap_28_io_enq_ready},
    {_Queue1_BundleMap_27_io_enq_ready},
    {_Queue1_BundleMap_26_io_enq_ready},
    {_Queue1_BundleMap_25_io_enq_ready},
    {_Queue1_BundleMap_24_io_enq_ready},
    {_Queue1_BundleMap_23_io_enq_ready},
    {_Queue1_BundleMap_22_io_enq_ready},
    {_Queue1_BundleMap_21_io_enq_ready},
    {_Queue1_BundleMap_20_io_enq_ready},
    {_Queue1_BundleMap_19_io_enq_ready},
    {_Queue1_BundleMap_18_io_enq_ready},
    {_Queue1_BundleMap_17_io_enq_ready},
    {_Queue1_BundleMap_16_io_enq_ready}
  };
  always @(posedge clock) begin
    automatic
    logic [15:0]
    _GEN_4 = {
      {_Queue1_BundleMap_15_io_deq_valid},
      {_Queue1_BundleMap_14_io_deq_valid},
      {_Queue1_BundleMap_13_io_deq_valid},
      {_Queue1_BundleMap_12_io_deq_valid},
      {_Queue1_BundleMap_11_io_deq_valid},
      {_Queue1_BundleMap_10_io_deq_valid},
      {_Queue1_BundleMap_9_io_deq_valid},
      {_Queue1_BundleMap_8_io_deq_valid},
      {_Queue1_BundleMap_7_io_deq_valid},
      {_Queue1_BundleMap_6_io_deq_valid},
      {_Queue1_BundleMap_5_io_deq_valid},
      {_Queue1_BundleMap_4_io_deq_valid},
      {_Queue1_BundleMap_3_io_deq_valid},
      {_Queue1_BundleMap_2_io_deq_valid},
      {_Queue1_BundleMap_1_io_deq_valid},
      {_Queue1_BundleMap_io_deq_valid}
    };
    automatic
    logic [15:0]
    _GEN_5 = {
      {_Queue1_BundleMap_31_io_deq_valid},
      {_Queue1_BundleMap_30_io_deq_valid},
      {_Queue1_BundleMap_29_io_deq_valid},
      {_Queue1_BundleMap_28_io_deq_valid},
      {_Queue1_BundleMap_27_io_deq_valid},
      {_Queue1_BundleMap_26_io_deq_valid},
      {_Queue1_BundleMap_25_io_deq_valid},
      {_Queue1_BundleMap_24_io_deq_valid},
      {_Queue1_BundleMap_23_io_deq_valid},
      {_Queue1_BundleMap_22_io_deq_valid},
      {_Queue1_BundleMap_21_io_deq_valid},
      {_Queue1_BundleMap_20_io_deq_valid},
      {_Queue1_BundleMap_19_io_deq_valid},
      {_Queue1_BundleMap_18_io_deq_valid},
      {_Queue1_BundleMap_17_io_deq_valid},
      {_Queue1_BundleMap_16_io_deq_valid}
    };
    if (~reset & ~(~auto_out_rvalid | _GEN_4[auto_out_rid])) begin
      if (1)
        $error(
            "Assertion failed\n    at UserYanker.scala:66 assert (!out.r.valid || r_valid) // Q must be ready faster than the response\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~auto_out_bvalid | _GEN_5[auto_out_bid])) begin
      if (1)
        $error(
            "Assertion failed\n    at UserYanker.scala:95 assert (!out.b.valid || b_valid) // Q must be ready faster than the response\n"
        );
      if (1) $fatal;
    end
  end
  wire [15:0] _GEN_6 = {
    {_Queue1_BundleMap_31_io_deq_bits_real_last},
    {_Queue1_BundleMap_30_io_deq_bits_real_last},
    {_Queue1_BundleMap_29_io_deq_bits_real_last},
    {_Queue1_BundleMap_28_io_deq_bits_real_last},
    {_Queue1_BundleMap_27_io_deq_bits_real_last},
    {_Queue1_BundleMap_26_io_deq_bits_real_last},
    {_Queue1_BundleMap_25_io_deq_bits_real_last},
    {_Queue1_BundleMap_24_io_deq_bits_real_last},
    {_Queue1_BundleMap_23_io_deq_bits_real_last},
    {_Queue1_BundleMap_22_io_deq_bits_real_last},
    {_Queue1_BundleMap_21_io_deq_bits_real_last},
    {_Queue1_BundleMap_20_io_deq_bits_real_last},
    {_Queue1_BundleMap_19_io_deq_bits_real_last},
    {_Queue1_BundleMap_18_io_deq_bits_real_last},
    {_Queue1_BundleMap_17_io_deq_bits_real_last},
    {_Queue1_BundleMap_16_io_deq_bits_real_last}
  };
  wire _GEN_7 = auto_out_bvalid & auto_in_bready;
  wire _GEN_8 = auto_in_awvalid & auto_out_awready;
  Queue1_BundleMap Queue1_BundleMap (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h0),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h0 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_1 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_1_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h1),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h1 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_1_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_1_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_2 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_2_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h2),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h2 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_2_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_2_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_3 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_3_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h3),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h3 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_3_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_3_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_4 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_4_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h4),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h4 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_4_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_4_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_5 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_5_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h5),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h5 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_5_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_5_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_6 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_6_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h6),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h6 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_6_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_6_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_7 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_7_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h7),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h7 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_7_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_7_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_8 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_8_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h8),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h8 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_8_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_8_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_9 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_9_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'h9),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'h9 & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_9_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_9_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_10 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_10_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'hA),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'hA & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_10_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_10_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_11 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_11_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'hB),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'hB & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_11_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_11_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_12 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_12_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'hC),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'hC & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_12_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_12_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_13 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_13_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'hD),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'hD & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_13_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_13_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_14 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_14_io_enq_ready),
      .io_enq_valid         (_GEN_2 & auto_in_arid == 4'hE),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & auto_out_rid == 4'hE & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_14_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_14_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_15 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_15_io_enq_ready),
      .io_enq_valid         (_GEN_2 & (&auto_in_arid)),
      .io_enq_bits_real_last(auto_in_arecho_real_last),
      .io_deq_ready         (_GEN_1 & (&auto_out_rid) & auto_out_rlast),
      .io_deq_valid         (_Queue1_BundleMap_15_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_15_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_16 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_16_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h0),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h0),
      .io_deq_valid         (_Queue1_BundleMap_16_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_16_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_17 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_17_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h1),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h1),
      .io_deq_valid         (_Queue1_BundleMap_17_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_17_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_18 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_18_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h2),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h2),
      .io_deq_valid         (_Queue1_BundleMap_18_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_18_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_19 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_19_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h3),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h3),
      .io_deq_valid         (_Queue1_BundleMap_19_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_19_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_20 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_20_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h4),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h4),
      .io_deq_valid         (_Queue1_BundleMap_20_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_20_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_21 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_21_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h5),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h5),
      .io_deq_valid         (_Queue1_BundleMap_21_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_21_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_22 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_22_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h6),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h6),
      .io_deq_valid         (_Queue1_BundleMap_22_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_22_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_23 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_23_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h7),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h7),
      .io_deq_valid         (_Queue1_BundleMap_23_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_23_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_24 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_24_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h8),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h8),
      .io_deq_valid         (_Queue1_BundleMap_24_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_24_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_25 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_25_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'h9),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'h9),
      .io_deq_valid         (_Queue1_BundleMap_25_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_25_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_26 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_26_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'hA),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'hA),
      .io_deq_valid         (_Queue1_BundleMap_26_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_26_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_27 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_27_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'hB),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'hB),
      .io_deq_valid         (_Queue1_BundleMap_27_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_27_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_28 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_28_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'hC),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'hC),
      .io_deq_valid         (_Queue1_BundleMap_28_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_28_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_29 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_29_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'hD),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'hD),
      .io_deq_valid         (_Queue1_BundleMap_29_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_29_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_30 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_30_io_enq_ready),
      .io_enq_valid         (_GEN_8 & auto_in_awid == 4'hE),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & auto_out_bid == 4'hE),
      .io_deq_valid         (_Queue1_BundleMap_30_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_30_io_deq_bits_real_last)
  );
  Queue1_BundleMap Queue1_BundleMap_31 (
      .clock                (clock),
      .reset                (reset),
      .io_enq_ready         (_Queue1_BundleMap_31_io_enq_ready),
      .io_enq_valid         (_GEN_8 & (&auto_in_awid)),
      .io_enq_bits_real_last(auto_in_awecho_real_last),
      .io_deq_ready         (_GEN_7 & (&auto_out_bid)),
      .io_deq_valid         (_Queue1_BundleMap_31_io_deq_valid),
      .io_deq_bits_real_last(_Queue1_BundleMap_31_io_deq_bits_real_last)
  );
  assign auto_in_awready = auto_out_awready & _GEN_3[auto_in_awid];
  assign auto_in_wready = auto_out_wready;
  assign auto_in_bvalid = auto_out_bvalid;
  assign auto_in_bid = auto_out_bid;
  assign auto_in_bresp = auto_out_bresp;
  assign auto_in_becho_real_last = _GEN_6[auto_out_bid];
  assign auto_in_arready = auto_out_arready & _GEN[auto_in_arid];
  assign auto_in_rvalid = auto_out_rvalid;
  assign auto_in_rid = auto_out_rid;
  assign auto_in_rdata = auto_out_rdata;
  assign auto_in_rresp = auto_out_rresp;
  assign auto_in_recho_real_last = _GEN_0[auto_out_rid];
  assign auto_in_rlast = auto_out_rlast;
  assign auto_out_awvalid = auto_in_awvalid & _GEN_3[auto_in_awid];
  assign auto_out_awid = auto_in_awid;
  assign auto_out_awaddr = auto_in_awaddr;
  assign auto_out_awsize = auto_in_awsize;
  assign auto_out_wvalid = auto_in_wvalid;
  assign auto_out_wdata = auto_in_wdata;
  assign auto_out_wstrb = auto_in_wstrb;
  assign auto_out_wlast = auto_in_wlast;
  assign auto_out_bready = auto_in_bready;
  assign auto_out_arvalid = auto_in_arvalid & _GEN[auto_in_arid];
  assign auto_out_arid = auto_in_arid;
  assign auto_out_araddr = auto_in_araddr;
  assign auto_out_arsize = auto_in_arsize;
  assign auto_out_rready = auto_in_rready;
endmodule
module Queue1_AXI4BundleAR (
    input         clock,
    reset,
    output        io_enq_ready,
    input         io_enq_valid,
    input  [ 3:0] io_enq_bits_id,
    input  [31:0] io_enq_bits_addr,
    input  [ 7:0] io_enq_bits_len,
    input  [ 2:0] io_enq_bits_size,
    input  [ 1:0] io_enq_bits_burst,
    input         io_deq_ready,
    output        io_deq_valid,
    output [ 3:0] io_deq_bits_id,
    output [31:0] io_deq_bits_addr,
    output [ 7:0] io_deq_bits_len,
    output [ 2:0] io_deq_bits_size,
    output [ 1:0] io_deq_bits_burst
);
  reg  [48:0] ram;
  reg         full;
  wire        io_deq_valid_0 = io_enq_valid | full;
  wire        do_enq = ~(~full & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (do_enq)
      ram <= {
        io_enq_bits_burst, io_enq_bits_size, io_enq_bits_len, io_enq_bits_addr, io_enq_bits_id
      };
    if (reset) full <= 1'h0;
    else if (~(do_enq == (full & io_deq_ready & io_deq_valid_0))) full <= do_enq;
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:1];
  end
  assign io_enq_ready = ~full;
  assign io_deq_valid = io_deq_valid_0;
  assign io_deq_bits_id = full ? ram[3:0] : io_enq_bits_id;
  assign io_deq_bits_addr = full ? ram[35:4] : io_enq_bits_addr;
  assign io_deq_bits_len = full ? ram[43:36] : io_enq_bits_len;
  assign io_deq_bits_size = full ? ram[46:44] : io_enq_bits_size;
  assign io_deq_bits_burst = full ? ram[48:47] : io_enq_bits_burst;
endmodule
module Queue1_AXI4BundleAW (
    input         clock,
    reset,
    output        io_enq_ready,
    input         io_enq_valid,
    input  [ 3:0] io_enq_bits_id,
    input  [31:0] io_enq_bits_addr,
    input  [ 7:0] io_enq_bits_len,
    input  [ 2:0] io_enq_bits_size,
    input  [ 1:0] io_enq_bits_burst,
    input         io_deq_ready,
    output        io_deq_valid,
    output [ 3:0] io_deq_bits_id,
    output [31:0] io_deq_bits_addr,
    output [ 7:0] io_deq_bits_len,
    output [ 2:0] io_deq_bits_size,
    output [ 1:0] io_deq_bits_burst
);
  reg  [48:0] ram;
  reg         full;
  wire        io_deq_valid_0 = io_enq_valid | full;
  wire        do_enq = ~(~full & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (do_enq)
      ram <= {
        io_enq_bits_burst, io_enq_bits_size, io_enq_bits_len, io_enq_bits_addr, io_enq_bits_id
      };
    if (reset) full <= 1'h0;
    else if (~(do_enq == (full & io_deq_ready & io_deq_valid_0))) full <= do_enq;
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:1];
  end
  assign io_enq_ready = ~full;
  assign io_deq_valid = io_deq_valid_0;
  assign io_deq_bits_id = full ? ram[3:0] : io_enq_bits_id;
  assign io_deq_bits_addr = full ? ram[35:4] : io_enq_bits_addr;
  assign io_deq_bits_len = full ? ram[43:36] : io_enq_bits_len;
  assign io_deq_bits_size = full ? ram[46:44] : io_enq_bits_size;
  assign io_deq_bits_burst = full ? ram[48:47] : io_enq_bits_burst;
endmodule
module Queue1_AXI4BundleW (
    input         clock,
    reset,
    output        io_enq_ready,
    input         io_enq_valid,
    input  [31:0] io_enq_bits_data,
    input  [ 3:0] io_enq_bits_strb,
    input         io_enq_bits_last,
    io_deq_ready,
    output        io_deq_valid,
    output [31:0] io_deq_bits_data,
    output [ 3:0] io_deq_bits_strb,
    output        io_deq_bits_last
);
  reg  [36:0] ram;
  reg         full;
  wire        io_deq_valid_0 = io_enq_valid | full;
  wire        do_enq = ~(~full & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (do_enq) ram <= {io_enq_bits_last, io_enq_bits_strb, io_enq_bits_data};
    if (reset) full <= 1'h0;
    else if (~(do_enq == (full & io_deq_ready & io_deq_valid_0))) full <= do_enq;
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:1];
  end
  assign io_enq_ready = ~full;
  assign io_deq_valid = io_deq_valid_0;
  assign io_deq_bits_data = full ? ram[31:0] : io_enq_bits_data;
  assign io_deq_bits_strb = full ? ram[35:32] : io_enq_bits_strb;
  assign io_deq_bits_last = full ? ram[36] : io_enq_bits_last;
endmodule
module AXI4Fragmenter (
    input         clock,
    reset,
    output        auto_in_awready,
    input         auto_in_awvalid,
    input  [ 3:0] auto_in_awid,
    input  [31:0] auto_in_awaddr,
    input  [ 7:0] auto_in_awlen,
    input  [ 2:0] auto_in_awsize,
    input  [ 1:0] auto_in_awburst,
    output        auto_in_wready,
    input         auto_in_wvalid,
    input  [31:0] auto_in_wdata,
    input  [ 3:0] auto_in_wstrb,
    input         auto_in_wlast,
    auto_in_bready,
    output        auto_in_bvalid,
    output [ 3:0] auto_in_bid,
    output [ 1:0] auto_in_bresp,
    output        auto_in_arready,
    input         auto_in_arvalid,
    input  [ 3:0] auto_in_arid,
    input  [31:0] auto_in_araddr,
    input  [ 7:0] auto_in_arlen,
    input  [ 2:0] auto_in_arsize,
    input  [ 1:0] auto_in_arburst,
    input         auto_in_rready,
    output        auto_in_rvalid,
    output [ 3:0] auto_in_rid,
    output [31:0] auto_in_rdata,
    output [ 1:0] auto_in_rresp,
    output        auto_in_rlast,
    input         auto_out_awready,
    output        auto_out_awvalid,
    output [ 3:0] auto_out_awid,
    output [31:0] auto_out_awaddr,
    output [ 2:0] auto_out_awsize,
    output        auto_out_awecho_real_last,
    input         auto_out_wready,
    output        auto_out_wvalid,
    output [31:0] auto_out_wdata,
    output [ 3:0] auto_out_wstrb,
    output        auto_out_wlast,
    auto_out_bready,
    input         auto_out_bvalid,
    input  [ 3:0] auto_out_bid,
    input  [ 1:0] auto_out_bresp,
    input         auto_out_becho_real_last,
    auto_out_arready,
    output        auto_out_arvalid,
    output [ 3:0] auto_out_arid,
    output [31:0] auto_out_araddr,
    output [ 2:0] auto_out_arsize,
    output        auto_out_arecho_real_last,
    auto_out_rready,
    input         auto_out_rvalid,
    input  [ 3:0] auto_out_rid,
    input  [31:0] auto_out_rdata,
    input  [ 1:0] auto_out_rresp,
    input         auto_out_recho_real_last,
    auto_out_rlast
);
  wire        nodeOut_wvalid;
  wire        w_idle;
  wire        in_awready;
  wire        _in_wdeq_q_io_deq_valid;
  wire        _in_wdeq_q_io_deq_bits_last;
  wire        _deq_q_1_io_deq_valid;
  wire [31:0] _deq_q_1_io_deq_bits_addr;
  wire [ 7:0] _deq_q_1_io_deq_bits_len;
  wire [ 2:0] _deq_q_1_io_deq_bits_size;
  wire [ 1:0] _deq_q_1_io_deq_bits_burst;
  wire        _deq_q_io_deq_valid;
  wire [31:0] _deq_q_io_deq_bits_addr;
  wire [ 7:0] _deq_q_io_deq_bits_len;
  wire [ 2:0] _deq_q_io_deq_bits_size;
  wire [ 1:0] _deq_q_io_deq_bits_burst;
  reg         busy;
  reg  [31:0] r_addr;
  reg  [ 7:0] r_len;
  wire [ 7:0] len = busy ? r_len : _deq_q_io_deq_bits_len;
  wire [31:0] addr = busy ? r_addr : _deq_q_io_deq_bits_addr;
  wire [31:0] _out_bits_addr_T = ~addr;
  wire [ 8:0] _out_bits_addr_T_2 = 9'h3 << _deq_q_io_deq_bits_size;
  reg         busy_1;
  reg  [31:0] r_addr_1;
  reg  [ 7:0] r_len_1;
  wire [ 7:0] len_1 = busy_1 ? r_len_1 : _deq_q_1_io_deq_bits_len;
  wire [31:0] addr_1 = busy_1 ? r_addr_1 : _deq_q_1_io_deq_bits_addr;
  wire [31:0] _out_bits_addr_T_7 = ~addr_1;
  wire [ 8:0] _out_bits_addr_T_9 = 9'h3 << _deq_q_1_io_deq_bits_size;
  reg         wbeats_latched;
  wire        _in_awready_T = w_idle | wbeats_latched;
  wire        nodeOut_awvalid = _deq_q_1_io_deq_valid & _in_awready_T;
  assign in_awready = auto_out_awready & _in_awready_T;
  wire       wbeats_valid = _deq_q_1_io_deq_valid & ~wbeats_latched;
  reg  [8:0] w_counter;
  assign w_idle = w_counter == 9'h0;
  wire [8:0] w_todo = w_idle ? {8'h0, wbeats_valid} : w_counter;
  wire       w_last = w_todo == 9'h1;
  wire       _wcounter_T = auto_out_wready & nodeOut_wvalid;
  assign nodeOut_wvalid = _in_wdeq_q_io_deq_valid & (~w_idle | wbeats_valid);
  always @(posedge clock) begin
    if (~reset & ~(~_wcounter_T | (|w_todo))) begin
      if (1)
        $error(
            "Assertion failed\n    at Fragmenter.scala:177 assert (!out.w.fire || w_todo =/= 0.U) // underflow impossible\n"
        );
      if (1) $fatal;
    end
    if (~reset & ~(~nodeOut_wvalid | ~_in_wdeq_q_io_deq_bits_last | w_last)) begin
      if (1)
        $error(
            "Assertion failed\n    at Fragmenter.scala:186 assert (!out.w.valid || !in_w.bits.last || w_last)\n"
        );
      if (1) $fatal;
    end
  end
  wire nodeOut_bready = auto_in_bready | ~auto_out_becho_real_last;
  reg [1:0] error_0;
  reg [1:0] error_1;
  reg [1:0] error_2;
  reg [1:0] error_3;
  reg [1:0] error_4;
  reg [1:0] error_5;
  reg [1:0] error_6;
  reg [1:0] error_7;
  reg [1:0] error_8;
  reg [1:0] error_9;
  reg [1:0] error_10;
  reg [1:0] error_11;
  reg [1:0] error_12;
  reg [1:0] error_13;
  reg [1:0] error_14;
  reg [1:0] error_15;
  wire [15:0][1:0] _GEN = {
    {error_15},
    {error_14},
    {error_13},
    {error_12},
    {error_11},
    {error_10},
    {error_9},
    {error_8},
    {error_7},
    {error_6},
    {error_5},
    {error_4},
    {error_3},
    {error_2},
    {error_1},
    {error_0}
  };
  always @(posedge clock) begin
    automatic logic _GEN_0;
    automatic logic _GEN_1;
    _GEN_0 = auto_out_arready & _deq_q_io_deq_valid;
    _GEN_1 = in_awready & _deq_q_1_io_deq_valid;
    if (reset) begin
      busy <= 1'h0;
      busy_1 <= 1'h0;
      wbeats_latched <= 1'h0;
      w_counter <= 9'h0;
      error_0 <= 2'h0;
      error_1 <= 2'h0;
      error_2 <= 2'h0;
      error_3 <= 2'h0;
      error_4 <= 2'h0;
      error_5 <= 2'h0;
      error_6 <= 2'h0;
      error_7 <= 2'h0;
      error_8 <= 2'h0;
      error_9 <= 2'h0;
      error_10 <= 2'h0;
      error_11 <= 2'h0;
      error_12 <= 2'h0;
      error_13 <= 2'h0;
      error_14 <= 2'h0;
      error_15 <= 2'h0;
    end else begin
      automatic logic _GEN_2 = nodeOut_bready & auto_out_bvalid;
      if (_GEN_0) busy <= |len;
      if (_GEN_1) busy_1 <= |len_1;
      wbeats_latched <=
        ~(auto_out_awready & nodeOut_awvalid)
        & (wbeats_valid & w_idle | wbeats_latched);
      w_counter <= w_todo - {8'h0, _wcounter_T};
      if (auto_out_bid == 4'h0 & _GEN_2) begin
        if (auto_out_becho_real_last) error_0 <= 2'h0;
        else error_0 <= error_0 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h1 & _GEN_2) begin
        if (auto_out_becho_real_last) error_1 <= 2'h0;
        else error_1 <= error_1 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h2 & _GEN_2) begin
        if (auto_out_becho_real_last) error_2 <= 2'h0;
        else error_2 <= error_2 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h3 & _GEN_2) begin
        if (auto_out_becho_real_last) error_3 <= 2'h0;
        else error_3 <= error_3 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h4 & _GEN_2) begin
        if (auto_out_becho_real_last) error_4 <= 2'h0;
        else error_4 <= error_4 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h5 & _GEN_2) begin
        if (auto_out_becho_real_last) error_5 <= 2'h0;
        else error_5 <= error_5 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h6 & _GEN_2) begin
        if (auto_out_becho_real_last) error_6 <= 2'h0;
        else error_6 <= error_6 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h7 & _GEN_2) begin
        if (auto_out_becho_real_last) error_7 <= 2'h0;
        else error_7 <= error_7 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h8 & _GEN_2) begin
        if (auto_out_becho_real_last) error_8 <= 2'h0;
        else error_8 <= error_8 | auto_out_bresp;
      end
      if (auto_out_bid == 4'h9 & _GEN_2) begin
        if (auto_out_becho_real_last) error_9 <= 2'h0;
        else error_9 <= error_9 | auto_out_bresp;
      end
      if (auto_out_bid == 4'hA & _GEN_2) begin
        if (auto_out_becho_real_last) error_10 <= 2'h0;
        else error_10 <= error_10 | auto_out_bresp;
      end
      if (auto_out_bid == 4'hB & _GEN_2) begin
        if (auto_out_becho_real_last) error_11 <= 2'h0;
        else error_11 <= error_11 | auto_out_bresp;
      end
      if (auto_out_bid == 4'hC & _GEN_2) begin
        if (auto_out_becho_real_last) error_12 <= 2'h0;
        else error_12 <= error_12 | auto_out_bresp;
      end
      if (auto_out_bid == 4'hD & _GEN_2) begin
        if (auto_out_becho_real_last) error_13 <= 2'h0;
        else error_13 <= error_13 | auto_out_bresp;
      end
      if (auto_out_bid == 4'hE & _GEN_2) begin
        if (auto_out_becho_real_last) error_14 <= 2'h0;
        else error_14 <= error_14 | auto_out_bresp;
      end
      if ((&auto_out_bid) & _GEN_2) begin
        if (auto_out_becho_real_last) error_15 <= 2'h0;
        else error_15 <= error_15 | auto_out_bresp;
      end
    end
    if (_GEN_0) begin
      if (_deq_q_io_deq_bits_burst == 2'h0) r_addr <= _deq_q_io_deq_bits_addr;
      else begin
        automatic logic [31:0] _inc_addr_T_1;
        _inc_addr_T_1 = addr + {16'h0, 16'h1 << _deq_q_io_deq_bits_size};
        if (_deq_q_io_deq_bits_burst == 2'h2) begin
          automatic
          logic [22:0]
          _wrapMask_T_1 = {7'h0, _deq_q_io_deq_bits_len, 8'hFF} << _deq_q_io_deq_bits_size;
          automatic logic [31:0] _mux_addr_T_1 = ~_deq_q_io_deq_bits_addr;
          r_addr <=
            {17'h0, _inc_addr_T_1[14:0] & _wrapMask_T_1[22:8]}
            | ~{_mux_addr_T_1[31:15], _mux_addr_T_1[14:0] | _wrapMask_T_1[22:8]};
        end else r_addr <= _inc_addr_T_1;
      end
      r_len <= len - 8'h1;
    end
    if (_GEN_1) begin
      if (_deq_q_1_io_deq_bits_burst == 2'h0) r_addr_1 <= _deq_q_1_io_deq_bits_addr;
      else begin
        automatic logic [31:0] _inc_addr_T_3;
        _inc_addr_T_3 = addr_1 + {16'h0, 16'h1 << _deq_q_1_io_deq_bits_size};
        if (_deq_q_1_io_deq_bits_burst == 2'h2) begin
          automatic
          logic [22:0]
          _wrapMask_T_3 = {7'h0, _deq_q_1_io_deq_bits_len, 8'hFF} << _deq_q_1_io_deq_bits_size;
          automatic logic [31:0] _mux_addr_T_6 = ~_deq_q_1_io_deq_bits_addr;
          r_addr_1 <=
            {17'h0, _inc_addr_T_3[14:0] & _wrapMask_T_3[22:8]}
            | ~{_mux_addr_T_6[31:15], _mux_addr_T_6[14:0] | _wrapMask_T_3[22:8]};
        end else r_addr_1 <= _inc_addr_T_3;
      end
      r_len_1 <= len_1 - 8'h1;
    end
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:3];
  end
  Queue1_AXI4BundleAR deq_q (
      .clock            (clock),
      .reset            (reset),
      .io_enq_ready     (auto_in_arready),
      .io_enq_valid     (auto_in_arvalid),
      .io_enq_bits_id   (auto_in_arid),
      .io_enq_bits_addr (auto_in_araddr),
      .io_enq_bits_len  (auto_in_arlen),
      .io_enq_bits_size (auto_in_arsize),
      .io_enq_bits_burst(auto_in_arburst),
      .io_deq_ready     (auto_out_arready & ~(|len)),
      .io_deq_valid     (_deq_q_io_deq_valid),
      .io_deq_bits_id   (auto_out_arid),
      .io_deq_bits_addr (_deq_q_io_deq_bits_addr),
      .io_deq_bits_len  (_deq_q_io_deq_bits_len),
      .io_deq_bits_size (_deq_q_io_deq_bits_size),
      .io_deq_bits_burst(_deq_q_io_deq_bits_burst)
  );
  Queue1_AXI4BundleAW deq_q_1 (
      .clock            (clock),
      .reset            (reset),
      .io_enq_ready     (auto_in_awready),
      .io_enq_valid     (auto_in_awvalid),
      .io_enq_bits_id   (auto_in_awid),
      .io_enq_bits_addr (auto_in_awaddr),
      .io_enq_bits_len  (auto_in_awlen),
      .io_enq_bits_size (auto_in_awsize),
      .io_enq_bits_burst(auto_in_awburst),
      .io_deq_ready     (in_awready & ~(|len_1)),
      .io_deq_valid     (_deq_q_1_io_deq_valid),
      .io_deq_bits_id   (auto_out_awid),
      .io_deq_bits_addr (_deq_q_1_io_deq_bits_addr),
      .io_deq_bits_len  (_deq_q_1_io_deq_bits_len),
      .io_deq_bits_size (_deq_q_1_io_deq_bits_size),
      .io_deq_bits_burst(_deq_q_1_io_deq_bits_burst)
  );
  Queue1_AXI4BundleW in_wdeq_q (
      .clock           (clock),
      .reset           (reset),
      .io_enq_ready    (auto_in_wready),
      .io_enq_valid    (auto_in_wvalid),
      .io_enq_bits_data(auto_in_wdata),
      .io_enq_bits_strb(auto_in_wstrb),
      .io_enq_bits_last(auto_in_wlast),
      .io_deq_ready    (auto_out_wready & (~w_idle | wbeats_valid)),
      .io_deq_valid    (_in_wdeq_q_io_deq_valid),
      .io_deq_bits_data(auto_out_wdata),
      .io_deq_bits_strb(auto_out_wstrb),
      .io_deq_bits_last(_in_wdeq_q_io_deq_bits_last)
  );
  assign auto_in_bvalid = auto_out_bvalid & auto_out_becho_real_last;
  assign auto_in_bid = auto_out_bid;
  assign auto_in_bresp = auto_out_bresp | _GEN[auto_out_bid];
  assign auto_in_rvalid = auto_out_rvalid;
  assign auto_in_rid = auto_out_rid;
  assign auto_in_rdata = auto_out_rdata;
  assign auto_in_rresp = auto_out_rresp;
  assign auto_in_rlast = auto_out_rlast & auto_out_recho_real_last;
  assign auto_out_awvalid = nodeOut_awvalid;
  assign auto_out_awaddr =
    ~{_out_bits_addr_T_7[31:2], _out_bits_addr_T_7[1:0] | ~(_out_bits_addr_T_9[1:0])};
  assign auto_out_awsize = _deq_q_1_io_deq_bits_size;
  assign auto_out_awecho_real_last = ~(|len_1);
  assign auto_out_wvalid = nodeOut_wvalid;
  assign auto_out_wlast = w_last;
  assign auto_out_bready = nodeOut_bready;
  assign auto_out_arvalid = _deq_q_io_deq_valid;
  assign auto_out_araddr =
    ~{_out_bits_addr_T[31:2], _out_bits_addr_T[1:0] | ~(_out_bits_addr_T_2[1:0])};
  assign auto_out_arsize = _deq_q_io_deq_bits_size;
  assign auto_out_arecho_real_last = ~(|len);
  assign auto_out_rready = auto_in_rready;
endmodule
module NonSyncResetSynchronizerPrimitiveShiftReg_d10 (
    input  clock,
    io_d,
    output io_q
);
  reg sync_0;
  reg sync_1;
  reg sync_2;
  reg sync_3;
  reg sync_4;
  reg sync_5;
  reg sync_6;
  reg sync_7;
  reg sync_8;
  reg sync_9;
  always @(posedge clock) begin
    sync_0 <= sync_1;
    sync_1 <= sync_2;
    sync_2 <= sync_3;
    sync_3 <= sync_4;
    sync_4 <= sync_5;
    sync_5 <= sync_6;
    sync_6 <= sync_7;
    sync_7 <= sync_8;
    sync_8 <= sync_9;
    sync_9 <= io_d;
  end
  initial begin
    automatic logic [31:0] _RANDOM[0:0];
  end
  assign io_q = sync_0;
endmodule
module SynchronizerShiftReg_w1_d10 (
    input  clock,
    io_d,
    output io_q
);
  NonSyncResetSynchronizerPrimitiveShiftReg_d10 output_chain (
      .clock(clock),
      .io_d (io_d),
      .io_q (io_q)
  );
endmodule
module ysyxSoCASIC (
    input         clock,
    reset,
    output        spi_sck,
    output [ 7:0] spi_ss,
    output        spi_mosi,
    input         spi_miso,
    uart_rx,
    output        uart_tx,
    sdram_clk,
    sdram_cke,
    sdram_cs,
    sdram_ras,
    sdram_cas,
    sdram_we,
    output [12:0] sdram_a,
    output [ 1:0] sdram_ba,
    output [ 3:0] sdram_dqm,
    inout  [31:0] sdram_dq,
    output [15:0] gpio_out,
    input  [15:0] gpio_in,
    output [ 7:0] gpio_seg_0,
    gpio_seg_1,
    gpio_seg_2,
    gpio_seg_3,
    gpio_seg_4,
    gpio_seg_5,
    gpio_seg_6,
    gpio_seg_7,
    input         ps2_clk,
    ps2_data,
    output [ 7:0] vga_r,
    vga_g,
    vga_b,
    output        vga_hsync,
    vga_vsync,
    vga_valid
);
  wire        _cpu_reset_chain_io_q;
  wire        _axi4frag_auto_in_awready;
  wire        _axi4frag_auto_in_wready;
  wire        _axi4frag_auto_in_bvalid;
  wire [ 3:0] _axi4frag_auto_in_bid;
  wire [ 1:0] _axi4frag_auto_in_bresp;
  wire        _axi4frag_auto_in_arready;
  wire        _axi4frag_auto_in_rvalid;
  wire [ 3:0] _axi4frag_auto_in_rid;
  wire [31:0] _axi4frag_auto_in_rdata;
  wire [ 1:0] _axi4frag_auto_in_rresp;
  wire        _axi4frag_auto_in_rlast;
  wire        _axi4frag_auto_out_awvalid;
  wire [ 3:0] _axi4frag_auto_out_awid;
  wire [31:0] _axi4frag_auto_out_awaddr;
  wire [ 2:0] _axi4frag_auto_out_awsize;
  wire        _axi4frag_auto_out_awecho_real_last;
  wire        _axi4frag_auto_out_wvalid;
  wire [31:0] _axi4frag_auto_out_wdata;
  wire [ 3:0] _axi4frag_auto_out_wstrb;
  wire        _axi4frag_auto_out_wlast;
  wire        _axi4frag_auto_out_bready;
  wire        _axi4frag_auto_out_arvalid;
  wire [ 3:0] _axi4frag_auto_out_arid;
  wire [31:0] _axi4frag_auto_out_araddr;
  wire [ 2:0] _axi4frag_auto_out_arsize;
  wire        _axi4frag_auto_out_arecho_real_last;
  wire        _axi4frag_auto_out_rready;
  wire        _axi4yank_auto_in_awready;
  wire        _axi4yank_auto_in_wready;
  wire        _axi4yank_auto_in_bvalid;
  wire [ 3:0] _axi4yank_auto_in_bid;
  wire [ 1:0] _axi4yank_auto_in_bresp;
  wire        _axi4yank_auto_in_becho_real_last;
  wire        _axi4yank_auto_in_arready;
  wire        _axi4yank_auto_in_rvalid;
  wire [ 3:0] _axi4yank_auto_in_rid;
  wire [31:0] _axi4yank_auto_in_rdata;
  wire [ 1:0] _axi4yank_auto_in_rresp;
  wire        _axi4yank_auto_in_recho_real_last;
  wire        _axi4yank_auto_in_rlast;
  wire        _axi4yank_auto_out_awvalid;
  wire [ 3:0] _axi4yank_auto_out_awid;
  wire [31:0] _axi4yank_auto_out_awaddr;
  wire [ 2:0] _axi4yank_auto_out_awsize;
  wire        _axi4yank_auto_out_wvalid;
  wire [31:0] _axi4yank_auto_out_wdata;
  wire [ 3:0] _axi4yank_auto_out_wstrb;
  wire        _axi4yank_auto_out_wlast;
  wire        _axi4yank_auto_out_bready;
  wire        _axi4yank_auto_out_arvalid;
  wire [ 3:0] _axi4yank_auto_out_arid;
  wire [31:0] _axi4yank_auto_out_araddr;
  wire [ 2:0] _axi4yank_auto_out_arsize;
  wire        _axi4yank_auto_out_rready;
  wire        _axi42apb_auto_in_awready;
  wire        _axi42apb_auto_in_wready;
  wire        _axi42apb_auto_in_bvalid;
  wire [ 3:0] _axi42apb_auto_in_bid;
  wire [ 1:0] _axi42apb_auto_in_bresp;
  wire        _axi42apb_auto_in_arready;
  wire        _axi42apb_auto_in_rvalid;
  wire [ 3:0] _axi42apb_auto_in_rid;
  wire [31:0] _axi42apb_auto_in_rdata;
  wire [ 1:0] _axi42apb_auto_in_rresp;
  wire        _axi42apb_auto_out_psel;
  wire        _axi42apb_auto_out_penable;
  wire        _axi42apb_auto_out_pwrite;
  wire [31:0] _axi42apb_auto_out_paddr;
  wire [31:0] _axi42apb_auto_out_pwdata;
  wire [ 3:0] _axi42apb_auto_out_pstrb;
  wire        _apbdelay_delayer_in_pready;
  wire        _apbdelay_delayer_in_pslverr;
  wire [31:0] _apbdelay_delayer_in_prdata;
  wire        _apbdelay_delayer_out_psel;
  wire        _apbdelay_delayer_out_penable;
  wire        _apbdelay_delayer_out_pwrite;
  wire [31:0] _apbdelay_delayer_out_paddr;
  wire [ 2:0] _apbdelay_delayer_out_pprot;
  wire [31:0] _apbdelay_delayer_out_pwdata;
  wire [ 3:0] _apbdelay_delayer_out_pstrb;
  wire        _lsdram_apb_auto_in_pready;
  wire        _lsdram_apb_auto_in_pslverr;
  wire [31:0] _lsdram_apb_auto_in_prdata;
  wire        _axi4ram_auto_in_awready;
  wire        _axi4ram_auto_in_wready;
  wire        _axi4ram_auto_in_bvalid;
  wire [ 3:0] _axi4ram_auto_in_bid;
  wire [ 1:0] _axi4ram_auto_in_bresp;
  wire        _axi4ram_auto_in_arready;
  wire        _axi4ram_auto_in_rvalid;
  wire [ 3:0] _axi4ram_auto_in_rid;
  wire [31:0] _axi4ram_auto_in_rdata;
  wire [ 1:0] _axi4ram_auto_in_rresp;
  wire        _lspi_auto_in_pready;
  wire        _lspi_auto_in_pslverr;
  wire [31:0] _lspi_auto_in_prdata;
  wire        _lvga_auto_in_pready;
  wire        _lvga_auto_in_pslverr;
  wire [31:0] _lvga_auto_in_prdata;
  wire        _lkeyboard_auto_in_pready;
  wire        _lkeyboard_auto_in_pslverr;
  wire [31:0] _lkeyboard_auto_in_prdata;
  wire        _lgpio_auto_in_pready;
  wire        _lgpio_auto_in_pslverr;
  wire [31:0] _lgpio_auto_in_prdata;
  wire        _luart_auto_in_pready;
  wire        _luart_auto_in_pslverr;
  wire [31:0] _luart_auto_in_prdata;
  wire        _cpu_auto_master_out_awvalid;
  wire [ 3:0] _cpu_auto_master_out_awid;
  wire [31:0] _cpu_auto_master_out_awaddr;
  wire [ 7:0] _cpu_auto_master_out_awlen;
  wire [ 2:0] _cpu_auto_master_out_awsize;
  wire [ 1:0] _cpu_auto_master_out_awburst;
  wire        _cpu_auto_master_out_wvalid;
  wire [31:0] _cpu_auto_master_out_wdata;
  wire [ 3:0] _cpu_auto_master_out_wstrb;
  wire        _cpu_auto_master_out_wlast;
  wire        _cpu_auto_master_out_bready;
  wire        _cpu_auto_master_out_arvalid;
  wire [ 3:0] _cpu_auto_master_out_arid;
  wire [31:0] _cpu_auto_master_out_araddr;
  wire [ 7:0] _cpu_auto_master_out_arlen;
  wire [ 2:0] _cpu_auto_master_out_arsize;
  wire [ 1:0] _cpu_auto_master_out_arburst;
  wire        _cpu_auto_master_out_rready;
  wire        _apbxbar_auto_in_pready;
  wire        _apbxbar_auto_in_pslverr;
  wire [31:0] _apbxbar_auto_in_prdata;
  wire        _apbxbar_auto_out_5_psel;
  wire        _apbxbar_auto_out_5_penable;
  wire        _apbxbar_auto_out_5_pwrite;
  wire [31:0] _apbxbar_auto_out_5_paddr;
  wire [ 2:0] _apbxbar_auto_out_5_pprot;
  wire [31:0] _apbxbar_auto_out_5_pwdata;
  wire [ 3:0] _apbxbar_auto_out_5_pstrb;
  wire        _apbxbar_auto_out_4_psel;
  wire        _apbxbar_auto_out_4_penable;
  wire        _apbxbar_auto_out_4_pwrite;
  wire [29:0] _apbxbar_auto_out_4_paddr;
  wire [ 2:0] _apbxbar_auto_out_4_pprot;
  wire [31:0] _apbxbar_auto_out_4_pwdata;
  wire [ 3:0] _apbxbar_auto_out_4_pstrb;
  wire        _apbxbar_auto_out_3_psel;
  wire        _apbxbar_auto_out_3_penable;
  wire        _apbxbar_auto_out_3_pwrite;
  wire [28:0] _apbxbar_auto_out_3_paddr;
  wire [ 2:0] _apbxbar_auto_out_3_pprot;
  wire [31:0] _apbxbar_auto_out_3_pwdata;
  wire [ 3:0] _apbxbar_auto_out_3_pstrb;
  wire        _apbxbar_auto_out_2_psel;
  wire        _apbxbar_auto_out_2_penable;
  wire        _apbxbar_auto_out_2_pwrite;
  wire [28:0] _apbxbar_auto_out_2_paddr;
  wire [ 2:0] _apbxbar_auto_out_2_pprot;
  wire [31:0] _apbxbar_auto_out_2_pwdata;
  wire [ 3:0] _apbxbar_auto_out_2_pstrb;
  wire        _apbxbar_auto_out_1_psel;
  wire        _apbxbar_auto_out_1_penable;
  wire        _apbxbar_auto_out_1_pwrite;
  wire [28:0] _apbxbar_auto_out_1_paddr;
  wire [ 2:0] _apbxbar_auto_out_1_pprot;
  wire [31:0] _apbxbar_auto_out_1_pwdata;
  wire [ 3:0] _apbxbar_auto_out_1_pstrb;
  wire        _apbxbar_auto_out_0_psel;
  wire        _apbxbar_auto_out_0_penable;
  wire        _apbxbar_auto_out_0_pwrite;
  wire [29:0] _apbxbar_auto_out_0_paddr;
  wire [ 2:0] _apbxbar_auto_out_0_pprot;
  wire [31:0] _apbxbar_auto_out_0_pwdata;
  wire [ 3:0] _apbxbar_auto_out_0_pstrb;
  wire        _axi4xbar_1_auto_in_awready;
  wire        _axi4xbar_1_auto_in_wready;
  wire        _axi4xbar_1_auto_in_bvalid;
  wire [ 3:0] _axi4xbar_1_auto_in_bid;
  wire [ 1:0] _axi4xbar_1_auto_in_bresp;
  wire        _axi4xbar_1_auto_in_arready;
  wire        _axi4xbar_1_auto_in_rvalid;
  wire [ 3:0] _axi4xbar_1_auto_in_rid;
  wire [31:0] _axi4xbar_1_auto_in_rdata;
  wire [ 1:0] _axi4xbar_1_auto_in_rresp;
  wire        _axi4xbar_1_auto_in_rlast;
  wire        _axi4xbar_1_auto_out_1_awvalid;
  wire [ 3:0] _axi4xbar_1_auto_out_1_awid;
  wire [27:0] _axi4xbar_1_auto_out_1_awaddr;
  wire        _axi4xbar_1_auto_out_1_wvalid;
  wire [31:0] _axi4xbar_1_auto_out_1_wdata;
  wire [ 3:0] _axi4xbar_1_auto_out_1_wstrb;
  wire        _axi4xbar_1_auto_out_1_bready;
  wire        _axi4xbar_1_auto_out_1_arvalid;
  wire [ 3:0] _axi4xbar_1_auto_out_1_arid;
  wire [27:0] _axi4xbar_1_auto_out_1_araddr;
  wire        _axi4xbar_1_auto_out_1_rready;
  wire        _axi4xbar_1_auto_out_0_awvalid;
  wire [ 3:0] _axi4xbar_1_auto_out_0_awid;
  wire [31:0] _axi4xbar_1_auto_out_0_awaddr;
  wire [ 2:0] _axi4xbar_1_auto_out_0_awsize;
  wire        _axi4xbar_1_auto_out_0_wvalid;
  wire [31:0] _axi4xbar_1_auto_out_0_wdata;
  wire [ 3:0] _axi4xbar_1_auto_out_0_wstrb;
  wire        _axi4xbar_1_auto_out_0_bready;
  wire        _axi4xbar_1_auto_out_0_arvalid;
  wire [ 3:0] _axi4xbar_1_auto_out_0_arid;
  wire [31:0] _axi4xbar_1_auto_out_0_araddr;
  wire [ 2:0] _axi4xbar_1_auto_out_0_arsize;
  wire        _axi4xbar_1_auto_out_0_rready;
  wire        _axi4xbar_auto_in_awready;
  wire        _axi4xbar_auto_in_wready;
  wire        _axi4xbar_auto_in_bvalid;
  wire [ 3:0] _axi4xbar_auto_in_bid;
  wire [ 1:0] _axi4xbar_auto_in_bresp;
  wire        _axi4xbar_auto_in_arready;
  wire        _axi4xbar_auto_in_rvalid;
  wire [ 3:0] _axi4xbar_auto_in_rid;
  wire [31:0] _axi4xbar_auto_in_rdata;
  wire [ 1:0] _axi4xbar_auto_in_rresp;
  wire        _axi4xbar_auto_in_rlast;
  wire        _axi4xbar_auto_out_awvalid;
  wire [ 3:0] _axi4xbar_auto_out_awid;
  wire [31:0] _axi4xbar_auto_out_awaddr;
  wire [ 7:0] _axi4xbar_auto_out_awlen;
  wire [ 2:0] _axi4xbar_auto_out_awsize;
  wire [ 1:0] _axi4xbar_auto_out_awburst;
  wire        _axi4xbar_auto_out_wvalid;
  wire [31:0] _axi4xbar_auto_out_wdata;
  wire [ 3:0] _axi4xbar_auto_out_wstrb;
  wire        _axi4xbar_auto_out_wlast;
  wire        _axi4xbar_auto_out_bready;
  wire        _axi4xbar_auto_out_arvalid;
  wire [ 3:0] _axi4xbar_auto_out_arid;
  wire [31:0] _axi4xbar_auto_out_araddr;
  wire [ 7:0] _axi4xbar_auto_out_arlen;
  wire [ 2:0] _axi4xbar_auto_out_arsize;
  wire [ 1:0] _axi4xbar_auto_out_arburst;
  wire        _axi4xbar_auto_out_rready;
  AXI4Xbar axi4xbar (
      .clock           (clock),
      .reset           (reset),
      .auto_in_awready (_axi4xbar_auto_in_awready),
      .auto_in_awvalid (_cpu_auto_master_out_awvalid),
      .auto_in_awid    (_cpu_auto_master_out_awid),
      .auto_in_awaddr  (_cpu_auto_master_out_awaddr),
      .auto_in_awlen   (_cpu_auto_master_out_awlen),
      .auto_in_awsize  (_cpu_auto_master_out_awsize),
      .auto_in_awburst (_cpu_auto_master_out_awburst),
      .auto_in_wready  (_axi4xbar_auto_in_wready),
      .auto_in_wvalid  (_cpu_auto_master_out_wvalid),
      .auto_in_wdata   (_cpu_auto_master_out_wdata),
      .auto_in_wstrb   (_cpu_auto_master_out_wstrb),
      .auto_in_wlast   (_cpu_auto_master_out_wlast),
      .auto_in_bready  (_cpu_auto_master_out_bready),
      .auto_in_bvalid  (_axi4xbar_auto_in_bvalid),
      .auto_in_bid     (_axi4xbar_auto_in_bid),
      .auto_in_bresp   (_axi4xbar_auto_in_bresp),
      .auto_in_arready (_axi4xbar_auto_in_arready),
      .auto_in_arvalid (_cpu_auto_master_out_arvalid),
      .auto_in_arid    (_cpu_auto_master_out_arid),
      .auto_in_araddr  (_cpu_auto_master_out_araddr),
      .auto_in_arlen   (_cpu_auto_master_out_arlen),
      .auto_in_arsize  (_cpu_auto_master_out_arsize),
      .auto_in_arburst (_cpu_auto_master_out_arburst),
      .auto_in_rready  (_cpu_auto_master_out_rready),
      .auto_in_rvalid  (_axi4xbar_auto_in_rvalid),
      .auto_in_rid     (_axi4xbar_auto_in_rid),
      .auto_in_rdata   (_axi4xbar_auto_in_rdata),
      .auto_in_rresp   (_axi4xbar_auto_in_rresp),
      .auto_in_rlast   (_axi4xbar_auto_in_rlast),
      .auto_out_awready(_axi4frag_auto_in_awready),
      .auto_out_awvalid(_axi4xbar_auto_out_awvalid),
      .auto_out_awid   (_axi4xbar_auto_out_awid),
      .auto_out_awaddr (_axi4xbar_auto_out_awaddr),
      .auto_out_awlen  (_axi4xbar_auto_out_awlen),
      .auto_out_awsize (_axi4xbar_auto_out_awsize),
      .auto_out_awburst(_axi4xbar_auto_out_awburst),
      .auto_out_wready (_axi4frag_auto_in_wready),
      .auto_out_wvalid (_axi4xbar_auto_out_wvalid),
      .auto_out_wdata  (_axi4xbar_auto_out_wdata),
      .auto_out_wstrb  (_axi4xbar_auto_out_wstrb),
      .auto_out_wlast  (_axi4xbar_auto_out_wlast),
      .auto_out_bready (_axi4xbar_auto_out_bready),
      .auto_out_bvalid (_axi4frag_auto_in_bvalid),
      .auto_out_bid    (_axi4frag_auto_in_bid),
      .auto_out_bresp  (_axi4frag_auto_in_bresp),
      .auto_out_arready(_axi4frag_auto_in_arready),
      .auto_out_arvalid(_axi4xbar_auto_out_arvalid),
      .auto_out_arid   (_axi4xbar_auto_out_arid),
      .auto_out_araddr (_axi4xbar_auto_out_araddr),
      .auto_out_arlen  (_axi4xbar_auto_out_arlen),
      .auto_out_arsize (_axi4xbar_auto_out_arsize),
      .auto_out_arburst(_axi4xbar_auto_out_arburst),
      .auto_out_rready (_axi4xbar_auto_out_rready),
      .auto_out_rvalid (_axi4frag_auto_in_rvalid),
      .auto_out_rid    (_axi4frag_auto_in_rid),
      .auto_out_rdata  (_axi4frag_auto_in_rdata),
      .auto_out_rresp  (_axi4frag_auto_in_rresp),
      .auto_out_rlast  (_axi4frag_auto_in_rlast)
  );
  AXI4Xbar_1 axi4xbar_1 (
      .clock             (clock),
      .reset             (reset),
      .auto_in_awready   (_axi4xbar_1_auto_in_awready),
      .auto_in_awvalid   (_axi4yank_auto_out_awvalid),
      .auto_in_awid      (_axi4yank_auto_out_awid),
      .auto_in_awaddr    (_axi4yank_auto_out_awaddr),
      .auto_in_awsize    (_axi4yank_auto_out_awsize),
      .auto_in_wready    (_axi4xbar_1_auto_in_wready),
      .auto_in_wvalid    (_axi4yank_auto_out_wvalid),
      .auto_in_wdata     (_axi4yank_auto_out_wdata),
      .auto_in_wstrb     (_axi4yank_auto_out_wstrb),
      .auto_in_wlast     (_axi4yank_auto_out_wlast),
      .auto_in_bready    (_axi4yank_auto_out_bready),
      .auto_in_bvalid    (_axi4xbar_1_auto_in_bvalid),
      .auto_in_bid       (_axi4xbar_1_auto_in_bid),
      .auto_in_bresp     (_axi4xbar_1_auto_in_bresp),
      .auto_in_arready   (_axi4xbar_1_auto_in_arready),
      .auto_in_arvalid   (_axi4yank_auto_out_arvalid),
      .auto_in_arid      (_axi4yank_auto_out_arid),
      .auto_in_araddr    (_axi4yank_auto_out_araddr),
      .auto_in_arsize    (_axi4yank_auto_out_arsize),
      .auto_in_rready    (_axi4yank_auto_out_rready),
      .auto_in_rvalid    (_axi4xbar_1_auto_in_rvalid),
      .auto_in_rid       (_axi4xbar_1_auto_in_rid),
      .auto_in_rdata     (_axi4xbar_1_auto_in_rdata),
      .auto_in_rresp     (_axi4xbar_1_auto_in_rresp),
      .auto_in_rlast     (_axi4xbar_1_auto_in_rlast),
      .auto_out_1_awready(_axi4ram_auto_in_awready),
      .auto_out_1_awvalid(_axi4xbar_1_auto_out_1_awvalid),
      .auto_out_1_awid   (_axi4xbar_1_auto_out_1_awid),
      .auto_out_1_awaddr (_axi4xbar_1_auto_out_1_awaddr),
      .auto_out_1_wready (_axi4ram_auto_in_wready),
      .auto_out_1_wvalid (_axi4xbar_1_auto_out_1_wvalid),
      .auto_out_1_wdata  (_axi4xbar_1_auto_out_1_wdata),
      .auto_out_1_wstrb  (_axi4xbar_1_auto_out_1_wstrb),
      .auto_out_1_bready (_axi4xbar_1_auto_out_1_bready),
      .auto_out_1_bvalid (_axi4ram_auto_in_bvalid),
      .auto_out_1_bid    (_axi4ram_auto_in_bid),
      .auto_out_1_bresp  (_axi4ram_auto_in_bresp),
      .auto_out_1_arready(_axi4ram_auto_in_arready),
      .auto_out_1_arvalid(_axi4xbar_1_auto_out_1_arvalid),
      .auto_out_1_arid   (_axi4xbar_1_auto_out_1_arid),
      .auto_out_1_araddr (_axi4xbar_1_auto_out_1_araddr),
      .auto_out_1_rready (_axi4xbar_1_auto_out_1_rready),
      .auto_out_1_rvalid (_axi4ram_auto_in_rvalid),
      .auto_out_1_rid    (_axi4ram_auto_in_rid),
      .auto_out_1_rdata  (_axi4ram_auto_in_rdata),
      .auto_out_1_rresp  (_axi4ram_auto_in_rresp),
      .auto_out_0_awready(_axi42apb_auto_in_awready),
      .auto_out_0_awvalid(_axi4xbar_1_auto_out_0_awvalid),
      .auto_out_0_awid   (_axi4xbar_1_auto_out_0_awid),
      .auto_out_0_awaddr (_axi4xbar_1_auto_out_0_awaddr),
      .auto_out_0_awsize (_axi4xbar_1_auto_out_0_awsize),
      .auto_out_0_wready (_axi42apb_auto_in_wready),
      .auto_out_0_wvalid (_axi4xbar_1_auto_out_0_wvalid),
      .auto_out_0_wdata  (_axi4xbar_1_auto_out_0_wdata),
      .auto_out_0_wstrb  (_axi4xbar_1_auto_out_0_wstrb),
      .auto_out_0_bready (_axi4xbar_1_auto_out_0_bready),
      .auto_out_0_bvalid (_axi42apb_auto_in_bvalid),
      .auto_out_0_bid    (_axi42apb_auto_in_bid),
      .auto_out_0_bresp  (_axi42apb_auto_in_bresp),
      .auto_out_0_arready(_axi42apb_auto_in_arready),
      .auto_out_0_arvalid(_axi4xbar_1_auto_out_0_arvalid),
      .auto_out_0_arid   (_axi4xbar_1_auto_out_0_arid),
      .auto_out_0_araddr (_axi4xbar_1_auto_out_0_araddr),
      .auto_out_0_arsize (_axi4xbar_1_auto_out_0_arsize),
      .auto_out_0_rready (_axi4xbar_1_auto_out_0_rready),
      .auto_out_0_rvalid (_axi42apb_auto_in_rvalid),
      .auto_out_0_rid    (_axi42apb_auto_in_rid),
      .auto_out_0_rdata  (_axi42apb_auto_in_rdata),
      .auto_out_0_rresp  (_axi42apb_auto_in_rresp)
  );
  APBFanout apbxbar (
      .auto_in_psel      (_apbdelay_delayer_out_psel),
      .auto_in_penable   (_apbdelay_delayer_out_penable),
      .auto_in_pwrite    (_apbdelay_delayer_out_pwrite),
      .auto_in_paddr     (_apbdelay_delayer_out_paddr),
      .auto_in_pprot     (_apbdelay_delayer_out_pprot),
      .auto_in_pwdata    (_apbdelay_delayer_out_pwdata),
      .auto_in_pstrb     (_apbdelay_delayer_out_pstrb),
      .auto_in_pready    (_apbxbar_auto_in_pready),
      .auto_in_pslverr   (_apbxbar_auto_in_pslverr),
      .auto_in_prdata    (_apbxbar_auto_in_prdata),
      .auto_out_5_psel   (_apbxbar_auto_out_5_psel),
      .auto_out_5_penable(_apbxbar_auto_out_5_penable),
      .auto_out_5_pwrite (_apbxbar_auto_out_5_pwrite),
      .auto_out_5_paddr  (_apbxbar_auto_out_5_paddr),
      .auto_out_5_pprot  (_apbxbar_auto_out_5_pprot),
      .auto_out_5_pwdata (_apbxbar_auto_out_5_pwdata),
      .auto_out_5_pstrb  (_apbxbar_auto_out_5_pstrb),
      .auto_out_5_pready (_lsdram_apb_auto_in_pready),
      .auto_out_5_pslverr(_lsdram_apb_auto_in_pslverr),
      .auto_out_5_prdata (_lsdram_apb_auto_in_prdata),
      .auto_out_4_psel   (_apbxbar_auto_out_4_psel),
      .auto_out_4_penable(_apbxbar_auto_out_4_penable),
      .auto_out_4_pwrite (_apbxbar_auto_out_4_pwrite),
      .auto_out_4_paddr  (_apbxbar_auto_out_4_paddr),
      .auto_out_4_pprot  (_apbxbar_auto_out_4_pprot),
      .auto_out_4_pwdata (_apbxbar_auto_out_4_pwdata),
      .auto_out_4_pstrb  (_apbxbar_auto_out_4_pstrb),
      .auto_out_4_pready (_lvga_auto_in_pready),
      .auto_out_4_pslverr(_lvga_auto_in_pslverr),
      .auto_out_4_prdata (_lvga_auto_in_prdata),
      .auto_out_3_psel   (_apbxbar_auto_out_3_psel),
      .auto_out_3_penable(_apbxbar_auto_out_3_penable),
      .auto_out_3_pwrite (_apbxbar_auto_out_3_pwrite),
      .auto_out_3_paddr  (_apbxbar_auto_out_3_paddr),
      .auto_out_3_pprot  (_apbxbar_auto_out_3_pprot),
      .auto_out_3_pwdata (_apbxbar_auto_out_3_pwdata),
      .auto_out_3_pstrb  (_apbxbar_auto_out_3_pstrb),
      .auto_out_3_pready (_lkeyboard_auto_in_pready),
      .auto_out_3_pslverr(_lkeyboard_auto_in_pslverr),
      .auto_out_3_prdata (_lkeyboard_auto_in_prdata),
      .auto_out_2_psel   (_apbxbar_auto_out_2_psel),
      .auto_out_2_penable(_apbxbar_auto_out_2_penable),
      .auto_out_2_pwrite (_apbxbar_auto_out_2_pwrite),
      .auto_out_2_paddr  (_apbxbar_auto_out_2_paddr),
      .auto_out_2_pprot  (_apbxbar_auto_out_2_pprot),
      .auto_out_2_pwdata (_apbxbar_auto_out_2_pwdata),
      .auto_out_2_pstrb  (_apbxbar_auto_out_2_pstrb),
      .auto_out_2_pready (_lgpio_auto_in_pready),
      .auto_out_2_pslverr(_lgpio_auto_in_pslverr),
      .auto_out_2_prdata (_lgpio_auto_in_prdata),
      .auto_out_1_psel   (_apbxbar_auto_out_1_psel),
      .auto_out_1_penable(_apbxbar_auto_out_1_penable),
      .auto_out_1_pwrite (_apbxbar_auto_out_1_pwrite),
      .auto_out_1_paddr  (_apbxbar_auto_out_1_paddr),
      .auto_out_1_pprot  (_apbxbar_auto_out_1_pprot),
      .auto_out_1_pwdata (_apbxbar_auto_out_1_pwdata),
      .auto_out_1_pstrb  (_apbxbar_auto_out_1_pstrb),
      .auto_out_1_pready (_luart_auto_in_pready),
      .auto_out_1_pslverr(_luart_auto_in_pslverr),
      .auto_out_1_prdata (_luart_auto_in_prdata),
      .auto_out_0_psel   (_apbxbar_auto_out_0_psel),
      .auto_out_0_penable(_apbxbar_auto_out_0_penable),
      .auto_out_0_pwrite (_apbxbar_auto_out_0_pwrite),
      .auto_out_0_paddr  (_apbxbar_auto_out_0_paddr),
      .auto_out_0_pprot  (_apbxbar_auto_out_0_pprot),
      .auto_out_0_pwdata (_apbxbar_auto_out_0_pwdata),
      .auto_out_0_pstrb  (_apbxbar_auto_out_0_pstrb),
      .auto_out_0_pready (_lspi_auto_in_pready),
      .auto_out_0_pslverr(_lspi_auto_in_pslverr),
      .auto_out_0_prdata (_lspi_auto_in_prdata)
  );
  CPU cpu (
      .clock                  (clock),
      .reset                  (_cpu_reset_chain_io_q | reset),
      .auto_master_out_awready(_axi4xbar_auto_in_awready),
      .auto_master_out_awvalid(_cpu_auto_master_out_awvalid),
      .auto_master_out_awid   (_cpu_auto_master_out_awid),
      .auto_master_out_awaddr (_cpu_auto_master_out_awaddr),
      .auto_master_out_awlen  (_cpu_auto_master_out_awlen),
      .auto_master_out_awsize (_cpu_auto_master_out_awsize),
      .auto_master_out_awburst(_cpu_auto_master_out_awburst),
      .auto_master_out_wready (_axi4xbar_auto_in_wready),
      .auto_master_out_wvalid (_cpu_auto_master_out_wvalid),
      .auto_master_out_wdata  (_cpu_auto_master_out_wdata),
      .auto_master_out_wstrb  (_cpu_auto_master_out_wstrb),
      .auto_master_out_wlast  (_cpu_auto_master_out_wlast),
      .auto_master_out_bready (_cpu_auto_master_out_bready),
      .auto_master_out_bvalid (_axi4xbar_auto_in_bvalid),
      .auto_master_out_bid    (_axi4xbar_auto_in_bid),
      .auto_master_out_bresp  (_axi4xbar_auto_in_bresp),
      .auto_master_out_arready(_axi4xbar_auto_in_arready),
      .auto_master_out_arvalid(_cpu_auto_master_out_arvalid),
      .auto_master_out_arid   (_cpu_auto_master_out_arid),
      .auto_master_out_araddr (_cpu_auto_master_out_araddr),
      .auto_master_out_arlen  (_cpu_auto_master_out_arlen),
      .auto_master_out_arsize (_cpu_auto_master_out_arsize),
      .auto_master_out_arburst(_cpu_auto_master_out_arburst),
      .auto_master_out_rready (_cpu_auto_master_out_rready),
      .auto_master_out_rvalid (_axi4xbar_auto_in_rvalid),
      .auto_master_out_rid    (_axi4xbar_auto_in_rid),
      .auto_master_out_rdata  (_axi4xbar_auto_in_rdata),
      .auto_master_out_rresp  (_axi4xbar_auto_in_rresp),
      .auto_master_out_rlast  (_axi4xbar_auto_in_rlast)
  );
  APBUart16550 luart (
      .clock          (clock),
      .reset          (reset),
      .auto_in_psel   (_apbxbar_auto_out_1_psel),
      .auto_in_penable(_apbxbar_auto_out_1_penable),
      .auto_in_pwrite (_apbxbar_auto_out_1_pwrite),
      .auto_in_paddr  (_apbxbar_auto_out_1_paddr),
      .auto_in_pprot  (_apbxbar_auto_out_1_pprot),
      .auto_in_pwdata (_apbxbar_auto_out_1_pwdata),
      .auto_in_pstrb  (_apbxbar_auto_out_1_pstrb),
      .auto_in_pready (_luart_auto_in_pready),
      .auto_in_pslverr(_luart_auto_in_pslverr),
      .auto_in_prdata (_luart_auto_in_prdata),
      .uart_rx        (uart_rx),
      .uart_tx        (uart_tx)
  );
  APBGPIO lgpio (
      .clock            (clock),
      .reset            (reset),
      .auto_in_psel     (_apbxbar_auto_out_2_psel),
      .auto_in_penable  (_apbxbar_auto_out_2_penable),
      .auto_in_pwrite   (_apbxbar_auto_out_2_pwrite),
      .auto_in_paddr    (_apbxbar_auto_out_2_paddr),
      .auto_in_pprot    (_apbxbar_auto_out_2_pprot),
      .auto_in_pwdata   (_apbxbar_auto_out_2_pwdata),
      .auto_in_pstrb    (_apbxbar_auto_out_2_pstrb),
      .auto_in_pready   (_lgpio_auto_in_pready),
      .auto_in_pslverr  (_lgpio_auto_in_pslverr),
      .auto_in_prdata   (_lgpio_auto_in_prdata),
      .gpio_bundle_out  (gpio_out),
      .gpio_bundle_in   (gpio_in),
      .gpio_bundle_seg_0(gpio_seg_0),
      .gpio_bundle_seg_1(gpio_seg_1),
      .gpio_bundle_seg_2(gpio_seg_2),
      .gpio_bundle_seg_3(gpio_seg_3),
      .gpio_bundle_seg_4(gpio_seg_4),
      .gpio_bundle_seg_5(gpio_seg_5),
      .gpio_bundle_seg_6(gpio_seg_6),
      .gpio_bundle_seg_7(gpio_seg_7)
  );
  APBKeyboard lkeyboard (
      .clock          (clock),
      .reset          (reset),
      .auto_in_psel   (_apbxbar_auto_out_3_psel),
      .auto_in_penable(_apbxbar_auto_out_3_penable),
      .auto_in_pwrite (_apbxbar_auto_out_3_pwrite),
      .auto_in_paddr  (_apbxbar_auto_out_3_paddr),
      .auto_in_pprot  (_apbxbar_auto_out_3_pprot),
      .auto_in_pwdata (_apbxbar_auto_out_3_pwdata),
      .auto_in_pstrb  (_apbxbar_auto_out_3_pstrb),
      .auto_in_pready (_lkeyboard_auto_in_pready),
      .auto_in_pslverr(_lkeyboard_auto_in_pslverr),
      .auto_in_prdata (_lkeyboard_auto_in_prdata),
      .ps2_bundle_clk (ps2_clk),
      .ps2_bundle_data(ps2_data)
  );
  APBVGA lvga (
      .clock           (clock),
      .reset           (reset),
      .auto_in_psel    (_apbxbar_auto_out_4_psel),
      .auto_in_penable (_apbxbar_auto_out_4_penable),
      .auto_in_pwrite  (_apbxbar_auto_out_4_pwrite),
      .auto_in_paddr   (_apbxbar_auto_out_4_paddr),
      .auto_in_pprot   (_apbxbar_auto_out_4_pprot),
      .auto_in_pwdata  (_apbxbar_auto_out_4_pwdata),
      .auto_in_pstrb   (_apbxbar_auto_out_4_pstrb),
      .auto_in_pready  (_lvga_auto_in_pready),
      .auto_in_pslverr (_lvga_auto_in_pslverr),
      .auto_in_prdata  (_lvga_auto_in_prdata),
      .vga_bundle_r    (vga_r),
      .vga_bundle_g    (vga_g),
      .vga_bundle_b    (vga_b),
      .vga_bundle_hsync(vga_hsync),
      .vga_bundle_vsync(vga_vsync),
      .vga_bundle_valid(vga_valid)
  );
  APBSPI lspi (
      .clock          (clock),
      .reset          (reset),
      .auto_in_psel   (_apbxbar_auto_out_0_psel),
      .auto_in_penable(_apbxbar_auto_out_0_penable),
      .auto_in_pwrite (_apbxbar_auto_out_0_pwrite),
      .auto_in_paddr  (_apbxbar_auto_out_0_paddr),
      .auto_in_pprot  (_apbxbar_auto_out_0_pprot),
      .auto_in_pwdata (_apbxbar_auto_out_0_pwdata),
      .auto_in_pstrb  (_apbxbar_auto_out_0_pstrb),
      .auto_in_pready (_lspi_auto_in_pready),
      .auto_in_pslverr(_lspi_auto_in_pslverr),
      .auto_in_prdata (_lspi_auto_in_prdata),
      .spi_bundle_sck (spi_sck),
      .spi_bundle_ss  (spi_ss),
      .spi_bundle_mosi(spi_mosi),
      .spi_bundle_miso(spi_miso)
  );
  AXI4RAM axi4ram (
      .clock          (clock),
      .reset          (reset),
      .auto_in_awready(_axi4ram_auto_in_awready),
      .auto_in_awvalid(_axi4xbar_1_auto_out_1_awvalid),
      .auto_in_awid   (_axi4xbar_1_auto_out_1_awid),
      .auto_in_awaddr (_axi4xbar_1_auto_out_1_awaddr),
      .auto_in_wready (_axi4ram_auto_in_wready),
      .auto_in_wvalid (_axi4xbar_1_auto_out_1_wvalid),
      .auto_in_wdata  (_axi4xbar_1_auto_out_1_wdata),
      .auto_in_wstrb  (_axi4xbar_1_auto_out_1_wstrb),
      .auto_in_bready (_axi4xbar_1_auto_out_1_bready),
      .auto_in_bvalid (_axi4ram_auto_in_bvalid),
      .auto_in_bid    (_axi4ram_auto_in_bid),
      .auto_in_bresp  (_axi4ram_auto_in_bresp),
      .auto_in_arready(_axi4ram_auto_in_arready),
      .auto_in_arvalid(_axi4xbar_1_auto_out_1_arvalid),
      .auto_in_arid   (_axi4xbar_1_auto_out_1_arid),
      .auto_in_araddr (_axi4xbar_1_auto_out_1_araddr),
      .auto_in_rready (_axi4xbar_1_auto_out_1_rready),
      .auto_in_rvalid (_axi4ram_auto_in_rvalid),
      .auto_in_rid    (_axi4ram_auto_in_rid),
      .auto_in_rdata  (_axi4ram_auto_in_rdata),
      .auto_in_rresp  (_axi4ram_auto_in_rresp)
  );
  APBSDRAM lsdram_apb (
      .clock           (clock),
      .reset           (reset),
      .auto_in_psel    (_apbxbar_auto_out_5_psel),
      .auto_in_penable (_apbxbar_auto_out_5_penable),
      .auto_in_pwrite  (_apbxbar_auto_out_5_pwrite),
      .auto_in_paddr   (_apbxbar_auto_out_5_paddr),
      .auto_in_pprot   (_apbxbar_auto_out_5_pprot),
      .auto_in_pwdata  (_apbxbar_auto_out_5_pwdata),
      .auto_in_pstrb   (_apbxbar_auto_out_5_pstrb),
      .auto_in_pready  (_lsdram_apb_auto_in_pready),
      .auto_in_pslverr (_lsdram_apb_auto_in_pslverr),
      .auto_in_prdata  (_lsdram_apb_auto_in_prdata),
      .sdram_bundle_clk(sdram_clk),
      .sdram_bundle_cke(sdram_cke),
      .sdram_bundle_cs (sdram_cs),
      .sdram_bundle_ras(sdram_ras),
      .sdram_bundle_cas(sdram_cas),
      .sdram_bundle_we (sdram_we),
      .sdram_bundle_a  (sdram_a),
      .sdram_bundle_ba (sdram_ba),
      .sdram_bundle_dqm(sdram_dqm),
      .sdram_bundle_dq (sdram_dq)
  );
  apb_delayer apbdelay_delayer (
      .clock(clock),
      .reset(reset),
      .in_psel(_axi42apb_auto_out_psel),
      .in_penable(_axi42apb_auto_out_penable),
      .in_pwrite(_axi42apb_auto_out_pwrite),
      .in_paddr(_axi42apb_auto_out_paddr),
      .in_pprot(3'h1),
      .in_pwdata(_axi42apb_auto_out_pwdata),
      .in_pstrb(_axi42apb_auto_out_pstrb),
      .in_pready(_apbdelay_delayer_in_pready),
      .in_pslverr(_apbdelay_delayer_in_pslverr),
      .in_prdata(_apbdelay_delayer_in_prdata),
      .out_psel(_apbdelay_delayer_out_psel),
      .out_penable(_apbdelay_delayer_out_penable),
      .out_pwrite(_apbdelay_delayer_out_pwrite),
      .out_paddr(_apbdelay_delayer_out_paddr),
      .out_pprot(_apbdelay_delayer_out_pprot),
      .out_pwdata(_apbdelay_delayer_out_pwdata),
      .out_pstrb(_apbdelay_delayer_out_pstrb),
      .out_pready(_apbxbar_auto_in_pready),
      .out_pslverr(_apbxbar_auto_in_pslverr),
      .out_prdata(_apbxbar_auto_in_prdata)
  );
  AXI4ToAPB axi42apb (
      .clock           (clock),
      .reset           (reset),
      .auto_in_awready (_axi42apb_auto_in_awready),
      .auto_in_awvalid (_axi4xbar_1_auto_out_0_awvalid),
      .auto_in_awid    (_axi4xbar_1_auto_out_0_awid),
      .auto_in_awaddr  (_axi4xbar_1_auto_out_0_awaddr),
      .auto_in_awsize  (_axi4xbar_1_auto_out_0_awsize),
      .auto_in_wready  (_axi42apb_auto_in_wready),
      .auto_in_wvalid  (_axi4xbar_1_auto_out_0_wvalid),
      .auto_in_wdata   (_axi4xbar_1_auto_out_0_wdata),
      .auto_in_wstrb   (_axi4xbar_1_auto_out_0_wstrb),
      .auto_in_bready  (_axi4xbar_1_auto_out_0_bready),
      .auto_in_bvalid  (_axi42apb_auto_in_bvalid),
      .auto_in_bid     (_axi42apb_auto_in_bid),
      .auto_in_bresp   (_axi42apb_auto_in_bresp),
      .auto_in_arready (_axi42apb_auto_in_arready),
      .auto_in_arvalid (_axi4xbar_1_auto_out_0_arvalid),
      .auto_in_arid    (_axi4xbar_1_auto_out_0_arid),
      .auto_in_araddr  (_axi4xbar_1_auto_out_0_araddr),
      .auto_in_arsize  (_axi4xbar_1_auto_out_0_arsize),
      .auto_in_rready  (_axi4xbar_1_auto_out_0_rready),
      .auto_in_rvalid  (_axi42apb_auto_in_rvalid),
      .auto_in_rid     (_axi42apb_auto_in_rid),
      .auto_in_rdata   (_axi42apb_auto_in_rdata),
      .auto_in_rresp   (_axi42apb_auto_in_rresp),
      .auto_out_psel   (_axi42apb_auto_out_psel),
      .auto_out_penable(_axi42apb_auto_out_penable),
      .auto_out_pwrite (_axi42apb_auto_out_pwrite),
      .auto_out_paddr  (_axi42apb_auto_out_paddr),
      .auto_out_pwdata (_axi42apb_auto_out_pwdata),
      .auto_out_pstrb  (_axi42apb_auto_out_pstrb),
      .auto_out_pready (_apbdelay_delayer_in_pready),
      .auto_out_pslverr(_apbdelay_delayer_in_pslverr),
      .auto_out_prdata (_apbdelay_delayer_in_prdata)
  );
  AXI4UserYanker axi4yank (
      .clock                   (clock),
      .reset                   (reset),
      .auto_in_awready         (_axi4yank_auto_in_awready),
      .auto_in_awvalid         (_axi4frag_auto_out_awvalid),
      .auto_in_awid            (_axi4frag_auto_out_awid),
      .auto_in_awaddr          (_axi4frag_auto_out_awaddr),
      .auto_in_awsize          (_axi4frag_auto_out_awsize),
      .auto_in_awecho_real_last(_axi4frag_auto_out_awecho_real_last),
      .auto_in_wready          (_axi4yank_auto_in_wready),
      .auto_in_wvalid          (_axi4frag_auto_out_wvalid),
      .auto_in_wdata           (_axi4frag_auto_out_wdata),
      .auto_in_wstrb           (_axi4frag_auto_out_wstrb),
      .auto_in_wlast           (_axi4frag_auto_out_wlast),
      .auto_in_bready          (_axi4frag_auto_out_bready),
      .auto_in_bvalid          (_axi4yank_auto_in_bvalid),
      .auto_in_bid             (_axi4yank_auto_in_bid),
      .auto_in_bresp           (_axi4yank_auto_in_bresp),
      .auto_in_becho_real_last (_axi4yank_auto_in_becho_real_last),
      .auto_in_arready         (_axi4yank_auto_in_arready),
      .auto_in_arvalid         (_axi4frag_auto_out_arvalid),
      .auto_in_arid            (_axi4frag_auto_out_arid),
      .auto_in_araddr          (_axi4frag_auto_out_araddr),
      .auto_in_arsize          (_axi4frag_auto_out_arsize),
      .auto_in_arecho_real_last(_axi4frag_auto_out_arecho_real_last),
      .auto_in_rready          (_axi4frag_auto_out_rready),
      .auto_in_rvalid          (_axi4yank_auto_in_rvalid),
      .auto_in_rid             (_axi4yank_auto_in_rid),
      .auto_in_rdata           (_axi4yank_auto_in_rdata),
      .auto_in_rresp           (_axi4yank_auto_in_rresp),
      .auto_in_recho_real_last (_axi4yank_auto_in_recho_real_last),
      .auto_in_rlast           (_axi4yank_auto_in_rlast),
      .auto_out_awready        (_axi4xbar_1_auto_in_awready),
      .auto_out_awvalid        (_axi4yank_auto_out_awvalid),
      .auto_out_awid           (_axi4yank_auto_out_awid),
      .auto_out_awaddr         (_axi4yank_auto_out_awaddr),
      .auto_out_awsize         (_axi4yank_auto_out_awsize),
      .auto_out_wready         (_axi4xbar_1_auto_in_wready),
      .auto_out_wvalid         (_axi4yank_auto_out_wvalid),
      .auto_out_wdata          (_axi4yank_auto_out_wdata),
      .auto_out_wstrb          (_axi4yank_auto_out_wstrb),
      .auto_out_wlast          (_axi4yank_auto_out_wlast),
      .auto_out_bready         (_axi4yank_auto_out_bready),
      .auto_out_bvalid         (_axi4xbar_1_auto_in_bvalid),
      .auto_out_bid            (_axi4xbar_1_auto_in_bid),
      .auto_out_bresp          (_axi4xbar_1_auto_in_bresp),
      .auto_out_arready        (_axi4xbar_1_auto_in_arready),
      .auto_out_arvalid        (_axi4yank_auto_out_arvalid),
      .auto_out_arid           (_axi4yank_auto_out_arid),
      .auto_out_araddr         (_axi4yank_auto_out_araddr),
      .auto_out_arsize         (_axi4yank_auto_out_arsize),
      .auto_out_rready         (_axi4yank_auto_out_rready),
      .auto_out_rvalid         (_axi4xbar_1_auto_in_rvalid),
      .auto_out_rid            (_axi4xbar_1_auto_in_rid),
      .auto_out_rdata          (_axi4xbar_1_auto_in_rdata),
      .auto_out_rresp          (_axi4xbar_1_auto_in_rresp),
      .auto_out_rlast          (_axi4xbar_1_auto_in_rlast)
  );
  AXI4Fragmenter axi4frag (
      .clock                    (clock),
      .reset                    (reset),
      .auto_in_awready          (_axi4frag_auto_in_awready),
      .auto_in_awvalid          (_axi4xbar_auto_out_awvalid),
      .auto_in_awid             (_axi4xbar_auto_out_awid),
      .auto_in_awaddr           (_axi4xbar_auto_out_awaddr),
      .auto_in_awlen            (_axi4xbar_auto_out_awlen),
      .auto_in_awsize           (_axi4xbar_auto_out_awsize),
      .auto_in_awburst          (_axi4xbar_auto_out_awburst),
      .auto_in_wready           (_axi4frag_auto_in_wready),
      .auto_in_wvalid           (_axi4xbar_auto_out_wvalid),
      .auto_in_wdata            (_axi4xbar_auto_out_wdata),
      .auto_in_wstrb            (_axi4xbar_auto_out_wstrb),
      .auto_in_wlast            (_axi4xbar_auto_out_wlast),
      .auto_in_bready           (_axi4xbar_auto_out_bready),
      .auto_in_bvalid           (_axi4frag_auto_in_bvalid),
      .auto_in_bid              (_axi4frag_auto_in_bid),
      .auto_in_bresp            (_axi4frag_auto_in_bresp),
      .auto_in_arready          (_axi4frag_auto_in_arready),
      .auto_in_arvalid          (_axi4xbar_auto_out_arvalid),
      .auto_in_arid             (_axi4xbar_auto_out_arid),
      .auto_in_araddr           (_axi4xbar_auto_out_araddr),
      .auto_in_arlen            (_axi4xbar_auto_out_arlen),
      .auto_in_arsize           (_axi4xbar_auto_out_arsize),
      .auto_in_arburst          (_axi4xbar_auto_out_arburst),
      .auto_in_rready           (_axi4xbar_auto_out_rready),
      .auto_in_rvalid           (_axi4frag_auto_in_rvalid),
      .auto_in_rid              (_axi4frag_auto_in_rid),
      .auto_in_rdata            (_axi4frag_auto_in_rdata),
      .auto_in_rresp            (_axi4frag_auto_in_rresp),
      .auto_in_rlast            (_axi4frag_auto_in_rlast),
      .auto_out_awready         (_axi4yank_auto_in_awready),
      .auto_out_awvalid         (_axi4frag_auto_out_awvalid),
      .auto_out_awid            (_axi4frag_auto_out_awid),
      .auto_out_awaddr          (_axi4frag_auto_out_awaddr),
      .auto_out_awsize          (_axi4frag_auto_out_awsize),
      .auto_out_awecho_real_last(_axi4frag_auto_out_awecho_real_last),
      .auto_out_wready          (_axi4yank_auto_in_wready),
      .auto_out_wvalid          (_axi4frag_auto_out_wvalid),
      .auto_out_wdata           (_axi4frag_auto_out_wdata),
      .auto_out_wstrb           (_axi4frag_auto_out_wstrb),
      .auto_out_wlast           (_axi4frag_auto_out_wlast),
      .auto_out_bready          (_axi4frag_auto_out_bready),
      .auto_out_bvalid          (_axi4yank_auto_in_bvalid),
      .auto_out_bid             (_axi4yank_auto_in_bid),
      .auto_out_bresp           (_axi4yank_auto_in_bresp),
      .auto_out_becho_real_last (_axi4yank_auto_in_becho_real_last),
      .auto_out_arready         (_axi4yank_auto_in_arready),
      .auto_out_arvalid         (_axi4frag_auto_out_arvalid),
      .auto_out_arid            (_axi4frag_auto_out_arid),
      .auto_out_araddr          (_axi4frag_auto_out_araddr),
      .auto_out_arsize          (_axi4frag_auto_out_arsize),
      .auto_out_arecho_real_last(_axi4frag_auto_out_arecho_real_last),
      .auto_out_rready          (_axi4frag_auto_out_rready),
      .auto_out_rvalid          (_axi4yank_auto_in_rvalid),
      .auto_out_rid             (_axi4yank_auto_in_rid),
      .auto_out_rdata           (_axi4yank_auto_in_rdata),
      .auto_out_rresp           (_axi4yank_auto_in_rresp),
      .auto_out_recho_real_last (_axi4yank_auto_in_recho_real_last),
      .auto_out_rlast           (_axi4yank_auto_in_rlast)
  );
  SynchronizerShiftReg_w1_d10 cpu_reset_chain (
      .clock(clock),
      .io_d (reset),
      .io_q (_cpu_reset_chain_io_q)
  );
endmodule
module ysyxSoCFull (
    input         clock,
    reset,
    output [15:0] externalPins_gpio_out,
    input  [15:0] externalPins_gpio_in,
    output [ 7:0] externalPins_gpio_seg_0,
    externalPins_gpio_seg_1,
    externalPins_gpio_seg_2,
    externalPins_gpio_seg_3,
    externalPins_gpio_seg_4,
    externalPins_gpio_seg_5,
    externalPins_gpio_seg_6,
    externalPins_gpio_seg_7,
    input         externalPins_ps2_clk,
    externalPins_ps2_data,
    output [ 7:0] externalPins_vga_r,
    externalPins_vga_g,
    externalPins_vga_b,
    output        externalPins_vga_hsync,
    externalPins_vga_vsync,
    externalPins_vga_valid,
    input         externalPins_uart_rx,
    output        externalPins_uart_tx
);
  wire        _flash_miso;
  wire        _asic_spi_sck;
  wire [ 7:0] _asic_spi_ss;
  wire        _asic_spi_mosi;
  wire        _asic_sdram_clk;
  wire        _asic_sdram_cke;
  wire        _asic_sdram_cs;
  wire        _asic_sdram_ras;
  wire        _asic_sdram_cas;
  wire        _asic_sdram_we;
  wire [12:0] _asic_sdram_a;
  wire [ 1:0] _asic_sdram_ba;
  wire [ 3:0] _asic_sdram_dqm;
  wire [31:0] _dq_wire;
  ysyxSoCASIC asic (
      .clock     (clock),
      .reset     (reset),
      .spi_sck   (_asic_spi_sck),
      .spi_ss    (_asic_spi_ss),
      .spi_mosi  (_asic_spi_mosi),
      .spi_miso  (_flash_miso),
      .uart_rx   (externalPins_uart_rx),
      .uart_tx   (externalPins_uart_tx),
      .sdram_clk (_asic_sdram_clk),
      .sdram_cke (_asic_sdram_cke),
      .sdram_cs  (_asic_sdram_cs),
      .sdram_ras (_asic_sdram_ras),
      .sdram_cas (_asic_sdram_cas),
      .sdram_we  (_asic_sdram_we),
      .sdram_a   (_asic_sdram_a),
      .sdram_ba  (_asic_sdram_ba),
      .sdram_dqm (_asic_sdram_dqm),
      .sdram_dq  (_dq_wire),
      .gpio_out  (externalPins_gpio_out),
      .gpio_in   (externalPins_gpio_in),
      .gpio_seg_0(externalPins_gpio_seg_0),
      .gpio_seg_1(externalPins_gpio_seg_1),
      .gpio_seg_2(externalPins_gpio_seg_2),
      .gpio_seg_3(externalPins_gpio_seg_3),
      .gpio_seg_4(externalPins_gpio_seg_4),
      .gpio_seg_5(externalPins_gpio_seg_5),
      .gpio_seg_6(externalPins_gpio_seg_6),
      .gpio_seg_7(externalPins_gpio_seg_7),
      .ps2_clk   (externalPins_ps2_clk),
      .ps2_data  (externalPins_ps2_data),
      .vga_r     (externalPins_vga_r),
      .vga_g     (externalPins_vga_g),
      .vga_b     (externalPins_vga_b),
      .vga_hsync (externalPins_vga_hsync),
      .vga_vsync (externalPins_vga_vsync),
      .vga_valid (externalPins_vga_valid)
  );
  flash flash (
      .sck (_asic_spi_sck),
      .ss  (_asic_spi_ss[0]),
      .mosi(_asic_spi_mosi),
      .miso(_flash_miso)
  );
  sdram sdram (
      .clk(_asic_sdram_clk),
      .cke(_asic_sdram_cke),
      .cs (_asic_sdram_cs),
      .ras(_asic_sdram_ras),
      .cas(_asic_sdram_cas),
      .we (_asic_sdram_we),
      .a  (_asic_sdram_a),
      .ba (_asic_sdram_ba),
      .dqm(_asic_sdram_dqm),
      .dq (_dq_wire)
  );
endmodule
module ysyxSoCTop (
    input clock,
    reset
);
  ysyxSoCFull dut (
      .clock                  (clock),
      .reset                  (reset),
      .externalPins_gpio_out  (),
      .externalPins_gpio_in   (16'h0),
      .externalPins_gpio_seg_0(),
      .externalPins_gpio_seg_1(),
      .externalPins_gpio_seg_2(),
      .externalPins_gpio_seg_3(),
      .externalPins_gpio_seg_4(),
      .externalPins_gpio_seg_5(),
      .externalPins_gpio_seg_6(),
      .externalPins_gpio_seg_7(),
      .externalPins_ps2_clk   (1'h0),
      .externalPins_ps2_data  (1'h0),
      .externalPins_vga_r     (),
      .externalPins_vga_g     (),
      .externalPins_vga_b     (),
      .externalPins_vga_hsync (),
      .externalPins_vga_vsync (),
      .externalPins_vga_valid (),
      .externalPins_uart_rx   (1'h0),
      .externalPins_uart_tx   ()
  );
endmodule

