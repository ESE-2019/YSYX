module bu
  import OoO_pkg::*;
(
    input fu_data_t fu_data,

    input logic bu_valid,

    input logic alu_res,
    input logic [31:0] pc,

    input logic [31:0] rs1_data,
    input logic [31:0] imm,
    input logic is_rv16,

    output logic [31:0] branch_result,

    output bp_resolve_t resolved_branch_o
);


  always_comb begin
    automatic logic [31:0] jump_base;
    jump_base = fu_data.operation == CF_JALR ? fu_data.operand_a : pc;
    resolved_branch_o.target_address = 32'b0;
    resolved_branch_o.is_taken = 1'b0;
    resolved_branch_o.valid = bu_valid;
    resolved_branch_o.is_mispredict = 1'b0;
    resolved_branch_o.cf_type = branch_predict_i.cf;

    //resolve_branch_o = 1'b0;  //TODO

    next_pc = pc + (is_rv16 ? 32'h2 : 32'h4);
    target_address = jump_base + fu_data.imm;
    if (fu_data.operation == CF_JALR) target_address[0] = 1'b0;

    branch_result = next_pc;
    resolved_branch_o.pc = pc;
    // There are only three sources of mispredicts:
    // 1. Branches
    // 2. Jumps to register addresses
    // 3. Zcmt instructions
    if (bu_valid) begin
      // write target address which goes to PC Gen or select target address if zcmt
      resolved_branch_o.target_address = alu_res ? target_address : next_pc;
      resolved_branch_o.is_taken = alu_res;

      // check the outcome of the branch speculation
      // if (branch) begin
      //   // Set the `cf_type` of the output as `branch`, this will update the BHT.
      //   resolved_branch_o.cf_type = ariane_pkg::Branch;
      //   // If the ALU comparison does not agree with the BHT prediction set the resolution as mispredicted.
      //   resolved_branch_o.is_mispredict  = branch_comp_res_i != (branch_predict_i.cf == ariane_pkg::Branch);
      // end
      // if (fu_data_i.operation == ariane_pkg::JALR
      //     // check if the address of the jump register is correct and that we actually predicted
      //     && (branch_predict_i.cf == ariane_pkg::NoCF || target_address != branch_predict_i.predict_address)) begin
      //   resolved_branch_o.is_mispredict = 1'b1;
      //   // update BTB only if this wasn't a return
      //   if (branch_predict_i.cf != ariane_pkg::Return)
      //     resolved_branch_o.cf_type = ariane_pkg::JumpR;
      // end
      // to resolve the branch in ID
      //resolve_branch_o = 1'b1;
    end
  end

endmodule
