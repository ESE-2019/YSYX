module ysyx_24080006_ifu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic fencei,
    output logic [31:0] inst,

    input  logic   idu2ifu_ready,
    output logic   ifu2exu_ready,
    input  stage_t exu2ifu,
    output stage_t ifu2idu,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [2:0] {
    RESET,
    IDLE,
    EXEC,
    HAZARD,
    WAIT
  } if_fsm_e;
  if_fsm_e curr, next;

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  logic fetch_twice_d, fetch_twice_q;
  assign ifu2icu_ready = 1'b1;

  logic detect_hazard_q, detect_hazard_d;
  logic [31:0] ic_val;
  logic is_zc_d, is_zc_q;
  logic zc_err, inst_err;
  logic [31:0] pc_d, pc_q;
  logic [31:0] fetch_addr_d, fetch_addr_q;
  logic [15:0] inst_buf;
  logic [31:0] inst_d, inst_q;
  assign inst = inst_q;
  wire branch_or_jump = exu2ifu.jump || exu2ifu.branch;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= RESET;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    next = IDLE;
    unique case (curr)
      RESET: next = EXEC;
      IDLE: begin
        next = EXEC;
      end
      EXEC: begin
        if (icu2ifu_valid && !fetch_twice_q) begin
          next = WAIT;
        end else begin
          next = curr;
        end
      end
      WAIT: begin
        if (idu2ifu_ready) begin
          if (detect_hazard_q) begin
            next = HAZARD;
          end else begin
            next = IDLE;
          end
        end else begin
          next = curr;
        end
      end
      HAZARD: begin
        if (exu2ifu.valid && exu2ifu.flush) begin
          next = EXEC;
        end else begin
          next = curr;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      ifu2exu_ready <= 1'b1;
      ifu2idu.valid <= 1'b0;
    end else begin
      unique case (curr)
        RESET: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
        IDLE: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
        EXEC: begin
          if (icu2ifu_valid && !fetch_twice_q) begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b1;
          end else begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end
        end
        WAIT: begin
          if (idu2ifu_ready) begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end else begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b1;
          end
        end
        HAZARD: begin
          ifu2exu_ready <= 1'b1;
          ifu2idu.valid <= 1'b0;
        end
      endcase
    end
  end

  always_comb begin
    if (fetch_twice_q) begin
      pc_d = pc_q;
      fetch_addr_d = fetch_addr_q + 32'h4;
      fetch_twice_d = 0;
    end else begin
      fetch_twice_d = 0;
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
      endcase
    end
  end


  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      ifu2icu_valid <= 1'b0;
      pc_q <= RST_ADDR;
      fetch_addr_q <= RST_ADDR;
      ifu2idu.pc <= RST_ADDR;
      inst_q <= 32'b0;
      is_zc_q <= 1'b0;
      fetch_twice_q <= 1'b0;
      inst_buf <= 16'b0;
      detect_hazard_q <= 1'b0;
    end else begin
      unique case (curr)
        RESET: begin
          ifu2icu_valid <= 1'b1;
        end
        IDLE: begin
          pc_q <= pc_d;
          fetch_addr_q <= fetch_addr_d;
          ifu2icu_valid <= 1'b1;
          fetch_twice_q <= fetch_twice_d;
        end
        EXEC: begin
          if (ifu2icu_valid & icu2ifu_ready) begin
            ifu2icu_valid <= 1'b0;
          end
          if (icu2ifu_valid) begin
            inst_buf <= ic_val[31:16];
            if (fetch_twice_q) begin
              ifu2icu_valid <= 1'b1;
              fetch_addr_q  <= fetch_addr_d;
              fetch_twice_q <= fetch_twice_d;
            end else begin
              is_zc_q <= is_zc_d;
              ifu2idu.pc <= pc_q;
              inst_q <= inst_d;
              detect_hazard_q <= detect_hazard_d;
              ifu2idu.is_zc <= is_zc_d;
              ifu2idu.flush <= detect_hazard_d;
            end
          end
        end
        WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
        HAZARD: begin
          if (exu2ifu.valid && exu2ifu.flush) begin
            if (branch_or_jump) begin
              pc_q <= exu2ifu.dnpc;
              fetch_addr_q <= {exu2ifu.dnpc[31:2], 2'b00};
              ifu2icu_valid <= 1'b1;
              fetch_twice_q <= exu2ifu.dnpc[1];
              //if(exu2ifu.dnpc[1]) $display("unsuggested misaligned jump taken at pc 0x%08x", pc_q);// most of these occur when ret
            end else begin
              pc_q <= pc_d;
              fetch_addr_q <= fetch_addr_d;
              ifu2icu_valid <= 1'b1;
              fetch_twice_q <= fetch_twice_d;
            end
          end
        end
      endcase
    end
  end  // fsm 3 for axi

  assign detect_hazard_d = inst_d[6:0] inside {JAL, JALR, SYSTEM, BRANCH, MISC_MEM};
  wire [31:0] zc_val = pc_q[1] ? {ic_val[15:0], inst_buf} : ic_val;
  ysyx_24080006_icu16 ICU (
      .*,
      .fetch_addr(fetch_addr_q)
  );
  ysyx_24080006_zcu ZCU (
      .*,
      .is_zc(is_zc_d),
      .inst (inst_d)
  );


`ifdef SIM_MODE
  import "DPI-C" function void dbg(
    input int inst,
    input int pc,
    input int ft_pc,
    input int type_cnt,
    input int ifu_cnt
  );
  function automatic logic INSIDE(input logic [31:0] addr, left, right);
    INSIDE = addr >= left && addr <= right;
  endfunction
  function automatic logic INSIDE_MEM(input logic [31:0] addr);
    INSIDE_MEM = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) ||  // FLASH
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff) ||  // NPC SRAM
        INSIDE(addr, 32'ha000_0000, 32'ha3ff_ffff);  // SDRAM
  endfunction
  logic [31:0] ftrace, type_cnt, ifu_cnt;
  always_ff @(posedge clock) begin
    if (reset) begin
      ftrace   <= RST_ADDR;
      type_cnt <= 1;
      ifu_cnt  <= 1;
    end else begin
      case (curr)
        HAZARD, IDLE: begin
          type_cnt <= type_cnt + 1;
          ifu_cnt  <= 1;
        end
        RESET, EXEC, WAIT: begin
          ifu_cnt <= ifu_cnt + 1;
          if (ifu2idu.valid && idu2ifu_ready) begin
            // if(zc_err) begin
            //   $display("[Zc] inst error 0x%08x at pc 0x%08x", zc_val, pc_q);
            //   $finish;
            // end
            dbg(inst, pc_q, (exu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
            type_cnt <= 1;
            if (branch_or_jump) ftrace <= exu2ifu.dnpc;
            else ftrace <= ftrace + 32'h4;
          end else type_cnt <= type_cnt + 1;
        end
        default: ;
      endcase
    end
  end
  always_ff @(posedge clock) begin
    if (ifu2idu.valid && idu2ifu_ready) begin
      if (!INSIDE_MEM(pc_q)) begin
        $display("[IFU]pc error 0x%08x", pc_q);
        $finish;
      end
    end
  end
`endif
endmodule
