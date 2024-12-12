module ysyx_24080006_id_stage
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] inst,
    output logic [31:0] idu_dbg_inst,
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

    input logic forward_en,
    input logic [31:0] forward_data,

    input  logic   exu2idu_ready,
    output logic   idu2ifu_ready,
    input  stage_t ifu2idu,
    output stage_t idu2exu
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
      idu2exu.is_zc <= 1'b0;
      idu2exu.flush <= 1'b0;
      csr_wdata <= 32'b0;
      detect_hazard_q <= 2'b0;
    end else begin
      unique case (curr)
        ID_IDLE: begin
          if (ifu2idu.valid) begin
            decoder <= idu;
            idu2exu.pc <= ifu2idu.pc;
            idu2exu.alu_a <= alu_a;
            idu2exu.alu_b <= alu_b;
            idu2exu.rs1_data <= rs1_data;  //for jalr
            idu2exu.rs2_data <= rs2_data;  //for store
            idu2exu.csr_rdata <= csr_rdata;
            idu2exu.is_zc <= ifu2idu.is_zc;
            idu2exu.flush <= ifu2idu.flush;
            csr_wdata <= rs1_data;
            detect_hazard_q <= detect_hazard_d;
            fwd_jalr <= inst[6:0] == JALR;
            fwd_store <= inst[6:0] == STORE;
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
          idu2exu.is_zc <= 1'b0;
          idu2exu.flush <= 1'b0;
          csr_wdata <= 32'b0;
          detect_hazard_q <= 2'b0;
        end
      endcase
    end
  end

  logic inst_err;
  ysyx_24080006_idu IDU (.*);
  wire illegal_inst = inst_err | ifu2idu.zc_err;

  assign rs1_addr = idu.rs1_addr;
  assign rs2_addr = idu.rs2_addr;
  assign csr_name = idu.csr_name;

  always_comb begin
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
  end

  always_comb begin
    detect_hazard_d = 2'b0;
    if (rd_addr != '0 && !forward_en) begin
      detect_hazard_d[0] = rd_addr == rs1_addr;
      detect_hazard_d[1] = rd_addr == rs2_addr;
    end
  end

`ifdef SIM_MODE
  always_ff @(posedge clock) begin
    if (ifu2idu.valid && idu2ifu_ready) begin
      if (illegal_inst) begin
        $display("[IDU] inst error 0x%08x at pc 0x%08x", inst, ifu2idu.pc);
        $finish;
      end
    end
  end
`endif
endmodule
