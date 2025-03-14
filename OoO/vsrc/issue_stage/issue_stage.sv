`default_nettype none

module issue_stage
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic   exu2idu_ready,
    output logic   idu2ifu_ready,
    input  stage_t ifu2idu,
    output stage_t idu2exu,

    output decoder_t issue_instr,
    output decoder_t commit_instr,
    input  logic     commit_valid,
    input  decoder_t idu2isu_instr,
    input  logic     idu2isu_valid,
    output logic     isu2idu_ready,

    output fu_data_t                  fu_data,
    output logic               [31:0] pc_o,
    output logic                      is_rv16,
    input  logic                      flu_ready_i,
    output logic                      alu_valid_o,
    output logic                      branch_valid_o,
    output branchpredict_sbe_t        branch_predict_o,
    input  logic                      lsu_ready_i,
    output logic                      lsu_valid_o,
    output logic                      mdu_valid,
    output logic                      csr_valid_o,

    input writeback_t [WriteBackPorts-1:0]                      wb,
    input logic       [WriteBackPorts-1:0][ScoreboardIndex-1:0] wb_idx,
    input logic       [WriteBackPorts-1:0][               31:0] wb_data,
    input logic       [WriteBackPorts-1:0]                      wb_valid
);

  typedef enum logic [1:0] {
    ID_IDLE,
    ID_WAIT,
    ID_HAZARD
  } id_fsm_e;
  id_fsm_e curr, next;

  logic [1:0] detect_hazard_q, detect_hazard_d;
  logic fwd_jalr, fwd_store;
  wire [31:0] ifu2idu_pc = ifu2idu.pc;

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
        if (ifu2idu.valid) begin
          if (|detect_hazard_d) begin
            next = ID_HAZARD;
          end else begin
            next = ID_WAIT;
          end
        end else begin
          next = curr;
        end
      end
      ID_WAIT: begin
        if (exu2idu_ready) begin
          next = ID_IDLE;
        end else begin
          next = curr;
        end
      end
      ID_HAZARD: begin
        if (!forward_en) begin
          next = curr;
        end else begin
          next = ID_WAIT;
        end
      end
      default: next = ID_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      idu2ifu_ready <= 1'b0;
      idu2exu.valid <= 1'b0;
    end else begin
      unique case (curr)
        ID_IDLE: begin
          if (ifu2idu.valid) begin
            if (|detect_hazard_d) begin
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
        ID_WAIT: begin
          if (exu2idu_ready) begin
            idu2ifu_ready <= 1'b1;
            idu2exu.valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
          end
        end
        ID_HAZARD: begin
          if (!forward_en) begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b0;
          end else begin
            idu2ifu_ready <= 1'b0;
            idu2exu.valid <= 1'b1;
            // $display("%d: 0x%08x", rs1_addr, rs1_data);
            // $display("%d: 0x%08x", rs2_addr, rs2_data);
          end
        end
        default: begin
          idu2ifu_ready <= 1'b0;
          idu2exu.valid <= 1'b0;
        end
      endcase
    end
  end  // fsm 3 for handshake

  decoder_t idu;
  logic [31:0] alu_a, alu_b;

  always_ff @(posedge clock) begin  // fsm 3 for pipeline
    if (reset) begin
      decoder <= '0;
      idu2exu.pc <= 32'b0;
      idu2exu.alu_a <= 32'b0;
      idu2exu.alu_b <= 32'b0;
      idu2exu.rs1_data <= 32'b0;
      idu2exu.rs2_data <= 32'b0;
      idu2exu.csr_rdata <= 32'b0;
      idu2exu.rv16 <= 1'b0;
      idu2exu.flush <= 1'b0;
      csr_wdata <= 32'b0;
      detect_hazard_q <= 2'b0;
    end else begin
      unique case (curr)
        ID_IDLE: begin
          if (ifu2idu.valid) begin
            decoder <= idu;
            idu2exu.alu_a <= alu_a;
            idu2exu.alu_b <= alu_b;
            idu2exu.rs1_data <= rs1_data;  //for jalr
            idu2exu.rs2_data <= rs2_data;  //for store
            idu2exu.csr_rdata <= csr_rdata;
            csr_wdata <= rs1_data;
            detect_hazard_q <= detect_hazard_d;
            fwd_jalr <= inst[6:0] == riscv_instr::JALR[6:0];
            fwd_store <= inst[6:0] == riscv_instr::SB[6:0];
            idu_dbg_inst <= inst;
          end
        end
        ID_WAIT: begin
        end
        ID_HAZARD: begin  //if (!forward_en)
          if (detect_hazard_q[0]) begin
            if (fwd_jalr) idu2exu.rs1_data <= forward_data;
            else idu2exu.alu_a <= forward_data;
          end
          if (detect_hazard_q[1]) begin  //should not be else if
            if (fwd_store) idu2exu.rs2_data <= forward_data;
            else idu2exu.alu_b <= forward_data;
          end
        end
        default: begin
          decoder <= '0;
          idu2exu.pc <= 32'b0;
          idu2exu.alu_a <= 32'b0;
          idu2exu.alu_b <= 32'b0;
          idu2exu.rs1_data <= 32'b0;
          idu2exu.rs2_data <= 32'b0;
          idu2exu.csr_rdata <= 32'b0;
          idu2exu.rv16 <= 1'b0;
          idu2exu.flush <= 1'b0;
          csr_wdata <= 32'b0;
          detect_hazard_q <= 2'b0;
        end
      endcase
    end
  end



endmodule

`default_nettype wire
