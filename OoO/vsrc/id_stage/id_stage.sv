`default_nettype none

module id_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] pc,
    input logic [31:0] inst,
    output decoder_t idu2isu_instr,

    input  logic isu2idu_ready,
    output logic idu2ifu_ready,
    input  logic ifu2idu_valid,
    output logic idu2isu_valid
);

  typedef enum logic [1:0] {
    ID_IDLE,
    ID_WAIT
  } id_fsm_e;
  id_fsm_e curr, next;

  logic     [31:0] instr;
  logic            is_rv16;
  logic            rv16_err;
  logic            rv32_err;
  decoder_t        decoded_instr;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= ID_IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      ID_IDLE: begin
        if (ifu2idu_valid) begin
          next = ID_WAIT;
        end else begin
          next = curr;
        end
      end
      ID_WAIT: begin
        if (isu2idu_ready) begin
          next = ID_IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = ID_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3
    if (reset) begin
      idu2ifu_ready <= 1'b0;
      idu2isu_valid <= 1'b0;
      idu2isu_instr <= '0;
    end else begin
      unique case (curr)
        ID_IDLE: begin
          if (ifu2idu_valid) begin
            idu2ifu_ready <= 1'b0;
            idu2isu_valid <= 1'b1;
            idu2isu_instr <= decoded_instr;
          end else begin
            idu2ifu_ready <= 1'b1;
            idu2isu_valid <= 1'b0;
          end
        end
        ID_WAIT: begin
          if (isu2idu_ready) begin
            idu2ifu_ready <= 1'b1;
            idu2isu_valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2isu_valid <= 1'b1;
          end
        end
        default: begin
          idu2ifu_ready <= 1'b0;
          idu2isu_valid <= 1'b0;
        end
      endcase
    end
  end

  rv16_decoder RV16 (.*);
  rv32_decoder RV32 (.*);

`ifdef SIM_MODE
  always_ff @(posedge clock) begin
    if (ifu2idu_valid && idu2ifu_ready) begin
      if (rv32_err) begin
        $display("[IDU] inst error 0x%08x at pc 0x%08x", inst, pc);
        $finish;
      end
    end
  end
`endif
endmodule

`default_nettype wire
