module frontend
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_frontend,
    input bju_t bju,
    input logic mret_valid,
    input logic [31:0] mepc_addr,
    input logic ex_valid,
    input logic [31:0] mtvec_addr,
    output frontend_t frontend_data,
    output logic frontend_valid,
    input logic backend_ready,

    output logic icache_hit,
    output logic icache_miss,
    output logic icache_skip,
    output logic is_compressed,
    output logic fetch_cycle,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m
);

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  assign ifu2icu_ready = 1'b1;
  logic [31:0] ic_val, ic_addr;
  logic [            31:0] icache_data_q;
  logic                    icache_valid_q;
  logic [            31:0] icache_addr_q;

  // Instruction Cache Registers, from I$
  logic                    instr_queue_ready;
  logic [InstPerFetch-1:0] inst_queue_push;
  logic [31:0] fetch_addr, next_fetch_d, next_fetch_q;  // next PC

  // indicates whether we come out of reset (then we need to load RstAddr)
  logic                    first_fetch;

  logic                    replay;
  logic [            31:0] replay_addr;

  // Instruction FIFO
  logic [            31:0] predict_addr;
  cf_e  [InstPerFetch-1:0] cf_type;

  logic [            31:0] instr;
  logic [            31:0] addr;
  logic                    instruction_valid;
  assign instruction_valid = icache_valid_q;
  assign addr = icache_addr_q;
  assign instr = icache_data_q;

  // for the return address stack it doens't matter as we have the
  // address of the call/return already
  logic bpu_predict;

  // Cache interface
  assign ifu2icu_valid = instr_queue_ready;

  always_comb begin
    if (first_fetch) begin
      fetch_addr   = RstAddr;
      next_fetch_d = RstAddr;
    end else begin
      fetch_addr   = next_fetch_q;
      next_fetch_d = next_fetch_q;
    end

    if (bpu_predict) begin
      fetch_addr   = predict_addr;
      next_fetch_d = predict_addr;
    end

    if (icu2ifu_ready & instr_queue_ready) begin
      next_fetch_d = fetch_addr + 32'h4;
    end

    if (replay) begin
      next_fetch_d = replay_addr;
    end

    if (bju.valid & bju.is_mispredict) begin
      next_fetch_d = bju.target_address;
    end

    // if (mret_valid) begin
    //   next_fetch_d = mepc_addr;
    // end

    // if (ex_valid) begin
    //   next_fetch_d = mtvec_addr;
    // end
  end
  wire flush_inside = flush_frontend | replay | bju.valid & bju.is_mispredict;
  always_ff @(posedge clock) begin
    if (reset) begin
      first_fetch    <= 1'b1;
      next_fetch_q   <= '0;
      icache_data_q  <= '0;
      icache_valid_q <= 1'b0;
      icache_addr_q  <= 'b0;
    end else begin
      first_fetch    <= 1'b0;
      next_fetch_q   <= next_fetch_d;
      icache_valid_q <= icu2ifu_valid & !flush_inside;
      if (icu2ifu_valid) begin
        icache_data_q <= ic_val;
        icache_addr_q <= ic_addr;
      end
    end
  end

  aligner_t [InstPerFetch-1:0] aligned;
  assign aligned[0].valid = instruction_valid;
  assign aligned[0].pc = addr;
  assign aligned[0].inst = instr;

  bpu BPU (.*);
  ideal_itcm ICU (.*);
  inst_queue INST_QUEUE (.*);

endmodule
