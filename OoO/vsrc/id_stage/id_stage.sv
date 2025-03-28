`default_nettype none

module id_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_frontend,

    input  frontend_t frontend_data,
    output decoder_t  idu2isu_instr,

    input  logic isu2idu_ready,
    output logic backend_ready,
    input  logic frontend_valid,
    output logic idu_valid
);

  wire  [31:0] pc = frontend_data.pc;
  wire  [31:0] inst = frontend_data.inst;
  bpu_t        bp;
  assign bp = frontend_data.bp;
  logic     [31:0] instr;
  logic            is_rv16;
  logic            rv16_err;
  logic            rv32_err;
  decoder_t        decoded_instr;

  typedef struct packed {
    logic valid;
    decoder_t decoded_instr;
  } idu_t;

  idu_t idu_d, idu_q;

  always_ff @(posedge clock) begin
    if (reset) begin
      idu_q <= '0;
    end else begin
      idu_q <= idu_d;
    end
  end

  always_comb begin
    idu_d = idu_q;
    backend_ready = 1'b0;

    if (isu2idu_ready) idu_d.valid = 1'b0;

    if (!idu_d.valid && frontend_valid) begin
      backend_ready = 1'b1;
      idu_d = '{decoded_instr, 1'b1};
    end

    if (flush_frontend) idu_d.valid = 1'b0;
  end

  assign idu_valid = idu_q.valid;
  assign idu2isu_instr = idu_q.decoded_instr;

  rv16_decoder RV16 (.*);
  rv32_decoder RV32 (.*);

`ifdef SIM_MODE
  always_ff @(posedge clock) begin
    if (frontend_valid && backend_ready) begin
      if (rv32_err) begin
        $display("[IDU] inst error 0x%08x at pc 0x%08x", inst, pc);
        $finish;
      end
    end
  end
`endif
endmodule

`default_nettype wire
