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

  logic icu2ifu_valid, ifu2icu_valid;
  logic icu2ifu_ready, ifu2icu_ready;
  logic fetch_twice_d, fetch_twice_q;
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
        if (icu2ifu_valid && !fetch_twice_q) begin
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
          if (icu2ifu_valid && !fetch_twice_q) begin
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

  logic [31:0] ic_val;
  logic is_zc_d, is_zc_q;
  logic zc_err, inst_err;
  assign is_zc = is_zc_q;
  logic [31:0] pc_d, pc_q;
  logic [31:0] fetch_addr_d, fetch_addr_q;
  logic [15:0] inst_buf;
  logic [31:0] inst_d, inst_q;
  assign inst = inst_q;

  always_comb begin
    if (fetch_twice_q) begin
      pc_d = pc_q;
      fetch_addr_d = fetch_addr_q + 32'h4;
      fetch_twice_d = 0;
    end else if (exu2ifu.jump || exu2ifu.branch) begin
      pc_d = exu2ifu.dnpc;
      fetch_addr_d = {exu2ifu.dnpc[31:2], 2'b00};
      fetch_twice_d = exu2ifu.dnpc[1];
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
    end else begin
      unique case (curr)
        RESET: begin
          //pc_q <= RST_ADDR;
          //fetch_addr_q <= RST_ADDR;
          ifu2icu_valid <= 1'b1;
        end
        IDLE: begin
          if (exu2ifu.valid) begin
            pc_q <= pc_d;
            fetch_addr_q <= fetch_addr_d;
            ifu2icu_valid <= 1'b1;
            fetch_twice_q <= fetch_twice_d;
          end else begin
            ifu2icu_valid <= 1'b0;
          end
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
            end
          end
        end
        WAIT: begin
          ifu2icu_valid <= 1'b0;
        end
      endcase
    end
  end  // fsm 3 for axi


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
        IDLE: begin
          type_cnt <= type_cnt + 1;
          ifu_cnt  <= 1;
        end
        RESET, EXEC: begin
          ifu_cnt <= ifu_cnt + 1;
          if (icu2ifu_valid & ~fetch_twice_q) begin
            dbg(zc_val, pc_q, (exu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
            type_cnt <= 1;
            if (exu2ifu.jump || exu2ifu.branch) ftrace <= exu2ifu.dnpc;
            else ftrace <= ftrace + 32'h4;
          end else type_cnt <= type_cnt + 1;
        end
        WAIT: type_cnt <= type_cnt + 1;
        default: ;
      endcase
    end
  end
  always_ff @(posedge clock) begin
    if (ifu2idu.valid) begin
      if (!INSIDE_MEM(pc_q)) begin
        $display("[IFU]pc error 0x%08x", pc_q);
        $finish;
      end
    end
  end
`endif
endmodule
