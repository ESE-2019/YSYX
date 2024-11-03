module ysyx_24080006_ifu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic   idu2ifu_ready,
    output logic   ifu2wbu_ready,
    input  stage_t wbu2ifu,
    output stage_t ifu2idu,

    ysyx_24080006_axi.master axi_ifu
);

  fsm_e curr, next;

  logic [31:0] pc;
`ifdef SOC_MODE
  localparam RST_ADDR = 32'h3000_0000 - 32'h4;
`else
  localparam RST_ADDR = 32'h8000_0000 - 32'h4;
`endif



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
        if (wbu2ifu.valid) next = EXEC;
        else next = IDLE;
      end
      EXEC: begin
        if (axi_ifu.rvalid) next = WAIT;
        else next = EXEC;
      end
      WAIT: begin
        if (idu2ifu_ready) next = IDLE;
        else next = WAIT;
      end
    endcase
  end

  always_ff @(posedge clock) begin  //fsm 3 for control
    unique if (reset) begin
      ifu2wbu_ready <= 1;
      ifu2idu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (wbu2ifu.valid) begin
            ifu2wbu_ready <= 0;
            ifu2idu.valid <= 0;
          end else begin
            ifu2wbu_ready <= 1;
            ifu2idu.valid <= 0;
          end
        end
        EXEC: begin
          if (axi_ifu.rvalid) begin
            ifu2wbu_ready <= 0;
            ifu2idu.valid <= 1;
          end else begin
            ifu2wbu_ready <= 0;
            ifu2idu.valid <= 0;
          end
        end
        WAIT: begin
          if (idu2ifu_ready) begin
            ifu2wbu_ready <= 1;
            ifu2idu.valid <= 0;
          end else begin
            ifu2wbu_ready <= 0;
            ifu2idu.valid <= 1;
          end
        end
      endcase
    end
  end

  assign axi_ifu.araddr = pc;  //TODO will be edited
`ifdef SIM_MODE
  import "DPI-C" function void dbg(
    input int inst,
    input int pc,
    input int ft_pc,
    input int type_cnt,
    input int ifu_cnt
  );
  logic [31:0] ftrace, type_cnt;
  logic [31:0] ifu_cnt;
`endif

  always_ff @(posedge clock) begin  //fsm 3 for axi
    unique if (reset) begin
      axi_ifu.arvalid <= 0;
      axi_ifu.rready <= 1;
      ifu2idu.inst <= '0;
      pc <= RST_ADDR;
      ifu2idu.pc <= '0;
`ifdef SIM_MODE
      ftrace   <= RST_ADDR;
      type_cnt <= 0;
      type_cnt <= 1;
`endif
    end else begin
      unique case (curr)
        IDLE: begin
`ifdef SIM_MODE
          type_cnt <= type_cnt + 1;
          ifu_cnt  <= 1;
`endif
          if (wbu2ifu.valid) begin
            axi_ifu.arvalid <= 1;
            axi_ifu.rready  <= 1;
            if (wbu2ifu.jump || wbu2ifu.branch) begin
              pc <= wbu2ifu.dnpc;
            end else begin
              pc <= pc + 32'h4;
            end
          end else begin
            axi_ifu.arvalid <= 0;
            axi_ifu.rready  <= 1;
          end
        end
        EXEC: begin
`ifdef SIM_MODE
          ifu_cnt <= ifu_cnt + 1;
`endif
          if (axi_ifu.arready) begin
            axi_ifu.arvalid <= 0;
          end
          if (axi_ifu.rvalid) begin
            axi_ifu.rready <= 1;
            ifu2idu.inst <= axi_ifu.rdata;
            ifu2idu.pc <= pc;
`ifdef SIM_MODE
            dbg(axi_ifu.rdata, pc, (wbu2ifu.jump ? ftrace : 0), type_cnt, ifu_cnt);
            type_cnt <= 1;
            if (wbu2ifu.jump || wbu2ifu.branch) ftrace <= wbu2ifu.dnpc;
            else ftrace <= ftrace + 32'h4;
`endif
          end else begin
`ifdef SIM_MODE
            type_cnt <= type_cnt + 1;
`endif
          end
        end
        WAIT: begin
`ifdef SIM_MODE
          type_cnt <= type_cnt + 1;
`endif
          axi_ifu.arvalid <= 0;
          axi_ifu.rready  <= 1;
        end
      endcase
    end
  end

`ifdef SOC_MODE
  function automatic logic INSIDE(input logic [31:0] addr, left, right);
    INSIDE = addr >= left && addr <= right;
  endfunction
  function automatic logic INSIDE_MEM(input logic [31:0] addr);
    INSIDE_MEM = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) ||  // FLASH
        INSIDE(addr, 32'h8000_0000, 32'h81ff_ffff);  // SDRAM
  endfunction
  always_ff @(posedge clock) begin
    if (curr == EXEC && !INSIDE_MEM(pc)) begin
      $display("[ifu2idu]addr error 0x%08x", pc);
      $finish;
    end
  end
`endif

endmodule
