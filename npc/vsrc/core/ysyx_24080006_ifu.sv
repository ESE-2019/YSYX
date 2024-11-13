module ysyx_24080006_ifu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output decoder_t decoder,

    input  logic   exu2ifu_ready,
    output logic   ifu2exu_ready,
    input  stage_t exu2ifu,
    output stage_t ifu2exu,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [1:0] {
    IDLE,
    EXEC,
    WAIT
  } if_fsm_e;
  if_fsm_e curr, next;

  logic [31:0] pc, inst;
  decoder_t idu;
  logic inst_err;

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  assign ifu2icu_ready = 1;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    next = IDLE;
    unique case (curr)
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
        if (exu2ifu_ready) begin
          next = IDLE;
        end else begin
          next = WAIT;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      ifu2exu_ready <= 1;
      ifu2exu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (exu2ifu.valid) begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 0;
          end else begin
            ifu2exu_ready <= 1;
            ifu2exu.valid <= 0;
          end
        end
        EXEC: begin
          if (icu2ifu_valid) begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 1;
          end else begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 0;
          end
        end
        WAIT: begin
          if (exu2ifu_ready) begin
            ifu2exu_ready <= 1;
            ifu2exu.valid <= 0;
          end else begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 1;
          end
        end
      endcase
    end
  end  // fsm 3 for handshake

  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      ifu2icu_valid <= 1'b0;
      pc <= RST_ADDR;
      ifu2exu.pc <= RST_ADDR;
      decoder <= idu;
    end else begin
      unique case (curr)
        IDLE: begin
          if (exu2ifu.valid) begin
            if (exu2ifu.jump || exu2ifu.branch) begin
              pc <= exu2ifu.dnpc;
            end else begin
              pc <= pc + 32'h4;
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
            ifu2exu.pc <= pc;
            decoder <= idu;
          end
        end
        WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
      endcase
    end
  end  // fsm 3 for axi

  ysyx_24080006_icu ICU (.*);
  ysyx_24080006_idu IDU (.*);


`ifdef SIM_MODE
  import "DPI-C" function void ebreak();
  import "DPI-C" function void INST_CNT(input int type_code);
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
    if (ifu2exu.valid) begin
      if (!INSIDE_MEM(pc)) begin
        $display("[IFU]pc error 0x%08x", pc);
        $finish;
      end else if (inst == EBREAK_INST) begin
        ebreak();
      end else if (inst_err) begin
        $display("[IDU] inst error 0x%08x at pc 0x%08x", inst, pc);
        $finish;
      end
      case (inst[6:0])
        AUIPC, LUI, OP, OP_IMM: INST_CNT(0);
        LOAD, STORE: INST_CNT(1);
        SYSTEM: INST_CNT(2);
        BRANCH: INST_CNT(3);
        JAL, JALR: INST_CNT(4);
        default: ;
      endcase
    end
  end
`endif
endmodule
