module issue
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    //input logic flush_i,
    input decoder_t issue_instr,
    input logic issue_valid,
    output logic issue_ready,
    input forwarding_t fwd,

    // to ex_stage
    output fu_data_t fu_data,
    output logic [31:0] pc,
    output logic is_rv16,
    input logic flu_ready,
    output logic alu_valid,
    output logic bu_valid,
    output logic mdu_valid,
    output logic csr_valid,
    //output branchpredict_sbe_t branch_predict_o,
    input logic lsu_ready,
    output logic lsu_valid,

    input logic [4:0] gpr_waddr,
    input logic [31:0] gpr_wdata,
    input logic gpr_we
);

  logic stall_raw, stall_waw, stall_rs1, stall_rs2;
  logic fu_busy;
  // output flipflop (ID <-> EX)
  fu_data_t fu_data_n, fu_data_q;

  logic alu_valid_n, alu_valid_q;
  logic mult_valid_n, mult_valid_q;
  logic lsu_valid_n, lsu_valid_q;
  logic csr_valid_n, csr_valid_q;
  logic branch_valid_n, branch_valid_q;

  //fwd logic
  logic        rs1_has_raw;
  logic        rs2_has_raw;

  logic        rs1_valid;
  logic        rs2_valid;

  logic [31:0] rs1_res;
  logic [31:0] rs2_res;

  // clobber
  fu_e  [31:0] rd_clobber_gpr;

  //forward logic
  logic [ScoreboardDepth+WriteBackPorts-1:0] rs1_fwd_req, rs2_fwd_req;
  logic [ScoreboardDepth+WriteBackPorts-1:0][31:0] rs_data;

  // forwarding signals
  logic forward_rs1, forward_rs2;
  assign fu_data = fu_data_q;
  assign alu_valid = alu_valid_q;
  assign bu_valid = branch_valid_q;
  assign lsu_valid = lsu_valid_q;
  assign csr_valid = csr_valid_q;
  assign mdu_valid = mult_valid_q;
  wire stall_issue_o = stall_raw;

  logic [31:0] gpr_rdata_1, gpr_rdata_2;
  // ---------------
  // Issue Stage
  // ---------------
  typedef struct packed {logic none, load, store, alu, ctrl_flow, mult, csr;} fus_busy_t;
  always_comb begin
    automatic fus_busy_t fus_busy = '0;

    if (!flu_ready) begin
      fus_busy.alu = 1'b1;
      fus_busy.ctrl_flow = 1'b1;
      fus_busy.csr = 1'b1;
      fus_busy.mult = 1'b1;
    end

    if (|mult_valid_q) begin
      fus_busy.alu = 1'b1;
      fus_busy.ctrl_flow = 1'b1;
      fus_busy.csr = 1'b1;
    end

    if (!lsu_ready) begin
      fus_busy.load  = 1'b1;
      fus_busy.store = 1'b1;
    end

    unique case (issue_instr.fu)
      FU_NONE:  fu_busy = fus_busy.none;
      FU_ALU:   fu_busy = fus_busy.alu;
      FU_BU:    fu_busy = fus_busy.ctrl_flow;
      FU_CSR:   fu_busy = fus_busy.csr;
      FU_MDU:   fu_busy = fus_busy.mult;
      FU_LOAD:  fu_busy = fus_busy.load;
      FU_STORE: fu_busy = fus_busy.store;
      default:  fu_busy = 1'b0;
    endcase
  end

  // -------------------
  // RD clobber process
  // -------------------
  // rd_clobber output: output currently clobbered destination registers

  // logic [             31:0][ScoreboardDepth:0] gpr_clobber_vld;
  // fu_t  [ScoreboardDepth:0]                    clobber_fu;
  // always_comb begin
  //   gpr_clobber_vld = '0;

  //   // default (highest entry hast lowest prio in arbiter tree below)
  //   clobber_fu[ScoreboardDepth] = FU_NONE;
  //   for (int unsigned i = 0; i < 32; i++) begin
  //     gpr_clobber_vld[i][ScoreboardDepth] = 1'b1;
  //   end

  //   // check for all valid entries and set the clobber accordingly

  //   for (int unsigned i = 0; i < ScoreboardDepth; i++) begin
  //     gpr_clobber_vld[fwd.instr[i].rd][i] = fwd.issued[i];
  //     clobber_fu[i] = fwd.instr[i].fu;
  //   end

  //   // GPR[0] is always free
  //   gpr_clobber_vld[0] = '0;
  // end

  // for (genvar i = 0; i < 32; i++) begin : gen_sel_clobbers
  //   // get fu that is going to clobber this register (there should be only one)
  //   rr_arb_tree #(
  //       .NumIn(ScoreboardDepth + 1),
  //       .DataType(fu_t),
  //       .ExtPrio(1'b1),
  //       .AxiVldRdy(1'b1)
  //   ) i_sel_gpr_clobbers (
  //       .clock  (clock),
  //       .reset (reset),
  //       .flush_i(1'b0),
  //       .rr_i   ('0),
  //       .req_i  (gpr_clobber_vld[i]),
  //       .gnt_o  (),
  //       .data_i (clobber_fu),
  //       .gnt_i  (1'b1),
  //       .req_o  (),
  //       .data_o (rd_clobber_gpr[i]),
  //       .idx_o  ()
  //   );
  // end

  always_comb begin
    for (int unsigned i = 0; i < 32; i++) begin
      rd_clobber_gpr[i] = FU_NONE;
    end

    for (int unsigned i = 0; i < ScoreboardDepth; i++) begin
      if (fwd.issued[i]) begin
        rd_clobber_gpr[fwd.instr[i].rd] = fwd.instr[i].fu;
      end
    end

    // GPR[0] is always free
    rd_clobber_gpr[0] = FU_NONE;
  end

  assign rs1_has_raw = rd_clobber_gpr[issue_instr.rs1] != FU_NONE;
  assign rs2_has_raw = rd_clobber_gpr[issue_instr.rs2] != FU_NONE;

  // ----------------------------------
  // Read Operands (a.k.a forwarding)
  // ----------------------------------
  // read operand interface: same logic as register file

  // WB ports have higher prio than entries
  for (genvar i = 0; i < WriteBackPorts; i++) begin : gen_rs_wb

    assign rs1_fwd_req[i] = (fwd.instr[fwd.wb[i].idx].rd == issue_instr.rs1) & (fwd.issued[fwd.wb[i].idx]) & fwd.wb[i].valid;

    assign rs2_fwd_req[i] = (fwd.instr[fwd.wb[i].idx].rd == issue_instr.rs2) & (fwd.issued[fwd.wb[i].idx]) & fwd.wb[i].valid;

    assign rs_data[i] = fwd.wb[i].data;
  end

  for (genvar i = 0; i < ScoreboardDepth; i++) begin : gen_rs_entries

    assign rs1_fwd_req[i+WriteBackPorts] = (fwd.instr[i].rd == issue_instr.rs1) & fwd.issued[i] & fwd.instr[i].valid;

    assign rs2_fwd_req[i+WriteBackPorts] = (fwd.instr[i].rd == issue_instr.rs2) & fwd.issued[i] & fwd.instr[i].valid;

    assign rs_data[i+WriteBackPorts] = fwd.instr[i].result;
  end

  // use fixed prio here
  // this implicitly gives higher prio to WB ports
  rr_arb_tree #(
      .NumIn(ScoreboardDepth + WriteBackPorts),
      .DataWidth(32),
      .ExtPrio(1'b1),
      .AxiVldRdy(1'b1)
  ) i_sel_rs1 (
      .clk_i  (clock),
      .rst_ni (~reset),
      .flush_i(1'b0),
      .rr_i   ('0),
      .req_i  (rs1_fwd_req),
      .gnt_o  (),
      .data_i (rs_data),
      .gnt_i  (1'b1),
      .req_o  (rs1_valid),
      .data_o (rs1_res),
      .idx_o  ()
  );

  rr_arb_tree #(
      .NumIn(ScoreboardDepth + WriteBackPorts),
      .DataWidth(32),
      .ExtPrio(1'b1),
      .AxiVldRdy(1'b1)
  ) i_sel_rs2 (
      .clk_i  (clock),
      .rst_ni (~reset),
      .flush_i(1'b0),
      .rr_i   ('0),
      .req_i  (rs2_fwd_req),
      .gnt_o  (),
      .data_i (rs_data),
      .gnt_i  (1'b1),
      .req_o  (rs2_valid),
      .data_o (rs2_res),
      .idx_o  ()
  );

  // ---------------
  // Register stage
  // ---------------
  // check that all operands are available, otherwise stall
  // forward corresponding register
  always_comb begin : operands_available
    stall_raw   = '0;
    stall_rs1   = '0;
    stall_rs2   = '0;
    // operand forwarding signals
    forward_rs1 = '0;
    forward_rs2 = '0;

    if (rs1_has_raw) begin
      if (rs1_valid) begin
        forward_rs1 = 1'b1;
      end else begin  // the operand is not available -> stall
        stall_raw = 1'b1;
        stall_rs1 = 1'b1;
      end
    end

    if (rs2_has_raw) begin
      if (rs2_valid) begin
        forward_rs2 = 1'b1;
      end else begin  // the operand is not available -> stall
        stall_raw = 1'b1;
        stall_rs2 = 1'b1;
      end
    end

  end

  // Forwarding/Output MUX
  always_comb begin
    fu_data_n.operand_a = gpr_rdata_1;
    fu_data_n.operand_b = gpr_rdata_2;

    fu_data_n.imm = issue_instr.result;
    fu_data_n.idx = issue_instr.idx;
    fu_data_n.fu = issue_instr.fu;
    fu_data_n.operation = issue_instr.op;

    // or should we forward
    if (forward_rs1) begin
      fu_data_n.operand_a = rs1_res;
    end
    if (forward_rs2) begin
      fu_data_n.operand_b = rs2_res;
    end

    // use the PC as operand a
    if (issue_instr.use_pc) begin
      fu_data_n.operand_a = issue_instr.pc;
    end

    // use the zimm as operand a
    if (issue_instr.use_zimm) begin
      // zero extend operand a
      fu_data_n.operand_a = {27'b0, issue_instr.rs1[4:0]};
    end
    // or is it an immediate (including PC), this is not the case for a store, control flow, and accelerator instructions
    if (issue_instr.use_imm && (issue_instr.fu != FU_STORE) && (issue_instr.fu != FU_BU)) begin
      fu_data_n.operand_b = issue_instr.result;
    end
  end

  always_comb begin
    alu_valid_n    = '0;
    lsu_valid_n    = '0;
    mult_valid_n   = '0;
    csr_valid_n    = '0;
    branch_valid_n = '0;
    if (issue_valid && issue_ready) begin
      case (issue_instr.fu)
        FU_ALU: begin
          alu_valid_n = 1'b1;
        end
        FU_BU: begin
          branch_valid_n = 1'b1;
        end
        FU_MDU: begin
          mult_valid_n = 1'b1;
        end
        FU_LOAD, FU_STORE: begin
          lsu_valid_n = 1'b1;
        end
        FU_CSR: begin
          csr_valid_n = 1'b1;
        end
        default: ;
      endcase
    end
    // if we got a flush request, de-assert the valid flag, otherwise we will start this
    // functional unit with the wrong inputs
    // if (flush_i) begin
    //   alu_valid_n    = '0;
    //   lsu_valid_n    = '0;
    //   mult_valid_n   = '0;
    //   alu2_valid_n   = '0;
    //   csr_valid_n    = '0;
    //   branch_valid_n = '0;
    // end
  end
  // FU select, assert the correct valid out signal (in the next cycle)
  // This needs to be like this to make verilator happy. I know its ugly.
  always_ff @(posedge clock) begin
    if (reset) begin
      alu_valid_q    <= '0;
      lsu_valid_q    <= '0;
      mult_valid_q   <= '0;
      csr_valid_q    <= '0;
      branch_valid_q <= '0;
    end else begin
      alu_valid_q    <= alu_valid_n;
      lsu_valid_q    <= lsu_valid_n;
      mult_valid_q   <= mult_valid_n;
      csr_valid_q    <= csr_valid_n;
      branch_valid_q <= branch_valid_n;
    end
  end

  always_comb begin
    stall_waw = '1;
    if (issue_valid && !fu_busy) begin
      // -----------------------------------------
      // WAW - Write After Write Dependency Check
      // -----------------------------------------
      // no other instruction has the same destination register -> issue the instruction
      if (rd_clobber_gpr[issue_instr.rd] == FU_NONE) begin
        stall_waw = 1'b0;
      end
      // or check that the target destination register will be written in this cycle by the
      // commit stage
      if (gpr_we && gpr_waddr == issue_instr.rd) begin
        stall_waw = 1'b0;
      end
    end
  end


  // We can issue an instruction if we do not detect that any other instruction is writing the same
  // destination register.
  // We also need to check if there is an unresolved branch in the scoreboard.
  always_comb begin
    issue_ready = 1'b0;
    // check that the instruction we got is valid
    // and that the functional unit we need is not busy
    if (issue_valid && !fu_busy) begin
      if (!stall_raw && !stall_waw) begin
        issue_ready = 1'b1;
      end
      // if (issue_instr.ex.valid) begin
      //   issue_ready = 1'b1;
      // end
    end
  end


  gpr_regfile GPR_REGFILE (
      .clock,
      .reset,
      .gpr_raddr_1(issue_instr.rs1[RegWidth-1:0]),
      .gpr_raddr_2(issue_instr.rs2[RegWidth-1:0]),
      .gpr_waddr  (gpr_waddr[RegWidth-1:0]),
      .gpr_rdata_1(gpr_rdata_1),
      .gpr_rdata_2(gpr_rdata_2),
      .gpr_wdata  (gpr_wdata),
      .gpr_we     (gpr_we)
  );


  // ----------------------
  // Registers (ID <-> EX)
  // ----------------------


  always_ff @(posedge clock) begin
    if (reset) begin
      fu_data_q        <= '0;
      pc               <= '0;
      is_rv16          <= 1'b0;
      //branch_predict_o <= {cf_t'(0), {CVA6Cfg.VLEN{1'b0}}};
    end else begin
      fu_data_q <= fu_data_n;
      if (issue_instr.fu == FU_BU) begin
        pc               <= issue_instr.pc;
        is_rv16          <= issue_instr.is_rv16;
        //branch_predict_o <= issue_instr.bp;
      end
    end
  end

endmodule
