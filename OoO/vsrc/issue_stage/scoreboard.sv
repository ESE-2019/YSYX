module scoreboard
  import OoO_pkg::*;
(
    input  logic                                                  clock,
    input  logic                                                  reset,
    output decoder_t                                              issue_instr,
    output decoder_t                                              commit_instr,
    input  logic                                                  commit_valid,
    input  decoder_t                                              idu2isu_instr,
    input  logic                                                  idu2isu_valid,
    output logic                                                  isu2idu_ready,
    output logic                                                  issue_valid,
    input  logic                                                  issue_ready,
    output forwarding_t                                           fwd,
    input  logic        [WriteBackPorts-1:0][ScoreboardIndex-1:0] wb_idx,
    input  logic        [WriteBackPorts-1:0][               31:0] wb_data,
    input  logic        [WriteBackPorts-1:0]                      wb_valid
);

  typedef struct packed {
    logic issued;
    decoder_t instr;
  } scoreboard_t;
  scoreboard_t [ScoreboardDepth-1:0] mem_q, mem_n;

  logic issue_ready;
  logic [ScoreboardIndex-1:0] issue_pointer_n, issue_pointer_q;
  logic [ScoreboardIndex-1:0] commit_pointer_n, commit_pointer_q;


  logic [ScoreboardIndex:0] sb_cnt;
  always_comb begin
    automatic logic tmp = '0;
    for (int unsigned i = 0; i < ScoreboardDepth; i++) begin
      tmp += mem_q[i].issued;
    end
    sb_cnt = tmp;
  end
  wire issue_full = sb_cnt >= ScoreboardDepth;

  assign commit_instr = mem_q[commit_pointer_q[i]].instr;

  always_comb begin
    issue_instr = idu2isu_instr;
    issue_instr.trans_id = issue_pointer_q;
    issue_valid = idu2isu_valid & ~issue_full;
    isu2idu_ready = issue_ready & ~issue_full;
  end

  always_comb begin
    mem_n       = mem_q;
    issue_ready = 1'b0;

    if (idu2isu_valid && isu2idu_ready) begin
      issue_ready = 1'b1;
      mem_n[issue_pointer_q] = '{issued: 1'b1, instr: idu2isu_instr};
    end

    // ------------
    // Write Back
    // ------------
    for (int unsigned i = 0; i < WriteBackPorts; i++) begin
      // check if this instruction was issued (e.g.: it could happen after a flush that there is still
      // something in the pipeline e.g. an incomplete memory operation)
      if (wb_valid[i] && mem_q[wb_idx[i]].issued) begin
        mem_n[wb_idx[i]].instr.valid  = 1'b1;
        mem_n[wb_idx[i]].instr.result = wb_data[i];
      end
    end

    // ------------
    // Commit Port
    // ------------
    if (commit_valid) begin
      // this instruction is no longer in issue e.g.: it is considered finished
      mem_n[commit_pointer_q].issued    = 1'b0;
      mem_n[commit_pointer_q].instr.valid = 1'b0;
    end

  end

  // FIFO counter updates
  assign commit_pointer_n = commit_pointer_q + commit_valid;
  assign issue_pointer_n  = issue_pointer_q + issue_ready;

  // Forwarding logic
  writeback_t [WriteBackPorts-1:0] wb;
  for (genvar i = 0; i < WriteBackPorts; i++) begin : gen_wb
    assign wb[i].valid = wb_valid[i];
    assign wb[i].data = wb_data[i];
    assign wb[i].trans_id = wb_idx[i];
  end

  logic [ScoreboardDepth-1:0] issued;
  for (genvar i = 0; i < ScoreboardDepth; i++) begin : gen_issued
    assign still_issued[i] = mem_q[i].issued;
  end

  assign fwd.issued = issued;
  assign fwd.wb = wb;
  for (genvar i = 0; i < ScoreboardDepth; i++) begin : gen_fwd
    assign fwd.instr[i] = mem_q[i].instr;
  end

  // sequential process
  always_ff @(posedge clock) begin
    if (reset) begin
      mem_q            <= '{default: sb_mem_t'(0)};
      commit_pointer_q <= '0;
      issue_pointer_q  <= '0;
    end else begin
      issue_pointer_q <= issue_pointer_n;
      mem_q <= mem_n;
      commit_pointer_q <= commit_pointer_n;
    end
  end

endmodule
