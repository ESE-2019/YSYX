module ysyx_24080006_id_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] inst,
    output decoder_t decoder,
    output logic fencei,

    output logic [REG_WIDTH-1:0] rs1_addr,
    output logic [REG_WIDTH-1:0] rs2_addr,
    input  logic [         31:0] rs1_data,
    input  logic [         31:0] rs2_data,

    input  logic   exu2idu_ready,
    output logic   idu2ifu_ready,
    input  stage_t ifu2idu,
    output stage_t idu2exu
);

  typedef enum logic {
    IDLE,
    EXEC
  } id_fsm_e;
  id_fsm_e curr, next;

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
        if (ifu2idu.valid) begin
          next = EXEC;
        end else begin
          next = IDLE;
        end
      end
      EXEC: begin
        if (exu2idu_ready) begin
          next = IDLE;
        end else begin
          next = EXEC;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      idu2ifu_ready <= 1'b1;
      idu2exu.valid <= 1'b0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2idu.valid) begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
          end else begin
            idu2ifu_ready <= 1'b1;
            idu2exu.valid <= 1'b0;
          end
        end
        EXEC: begin
          if (exu2idu_ready) begin
            idu2ifu_ready <= 1'b1;
            idu2exu.valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
          end
        end
      endcase
    end
  end  // fsm 3 for handshake

  decoder_t idu;

  always_ff @(posedge clock) begin  // fsm 3 for icu
    if (reset) begin
      decoder <= idu;
      idu2exu.pc <= ifu2idu.pc;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2idu.valid) begin
            decoder <= idu;
            idu2exu.pc <= ifu2idu.pc;
            idu2exu.rs1_data <= rs1_data;
            idu2exu.rs2_data <= rs2_data;
          end
        end
        EXEC: begin
        end
      endcase
    end
  end

  logic inst_err;
  ysyx_24080006_idu IDU (.*);
  assign rs1_addr = idu.rs1_addr;
  assign rs2_addr = idu.rs2_addr;

`ifdef SIM_MODE
  import "DPI-C" function void ebreak();
  import "DPI-C" function void INST_CNT(input int type_code);
  logic [31:0] ftrace, type_cnt, ifu_cnt;
  always_ff @(posedge clock) begin
    if (idu2exu.valid) begin
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
