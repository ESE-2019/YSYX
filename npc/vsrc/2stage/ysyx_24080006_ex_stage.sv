module ysyx_24080006_ex_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic   ifu2exu_ready,
    output logic   exu2ifu_ready,
    input  stage_t ifu2exu,
    output stage_t exu2ifu,

    ysyx_24080006_axi.master axi_lsu
);


  logic [31:0] immB, immI, immJ, immS, immU;
  inst_op_e                 inst_op;
  logic     [          2:0] funct3;
  logic     [         31:0] dnpc;

  logic                     reg_we;
  logic     [REG_WIDTH-1:0] rs1_addr;
  logic     [REG_WIDTH-1:0] rs2_addr;
  logic     [REG_WIDTH-1:0] rd;
  logic     [         31:0] wdata;
  logic     [         31:0] rs1_val;
  logic     [         31:0] rs2_val;
  logic     [REG_WIDTH-1:0] rd_addr;
  ysyx_24080006_reg REG (.*);
  logic        csr_we;
  logic [31:0] mepc_val;
  logic        mepc_en;
  logic [11:0] csr_addr;
  logic [11:0] csr_waddr;
  logic [31:0] csr_wdata;
  logic [31:0] csr_rdata;
  ysyx_24080006_csr CSR (.*);
  logic [31:0] alu_src1, alu_src2;
  alu_op_e alu_op;
  logic [31:0] alu_res;
  ysyx_24080006_alu ALU (.*);


  logic [31:0] ldata;

  wire ecall = ifu2exu.inst == ECALL;
  wire csr_we_flag = inst_op == System && (funct3 != 3'b0);
  wire reg_we_flag = inst_op inside {Auipc, Lui, Jal, Jalr, I_type, R_type, Load};
  assign wdata = csr_we_flag ? csr_rdata : inst_op == Load ? ldata : alu_res;
  wire jump = (inst_op inside {Jal, Jalr}) || (inst_op == System && !csr_we_flag);
  wire branch = (inst_op == Branch) && alu_res[0];
  assign csr_wdata = ecall ? 32'd11 : alu_res;
  assign csr_waddr = ecall ? 12'h342 : csr_addr;


  fsm_e curr, next;

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
          if (inst_op inside {Load, Store}) begin
            next = EXEC;
          end else begin
            next = WAIT;
          end
        end else next = IDLE;
      end
      EXEC: begin
        if (axi_lsu.rvalid || axi_lsu.bvalid) next = WAIT;
        else next = EXEC;
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
            if (inst_op inside {Load, Store}) begin
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

  logic [1:0] Mr_param_addr;
  logic [2:0] Mr_param_funct3;

`ifdef SIM_MODE
  logic [31:0] lsu_cnt;
  import "DPI-C" function void LSU_CNT(
    input int load_en,
    input int cnt
  );
`endif

  function automatic logic [31:0] Mr(input logic [31:0] rdata, input logic [1:0] addr,
                                     input logic [2:0] funct3);
    logic [ 4:0] Mr_shamt;
    logic [31:0] tmp;
    unique case (addr)
      2'b00: Mr_shamt = 0;
      2'b01: Mr_shamt = 8;
      2'b10: Mr_shamt = 16;
      2'b11: Mr_shamt = 24;
    endcase
    tmp = rdata >> Mr_shamt;
    unique case (funct3)
      3'b000: Mr = {{24{tmp[7]}}, tmp[7:0]};
      3'b001: Mr = {{16{tmp[15]}}, tmp[15:0]};
      3'b010: Mr = tmp[31:0];
      3'b100: Mr = {24'b0, tmp[7:0]};
      3'b101: Mr = {16'b0, tmp[15:0]};
      default: begin
        Mr = 0;
      end
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
      axi_lsu.wstrb <= '0;
      axi_lsu.arsize <= '0;
      axi_lsu.awsize <= '0;
      ldata <= '0;
      Mr_param_addr <= '0;
      Mr_param_funct3 <= '0;
      reg_we <= '0;
      csr_we <= '0;
      exu2ifu.dnpc <= '0;
      exu2ifu.jump <= '0;
      exu2ifu.branch <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2exu.valid) begin
            exu2ifu.dnpc   <= dnpc;
            exu2ifu.jump   <= jump;
            exu2ifu.branch <= branch;
`ifdef SIM_MODE
            lsu_cnt <= 1;
`endif
            if (inst_op == Load) begin  // load / read
              axi_lsu.arvalid <= 1;
              axi_lsu.rready <= 0;
              axi_lsu.awvalid <= 0;
              axi_lsu.wvalid <= 0;
              axi_lsu.bready <= 0;
              axi_lsu.arsize <= {1'b0, funct3[1:0]};
              axi_lsu.araddr <= alu_res;
              Mr_param_addr <= alu_res[1:0];
              Mr_param_funct3 <= funct3;
              reg_we <= '0;
              csr_we <= '0;
            end else if (inst_op == Store) begin  // store / write
              axi_lsu.arvalid <= 0;
              axi_lsu.rready <= 0;
              axi_lsu.awvalid <= 1;
              axi_lsu.wvalid <= 1;
              axi_lsu.bready <= 0;
              axi_lsu.awaddr <= alu_res;
              axi_lsu.wdata <= rs2_val << ({3'b0, alu_res[1:0]} << 3);
              axi_lsu.awsize <= funct3;
              axi_lsu.wstrb <= WSTRB_LUT[funct3[1:0]] << alu_res[1:0];
              reg_we <= '0;
              csr_we <= '0;
            end else begin  // bypass
              axi_lsu.arvalid <= 0;
              axi_lsu.rready <= 0;
              axi_lsu.awvalid <= 0;
              axi_lsu.wvalid <= 0;
              axi_lsu.bready <= 0;
              reg_we <= csr_we_flag | reg_we_flag;
              csr_we <= csr_we_flag | ecall;
            end
          end else begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
            csr_we <= '0;
          end
        end
        EXEC: begin
`ifdef SIM_MODE
          lsu_cnt <= lsu_cnt + 1;
`endif
          if (axi_lsu.arready) axi_lsu.arvalid <= 0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 0;
          if (axi_lsu.bvalid) begin
            axi_lsu.bready <= 1;
            reg_we <= '0;
            csr_we <= '0;
`ifdef SIM_MODE
            LSU_CNT(0, lsu_cnt);
`endif
            //$display("[LSU] 0x%08x write [0x%08x]", axi_lsu.awaddr, axi_lsu.wdata);
          end
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1;
            ldata <= Mr(axi_lsu.rdata, Mr_param_addr, Mr_param_funct3);
            reg_we <= reg_we_flag;
            csr_we <= '0;
`ifdef SIM_MODE
            LSU_CNT(1, lsu_cnt);
`endif
            //$display("[LSU] 0x%08x read [0x%08x]", axi_lsu.araddr, axi_lsu.rdata);
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
            csr_we <= '0;
          end else begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready <= 0;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid <= 0;
            axi_lsu.bready <= 0;
            reg_we <= '0;
            csr_we <= '0;
          end
        end
      endcase
    end
  end

  assign immB = {
    {20{ifu2exu.inst[31]}}, ifu2exu.inst[7], ifu2exu.inst[30:25], ifu2exu.inst[11:8], 1'b0
  };
  assign immI = {{20{ifu2exu.inst[31]}}, ifu2exu.inst[31:20]};
  assign immJ = {
    {12{ifu2exu.inst[31]}}, ifu2exu.inst[19:12], ifu2exu.inst[20], ifu2exu.inst[30:21], 1'b0
  };
  assign immS = {{20{ifu2exu.inst[31]}}, ifu2exu.inst[31:25], ifu2exu.inst[11:7]};
  assign immU = {ifu2exu.inst[31:12], 12'b0};


  assign inst_op = inst_op_e'(ifu2exu.inst[6:0]);
  assign funct3 = ifu2exu.inst[14:12];
  assign rs1_addr = ifu2exu.inst[15+:REG_WIDTH];
  assign rs2_addr = ifu2exu.inst[20+:REG_WIDTH];
  assign rd_addr = ifu2exu.inst[7+:REG_WIDTH];
  assign rd = rd_addr;

  assign mepc_val = ifu2exu.pc;
  assign mepc_en = ifu2exu.inst == ECALL;
  assign csr_addr = ( ifu2exu.inst == ECALL ) ? 12'h305 :  
      (ifu2exu.inst == 32'b0011000_00010_00000_000_00000_11100_11) ? 12'h341 :   
      ifu2exu.inst[31:20];


  always_comb begin
    unique case (inst_op)
      Jal: dnpc = ifu2exu.pc + immJ;
      Jalr: dnpc = (rs1_val + immI) & 32'hffff_fffe;
      Branch: dnpc = ifu2exu.pc + immB;
      System: dnpc = csr_rdata;
      default: dnpc = csr_rdata;
    endcase
  end

  always_comb begin
    unique case (inst_op)
      Jal, Jalr, Auipc: alu_src1 = ifu2exu.pc;
      Lui:              alu_src1 = '0;
      default:          alu_src1 = rs1_val;
    endcase
  end

  always_comb begin
    unique case (inst_op)
      Auipc, Lui: alu_src2 = immU;
      Store: alu_src2 = immS;
      Load, I_type: alu_src2 = immI;
      Branch, R_type: alu_src2 = rs2_val;
      Jal, Jalr: alu_src2 = 32'h4;
      System:
      if (funct3 == 3'b010) alu_src2 = csr_rdata;
      else alu_src2 = '0;
      default: alu_src2 = '0;
    endcase
  end

  always_comb begin
    alu_op = ADD;
    unique case (inst_op)
      Branch:
      unique case (funct3)
        3'b000:  alu_op = BEQ;
        3'b001:  alu_op = BNE;
        3'b100:  alu_op = BLT;
        3'b101:  alu_op = BGE;
        3'b110:  alu_op = BLTU;
        3'b111:  alu_op = BGEU;
        default: ;
      endcase
      I_type:
      unique case (funct3)
        3'b000:  alu_op = ADD;
        3'b001:  alu_op = SLL;
        3'b010:  alu_op = SLT;
        3'b011:  alu_op = SLTU;
        3'b100:  alu_op = XOR;
        3'b101:
        if (!ifu2exu.inst[30]) begin
          alu_op = SRL;
        end else begin
          alu_op = SRA;
        end
        3'b110:  alu_op = OR;
        3'b111:  alu_op = AND;
        default: ;
      endcase
      R_type:
      unique case (funct3)
        3'b000:
        if (!ifu2exu.inst[30]) begin
          alu_op = ADD;
        end else begin
          alu_op = SUB;
        end
        3'b001:  alu_op = SLL;
        3'b010:  alu_op = SLT;
        3'b011:  alu_op = SLTU;
        3'b100:  alu_op = XOR;
        3'b101:
        if (!ifu2exu.inst[30]) begin
          alu_op = SRL;
        end else begin
          alu_op = SRA;
        end
        3'b110:  alu_op = OR;
        3'b111:  alu_op = AND;
        default: ;
      endcase
      Jal, Jalr, Lui, Auipc, Load, Store: alu_op = ADD;
      System:
      if (funct3 == 3'b010) begin
        alu_op = OR;
      end else begin
        alu_op = ADD;
      end
      default: ;
    endcase
  end


  assign axi_lsu.arid    = 4'h1;
  assign axi_lsu.arlen   = 8'h0;
  assign axi_lsu.arburst = 2'h0;
  assign axi_lsu.awid    = 4'h2;
  assign axi_lsu.awlen   = 8'h0;
  assign axi_lsu.awburst = 2'h0;
  assign axi_lsu.wlast   = 1'b0;


`ifdef SIM_MODE
  import "DPI-C" function void ebreak();
  import "DPI-C" function void INST_CNT(input int type_code);
  always_ff @(posedge clock) begin
    if (curr == IDLE && ifu2exu.valid)
      case (inst_op)

        Auipc, Lui, R_type, I_type: INST_CNT(0);

        Load, Store: INST_CNT(1);

        System: begin
          INST_CNT(2);
          if (ifu2exu.inst == 32'b0000000_00001_00000_000_00000_11100_11) ebreak();
        end

        Branch: INST_CNT(3);

        Jal, Jalr: INST_CNT(4);

        default: begin
          $display("[IDU] inst error 0x%08x at pc 0x%08x", ifu2exu.inst, ifu2exu.pc);
          $finish;
        end
      endcase
  end
`endif

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
        INSIDE(addr, 32'h8000_0000, 32'h81ff_ffff);  // SDRAM
  endfunction

  import "DPI-C" function void SKIP_DIFFTEST();

  always_ff @(posedge clock) begin
    if (curr == EXEC && ifu2exu.store) begin
      if (INSIDE_PERIP(axi_lsu.awaddr)) begin
        SKIP_DIFFTEST();
      end else if (INSIDE_MEM(axi_lsu.awaddr));
      else begin
        $display("[LSU] store addr error 0x%08x at pc 0x%08x", axi_lsu.awaddr, ifu2exu.pc);
        $finish;
      end
    end
    if (curr == EXEC && ifu2exu.load) begin
      if (INSIDE_PERIP(axi_lsu.araddr)) begin
        SKIP_DIFFTEST();
      end else if (INSIDE_MEM(axi_lsu.araddr));
      else begin
        $display("[LSU] load addr error 0x%08x at pc 0x%08x", axi_lsu.araddr, ifu2exu.pc);
        $finish;
      end
    end
  end
`endif
endmodule
