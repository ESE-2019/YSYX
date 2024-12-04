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
    end else if (reg_we && rd_addr != '0) begin
      regfile[rd_addr] <= rd_data;
      //$display("[rd]%d: 0x%08x", rd_addr, rd_data);
    end
  end

  wire forward_1 = reg_we && |rd_addr != 1'b0 && (rd_addr == rs1_addr);
  wire forward_2 = reg_we && |rd_addr != 1'b0 && (rd_addr == rs2_addr);

  assign rs1_data = forward_1 ? rd_data : regfile[rs1_addr];  //forward_1 ? rd_data :
  assign rs2_data = forward_2 ? rd_data : regfile[rs2_addr];  //forward_2 ? rd_data :

endmodule
