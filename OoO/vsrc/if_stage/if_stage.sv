`default_nettype none

module if_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic        fencei,
    output logic [31:0] inst,
    output logic [31:0] id_pc,
    input  logic [31:0] ifu_dbg_inst,

    input  logic idu2ifu_ready,
    output logic ifu2idu_valid,

    input logic retire_valid,
    input logic retire_cf,
    input logic retire_jump,
    input logic retire_branch,
    input logic retire_is_rv16,
    input logic [31:0] retire_pc,
    input logic [31:0] retire_dnpc,

    output logic icache_hit,
    output logic icache_miss,
    output logic icache_skip,
    output logic is_compressed,
    output logic fetch_cycle,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m
);

  typedef enum logic [2:0] {
    IF_RESET,
    IF_IDLE,
    IF_EXEC,
    IF_HAZARD,
    IF_WAIT
  } if_fsm_e;
  if_fsm_e curr, next;

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  logic fetch_twice, fetch_twice_terminated;
  assign ifu2icu_ready = 1'b1;

  logic detect_hazard_q, detect_hazard_d;
  logic [31:0] ic_val;
  logic rv16_d, rv16_q;
  logic rv16_err;
  logic [31:0] pc_d, pc_q;
  logic [31:0] fetch_addr_d, fetch_addr_q;
  logic [15:0] inst_buf;
  logic [31:0] inst_d, inst_q, pre_dec_inst;
  assign inst = inst_q;
  wire branch_or_jump = retire_jump || retire_branch;
  assign detect_hazard_d = pre_dec_inst[6:0] inside {riscv_instr::JAL[6:0], riscv_instr::JALR[6:0],
    riscv_instr::ECALL[6:0], riscv_instr::BEQ[6:0], riscv_instr::FENCE[6:0]};

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IF_RESET;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IF_RESET: next = IF_EXEC;
      IF_IDLE: begin
        next = IF_EXEC;
      end
      IF_EXEC: begin
        if (icu2ifu_valid && (!fetch_twice | rv16_d)) begin
          next = IF_WAIT;
        end else begin
          next = curr;
        end
      end
      IF_WAIT: begin
        if (idu2ifu_ready) begin
          if (detect_hazard_q) begin
            next = IF_HAZARD;
          end else begin
            next = IF_IDLE;
          end
        end else begin
          next = curr;
        end
      end
      IF_HAZARD: begin
        if (retire_valid & retire_cf) begin
          next = IF_EXEC;
        end else begin
          next = curr;
        end
      end
      default:  next = IF_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      ifu2idu_valid <= 1'b0;
    end else begin
      unique case (curr)
        IF_RESET: begin
          ifu2idu_valid <= 1'b0;
        end
        IF_IDLE: begin
          ifu2idu_valid <= 1'b0;
        end
        IF_EXEC: begin
          if (icu2ifu_valid && (!fetch_twice | rv16_d)) begin
            ifu2idu_valid <= 1'b1;
          end else begin
            ifu2idu_valid <= 1'b0;
          end
        end
        IF_WAIT: begin
          if (idu2ifu_ready) begin
            ifu2idu_valid <= 1'b0;
          end else begin
            ifu2idu_valid <= 1'b1;
          end
        end
        IF_HAZARD: begin
          ifu2idu_valid <= 1'b0;
        end
        default: begin
          ifu2idu_valid <= 1'b0;
        end
      endcase
    end
  end

  always_comb begin
    if (fetch_twice_terminated) begin
      pc_d = pc_q + 32'h2;
      fetch_addr_d = fetch_addr_q + 32'h4;
    end else if (fetch_twice) begin
      pc_d = pc_q;
      fetch_addr_d = fetch_addr_q + 32'h4;
    end else begin
      unique case ({
        pc_q[1], rv16_q
      })
        2'b00: begin
          pc_d = pc_q + 32'h4;
          fetch_addr_d = fetch_addr_q + 32'h4;
        end
        2'b01: begin
          pc_d = pc_q + 32'h2;
          fetch_addr_d = fetch_addr_q + 32'h4;
        end
        2'b10: begin
          pc_d = pc_q + 32'h4;
          fetch_addr_d = fetch_addr_q + 32'h4;
        end
        2'b11: begin
          pc_d = pc_q + 32'h2;
          fetch_addr_d = fetch_addr_q;
        end
        default: begin
          pc_d = pc_q;
          fetch_addr_d = fetch_addr_q;
        end
      endcase
    end
  end


  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      ifu2icu_valid <= 1'b0;
      pc_q <= RstAddr;
      fetch_addr_q <= RstAddr;
      id_pc <= RstAddr;
      inst_q <= 32'b0;
      rv16_q <= 1'b0;
      fetch_twice <= 1'b0;
      inst_buf <= 16'b0;
      detect_hazard_q <= 1'b0;
      fetch_twice_terminated <= 1'b0;
    end else begin
      unique case (curr)
        IF_RESET: begin
          ifu2icu_valid <= 1'b1;
        end
        IF_IDLE: begin
          pc_q <= pc_d;
          fetch_addr_q <= fetch_addr_d;
          ifu2icu_valid <= 1'b1;
          fetch_twice <= 1'b0;
          fetch_twice_terminated <= 1'b0;
        end
        IF_EXEC: begin
          if (ifu2icu_valid & icu2ifu_ready) begin
            ifu2icu_valid <= 1'b0;
          end else begin
            if (icu2ifu_valid) begin
              inst_buf <= ic_val[31:16];
              if (fetch_twice) begin
                if (rv16_d) begin  // fetch_twice_terminated
                  rv16_q <= rv16_d;
                  id_pc <= pc_q;
                  inst_q <= inst_d;
                  detect_hazard_q <= detect_hazard_d;
                  fetch_twice_terminated <= 1'b1;
                end else begin  // fetch_twice
                  ifu2icu_valid <= 1'b1;
                  fetch_addr_q <= fetch_addr_d;
                  fetch_twice <= 1'b0;
                  fetch_twice_terminated <= 1'b0;
                end
              end else begin  // common case
                rv16_q <= rv16_d;
                id_pc <= pc_q;
                inst_q <= inst_d;
                detect_hazard_q <= detect_hazard_d;
              end
            end
          end
        end
        IF_WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
        IF_HAZARD: begin
          if (retire_valid & retire_cf) begin
            if (branch_or_jump) begin
              pc_q <= retire_dnpc;
              fetch_addr_q <= {retire_dnpc[31:2], 2'b00};
              ifu2icu_valid <= 1'b1;
              fetch_twice <= retire_dnpc[1];
              fetch_twice_terminated <= 1'b0;
            end else begin
              pc_q <= pc_d;
              fetch_addr_q <= fetch_addr_d;
              ifu2icu_valid <= 1'b1;
              fetch_twice <= 1'b0;
              fetch_twice_terminated <= 1'b0;
            end
          end
        end
        default: ;
      endcase
    end
  end  // fsm 3 for axi

  always_comb begin
    if (fetch_twice) begin  // fetch_twice occurs in misaligned pc
      inst_d = {16'b0, ic_val[31:16]};
    end else begin
      inst_d = pc_q[1] ? {ic_val[15:0], inst_buf} : ic_val;
    end
    rv16_d = inst_d[1:0] != 2'b11;
  end

  wire [31:0] fetch_addr = fetch_addr_q;

  ideal_itcm ICU (.*);
  rv16_decoder PRE_DEC (
      .inst(inst_d),
      .instr(pre_dec_inst),
      .is_rv16(),
      .rv16_err()
  );

  assign is_compressed = rv16_d & ifu2idu_valid & idu2ifu_ready;
  assign fetch_cycle   = curr == IF_EXEC;

`ifdef SIM_MODE
  import ysyx_24080006_sim_pkg::*;
  import "DPI-C" function void dbg(
    input int inst,
    input int pc,
    input int ft_pc,
    input int ifu_cnt
  );
  import "DPI-C" function void INST_START();
  logic [31:0] ftrace, ifu_cnt;
  time inst_queue[$];

  always_ff @(posedge clock) begin
    if (reset) begin
      ftrace  <= RstAddr;
      ifu_cnt <= 1;
      inst_queue.delete();
    end else begin
      case (curr)
        IF_RESET, IF_IDLE, IF_HAZARD: begin
          if (next == IF_EXEC) begin
            inst_queue.push_front($time);
            ifu_cnt <= 1;
          end
        end
        IF_EXEC, IF_WAIT: begin
          ifu_cnt <= ifu_cnt + 1;
          if (ifu2idu_valid && idu2ifu_ready) begin
            dbg(inst, pc_q, (retire_jump ? ftrace : 0), ifu_cnt);
            if (branch_or_jump) ftrace <= retire_dnpc;
            else ftrace <= pc_d;
          end
        end
        default: ;
      endcase
    end
  end
  import "DPI-C" function void retirement(input int pc);
  import "DPI-C" function void ebreak();
  bit retire = 0;
  bit [31:0] difftest_pc;
  time op_c = 0, br_c = 0, ls_c = 0, sys_c = 0;
  int op_i = 0, br_i = 0, ls_i = 0, sys_i = 0;
  always_ff @(posedge clock) begin
    if (retire_valid) begin
      case (ifu_dbg_inst[6:0])
        riscv_instr::AUIPC[6:0], riscv_instr::LUI[6:0],
        riscv_instr::ADD[6:0], riscv_instr::ADDI[6:0]: begin
          op_c += ($time - inst_queue.pop_back) / 2;
          op_i++;
        end
        riscv_instr::LB[6:0], riscv_instr::SB[6:0]: begin
          ls_c += ($time - inst_queue.pop_back) / 2;
          ls_i++;
        end
        riscv_instr::ECALL[6:0], riscv_instr::FENCE[6:0]: begin
          sys_c += ($time - inst_queue.pop_back) / 2;
          sys_i++;
        end
        riscv_instr::BEQ[6:0], riscv_instr::JAL[6:0], riscv_instr::JALR[6:0]: begin
          br_c += ($time - inst_queue.pop_back) / 2;
          br_i++;
        end
        default: ;
      endcase
      //if (ifu_dbg_inst == riscv_instr::WFI || ifu_dbg_inst == riscv_instr::EBREAK) ebreak();
      retire <= 1'b1;
      if (branch_or_jump) difftest_pc <= retire_dnpc;
      else difftest_pc <= retire_pc + (retire_is_rv16 ? 32'h2 : 32'h4);
    end else retire <= 1'b0;
    if (retire) begin
      retirement(difftest_pc);
    end
  end
`endif
endmodule

`default_nettype wire
