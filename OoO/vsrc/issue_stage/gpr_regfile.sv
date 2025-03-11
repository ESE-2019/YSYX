`default_nettype none

module gpr_regfile
  import ysyx_24080006_pkg::*;
(
    input  logic                clock,
    input  logic                reset,
    input  logic [RegWidth-1:0] gpr_raddr_1,
    input  logic [RegWidth-1:0] gpr_raddr_2,
    input  logic [RegWidth-1:0] gpr_waddr,
    output logic [        31:0] gpr_rdata_1,
    output logic [        31:0] gpr_rdata_2,
    input  logic [        31:0] gpr_wdata,
    input  logic                gpr_we
);

  logic [31:0] regfile[1<<RegWidth];

  always_ff @(posedge clock) begin
    if (reset) begin
      foreach (regfile[i]) begin
        regfile[i] <= '0;
      end
    end else if (gpr_we && gpr_waddr != '0) begin
      regfile[gpr_waddr] <= gpr_wdata;
    end
  end

  assign gpr_rdata_1 = regfile[gpr_raddr_1];
  assign gpr_rdata_2 = regfile[gpr_raddr_2];

endmodule

`default_nettype wire
