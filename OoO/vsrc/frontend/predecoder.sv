module predecoder
  import OoO_pkg::*;
(
    input logic [31:0] inst,
    output predecoder_t predecoded
);

  import riscv_instr::*;

  wire rv32_branch = inst[6:0] == BEQ[6:0];
  wire rv32_jal = inst[6:0] == JAL[6:0] || inst == MRET;
  wire rv32_jalr = inst[6:0] == JALR[6:0];
  wire rv32_call = (rv32_jalr | rv32_jal) & (inst[11:7] == 5'd1);
  wire rv32_ret = rv32_jalr & (inst[19:15] == 5'd1) & (inst[19:15] != inst[11:7]);
  // wire rv32_call = (rv32_jalr | rv32_jal) & ((inst[11:7] == 5'd1) | inst[11:7] == 5'd5);
  // wire rv32_ret = rv32_jalr & ((inst[19:15] == 5'd1) | inst[19:15] == 5'd5) & (inst[19:15] != inst[11:7]);

  wire rv16_branch = inst[15:13] inside {C_BEQZ[15:13], C_BNEZ[15:13]} && inst[1:0] == C_BEQZ[1:0];
  wire rvc_j = inst[15:13] == C_J[15:13] && inst[1:0] == C_J[1:0];
  wire rvc_jal = inst[15:13] == C_JAL[15:13] && inst[1:0] == C_JAL[1:0];  // RV64 doesn't have C_JAL
  wire rvc_jr = inst[15:12] == C_JR[15:12] && inst[6:0] == C_JR[6:0];
  wire rvc_jalr = inst[15:12] == C_JALR[15:12] && inst[6:0] == C_JALR[6:0];
  wire rv16_jal = rvc_j | rvc_jal;
  wire rv16_call = rvc_jalr | rvc_jal;
  wire rv16_ret = ((inst[11:7] == 5'd1) | (inst[11:7] == 5'd5)) & rvc_jr;

  assign predecoded.branch = rv32_branch | rv16_branch;
  assign predecoded.jal = rv32_jal | rv16_jal;
  assign predecoded.jalr = ~(rv32_ret | rv16_ret) & (rv32_jalr | rvc_jalr | rvc_jr);
  assign predecoded.call = rv32_call | rv16_call;
  assign predecoded.ret = rv32_ret | rv16_ret;

  always_comb begin
    predecoded.imm = 32'b0;
    if (inst == MRET) begin
      predecoded.imm = 32'b0;
    end else if (inst[1:0] == 2'b11) begin
      if (inst[3]) begin  // J
        predecoded.imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
      end else begin  // B
        predecoded.imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
      end
    end else begin
      if (inst[14]) begin  // B
        predecoded.imm = {{24{inst[12]}}, inst[6:5], inst[2], inst[11:10], inst[4:3], 1'b0};
      end else begin  // J
        predecoded.imm = {
          {21{inst[12]}}, inst[8], inst[10:9], inst[6], inst[7], inst[2], inst[11], inst[5:3], 1'b0
        };
      end
    end
  end

endmodule
