module bu
  import OoO_pkg::*;
(
    input fu_data_t fu_data,

    input logic bu_valid,

    input logic [31:0] alu_result,
    input logic [31:0] pc,
    input logic is_rv16,

    output logic [31:0] branch_result,  // next pc
    output logic [31:0] branch_address,
    output logic branch_taken
);

  always_comb begin
    automatic logic [31:0] target_address;
    branch_address = 32'b0;
    branch_taken = 1'b0;
    branch_result = pc + (is_rv16 ? 32'h2 : 32'h4);
    target_address = (fu_data.operation == CF_JALR ? fu_data.operand_a : pc) + fu_data.imm;
    if (fu_data.operation == CF_JALR) target_address[0] = 1'b0;

    if (bu_valid) begin
      branch_address = alu_result[0] || fu_data.operation inside {CF_JAL, CF_JALR} ?
        target_address : branch_result;
      branch_taken = alu_result[0];
    end
  end

endmodule
