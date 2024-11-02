module ysyx_24080006_wbu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic [ 4:0] rd,
    output logic [31:0] wdata,
    output logic        we,

    output logic        csr_we,
    output logic [11:0] csr_waddr,
    output logic [31:0] csr_wdata,

    input  logic   ifu2wbu_ready,
    output logic   wbu2lsu_ready,
    input  stage_t lsu2wbu,
    output stage_t wbu2ifu
);

  typedef enum logic [1:0] {
    IDLE,
    EXEC,
    WAIT,
    RST
  } WBU_STATE;
  WBU_STATE curr, next;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= RST;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (lsu2wbu.valid) next = EXEC;
        else next = IDLE;
      end
      EXEC, WAIT: begin
        if (ifu2wbu_ready) next = IDLE;
        else next = WAIT;
      end
      RST: next = IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  //fsm 3 for control
    unique if (reset) begin
      wbu2lsu_ready <= 0;
      wbu2ifu.valid <= 0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (lsu2wbu.valid) begin
            wbu2lsu_ready <= 0;
            wbu2ifu.valid <= 1;
          end else begin
            wbu2lsu_ready <= 1;
            wbu2ifu.valid <= 0;
          end
        end
        EXEC, WAIT: begin
          if (ifu2wbu_ready) begin
            wbu2lsu_ready <= 1;
            wbu2ifu.valid <= 0;
          end else begin
            wbu2lsu_ready <= 0;
            wbu2ifu.valid <= 1;
          end
        end
        RST: begin
          wbu2lsu_ready <= 0;
          wbu2ifu.valid <= 1;
        end
      endcase
    end
  end

  always_ff @(posedge clock) begin  //fsm 3 for exu output
    unique if (reset) begin
      rd <= '0;
      wdata <= '0;
      we <= '0;
      csr_we <= '0;
      csr_waddr <= '0;
      csr_wdata <= '0;
    end else begin
      if (curr == IDLE && lsu2wbu.valid) begin
        if (lsu2wbu.wb) begin  // TODO unnecessary?
          rd <= lsu2wbu.rd_addr;
          wdata <= lsu2wbu.alu_res;
          we <= lsu2wbu.wb;
        end else if (lsu2wbu.csr_we) begin
          rd <= lsu2wbu.rd_addr;
          wdata <= lsu2wbu.csr_wdata;
          we <= 1'b1;
          csr_we <= lsu2wbu.csr_we;
          csr_waddr <= lsu2wbu.csr_addr;
          csr_wdata <= lsu2wbu.alu_res;
        end else if (lsu2wbu.ecall) begin
          csr_we <= 1'b1;  //lsu2wbu.csr_we;
          csr_waddr <= 12'h342;
          csr_wdata <= 32'd11;
        end else begin
          rd <= '0;
          wdata <= '0;
          we <= '0;
          csr_we <= '0;
          csr_waddr <= '0;
          csr_wdata <= '0;
        end
      end else begin
        rd <= '0;
        wdata <= '0;
        we <= '0;
        csr_we <= '0;
        csr_waddr <= '0;
        csr_wdata <= '0;
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      wbu2ifu.dnpc <= '0;
      wbu2ifu.jump <= '0;
      wbu2ifu.branch <= '0;
      wbu2ifu.rd_addr <= '0;
    end else if (curr == IDLE && lsu2wbu.valid) begin
      wbu2ifu.dnpc <= lsu2wbu.dnpc;
      wbu2ifu.jump <= lsu2wbu.jump;
      wbu2ifu.branch <= lsu2wbu.branch;
      wbu2ifu.rd_addr <= (lsu2wbu.wb) ? lsu2wbu.rd_addr : '0;
    end

  end

endmodule
