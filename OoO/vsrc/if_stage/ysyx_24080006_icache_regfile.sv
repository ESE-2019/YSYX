`default_nettype none

module ysyx_24080006_icache_regfile
  import OoO_pkg::*;
(
    input  logic                        clock,
    input  logic                        reset,
    input  logic                        fencei,
    input  logic    [IcacheLineNum-1:0] ic_index,
    output icache_t                     ic_rdata,
    input  logic                        ic_we,
    input  logic    [IcacheLineNum-1:0] ic_waddr,
    input  icache_t                     ic_wdata
);
  icache_t Memory[2 ** IcacheLineNum];
  always @(posedge clock) begin
    if (reset) begin
      foreach (Memory[i]) Memory[i] <= '0;
    end else if (fencei) begin
      foreach (Memory[i]) Memory[i].valid <= 1'b0;
    end else begin
      if (ic_we) Memory[ic_waddr] <= ic_wdata;
    end
  end
  assign ic_rdata = ic_we && (ic_index == ic_waddr) ? ic_wdata : Memory[ic_index];
endmodule

`default_nettype wire
