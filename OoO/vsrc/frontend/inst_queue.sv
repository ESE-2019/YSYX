module inst_queue
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_i,
    input logic [31:0] instr_i,
    input logic [31:0] addr_i,
    input logic valid_i,
    output logic ready_o,
    output logic inst_queue_push,
    input logic [31:0] predict_addr,
    input cf_t cf_type_i,
    output logic replay,
    output logic [31:0] replay_addr,
    output frontend_t frontend_data,
    output logic frontend_valid,
    input logic backend_ready
);
  // instruction queues
  frontend_t fifo_in, fifo_out;
  logic fifo_push;
  logic pop_instr;
  logic instr_queue_full;
  logic instr_queue_empty;
  logic instr_overflow;

  // replay interface
  logic instr_overflow_fifo;
  assign ready_o = ~instr_queue_full;
  assign inst_queue_push = fifo_push;
  // ----------------------
  // Input interface
  // ----------------------
  assign fifo_push = valid_i & ~instr_queue_full;

  assign fifo_in.pc = addr_i;
  assign fifo_in.inst = instr_i;
  assign fifo_in.bp.cf = cf_type_i;
  assign fifo_in.bp.predict_addr = predict_addr;

  // ----------------------
  // Replay Logic
  // ----------------------
  // We need to replay a instruction fetch iff:
  // 1. One of the instruction data FIFOs was full and we needed it
  // (e.g.: we pushed and it was full)
  // 2. The address/branch predict FIFO was full
  // if one of the FIFOs was full we need to replay the faulting instruction
  assign instr_overflow_fifo = instr_queue_full & valid_i;
  assign instr_overflow = |instr_overflow_fifo;
  assign replay = instr_overflow;
  assign replay_addr = addr_i;

  // ----------------------
  // Downstream interface
  // ----------------------
  // as long as there is at least one queue which can take the value we have a valid instruction
  assign frontend_valid = ~instr_queue_empty;


  assign frontend_data = fifo_out;
  assign pop_instr = frontend_valid & backend_ready;

  cva6_fifo_v3 #(
      .FPGA_ALTERA(0),
      .DEPTH(4),
      .dtype(frontend_t),
      .FPGA_EN(0)
  ) i_fifo_instr_data (
      .clk_i     (clock),
      .rst_ni    (~reset),
      .flush_i   (flush_i),
      .testmode_i(1'b0),
      .full_o    (instr_queue_full),
      .empty_o   (instr_queue_empty),
      .usage_o   (),
      .data_i    (fifo_in),
      .push_i    (fifo_push),
      .data_o    (fifo_out),
      .pop_i     (pop_instr)
  );


endmodule
