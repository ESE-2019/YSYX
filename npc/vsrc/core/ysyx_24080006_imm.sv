module ysyx_24080006_imm (
    input  logic [31:0] inst,
    output logic [31:0] imm
);

  always_comb begin
    imm = {{20{inst[31]}}, inst[31:20]};
    unique case (inst[6:0])
      7'b0010011, 7'b0000011, 7'b1100111: imm = {{20{inst[31]}}, inst[31:20]};  //I
      7'b0100011: imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};  //S
      7'b1100011: imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};  //B
      7'b0110111, 7'b0010111: imm = {inst[31:12], 12'b0};  //U
      7'b1101111: imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};  //J
      default: ;
    endcase
  end
endmodule
