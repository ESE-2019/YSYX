module inst_queue
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_frontend,
    input logic [31:0] instr,
    input logic [31:0] addr,
    input logic instruction_valid,
    output logic instr_queue_ready,
    output logic inst_queue_push,
    input logic [31:0] predict_addr,
    input cf_e cf_type,
    output logic replay,
    output logic [31:0] replay_addr,
    output frontend_t frontend_data,
    output logic frontend_valid,
    input logic backend_ready
);

  frontend_t fifo_wdata;
  logic fifo_wren;
  logic fifo_full;
  logic fifo_empty;

  assign instr_queue_ready = ~fifo_full;
  assign inst_queue_push = fifo_wren;

  assign fifo_wren = instruction_valid & ~fifo_full;
  assign fifo_wdata.pc = addr;
  assign fifo_wdata.inst = instr;
  assign fifo_wdata.bp.cf = cf_type;
  assign fifo_wdata.bp.predict_addr = predict_addr;

  assign replay = fifo_full & instruction_valid;
  assign replay_addr = addr;

  assign frontend_valid = ~fifo_empty;

  fifo #(
      .DATA_WIDTH($bits(fifo_wdata))
  ) INST_FIFO (
      .clock,
      .reset,
      .fifo_flush(flush_frontend),
      .fifo_wren,
      .fifo_rden(frontend_valid & backend_ready),
      .fifo_wdata,
      .fifo_rdata(frontend_data),
      .fifo_full,
      .fifo_empty,
      .fifo_data_avail()
  );


endmodule
