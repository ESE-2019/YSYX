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
  logic [31:0] ic_val, fetch_addr, ic_addr;
  logic [            31:0] icache_data_q;
  logic                    icache_valid_q;
  logic [            31:0] icache_addr_q;

  // Instruction Cache Registers, from I$
  logic                    instr_queue_ready;
  logic [InstPerFetch-1:0] inst_queue_push;
  // instruction fetch is ready
  logic                    if_ready;
  logic [31:0] npc_d, npc_q;  // next PC

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
  logic bp_valid;

  // Cache interface
  assign ifu2icu_valid = instr_queue_ready;
  assign if_ready = icu2ifu_ready & instr_queue_ready;

  always_comb begin
    automatic logic [31:0] fetch_address;
    if (first_fetch) begin
      npc_d         = RstAddr;
      fetch_address = RstAddr;
    end else begin
      fetch_address = npc_q;
      // keep stable by default
      npc_d         = npc_q;
    end
    // 0. Branch Prediction
    if (bp_valid) begin
      fetch_address = predict_addr;
      npc_d = predict_addr;
    end
    // 1. Default assignment
    if (if_ready) begin
      npc_d = fetch_address + 32'h4;
    end
    // 2. Replay instruction fetch
    if (replay) begin
      npc_d = replay_addr;
    end
    // 3. Control flow change request
    if (bju.valid & bju.is_mispredict) begin
      npc_d = bju.target_address;
    end
    // 4. Return from environment call
    if (mret_valid) begin
      npc_d = mepc_addr;
    end
    // 5. Exception/Interrupt
    if (ex_valid) begin
      npc_d = mtvec_addr;
    end

    fetch_addr = fetch_address;
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      first_fetch    <= 1'b1;
      npc_q          <= '0;
      icache_data_q  <= '0;
      icache_valid_q <= 1'b0;
      icache_addr_q  <= 'b0;
    end else begin
      first_fetch    <= 1'b0;
      npc_q          <= npc_d;
      icache_valid_q <= icu2ifu_valid;
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
  inst_queue INST_QUEUE (
      .*,
      .instr_i       (instr),              // from re-aligner
      .addr_i        (addr),               // from re-aligner
      .predict_addr  (predict_addr),
      .cf_type_i     (cf_type),
      .ready_o       (instr_queue_ready),
      .replay        (replay),
      .replay_addr   (replay_addr)
  );

endmodule
