module ysyx_24080006_id_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] inst,
    output decoder_t decoder,
    output logic fencei,

    input  logic                 reg_we,
    input  logic [REG_WIDTH-1:0] rd_addr,
    output logic [REG_WIDTH-1:0] rs1_addr,
    output logic [REG_WIDTH-1:0] rs2_addr,
    input  logic [         31:0] rs1_data,
    input  logic [         31:0] rs2_data,

    output csr_name_e csr_name,
    output logic [31:0] csr_wdata,
    input logic [31:0] csr_rdata,

    input  logic   exu2idu_ready,
    output logic   idu2ifu_ready,
    input  stage_t ifu2idu,
    output stage_t idu2exu
);

  typedef enum logic [1:0] {
    IDLE,
    WAIT,
    HAZARD
  } id_fsm_e;
  id_fsm_e curr, next;

  logic detect_hazard_q, detect_hazard_d;

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
        if (ifu2idu.valid) begin
          if (detect_hazard_d) begin
            next = HAZARD;
          end else begin
            next = WAIT;
          end
        end else begin
          next = curr;
        end
      end
      WAIT: begin
        if (exu2idu_ready) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
      HAZARD: begin
        if (detect_hazard_d) begin
          next = curr;
        end else begin
          next = WAIT;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      idu2ifu_ready <= 1'b0;
      idu2exu.valid <= 1'b0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2idu.valid) begin
            if (detect_hazard_d) begin
              idu2ifu_ready <= 1'b0;
              //$display("detect hzd rd_%d rs1_%d rs2_%d", rd_addr, rs1_addr, rs2_addr);
              idu2exu.valid <= 1'b0;
            end else begin
              idu2ifu_ready <= 1'b0;
              idu2exu.valid <= 1'b1;
            end
          end else begin
            idu2ifu_ready <= 1'b1;
            idu2exu.valid <= 1'b0;
          end
        end
        WAIT: begin
          if (exu2idu_ready) begin
            idu2ifu_ready <= 1'b1;
            idu2exu.valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
          end
        end
        HAZARD: begin
          if (detect_hazard_d) begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
            // $display("%d: 0x%08x", rs1_addr, rs1_data);
            // $display("%d: 0x%08x", rs2_addr, rs2_data);
          end
        end
      endcase
    end
  end  // fsm 3 for handshake

  decoder_t idu;
  logic [31:0] dnpc, alu_a, alu_b;

  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      decoder <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2idu.valid) begin
            decoder <= idu;
            idu2exu.pc <= ifu2idu.pc;
            idu2exu.alu_a <= alu_a;
            idu2exu.alu_b <= alu_b;
            idu2exu.rs1_data <= rs1_data;
            idu2exu.rs2_data <= rs2_data;
            idu2exu.csr_rdata <= csr_rdata;
            idu2exu.is_zc <= ifu2idu.is_zc;
            idu2exu.flush <= ifu2idu.flush;
            csr_wdata <= rs1_data;
          end
        end
        WAIT: begin
        end
        HAZARD: begin
          idu2exu.alu_a <= alu_a;
          idu2exu.alu_b <= alu_b;
          idu2exu.rs1_data <= rs1_data;
          idu2exu.rs2_data <= rs2_data;
          csr_wdata <= rs1_data;
        end
      endcase
    end
  end

  logic inst_err;
  ysyx_24080006_idu IDU (.*);
  always_comb begin
    if (curr == IDLE) begin
      rs1_addr = idu.rs1_addr;
      rs2_addr = idu.rs2_addr;
      csr_name = idu.csr_name;
      unique case (idu.alu_set.alu_a)
        RS1:     alu_a = rs1_data;
        PC:      alu_a = ifu2idu.pc;
        CONST0:  alu_a = 32'b0;
        default: alu_a = 32'b0;
      endcase
      unique case (idu.alu_set.alu_b)
        IMM:     alu_b = idu.imm;
        RS2:     alu_b = rs2_data;
        PC_INCR: alu_b = ifu2idu.is_zc ? 32'h2 : 32'h4;
        CSR:     alu_b = csr_rdata;
        default: alu_b = 32'h4;
      endcase
    end else begin
      rs1_addr = decoder.rs1_addr;
      rs2_addr = decoder.rs2_addr;
      csr_name = decoder.csr_name;
      unique case (decoder.alu_set.alu_a)
        RS1:     alu_a = rs1_data;
        PC:      alu_a = idu2exu.pc;
        CONST0:  alu_a = 32'b0;
        default: alu_a = 32'b0;
      endcase
      unique case (decoder.alu_set.alu_b)
        IMM:     alu_b = decoder.imm;
        RS2:     alu_b = rs2_data;
        PC_INCR: alu_b = idu2exu.is_zc ? 32'h2 : 32'h4;
        CSR:     alu_b = csr_rdata;
        default: alu_b = 32'h4;
      endcase
    end
  end

  always_comb begin
    detect_hazard_d = 0;
    if (rd_addr != '0 && !reg_we) begin
      detect_hazard_d = rd_addr == rs1_addr || rd_addr == rs2_addr;
    end
  end

`ifdef SIM_MODE
  import "DPI-C" function void ebreak();
  import "DPI-C" function void INST_CNT(input int type_code);
  logic [31:0] ftrace, type_cnt, ifu_cnt;
  always_ff @(posedge clock) begin
    if (idu2exu.valid && exu2idu_ready) begin
      if (inst == EBREAK_INST) begin
        ebreak();
      end else if (inst_err) begin
        $display("[IDU] inst error 0x%08x at pc 0x%08x", inst, ifu2idu.pc);
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
