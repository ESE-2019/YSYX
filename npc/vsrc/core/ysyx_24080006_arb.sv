module ysyx_24080006_arb (
    input clock,
    input reset,
    ysyx_24080006_axi.slave axi_ifu,
    ysyx_24080006_axi.slave axi_lsu,
    ysyx_24080006_axi.master axi
);
  import ysyx_24080006_pkg::*;
  //write channel
  assign axi_lsu.awready = axi.awready;
  assign axi.awvalid     = axi_lsu.awvalid;
  assign axi.awaddr      = axi_lsu.awaddr;
  assign axi.awid        = axi_lsu.awid;
  assign axi.awlen       = axi_lsu.awlen;
  assign axi.awsize      = axi_lsu.awsize;
  assign axi.awburst     = axi_lsu.awburst;

  assign axi_lsu.wready  = axi.wready;
  assign axi.wvalid      = axi_lsu.wvalid;
  assign axi.wdata       = axi_lsu.wdata;
  assign axi.wstrb       = axi_lsu.wstrb;
  assign axi.wlast       = axi_lsu.wlast;

  assign axi.bready      = axi_lsu.bready;
  assign axi_lsu.bvalid  = axi.bvalid;
  assign axi_lsu.bresp   = axi.bresp;
  assign axi_lsu.bid     = axi.bid;

  //read channel
  assign axi_ifu.rresp   = axi.rresp;
  assign axi_ifu.rdata   = axi.rdata;
  assign axi_ifu.rlast   = axi.rlast;
  assign axi_ifu.rid     = axi.rid;

  assign axi_lsu.rresp   = axi.rresp;
  assign axi_lsu.rdata   = axi.rdata;
  assign axi_lsu.rlast   = axi.rlast;
  assign axi_lsu.rid     = axi.rid;

  enum logic [1:0] {
    IDLE,
    IFUR,
    LSUR
  }
      curr, next;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  // fsm 2
    unique case (curr)
      IDLE: begin
        if (axi_lsu.arvalid || axi_lsu.rvalid) next = LSUR;
        else if (axi_ifu.arvalid || axi_ifu.rvalid) next = IFUR;
        else next = IDLE;
      end
      LSUR: begin
        if (axi_lsu.rready && axi_lsu.rvalid)  // && axi_lsu.rlast
          next = IDLE;
        else next = LSUR;
      end
      IFUR: begin
        if (axi_ifu.rready && axi_ifu.rvalid && (axi_ifu.arlen == '0 || axi_ifu.rlast))  // && axi_ifu.rlast
          next = IDLE;
        else next = IFUR;
      end
    endcase
  end

  assign axi_ifu.arready = curr == IFUR ? axi.arready : 0;
  assign axi_lsu.arready = curr == LSUR ? axi.arready : 0;
  assign axi_ifu.rvalid  = curr == IFUR ? axi.rvalid : 0;
  assign axi_lsu.rvalid  = curr == LSUR ? axi.rvalid : 0;
  always_comb begin
    unique case (curr)
      IDLE: begin
        axi.arvalid = 0;
        axi.rready  = 0;
      end
      LSUR: begin
        axi.arvalid = axi_lsu.arvalid;
        axi.rready  = axi_lsu.rready;
      end
      IFUR: begin
        axi.arvalid = axi_ifu.arvalid;
        axi.rready  = axi_ifu.rready;
      end
    endcase
  end

  assign axi.araddr  = curr == LSUR ? axi_lsu.araddr  : axi_ifu.araddr;
  assign axi.arid    = curr == LSUR ? axi_lsu.arid    : axi_ifu.arid  ;
  assign axi.arlen   = curr == LSUR ? axi_lsu.arlen   : axi_ifu.arlen ;
  assign axi.arsize  = curr == LSUR ? axi_lsu.arsize  : axi_ifu.arsize;
  assign axi.arburst = curr == LSUR ? axi_lsu.arburst : axi_ifu.arburst;

endmodule
