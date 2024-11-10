module ysyx_24080006_ex_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input decoder_t decoder,

    input  logic   ifu2exu_ready,
    output logic   exu2ifu_ready,
    input  stage_t ifu2exu,
    output stage_t exu2ifu,

    ysyx_24080006_axi.master axi_lsu
);

  logic mdu_valid_o, mdu_valid_i;

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
        if (ifu2exu.valid) begin
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
        if (axi_lsu.rvalid || axi_lsu.bvalid) next = WAIT;
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
      exu2ifu_ready <= 1;
      exu2ifu.valid <= 1;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2exu.valid) begin
            if (decoder.lsu_set.lsu_enable) begin
              exu2ifu_ready <= 0;
              exu2ifu.valid <= 0;
            end else if (decoder.mdu_set.mdu_enable) begin
              exu2ifu_ready <= 0;
              exu2ifu.valid <= 0;
            end else begin  // bypass
              exu2ifu_ready <= 0;
              exu2ifu.valid <= 1;
            end
          end else begin
            exu2ifu_ready <= 1;
            exu2ifu.valid <= 0;
          end
        end
        EXEC: begin
          if (axi_lsu.rvalid || axi_lsu.bvalid) begin
            exu2ifu_ready <= 0;
            exu2ifu.valid <= 1;
          end else begin
            exu2ifu_ready <= 0;
            exu2ifu.valid <= 0;
          end
        end
        MD_EXEC: begin
          if (mdu_valid_i) begin
            exu2ifu_ready <= 0;
            exu2ifu.valid <= 1;
          end else begin
            exu2ifu_ready <= 0;
            exu2ifu.valid <= 0;
          end
        end
        WAIT: begin
          if (ifu2exu_ready) begin
            exu2ifu_ready <= 1;
            exu2ifu.valid <= 0;
          end else begin
            exu2ifu_ready <= 0;
            exu2ifu.valid <= 1;
          end
        end
      endcase
    end
  end

  logic [31:0] dnpc;
  logic [31:0] rs1_data, rs2_data, rd_data;
  logic [31:0] csr_rdata;
  logic reg_we;
  logic [31:0] alu_a, alu_b, alu_c, mdu_c;
  logic [ 4:0] Mr_param;

  function automatic logic [31:0] Mr(input logic [31:0] rdata, input logic [4:0] param);
    logic [31:0] tmp;
    tmp = rdata >> ({3'b0, param[1:0]} << 3);
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
      axi_lsu.arvalid <= '0;
      axi_lsu.rready <= '0;
      axi_lsu.awvalid <= '0;
      axi_lsu.wvalid <= '0;
      axi_lsu.bready <= '0;
      axi_lsu.araddr <= '0;
      axi_lsu.awaddr <= '0;
      axi_lsu.wdata <= '0;
      //axi_lsu.wstrb <= '0;
      axi_lsu.arsize <= '0;
      axi_lsu.awsize <= '0;
      Mr_param <= '0;
      reg_we <= '0;
      rd_data <= '0;
      exu2ifu.dnpc <= '0;
      exu2ifu.jump <= '0;
      exu2ifu.branch <= '0;
      mdu_valid_o <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2exu.valid) begin
            exu2ifu.dnpc   <= dnpc;
            exu2ifu.jump   <= decoder.jal | decoder.jalr | decoder.ecall | decoder.mret;
            exu2ifu.branch <= alu_c[0] & decoder.branch;
            if (decoder.lsu_set.lsu_enable) begin

              if (decoder.lsu_set.lsu_write) begin
                axi_lsu.arvalid <= 0;
                axi_lsu.rready <= 0;
                axi_lsu.awvalid <= 1;
                axi_lsu.wvalid <= 1;
                axi_lsu.bready <= 0;
                axi_lsu.awaddr <= alu_c;
                axi_lsu.wdata <= rs2_data;  // << ({3'b0, alu_c[1:0]} << 3);
                axi_lsu.awsize <= {1'b0, decoder.lsu_set.lsu_size};
                //axi_lsu.wstrb <= WSTRB_LUT[decoder.lsu_set.lsu_size] << alu_c[1:0];
                reg_we <= '0;
              end else begin
                axi_lsu.arvalid <= 1;
                axi_lsu.rready <= 0;
                axi_lsu.awvalid <= 0;
                axi_lsu.wvalid <= 0;
                axi_lsu.bready <= 0;
                axi_lsu.arsize <= {1'b0, decoder.lsu_set.lsu_size};
                axi_lsu.araddr <= alu_c;
                Mr_param <= {decoder.lsu_set.lsu_sext, decoder.lsu_set.lsu_size, alu_c[1:0]};
                reg_we <= '0;
              end
            end else if (decoder.mdu_set.mdu_enable) begin
              axi_lsu.arvalid <= 0;
              axi_lsu.rready <= 0;
              axi_lsu.awvalid <= 0;
              axi_lsu.wvalid <= 0;
              axi_lsu.bready <= 0;
              reg_we <= '0;
              mdu_valid_o <= 1;
            end else begin  // bypass
              axi_lsu.arvalid <= 0;
              axi_lsu.rready <= 0;
              axi_lsu.awvalid <= 0;
              axi_lsu.wvalid <= 0;
              axi_lsu.bready <= 0;
              reg_we <= decoder.reg_we;
              rd_data <= alu_c;
            end
          end else begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
          end
        end
        EXEC: begin
          if (axi_lsu.arready) axi_lsu.arvalid <= 0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 0;
          if (axi_lsu.bvalid) begin
            axi_lsu.bready <= 1;
            reg_we <= '0;
          end
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1;
            rd_data <= Mr(axi_lsu.rdata, Mr_param);
            reg_we <= decoder.reg_we;
          end
        end
        MD_EXEC: begin
          if (mdu_valid_i) begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= decoder.reg_we;
            rd_data <= mdu_c;
            mdu_valid_o <= 0;
          end else begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
            mdu_valid_o <= 1;
          end
        end
        WAIT: begin
          if (ifu2exu_ready) begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
          end else begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
          end
        end
      endcase
    end
  end

  ysyx_24080006_reg REG (
      .*,
      .rs1_addr(decoder.rs1_addr),
      .rs2_addr(decoder.rs2_addr),
      .rd_addr (decoder.rd_addr)
  );
  mdu2alu_t mdu2alu;
  alu2mdu_t alu2mdu;
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
      .pc(ifu2exu.pc),
      .csr_set(decoder.csr_set),
      .csr_wdata(rs1_data)
  );

  always_comb begin
    unique case (1'b1)
      decoder.jal: dnpc = ifu2exu.pc + decoder.imm;
      decoder.jalr: dnpc = (rs1_data + decoder.imm) & 32'hffff_fffe;
      decoder.branch: dnpc = ifu2exu.pc + decoder.imm;
      decoder.ecall: dnpc = csr_rdata;
      decoder.mret: dnpc = csr_rdata;
      default: dnpc = csr_rdata;
    endcase
  end

  always_comb begin
    unique case (decoder.alu_set.alu_a)
      RS1:     alu_a = rs1_data;
      PC:      alu_a = ifu2exu.pc;
      CONST0:  alu_a = 32'b0;
      default: alu_a = 32'b0;
    endcase
  end

  always_comb begin
    unique case (decoder.alu_set.alu_b)
      IMM:     alu_b = decoder.imm;
      RS2:     alu_b = rs2_data;
      CONST4:  alu_b = 32'h4;
      CSR:     alu_b = csr_rdata;
      default: alu_b = 32'h4;
    endcase
  end

  assign axi_lsu.arid    = 4'h1;
  assign axi_lsu.arlen   = 8'h0;
  assign axi_lsu.arburst = 2'h0;
  assign axi_lsu.awid    = 4'h2;
  assign axi_lsu.awlen   = 8'h0;
  assign axi_lsu.awburst = 2'h0;
  assign axi_lsu.wlast   = 1'b1;

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
    if (curr == EXEC && axi_lsu.bvalid) begin
      //$display("[LSU] 0x%08x write [0x%08x]", axi_lsu.awaddr, axi_lsu.wdata);
      LSU_CNT(0, lsu_cnt);
      if (INSIDE_PERIP(axi_lsu.awaddr)) SKIP_DIFFTEST();
      else if (!INSIDE_MEM(axi_lsu.awaddr)) begin
        $display("[LSU] store addr error 0x%08x at pc 0x%08x", axi_lsu.awaddr, ifu2exu.pc);
        $finish;
      end
    end
    if (curr == EXEC && axi_lsu.rvalid) begin
      //$display("[LSU] 0x%08x read [0x%08x]", axi_lsu.araddr, axi_lsu.rdata);
      LSU_CNT(1, lsu_cnt);
      if (INSIDE_PERIP(axi_lsu.araddr)) SKIP_DIFFTEST();
      else if (!INSIDE_MEM(axi_lsu.araddr)) begin
        $display("[LSU] load addr error 0x%08x at pc 0x%08x", axi_lsu.araddr, ifu2exu.pc);
        $finish;
      end
    end
  end
`endif
endmodule
