module dummy_csr
  import OoO_pkg::*;
(
    // Subsystem Clock - SUBSYSTEM
    input logic clock,
    // Asynchronous reset active low - SUBSYSTEM
    input logic reset,
    // Flush CSR - CONTROLLER
    input logic flush_i,
    // FU data needed to execute instruction - ISSUE_STAGE
    input fu_data_t fu_data_i,
    // CSR FU is ready - ISSUE_STAGE
    output logic csr_ready,
    // CSR instruction is valid - ISSUE_STAGE
    input logic csr_valid,
    // CSR buffer result - ISSUE_STAGE
    output logic [CVA6Cfg.XLEN-1:0] csr_result_o,
    // commit the pending CSR OP - TO_BE_COMPLETED
    input logic commit_csr,
    // CSR address to write - COMMIT_STAGE
    output logic [11:0] csr_addr_o
);


  typedef struct packed {
    logic [11:0] addr;
    logic        valid;
  } dummy_csr_t;
  dummy_csr_t dummy_csr_n, dummy_csr_q;

  // control logic, scoreboard signals
  assign csr_result_o = fu_data_i.operand_a;
  assign csr_addr_o   = dummy_csr_q.addr;

  // write logic
  always_comb begin
    dummy_csr_n   = dummy_csr_q;
    // by default we are ready
    csr_ready = 1'b1;
    // if we have a valid uncomiited csr req or are just getting one WITHOUT a commit in, we are not ready
    if ((dummy_csr_q.valid || csr_valid) && ~commit_csr) csr_ready = 1'b0;
    // if we got a valid from the scoreboard
    // store the CSR address
    if (csr_valid) begin
      dummy_csr_n.addr = fu_data_i.operand_b[11:0];
      dummy_csr_n.valid       = 1'b1;
    end
    // if we get a commit and no new valid instruction -> clear the valid bit
    if (commit_csr && ~csr_valid) begin
      dummy_csr_n.valid = 1'b0;
    end
    // clear the buffer if we flushed
    if (flush_i) dummy_csr_n.valid = 1'b0;
  end
  // sequential process
  always_ff @(posedge clock) begin
    if (reset) begin
      dummy_csr_q <= '0;
    end else begin
      dummy_csr_q <= dummy_csr_n;
    end
  end


endmodule
