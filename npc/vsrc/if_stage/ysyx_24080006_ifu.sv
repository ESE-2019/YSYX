module ysyx_24080006_ifu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic        fencei,
    output logic [31:0] inst,
    input  logic [31:0] exu_dbg_inst,

    input  logic   idu2ifu_ready,
    output logic   ifu2exu_ready,
    input  stage_t exu2ifu,
    output stage_t ifu2idu,

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
  logic [31:0] ic_val, zc_val;
  logic is_zc_d, is_zc_q;
  logic zc_err;
  logic [31:0] pc_d, pc_q;
  logic [31:0] fetch_addr_d, fetch_addr_q;
  logic [15:0] inst_buf;
  logic [31:0] inst_d, inst_q;
  assign inst = inst_q;
  wire branch_or_jump = exu2ifu.jump || exu2ifu.branch;
  wire [31:0] immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
  wire jal = 1'b0;
  assign detect_hazard_d = inst_d[6:0] inside {JAL, JALR, SYSTEM, BRANCH, MISC_MEM};
  // wire jal = inst[6:0] == JAL;
  // assign detect_hazard_d = inst_d[6:0] inside {JALR, SYSTEM, BRANCH, MISC_MEM};

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
        if (icu2ifu_valid && (!fetch_twice | is_zc_d)) begin
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
        if (exu2ifu.valid && exu2ifu.flush) begin
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
      ifu2exu_ready <= 1'b0;
      ifu2idu.valid <= 1'b0;
    end else begin
      unique case (curr)
        IF_RESET: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
        IF_IDLE: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
        IF_EXEC: begin
          if (icu2ifu_valid && (!fetch_twice | is_zc_d)) begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b1;
          end else begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end
        end
        IF_WAIT: begin
          if (idu2ifu_ready) begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end else begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b1;
          end
        end
        IF_HAZARD: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
        default: begin
          ifu2exu_ready <= 1'b0;
          ifu2idu.valid <= 1'b0;
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
    end else if (jal) begin
      pc_d = pc_q + immJ;
      fetch_addr_d = {pc_d[31:2], 2'b00};
    end else begin
      unique case ({
        pc_q[1], is_zc_q
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
      pc_q <= RST_ADDR;
      fetch_addr_q <= RST_ADDR;
      ifu2idu.pc <= RST_ADDR;
      ifu2idu.is_zc <= 1'b0;
      ifu2idu.flush <= 1'b0;
      inst_q <= 32'b0;
      is_zc_q <= 1'b0;
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
          fetch_twice <= jal & pc_d[1];
          fetch_twice_terminated <= 1'b0;
        end
        IF_EXEC: begin
          if (ifu2icu_valid & icu2ifu_ready) begin
            ifu2icu_valid <= 1'b0;
          end else begin
            if (icu2ifu_valid) begin
              inst_buf <= ic_val[31:16];
              if (fetch_twice) begin
                if (is_zc_d) begin  // fetch_twice_terminated
                  is_zc_q <= is_zc_d;
                  ifu2idu.pc <= pc_q;
                  inst_q <= inst_d;
                  detect_hazard_q <= detect_hazard_d;
                  ifu2idu.is_zc <= is_zc_d;
                  ifu2idu.zc_err <= zc_err;
                  ifu2idu.flush <= detect_hazard_d;
                  fetch_twice_terminated <= 1'b1;
                end else begin  // fetch_twice
                  ifu2icu_valid <= 1'b1;
                  fetch_addr_q <= fetch_addr_d;
                  fetch_twice <= 1'b0;
                  fetch_twice_terminated <= 1'b0;
                end
              end else begin  // common case
                is_zc_q <= is_zc_d;
                ifu2idu.pc <= pc_q;
                inst_q <= inst_d;
                detect_hazard_q <= detect_hazard_d;
                ifu2idu.is_zc <= is_zc_d;
                ifu2idu.zc_err <= zc_err;
                ifu2idu.flush <= detect_hazard_d;
              end
            end
          end
        end
        IF_WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
        IF_HAZARD: begin
          if (exu2ifu.valid && exu2ifu.flush) begin
            if (branch_or_jump) begin
              pc_q <= exu2ifu.dnpc;
              fetch_addr_q <= {exu2ifu.dnpc[31:2], 2'b00};
              ifu2icu_valid <= 1'b1;
              fetch_twice <= exu2ifu.dnpc[1];
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
      zc_val = {16'b0, ic_val[31:16]};
    end else begin
      zc_val = pc_q[1] ? {ic_val[15:0], inst_buf} : ic_val;
    end
  end

  wire [31:0] fetch_addr = fetch_addr_q;
  ysyx_24080006_icu ICU (.*);
  ysyx_24080006_zcu ZCU (
      .*,
      .is_zc(is_zc_d),
      .inst (inst_d)
  );

  assign is_compressed = ifu2idu.is_zc & ifu2idu.valid & idu2ifu_ready;
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
      ftrace  <= RST_ADDR;
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
          if (ifu2idu.valid && idu2ifu_ready) begin
            dbg(inst, pc_q, (exu2ifu.jump ? ftrace : 0), ifu_cnt);
            if (branch_or_jump) ftrace <= exu2ifu.dnpc;
            else ftrace <= pc_d;
          end
        end
        default: ;
      endcase
    end
  end
  import "DPI-C" function int sdram_read(
    int i,
    int j,
    int k
  );
  import "DPI-C" function int pmem_read(input int raddr);
  always_ff @(posedge clock) begin
    if (ifu2idu.valid && idu2ifu_ready) begin
      if (!INSIDE_MEM(pc_q)) begin
        $display("[IFU]pc error 0x%08x", pc_q);
        $finish;
      end
    end
    if (icu2ifu_valid) begin
      if (INSIDE(fetch_addr, 32'h3000_0000, 32'h30ff_ffff)) begin
        if (ic_val != pmem_read({8'h80, fetch_addr[23:0]})) begin
          $finish;
        end
      end else if (INSIDE(fetch_addr, 32'ha000_0000, 32'ha3ff_ffff)) begin
        if (ic_val != sdram_read(
                {30'b0, fetch_addr[12:11]}, {19'b0, fetch_addr[25:13]}, {23'b0, fetch_addr[10:2]}
            )) begin
          $finish;
        end
      end
    end
  end
  import "DPI-C" function void retirement(input int pc);
  import "DPI-C" function void ebreak();
  bit retire = 0;
  bit [31:0] retire_pc;
  time op_c = 0, br_c = 0, ls_c = 0, sys_c = 0;
  int op_i = 0, br_i = 0, ls_i = 0, sys_i = 0;
  always_ff @(posedge clock) begin
    if (exu2ifu.valid && ifu2exu_ready) begin
      case (exu_dbg_inst[6:0])
        AUIPC, LUI, OP, OP_IMM: begin
          op_c += ($time - inst_queue.pop_back) / 2;
          op_i++;
        end
        LOAD, STORE: begin
          ls_c += ($time - inst_queue.pop_back) / 2;
          ls_i++;
        end
        SYSTEM, MISC_MEM: begin
          sys_c += ($time - inst_queue.pop_back) / 2;
          sys_i++;
        end
        BRANCH, JAL, JALR: begin
          br_c += ($time - inst_queue.pop_back) / 2;
          br_i++;
        end
        default: ;
      endcase
      if (exu_dbg_inst == WFI_INST || exu_dbg_inst == EBREAK_INST) ebreak();
      retire <= 1'b1;
      if (branch_or_jump) retire_pc <= exu2ifu.dnpc;
      else retire_pc <= exu2ifu.pc + 32'h4;
    end else retire <= 1'b0;
    if (retire) begin
      retirement(retire_pc);
    end
  end
`endif
endmodule
