module ysyx_24080006_csr
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input csr_set_t csr_set,
    input logic [31:0] pc,

    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  wire [31:0] csr_cause = 32'd11;
  logic [31:0] csr_reg[8];



  assign csr_rdata = csr_reg[csr_set.csr_name];

  always_ff @(posedge clock) begin
    if (reset) begin
      csr_reg[mstatus] <= 32'h1800;
      csr_reg[mtvec] <= '0;
      csr_reg[mepc] <= '0;
      csr_reg[mcause] <= '0;
      csr_reg[mvendorid] <= 32'h79737978;
      csr_reg[marchid] <= 32'd24080006;
    end else begin
      if (ecall) begin
        csr_reg[mstatus] <= 32'h1800;
        csr_reg[mcause] <= csr_cause;
        csr_reg[mepc] <= pc;
      end else if (mret) begin
        csr_reg[mstatus] <= 32'h1800;
      end else if (csr_set.csr_enable) begin
        unique case (csr_set.csr_op)
          READ:  csr_reg[csr_set.csr_name] <= csr_reg[csr_set.csr_name];
          WRITE: csr_reg[csr_set.csr_name] <= csr_wdata;
          SET:   csr_reg[csr_set.csr_name] <= csr_wdata | csr_reg[csr_set.csr_name];
          CLEAR: csr_reg[csr_set.csr_name] <= ~csr_wdata & csr_reg[csr_set.csr_name];
        endcase
      end
    end
  end
endmodule
