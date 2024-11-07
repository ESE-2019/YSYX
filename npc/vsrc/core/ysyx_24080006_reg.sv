module ysyx_24080006_reg
  import ysyx_24080006_pkg::*;
(
    input  logic                 clock,
    input  logic                 reset,
    input  logic                 reg_we,
    input  logic [REG_WIDTH-1:0] rs1_addr,
    input  logic [REG_WIDTH-1:0] rs2_addr,
    input  logic [REG_WIDTH-1:0] rd_addr,
    input  logic [         31:0] rd_data,
    output logic [         31:0] rs1_data,
    output logic [         31:0] rs2_data
);

  logic [31:0] regfile[1<<REG_WIDTH];

  always_ff @(posedge clock) begin
    if (reset) begin
      foreach (regfile[i]) begin
        regfile[i] <= '0;
      end
    end else if (reg_we && |rd_addr != 1'b0) begin
      regfile[rd_addr] <= rd_data;
    end
  end

  assign rs1_data = regfile[rs1_addr];
  assign rs2_data = regfile[rs2_addr];

endmodule
