module dummy_csr
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    //input logic flush,
    input fu_data_t fu_data,
    output logic csr_ready,
    input logic csr_valid,
    output logic [31:0] csr_result,
    input logic commit_csr,
    output logic [11:0] csr_addr
);

  logic [11:0] csr_addr_d;
  logic csr_valid_d, csr_valid_q;
  assign csr_result = fu_data.operand_a;

  always_comb begin
    csr_addr_d = csr_addr;
    csr_valid_d = csr_valid_q;
    csr_ready   = 1'b1;

    if ((csr_valid_q || csr_valid) && ~commit_csr) csr_ready = 1'b0;

    if (csr_valid) begin
      csr_addr_d  = fu_data.operand_b[11:0];
      csr_valid_d = 1'b1;
    end

    if (commit_csr && ~csr_valid) begin
      csr_valid_d = 1'b0;
    end

    //if (flush) csr_valid_d = 1'b0;
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      csr_addr <= 12'b0;
      csr_valid_q <= 1'b0;
    end else begin
      csr_addr <= csr_addr_d;
      csr_valid_q <= csr_valid_d;
    end
  end

endmodule
