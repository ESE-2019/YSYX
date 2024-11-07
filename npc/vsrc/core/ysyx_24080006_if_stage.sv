module ysyx_24080006_if_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic    [IC_N-1:0] ic_index,
    input  icache_t            ic_rdata,
    output logic               ic_we,
    output icache_t            ic_wdata,

    output decoder_t decoder,

    input  logic   exu2ifu_ready,
    output logic   ifu2exu_ready,
    input  stage_t exu2ifu,
    output stage_t ifu2exu,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [1:0] {
    IDLE,
    CHECK,
    EXEC,
    WAIT
  } if_fsm_e;
  if_fsm_e curr, next;

  logic [31:0] pc, inst;
  decoder_t idu;
  logic inst_err;

  assign ic_index = pc[IC_M+IC_N-1:IC_M];
  wire [31-IC_M-IC_N:0] tag = pc[31:IC_M+IC_N];
  wire skip_icache = pc < 32'h1000_0000;
  wire hit = ic_rdata.valid && (tag == ic_rdata.tag);
  assign inst = hit ? ic_rdata.inst : axi_ifu.rdata;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (exu2ifu.valid) begin
          if (skip_icache) begin
            next = EXEC;
          end else begin
            next = CHECK;
          end
        end else begin
          next = IDLE;
        end
      end
      CHECK: begin
        if (hit) begin
          next = WAIT;
        end else begin
          next = EXEC;
        end
      end
      EXEC: begin
        if (axi_ifu.rvalid) begin
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
        CHECK: begin
          if (hit) begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 1;
          end else begin
            ifu2exu_ready <= 0;
            ifu2exu.valid <= 0;
          end
        end
        EXEC: begin
          if (axi_ifu.rvalid) begin
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

  always_ff @(posedge clock) begin  // fsm 3 for axi
    decoder <= idu;
    if (reset) begin
      axi_ifu.arvalid <= 1'b0;
      axi_ifu.rready <= 1'b0;
      ic_we <= 1'b0;
      ic_wdata <= '0;
      pc <= RST_ADDR;
      ifu2exu.pc <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (exu2ifu.valid) begin
            if (exu2ifu.jump || exu2ifu.branch) begin
              pc <= exu2ifu.dnpc;
            end else begin
              pc <= pc + 32'h4;
            end
            if (skip_icache) begin
              axi_ifu.arvalid <= 1'b1;
              axi_ifu.rready <= 1'b0;
              ic_we <= 1'b0;
            end else begin
              axi_ifu.arvalid <= 1'b0;
              axi_ifu.rready <= 1'b0;
              ic_we <= 1'b0;
            end
          end else begin
            axi_ifu.arvalid <= 1'b0;
            axi_ifu.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        CHECK: begin
          if (hit) begin
            ifu2exu.pc <= pc;
            axi_ifu.arvalid <= 1'b0;
            axi_ifu.rready <= 1'b0;
            ic_we <= 1'b0;
          end else begin
            axi_ifu.arvalid <= 1'b1;
            axi_ifu.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        EXEC: begin
          if (axi_ifu.arready) begin
            axi_ifu.arvalid <= 1'b0;
          end
          if (axi_ifu.rvalid) begin
            axi_ifu.rready <= 1'b1;
            ifu2exu.pc <= pc;
            if (!skip_icache) begin
              ic_we <= 1'b1;
              ic_wdata <= {1'b1, tag, axi_ifu.rdata};
            end
          end else begin
            axi_ifu.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        WAIT: begin
          axi_ifu.rready <= axi_ifu.rvalid;
          if (exu2ifu_ready) begin
            axi_ifu.arvalid <= 1'b0;
            ic_we <= 1'b0;
          end else begin
            axi_ifu.arvalid <= 1'b0;
            ic_we <= 1'b0;
          end
        end
      endcase
    end
  end  // fsm 3 for axi

  assign axi_ifu.araddr  = pc;
  assign axi_ifu.arid    = 4'h0;
  assign axi_ifu.arlen   = 8'h0;
  assign axi_ifu.arsize  = 3'h2;
  assign axi_ifu.arburst = 2'h1;

  ysyx_24080006_decoder DECODER (.*);


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
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff);  // SDRAM
  endfunction
  int hit_num = 0;
  int skip_num = 0;
  int miss_num = 0;
  logic [31:0] ftrace, type_cnt, ifu_cnt;
  always_ff @(posedge clock) begin
    if (reset) begin
      ftrace   <= RST_ADDR;
      type_cnt <= 0;
      type_cnt <= 1;
    end else begin
      unique case (curr)
        IDLE: begin
          type_cnt <= type_cnt + 1;
          ifu_cnt  <= 1;
          if (exu2ifu.valid && skip_icache) skip_num++;
        end
        CHECK: begin
          ifu_cnt <= ifu_cnt + 1;
          if (hit) begin
            hit_num++;
            dbg(ic_rdata.inst, pc, (exu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
            type_cnt <= 1;
            if (exu2ifu.jump || exu2ifu.branch) ftrace <= exu2ifu.dnpc;
            else ftrace <= ftrace + 32'h4;
          end else begin
            miss_num++;
            type_cnt <= type_cnt + 1;
          end
        end
        EXEC: begin
          ifu_cnt <= ifu_cnt + 1;
          if (axi_ifu.rvalid) begin
            dbg(axi_ifu.rdata, pc, (exu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
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
