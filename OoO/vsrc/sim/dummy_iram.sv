module dummy_iram
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic instr_req_o,
    input logic [31:0] instr_addr_o,
    output logic instr_gnt_i,
    output logic instr_rvalid_i,
    output logic [31:0] instr_rdata_i
);

  import "DPI-C" function int pmem_read(input int raddr);

  logic rden;

  always_ff @(posedge clock) begin
    if (reset) begin
      instr_gnt_i <= 1'b0;
      instr_rvalid_i <= 1'b0;
      instr_rdata_i <= 32'b0;
      rden <= 1'b0;
    end else begin
      if (instr_req_o) begin
        instr_gnt_i <= 1'b1;
        rden <= 1'b1;
        instr_rdata_i <= pmem_read(instr_addr_o);
      end else begin
        instr_gnt_i <= 1'b0;
      end
      if (rden) begin
        instr_rvalid_i <= 1'b1;
        rden <= 1'b0;
      end else begin
        instr_rvalid_i <= 1'b0;
      end
    end
  end

endmodule
