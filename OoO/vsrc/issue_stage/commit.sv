module commit
  import OoO_pkg::*;
(
    input decoder_t commit_instr,
    output logic commit_valid,
    output logic [4:0] gpr_waddr,
    output logic [31:0] gpr_wdata,
    output logic gpr_we,
    output fu_op_e csr_op,
    output logic [31:0] csr_wdata,
    input logic [31:0] csr_rdata,
    output logic commit_csr,
    output logic commit_lsu
);

  assign gpr_waddr  = commit_instr.rd;
  assign commit_lsu = commit_instr.fu inside {FU_LOAD, FU_STORE} ? 1'b1 : 1'b0;

  always_comb begin
    commit_valid = 1'b0;
    gpr_we = 1'b0;
    commit_csr = 1'b0;
    gpr_wdata = commit_instr.result;
    csr_op = ALU_ADD;
    csr_wdata = 32'b0;

    if (commit_instr.valid) begin
      commit_valid = 1'b1;
      gpr_we = 1'b1;

      if (commit_instr.fu == FU_CSR) begin
        csr_op    = commit_instr.op;
        csr_wdata = commit_instr.result;
        commit_csr = 1'b1;
        gpr_wdata = csr_rdata;
      end

    end

  end

endmodule
