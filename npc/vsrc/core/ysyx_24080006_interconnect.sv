module ysyx_24080006_interconnect
  import ysyx_24080006_pkg::*;
(
    input clock,
    input reset,

    input  axi_r_m2s_t ifu_r_m2s,
    output axi_r_s2m_t ifu_r_s2m,

    input  axi_w_m2s_t lsu_w_m2s,
    output axi_w_s2m_t lsu_w_s2m,
    input  axi_r_m2s_t lsu_r_m2s,
    output axi_r_s2m_t lsu_r_s2m,

    output axi_w_m2s_t clint_w_m2s,
    input  axi_w_s2m_t clint_w_s2m,
    output axi_r_m2s_t clint_r_m2s,
    input  axi_r_s2m_t clint_r_s2m,

    output axi_w_m2s_t core_w_m2s,
    input  axi_w_s2m_t core_w_s2m,
    output axi_r_m2s_t core_r_m2s,
    input  axi_r_s2m_t core_r_s2m
);

  axi_w_m2s_t imd_w_m2s;
  axi_w_s2m_t imd_w_s2m;
  axi_r_m2s_t imd_r_m2s;
  axi_r_s2m_t imd_r_s2m;

  //write channel
  assign lsu_w_s2m.awready = imd_w_s2m.awready;
  assign imd_w_m2s.awvalid = lsu_w_m2s.awvalid;
  assign imd_w_m2s.awaddr  = lsu_w_m2s.awaddr;
  assign imd_w_m2s.awid    = lsu_w_m2s.awid;
  assign imd_w_m2s.awlen   = lsu_w_m2s.awlen;
  assign imd_w_m2s.awsize  = lsu_w_m2s.awsize;
  assign imd_w_m2s.awburst = lsu_w_m2s.awburst;

  assign lsu_w_s2m.wready  = imd_w_s2m.wready;
  assign imd_w_m2s.wvalid  = lsu_w_m2s.wvalid;
  assign imd_w_m2s.wdata   = lsu_w_m2s.wdata;
  assign imd_w_m2s.wstrb   = lsu_w_m2s.wstrb;
  assign imd_w_m2s.wlast   = lsu_w_m2s.wlast;

  assign imd_w_m2s.bready  = lsu_w_m2s.bready;
  assign lsu_w_s2m.bvalid  = imd_w_s2m.bvalid;
  assign lsu_w_s2m.bresp   = imd_w_s2m.bresp;
  assign lsu_w_s2m.bid     = imd_w_s2m.bid;

  //read channel
  assign ifu_r_s2m.rresp   = imd_r_s2m.rresp;
  assign ifu_r_s2m.rdata   = imd_r_s2m.rdata;
  assign ifu_r_s2m.rlast   = imd_r_s2m.rlast;
  assign ifu_r_s2m.rid     = imd_r_s2m.rid;

  assign lsu_r_s2m.rresp   = imd_r_s2m.rresp;
  assign lsu_r_s2m.rdata   = imd_r_s2m.rdata;
  assign lsu_r_s2m.rlast   = imd_r_s2m.rlast;
  assign lsu_r_s2m.rid     = imd_r_s2m.rid;

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
        if (ifu_r_m2s.arvalid) begin
          next = IFUR;
        end else if (lsu_r_m2s.arvalid) begin
          next = LSUR;
        end else begin
          next = IDLE;
        end
      end
      LSUR: begin
        if (lsu_r_m2s.rready && lsu_r_s2m.rvalid && lsu_r_s2m.rlast) begin
          if (ifu_r_m2s.arvalid) begin
            next = IFUR;
          end else begin
            next = IDLE;
          end
        end else begin
          next = LSUR;
        end
      end
      IFUR: begin
        if (ifu_r_m2s.rready && ifu_r_s2m.rvalid && ifu_r_s2m.rlast) begin
          if (lsu_r_m2s.arvalid) begin
            next = LSUR;
          end else begin
            next = IDLE;
          end
        end else begin
          next = IFUR;
        end
      end
    endcase
  end

  assign ifu_r_s2m.arready = curr == IFUR ? imd_r_s2m.arready : 0;
  assign lsu_r_s2m.arready = curr == LSUR ? imd_r_s2m.arready : 0;
  assign ifu_r_s2m.rvalid  = curr == IFUR ? imd_r_s2m.rvalid : 0;
  assign lsu_r_s2m.rvalid  = curr == LSUR ? imd_r_s2m.rvalid : 0;

  always_comb begin
    unique case (curr)
      IDLE: begin
        imd_r_m2s.arvalid = 0;
        imd_r_m2s.rready  = 0;
      end
      LSUR: begin
        imd_r_m2s.arvalid = lsu_r_m2s.arvalid;
        imd_r_m2s.rready  = lsu_r_m2s.rready;
      end
      IFUR: begin
        imd_r_m2s.arvalid = ifu_r_m2s.arvalid;
        imd_r_m2s.rready  = ifu_r_m2s.rready;
      end
    endcase
  end

  assign imd_r_m2s.araddr = curr == LSUR ? lsu_r_m2s.araddr : ifu_r_m2s.araddr;
  assign imd_r_m2s.arid = '0;  //curr == LSUR ? lsu_r_m2s.arid    : ifu_r_m2s.arid  ;
  assign imd_r_m2s.arlen = curr == LSUR ? lsu_r_m2s.arlen : ifu_r_m2s.arlen;
  assign imd_r_m2s.arsize = curr == LSUR ? lsu_r_m2s.arsize : ifu_r_m2s.arsize;
  assign imd_r_m2s.arburst = 2'b10;  //curr == LSUR ? lsu_r_m2s.arburst : ifu_r_m2s.arburst;

  // write channel
  assign imd_w_s2m.awready = imd_w_m2s.awaddr >= 32'h0200_ffff ? core_w_s2m.awready : clint_w_s2m.awready;
  assign core_w_m2s.awvalid = imd_w_m2s.awaddr >= 32'h0200_ffff ? imd_w_m2s.awvalid : 0;
  assign clint_w_m2s.awvalid = imd_w_m2s.awaddr < 32'h0200_ffff ? imd_w_m2s.awvalid : 0;
  assign core_w_m2s.awaddr = imd_w_m2s.awaddr;
  assign core_w_m2s.awid = imd_w_m2s.awid;
  assign core_w_m2s.awlen = imd_w_m2s.awlen;
  assign core_w_m2s.awsize = imd_w_m2s.awsize;
  assign core_w_m2s.awburst = imd_w_m2s.awburst;
  assign clint_w_m2s.awaddr = imd_w_m2s.awaddr;
  assign clint_w_m2s.awid = imd_w_m2s.awid;
  assign clint_w_m2s.awlen = imd_w_m2s.awlen;
  assign clint_w_m2s.awsize = imd_w_m2s.awsize;
  assign clint_w_m2s.awburst = imd_w_m2s.awburst;

  assign imd_w_s2m.wready = imd_w_m2s.awaddr >= 32'h0200_ffff ? core_w_s2m.wready : clint_w_s2m.wready;
  assign core_w_m2s.wvalid = imd_w_m2s.awaddr >= 32'h0200_ffff ? imd_w_m2s.wvalid : 0;
  assign clint_w_m2s.wvalid = imd_w_m2s.awaddr < 32'h0200_ffff ? imd_w_m2s.wvalid : 0;
  assign core_w_m2s.wdata = imd_w_m2s.wdata;
  assign core_w_m2s.wstrb = imd_w_m2s.wstrb;
  assign core_w_m2s.wlast = imd_w_m2s.wlast;
  assign clint_w_m2s.wdata = imd_w_m2s.wdata;
  assign clint_w_m2s.wstrb = imd_w_m2s.wstrb;
  assign clint_w_m2s.wlast = imd_w_m2s.wlast;

  assign core_w_m2s.bready = imd_w_m2s.awaddr >= 32'h0200_ffff ? imd_w_m2s.bready : 0;
  assign clint_w_m2s.bready = imd_w_m2s.awaddr < 32'h0200_ffff ? imd_w_m2s.bready : 0;
  assign imd_w_s2m.bvalid = imd_w_m2s.awaddr >= 32'h0200_ffff ? core_w_s2m.bvalid : clint_w_s2m.bvalid;

  // read channel
  assign imd_r_s2m.arready = imd_r_m2s.araddr >= 32'h0200_ffff ? core_r_s2m.arready : clint_r_s2m.arready;
  assign core_r_m2s.arvalid = imd_r_m2s.araddr >= 32'h0200_ffff ? imd_r_m2s.arvalid : 0;
  assign clint_r_m2s.arvalid = imd_r_m2s.araddr < 32'h0200_ffff ? imd_r_m2s.arvalid : 0;
  assign core_r_m2s.araddr = imd_r_m2s.araddr;
  assign core_r_m2s.arid = imd_r_m2s.arid;
  assign core_r_m2s.arlen = imd_r_m2s.arlen;
  assign core_r_m2s.arsize = imd_r_m2s.arsize;
  assign core_r_m2s.arburst = imd_r_m2s.arburst;
  assign clint_r_m2s.araddr = imd_r_m2s.araddr;
  assign clint_r_m2s.arid = imd_r_m2s.arid;
  assign clint_r_m2s.arlen = imd_r_m2s.arlen;
  assign clint_r_m2s.arsize = imd_r_m2s.arsize;
  assign clint_r_m2s.arburst = imd_r_m2s.arburst;

  assign core_r_m2s.rready = imd_r_m2s.araddr >= 32'h0200_ffff ? imd_r_m2s.rready : 0;
  assign clint_r_m2s.rready = imd_r_m2s.araddr < 32'h0200_ffff ? imd_r_m2s.rready : 0;
  assign imd_r_s2m.rvalid = imd_r_m2s.araddr >= 32'h0200_ffff ? core_r_s2m.rvalid : clint_r_s2m.rvalid;
  assign imd_r_s2m.rdata = imd_r_m2s.araddr >= 32'h0200_ffff ? core_r_s2m.rdata : clint_r_s2m.rdata;
  assign imd_r_s2m.rlast = imd_r_m2s.araddr >= 32'h0200_ffff ? core_r_s2m.rlast : clint_r_s2m.rlast;

endmodule
