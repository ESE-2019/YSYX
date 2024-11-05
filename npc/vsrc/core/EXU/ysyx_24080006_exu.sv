module ysyx_24080006_exu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic   lsu2exu_ready,
    output logic   exu2idu_ready,
    input  stage_t idu2exu,
    output stage_t exu2lsu
);

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
        if (idu2exu.valid) next = EXEC;
        else next = IDLE;
      end
      EXEC, WAIT: begin
        if (lsu2exu_ready) next = IDLE;
        else next = WAIT;
      end
    endcase
  end

  always_ff @(posedge clock) begin  //fsm 3 for control
    unique if (reset) begin
      exu2idu_ready <= 1;
      exu2lsu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (idu2exu.valid) begin
            exu2idu_ready <= 0;
            exu2lsu.valid <= 1;
          end else begin
            exu2idu_ready <= 1;
            exu2lsu.valid <= 0;
          end
        end
        EXEC, WAIT: begin
          if (lsu2exu_ready) begin
            exu2idu_ready <= 1;
            exu2lsu.valid <= 0;
          end else begin
            exu2idu_ready <= 0;
            exu2lsu.valid <= 1;
          end
        end
      endcase
    end
  end

  logic [31:0] alu_res;

  ysyx_24080006_alu ALU (
      .*,
      .alu_src1(idu2exu.alu_src1),
      .alu_src2(idu2exu.alu_src2),
      .alu_op  (idu2exu.alu_op)
  );

  wire branch = idu2exu.branch & alu_res[0];

`ifdef SIM_MODE
  import "DPI-C" function void EXU_CNT();
`endif
  always_ff @(posedge clock) begin
    if (reset) begin
      exu2lsu.dnpc <= '0;
      exu2lsu.sdata <= '0;
      exu2lsu.rd_addr <= '0;
      exu2lsu.alu_res <= '0;
      exu2lsu.funct3 <= '0;
      exu2lsu.load <= '0;
      exu2lsu.store <= '0;
      exu2lsu.wb <= '0;
      exu2lsu.jump <= '0;
      exu2lsu.branch <= '0;
      exu2lsu.csr_addr <= '0;
      exu2lsu.csr_we <= '0;
      exu2lsu.csr_wdata <= '0;
      exu2lsu.ecall <= '0;
      exu2lsu.pc <= '0;
    end else if (curr == IDLE && idu2exu.valid) begin
      exu2lsu.dnpc <= idu2exu.dnpc;
      exu2lsu.sdata <= idu2exu.sdata;
      exu2lsu.rd_addr <= idu2exu.rd_addr;
      exu2lsu.alu_res <= alu_res;
      exu2lsu.funct3 <= idu2exu.funct3;
      exu2lsu.load <= idu2exu.load;
      exu2lsu.store <= idu2exu.store;
      exu2lsu.wb <= idu2exu.wb;
      exu2lsu.jump <= idu2exu.jump;
      exu2lsu.branch <= branch;
      exu2lsu.csr_addr <= idu2exu.csr_addr;
      exu2lsu.csr_we <= idu2exu.csr_we;
      exu2lsu.csr_wdata <= idu2exu.csr_wdata;
      exu2lsu.ecall <= idu2exu.ecall;
      exu2lsu.pc <= idu2exu.pc;
`ifdef SIM_MODE
      EXU_CNT();
`endif
    end
  end

endmodule
