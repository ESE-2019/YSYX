module ysyx_24080006_ex_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input decoder_t decoder,
    input logic is_zc,

    output logic                 reg_we,
    output logic [REG_WIDTH-1:0] rd_addr,
    output logic [         31:0] rd_data,

    input fencei,

    input  logic   ifu2exu_ready,
    output logic   exu2idu_ready,
    input  stage_t idu2exu,
    output stage_t exu2ifu,

    ysyx_24080006_axi.master axi_lsu
);

  logic mdu_valid_o, mdu_valid_i;
  mdu2alu_t mdu2alu;
  alu2mdu_t alu2mdu;
  logic lsu2dcu_valid;
  logic lsu2dcu_ready;
  logic dcu2lsu_valid;
  logic dcu2lsu_ready;
  assign lsu2dcu_ready = 1'b1;

  typedef enum logic [1:0] {
    IDLE,
    EXEC,
    MD_EXEC,
    WAIT
  } ex_fsm_e;
  ex_fsm_e curr, next;

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
        if (idu2exu.valid) begin
          if (decoder.lsu_set.lsu_enable) begin
            next = EXEC;
          end else if (decoder.mdu_set.mdu_enable) begin
            next = MD_EXEC;
          end else begin
            next = WAIT;
          end
        end else next = IDLE;
      end
      EXEC: begin
        if (dcu2lsu_valid) next = WAIT;
        else next = EXEC;
      end
      MD_EXEC: begin
        if (mdu_valid_i) next = WAIT;
        else next = MD_EXEC;
      end
      WAIT: begin
        if (ifu2exu_ready) next = IDLE;
        else next = WAIT;
      end
    endcase
  end

  always_ff @(posedge clock) begin  //fsm 3 for control
    unique if (reset) begin
      exu2idu_ready <= 0;
      exu2ifu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (idu2exu.valid) begin
            if (decoder.lsu_set.lsu_enable) begin
              exu2idu_ready <= 0;
              exu2ifu.valid <= 0;
            end else if (decoder.mdu_set.mdu_enable) begin
              exu2idu_ready <= 0;
              exu2ifu.valid <= 0;
            end else begin  // bypass
              exu2idu_ready <= 0;
              exu2ifu.valid <= 1;
            end
          end else begin
            exu2idu_ready <= 1;
            exu2ifu.valid <= 0;
          end
        end
        EXEC: begin
          if (dcu2lsu_valid) begin
            exu2idu_ready <= 0;
            exu2ifu.valid <= 1;
          end else begin
            exu2idu_ready <= 0;
            exu2ifu.valid <= 0;
          end
        end
        MD_EXEC: begin
          if (mdu_valid_i) begin
            exu2idu_ready <= 0;
            exu2ifu.valid <= 1;
          end else begin
            exu2idu_ready <= 0;
            exu2ifu.valid <= 0;
          end
        end
        WAIT: begin
          if (ifu2exu_ready) begin
            exu2idu_ready <= 1;
            exu2ifu.valid <= 0;
          end else begin
            exu2idu_ready <= 0;
            exu2ifu.valid <= 1;
          end
        end
      endcase
    end
  end

  logic [31:0] dnpc;
  logic [31:0] csr_rdata;
  logic [31:0] alu_a, alu_b, alu_c, mdu_c;
  logic [4:0] Mr_param;
  logic [31:0] dcu_addr;
  logic [1:0] dcu_size;
  logic dcu_write;
  logic [31:0] dcu_wdata;
  logic [31:0] dcu_rdata;

  function automatic logic [31:0] Mr(input logic [31:0] rdata, input logic [4:0] param);
    logic [31:0] tmp;
    tmp = rdata >> {param[1:0], 3'b0};
    unique case (param[4:2])
      3'b000:  Mr = {{24{tmp[7]}}, tmp[7:0]};
      3'b001:  Mr = {{16{tmp[15]}}, tmp[15:0]};
      3'b010:  Mr = tmp[31:0];
      3'b100:  Mr = {24'b0, tmp[7:0]};
      3'b101:  Mr = {16'b0, tmp[15:0]};
      default: Mr = tmp[31:0];
    endcase
  endfunction

  always_ff @(posedge clock) begin  //fsm 3 for axi
    unique if (reset) begin
      lsu2dcu_valid <= 1'b0;
      Mr_param <= '0;
      reg_we <= '0;
      rd_data <= '0;
      exu2ifu.dnpc <= '0;
      exu2ifu.jump <= '0;
      exu2ifu.branch <= '0;
      mdu_valid_o <= 0;
      dcu_addr <= 32'b0;
      dcu_size <= 2'b0;
      dcu_write <= 1'b0;
      dcu_wdata <= 32'b0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (idu2exu.valid) begin
            exu2ifu.dnpc   <= dnpc;
            exu2ifu.jump   <= decoder.jal | decoder.jalr | decoder.ecall | decoder.mret;
            exu2ifu.branch <= alu_c[0] & decoder.branch;
            if (decoder.lsu_set.lsu_enable) begin
              Mr_param <= {decoder.lsu_set.lsu_sext, decoder.lsu_set.lsu_size, alu2mdu.res_32[1:0]};
              lsu2dcu_valid <= 1'b1;
              dcu_addr <= alu2mdu.res_32;
              dcu_size <= decoder.lsu_set.lsu_size;
              dcu_write <= decoder.lsu_set.lsu_write;
              dcu_wdata <= idu2exu.rs2_data;
            end else if (decoder.mdu_set.mdu_enable) begin  // mul/div
              lsu2dcu_valid <= 1'b0;
              reg_we <= '0;
              mdu_valid_o <= 1;
            end else begin  // bypass
              lsu2dcu_valid <= 1'b0;
              reg_we <= decoder.reg_we;
              rd_data <= alu_c;
            end
          end else begin
            lsu2dcu_valid <= 1'b0;
            reg_we <= '0;
          end
        end
        EXEC: begin
          if (lsu2dcu_valid & dcu2lsu_ready) lsu2dcu_valid <= 1'b0;
          if (dcu2lsu_valid) begin
            rd_data <= Mr(dcu_rdata, Mr_param);
            reg_we  <= decoder.reg_we;
          end
        end
        MD_EXEC: begin
          if (mdu_valid_i) begin
            reg_we <= decoder.reg_we;
            rd_data <= mdu_c;
            mdu_valid_o <= 0;
          end else begin
            reg_we <= '0;
            mdu_valid_o <= 1;
          end
        end
        WAIT: begin
          reg_we <= '0;
        end
      endcase
    end
  end
  ysyx_24080006_dcu DCU (.*);
  ysyx_24080006_alu ALU (
      .*,
      .mdu_enable(decoder.mdu_set.mdu_enable),
      .alu_op(decoder.alu_set.alu_op)
  );
  ysyx_24080006_mdu MDU (
      .*,
      .mdu_a  (alu_a),
      .mdu_b  (alu_b),
      .mdu_set(decoder.mdu_set),
      .valid_i(mdu_valid_o),
      .valid_o(mdu_valid_i)
  );
  ysyx_24080006_csr CSRU (
      .*,
      .ecall(decoder.ecall),
      .mret(decoder.mret),
      .pc(idu2exu.pc),
      .csr_set(decoder.csr_set),
      .csr_wdata(idu2exu.rs1_data)
  );

  always_comb begin
    unique case (1'b1)
      decoder.jal: dnpc = idu2exu.pc + decoder.imm;
      decoder.jalr: dnpc = (idu2exu.rs1_data + decoder.imm) & 32'hffff_fffe;
      decoder.branch: dnpc = idu2exu.pc + decoder.imm;
      decoder.ecall: dnpc = csr_rdata;
      decoder.mret: dnpc = csr_rdata;
      default: dnpc = csr_rdata;
    endcase
  end

  always_comb begin
    unique case (decoder.alu_set.alu_a)
      RS1:     alu_a = idu2exu.rs1_data;
      PC:      alu_a = idu2exu.pc;
      CONST0:  alu_a = 32'b0;
      default: alu_a = 32'b0;
    endcase
  end

  always_comb begin
    unique case (decoder.alu_set.alu_b)
      IMM:     alu_b = decoder.imm;
      RS2:     alu_b = idu2exu.rs2_data;
      PC_INCR: alu_b = is_zc ? 32'h2 : 32'h4;
      CSR:     alu_b = csr_rdata;
      default: alu_b = 32'h4;
    endcase
  end

  assign rd_addr = decoder.rd_addr;

`ifdef SOC_MODE
  function automatic logic INSIDE(input logic [31:0] addr, left, right);
    INSIDE = addr >= left && addr <= right;
  endfunction
  function automatic logic INSIDE_PERIP(input logic [31:0] addr);
    INSIDE_PERIP = INSIDE(addr, 32'h0200_0000, 32'h0200_ffff) ||  // CLINT
        INSIDE(addr, 32'h1000_0000, 32'h1000_0fff) ||  // UART
        INSIDE(addr, 32'h1000_2000, 32'h1000_200f) ||  // GPIO
        INSIDE(addr, 32'h1001_1000, 32'h1001_1007) ||  // PS2
        INSIDE(addr, 32'h2100_0000, 32'h211f_ffff);  // VGA
  endfunction
  function automatic logic INSIDE_MEM(input logic [31:0] addr);
    INSIDE_MEM = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) ||  // FLASH
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff) ||  // NPC SRAM
        INSIDE(addr, 32'ha000_0000, 32'ha3ff_ffff);  // SDRAM
  endfunction
  import "DPI-C" function void SKIP_DIFFTEST();
  import "DPI-C" function void LSU_CNT(
    input int load_en,
    input int cnt
  );
  int lsu_cnt = 0;
  always_ff @(posedge clock) begin
    if (curr == IDLE) lsu_cnt = 1;
    else lsu_cnt++;
    if (curr == EXEC && dcu2lsu_valid && decoder.lsu_set.lsu_write) begin
      //$display("[LSU] 0x%08x write [0x%08x]", dcu_addr, dcu_wdata);
      LSU_CNT(0, lsu_cnt);
      if (INSIDE_PERIP(dcu_addr)) SKIP_DIFFTEST();
      else if (!INSIDE_MEM(dcu_addr)) begin
        $display("[LSU] store addr error 0x%08x at pc 0x%08x", dcu_addr, idu2exu.pc);
        $finish;
      end
    end
    if (curr == EXEC && dcu2lsu_valid && !decoder.lsu_set.lsu_write) begin
      //$display("[LSU] 0x%08x read [0x%08x]", dcu_addr, dcu_rdata);
      LSU_CNT(1, lsu_cnt);
      if (INSIDE_PERIP(dcu_addr)) SKIP_DIFFTEST();
      else if (!INSIDE_MEM(dcu_addr)) begin
        $display("[LSU] load addr error 0x%08x at pc 0x%08x", dcu_addr, idu2exu.pc);
        $finish;
      end
    end
  end
`endif
endmodule
