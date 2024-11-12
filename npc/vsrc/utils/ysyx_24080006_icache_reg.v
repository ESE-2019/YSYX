module ysyx_24080006_icache_reg
  import ysyx_24080006_pkg::*;
(
    input  logic               clock,
    input  logic               reset,
    input  logic    [IC_N-1:0] ic_index,
    output icache_t            ic_rdata,
    input  logic               ic_we,
    input  icache_t            ic_wdata
);
  icache_t Memory[IC_2];
  always @(posedge clock) begin
    if (reset) begin
      foreach (Memory[i]) Memory[i] <= '0;
    end else begin
      if (ic_we) Memory[ic_index] <= ic_wdata;
    end
  end
  assign ic_rdata = Memory[ic_index];
endmodule
