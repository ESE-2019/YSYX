module ysyx_24080006_csr
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input csr_set_t csr_set,
    input csr_name_e csr_name,
    input logic [31:0] csr_pc,

    input logic instret,

    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  wire [31:0] csr_cause = 32'd11;
  logic [31:0] csr_reg[8];
  logic [31:0] minstret_low_q, minstret_low_d, minstret_high_q, minstret_high_d;
  always_comb begin
    case (csr_name)
      minstret:  csr_rdata = minstret_low_q;
      minstreth: csr_rdata = minstret_high_q;
      default:   csr_rdata = csr_reg[csr_name];
    endcase
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      csr_reg[mstatus] <= 32'h1800;
      csr_reg[mtvec] <= '0;
      csr_reg[mepc] <= '0;
      csr_reg[mcause] <= '0;
      csr_reg[mvendorid] <= 32'h79737978;
      csr_reg[marchid] <= 32'd24080006;
    end else begin
      if (ecall) begin
        csr_reg[mstatus] <= 32'h1800;
        csr_reg[mcause] <= csr_cause;
        csr_reg[mepc] <= csr_pc;
      end else if (mret) begin
        csr_reg[mstatus] <= 32'h1800;
      end else if (csr_set.csr_enable) begin
        //$display("csr_%d en_%d wdata 0x%08x at pc 0x%08x", csr_name, csr_set.csr_op, csr_wdata, csr_pc);
        unique case (csr_set.csr_op)
          READ: csr_reg[csr_name] <= csr_reg[csr_name];
          WRITE: csr_reg[csr_name] <= csr_wdata;
          SET: csr_reg[csr_name] <= csr_wdata | csr_reg[csr_name];
          CLEAR: csr_reg[csr_name] <= ~csr_wdata & csr_reg[csr_name];
          default: csr_reg[csr_name] <= csr_reg[csr_name];
        endcase
      end
    end
  end

  always_comb begin
    minstret_low_d  = minstret_low_q;
    minstret_high_d = minstret_high_q;
    if (instret) begin
      {minstret_high_d, minstret_low_d} = {minstret_high_q, minstret_low_q} + 64'b1;
    end
  end
  always_ff @(posedge clock) begin
    if (reset) begin
      minstret_high_q <= 32'b0;
      minstret_low_q  <= 32'b0;
    end else begin
      minstret_high_q <= minstret_high_d;
      minstret_low_q  <= minstret_low_d;
    end
  end

endmodule
