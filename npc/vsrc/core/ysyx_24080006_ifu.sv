module ysyx_24080006_ifu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic fencei,
    output logic is_zc,
    output logic [31:0] inst,

    input  logic   idu2ifu_ready,
    output logic   ifu2exu_ready,
    input  stage_t exu2ifu,
    output stage_t ifu2idu,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [1:0] {
    RESET,
    IDLE,
    EXEC,
    WAIT
  } if_fsm_e;
  if_fsm_e curr, next;

  logic [31:0] pc, fetch_addr, ic_val, zc_val;
  decoder_t idu;
  logic is_zc_d, zc_err, inst_err;

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  assign ifu2icu_ready = 1'b1;

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
        if (exu2ifu.valid) begin
          next = EXEC;
        end else begin
          next = IDLE;
        end
      end
      EXEC: begin
        if (icu2ifu_valid) begin
          next = WAIT;
        end else begin
          next = EXEC;
        end
      end
      WAIT: begin
        if (idu2ifu_ready) begin
          next = IDLE;
        end else begin
          next = WAIT;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      ifu2exu_ready <= 1'b0;
      ifu2idu.valid <= 1'b0;
    end else begin
      unique case (curr)
        RESET: begin
          ifu2exu_ready <= 1'b0;
          ifu2idu.valid <= 1'b0;
        end
        IDLE: begin
          if (exu2ifu.valid) begin
            ifu2exu_ready <= 1'b0;
            ifu2idu.valid <= 1'b0;
          end else begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end
        end
        EXEC: begin
          if (icu2ifu_valid) begin
            ifu2exu_ready <= 1'b0;
            ifu2idu.valid <= 1'b1;
          end else begin
            ifu2exu_ready <= 1'b0;
            ifu2idu.valid <= 1'b0;
          end
        end
        WAIT: begin
          if (idu2ifu_ready) begin
            ifu2exu_ready <= 1'b1;
            ifu2idu.valid <= 1'b0;
          end else begin
            ifu2exu_ready <= 1'b0;
            ifu2idu.valid <= 1'b1;
          end
        end
      endcase
    end
  end  // fsm 3 for handshake

  logic [31:0] pc_d, pc_q;
  logic [31:0] fetch_addr_d, fetch_addr_q;
  logic [15:0] inst_buf_d, inst_buf_q;
  // always_comb begin
  //   unique case ({
  //     pc[1], is_zc
  //   })
  //     2'b00: begin
  //       zc_val = ic_val;
  //       inst_buf_d = 16'h0;
  //       pc_incr_d = 32'h4;
  //       fetch_incr_d = 32'h4;
  //     end
  //     2'b10: begin
  //       zc_val = {ic_val[15:0], inst_buf_q};
  //       inst_buf_d = ic_val[31:16];
  //       pc_incr_d = 32'h4;
  //       fetch_incr_d = 32'h4;
  //     end
  //     2'b01: begin
  //       zc_val = ic_val;
  //       inst_buf_d = ic_val[31:16];
  //       pc_incr_d = 32'h2;
  //       fetch_incr_d = 32'h4;
  //     end
  //     2'b11: begin
  //       zc_val = {ic_val[15:0], inst_buf_q};
  //       inst_buf_d = 16'h0;
  //       pc_incr_d = 32'h2;
  //       fetch_incr_d = 32'h0;
  //     end
  //   endcase
  // end


  logic branch_or_jump;
  logic bj_unalign;
  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      ifu2icu_valid <= 1'b0;
      pc <= RST_ADDR;
      fetch_addr <= RST_ADDR;
      ifu2idu.pc <= RST_ADDR;
      inst <= 32'h0;
      is_zc <= 0;
      pc_incr_q <= 32'h4;
      fetch_incr_q <= 32'h4;
      inst_buf_q <= 16'h0;
      branch_or_jump <= 1'b0;
      bj_unalign <= 1'b0;
    end else begin
      unique case (curr)
        RESET: begin
          pc <= RST_ADDR;
          fetch_addr <= RST_ADDR;
          ifu2icu_valid <= 1'b1;
        end
        IDLE: begin
          inst_buf_q <= inst_buf_d;
          if (exu2ifu.valid) begin
            pc_incr_q <= pc_incr_d;
            fetch_incr_q <= fetch_incr_d;
            if (exu2ifu.jump || exu2ifu.branch) begin
              pc <= exu2ifu.dnpc;
              fetch_addr <= {exu2ifu.dnpc[31:2], 2'b00};
              bj_unalign <= exu2ifu.dnpc[1];
              branch_or_jump <= 1'b1;
            end else begin
              pc <= pc + pc_incr_d;
              fetch_addr <= fetch_addr + fetch_incr_d;
            end
            ifu2icu_valid <= 1'b1;
          end else begin
            ifu2icu_valid <= 1'b0;
          end
        end
        EXEC: begin
          if (ifu2icu_valid & icu2ifu_ready) begin
            ifu2icu_valid <= 1'b0;
          end
          if (icu2ifu_valid) begin
            is_zc <= is_zc_d;
            ifu2idu.pc <= pc;
            inst <= idu;
          end
        end
        WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
      endcase
    end
  end  // fsm 3 for axi


  ysyx_24080006_icu ICU (.*);
  ysyx_24080006_zcu ZCU (
      .*,
      .is_zc(is_zc_d)
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
      unique case (curr)
        IDLE: begin
          type_cnt <= type_cnt + 1;
          ifu_cnt  <= 1;
        end
        EXEC: begin
          ifu_cnt <= ifu_cnt + 1;
          if (icu2ifu_valid) begin
            dbg(inst, pc, (exu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
            type_cnt <= 1;
            if (exu2ifu.jump || exu2ifu.branch) ftrace <= exu2ifu.dnpc;
            else ftrace <= ftrace + 32'h4;
          end else type_cnt <= type_cnt + 1;
        end
        WAIT: type_cnt <= type_cnt + 1;
      endcase
    end
  end
  always_ff @(posedge clock) begin
    if (ifu2idu.valid) begin
      if (!INSIDE_MEM(pc)) begin
        $display("[IFU]pc error 0x%08x", pc);
        $finish;
      end
    end
  end
`endif
endmodule
