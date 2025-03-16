module scoreboard
  import OoO_pkg::*;
(
    input  logic                             clock,
    input  logic                             reset,
    output decoder_t                         issue_instr,
    output decoder_t                         commit_instr,
    input  logic                             commit_valid,
    input  decoder_t                         idu2isu_instr,
    input  logic                             idu2isu_valid,
    output logic                             isu2idu_ready,
    output logic                             issue_valid,
    input  logic                             issue_ready,
    output forwarding_t                      fwd,
    input  writeback_t  [WriteBackPorts-1:0] wb
);
  scoreboard_t [ScoreboardDepth-1:0] mem_q, mem_n;

  logic [ScoreboardIndex-1:0] num_issue;
  logic [ScoreboardIndex-1:0] issue_pointer_n, issue_pointer_q;
  logic [ScoreboardIndex-1:0] commit_pointer_n, commit_pointer_q;


  logic [ScoreboardIndex:0] sb_cnt;
  always_comb begin
    automatic logic [ScoreboardIndex:0] tmp = '0;
    for (int unsigned i = 0; i < ScoreboardDepth; i++) begin
      tmp += {{(ScoreboardIndex - 1) {1'b0}}, mem_q[i].issued};
    end
    sb_cnt = tmp;
  end
  wire issue_full = sb_cnt >= ScoreboardDepth[ScoreboardIndex:0];

  assign commit_instr = mem_q[commit_pointer_q].instr;

  always_comb begin
    issue_instr = idu2isu_instr;
    issue_instr.idx = issue_pointer_q;
    issue_valid = idu2isu_valid & ~issue_full;
    isu2idu_ready = issue_ready & ~issue_full;
  end

  always_comb begin
    mem_n     = mem_q;
    num_issue = '0;

    if (idu2isu_valid && isu2idu_ready) begin
      num_issue = 1;
      mem_n[issue_pointer_q] = '{issued: 1'b1, instr: idu2isu_instr};
    end

    // ------------
    // Write Back
    // ------------
    for (int unsigned i = 0; i < WriteBackPorts; i++) begin
      // check if this instruction was issued (e.g.: it could happen after a flush that there is still
      // something in the pipeline e.g. an incomplete memory operation)
      if (wb[i].valid && mem_q[wb[i].idx].issued) begin
        mem_n[wb[i].idx].instr.valid  = 1'b1;
        mem_n[wb[i].idx].instr.result = wb[i].data;
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
  assign issue_pointer_n  = issue_pointer_q + num_issue;

  // Forwarding logic
  logic [ScoreboardDepth-1:0] issued;
  for (genvar i = 0; i < ScoreboardDepth; i++) begin : gen_issued
    assign issued[i] = mem_q[i].issued;
  end

  assign fwd.issued = issued;
  assign fwd.wb = wb;
  for (genvar i = 0; i < ScoreboardDepth; i++) begin : gen_fwd
    assign fwd.instr[i] = mem_q[i].instr;
  end

  // sequential process
  always_ff @(posedge clock) begin
    if (reset) begin
      mem_q            <= '{default: scoreboard_t'(0)};
      commit_pointer_q <= '0;
      issue_pointer_q  <= '0;
    end else begin
      issue_pointer_q <= issue_pointer_n;
      mem_q <= mem_n;
      commit_pointer_q <= commit_pointer_n;
    end
  end

endmodule
