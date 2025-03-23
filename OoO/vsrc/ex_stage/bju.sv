module bju
  import OoO_pkg::*;
(
    input fu_data_t fu_data,

    input logic bju_valid,

    input logic [31:0] alu_result,
    input logic [31:0] pc,
    input logic is_rv16,

    input  bpu_t bpu,
    output bju_t bju,

    output logic [31:0] branch_result
);

  always_comb begin
    automatic logic [31:0] target_address;
    target_address = (fu_data.operation == BJU_JALR ? fu_data.operand_a : pc) + fu_data.imm;
    if (fu_data.operation == BJU_JALR) target_address[0] = 1'b0;

    branch_result = pc + (is_rv16 ? 32'h2 : 32'h4);  // next pc

    bju.valid = branch_valid_i;
    bju.pc = pc_i;
    bju.target_address = 32'b0;
    bju.is_mispredict = 1'b0;
    bju.is_taken = 1'b0;
    bju.cf_type = bpu.cf;

    if (bju_valid) begin
      if (fu_data.operation == BJU_JAL) begin
        ;
      end else if (fu_data.operation == BJU_JALR) begin

        bju.target_address = target_address;
        if (bpu.cf == CF_NONE || target_address != bpu.predict_addr) begin
          bju.is_mispredict = 1'b1;
          if (bpu.cf != CF_RET) bju.cf_type = CF_JALR;
        end

      end else begin

        bju.target_address = alu_result[0] ? target_address : branch_result;
        bju.is_taken = alu_result[0];
        bju.cf_type = CF_BRANCH;
        bju.is_mispredict = alu_result[0] != (bpu.cf == CF_BRANCH);

      end
    end
  end

endmodule
