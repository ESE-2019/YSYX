module ysyx_24080006_csr
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input csr_set_t csr_set,
    input system_e csr_name,
    input logic [31:0] csr_pc,

    input logic instret,

    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  logic [31:0] csr_wdata_masked;
  logic illegal_csr;

  wire [31:0] csr_cause = 32'd11;

  logic [31:0] mstatus_q, mstatus_d;
  logic mstatus_en;
  logic [31:0] mtvec_q, mtvec_d;
  logic mtvec_en;
  logic [31:0] mepc_q, mepc_d;
  logic mepc_en;
  logic [31:0] mcause_q, mcause_d;
  logic mcause_en;
  logic [31:0] mcycle_low_q, mcycle_low_d;
  logic [31:0] minstret_low_q, minstret_low_d;
  logic [31:0] mcycle_high_q, mcycle_high_d;
  logic [31:0] minstret_high_q, minstret_high_d;

  always_comb begin
    csr_rdata   = 32'b0;
    illegal_csr = 1'b0;
    unique case (csr_name)
      MSTATUS:   csr_rdata = mstatus_q;
      MTVEC:     csr_rdata = mtvec_q;
      MEPC:      csr_rdata = mepc_q;
      MCAUSE:    csr_rdata = mcause_q;
      MCYCLE:    csr_rdata = mcycle_low_q;
      MINSTRET:  csr_rdata = minstret_low_q;
      MCYCLEH:   csr_rdata = mcycle_high_q;
      MINSTRETH: csr_rdata = minstret_high_q;
      MVENDORID: csr_rdata = 32'h79737978;
      MARCHID:   csr_rdata = 32'd24080006;
      default:   illegal_csr = 1'b1;
    endcase
  end


  always_comb begin
    unique case (csr_set.csr_op)
      READ:    csr_wdata_masked = csr_wdata;
      WRITE:   csr_wdata_masked = csr_wdata;
      SET:     csr_wdata_masked = csr_wdata | csr_rdata;
      CLEAR:   csr_wdata_masked = ~csr_wdata & csr_rdata;
      default: csr_wdata_masked = csr_wdata;
    endcase
  end

  wire csr_we = csr_set.csr_enable & ~illegal_csr & csr_set.csr_op inside {WRITE, SET, CLEAR};

  always_comb begin
    mstatus_en = 1'b0;
    mtvec_en = 1'b0;
    mepc_en = 1'b0;
    mcause_en = 1'b0;
    if (csr_we) begin
      unique case (csr_name)
        MSTATUS: mstatus_en = 1'b1;
        MTVEC:   mtvec_en = 1'b1;
        MEPC:    mepc_en = 1'b1;
        MCAUSE:  mcause_en = 1'b1;
        default: ;
      endcase
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      mstatus_q <= 32'h1800;
    end else begin
      if (ecall) begin
        mstatus_q <= 32'h1800;
        mcause_q <= csr_cause;
        mepc_q <= csr_pc;
      end else if (mret) begin
        mstatus_q <= 32'h1800;
      end else begin
        if (mstatus_en) mstatus_q <= csr_wdata_masked;
        if (mtvec_en) mtvec_q <= csr_wdata_masked;
        if (mepc_en) mepc_q <= csr_wdata_masked;
        if (mcause_en) mcause_q <= csr_wdata_masked;
      end
    end
  end

  always_comb begin
    mcycle_high_d  = mcycle_high_q;
    mcycle_low_d = mcycle_low_q;
    if (1) begin
      {mcycle_high_d, mcycle_low_d} = {mcycle_high_q, mcycle_low_q} + 64'b1;
    end
  end
  always_ff @(posedge clock) begin
    if (reset) begin
      mcycle_high_q <= 32'b0;
      mcycle_low_q  <= 32'b0;
    end else begin
      mcycle_high_q <= mcycle_high_d;
      mcycle_low_q  <= mcycle_low_d;
    end
  end

  always_comb begin
    minstret_high_d = minstret_high_q;
    minstret_low_d  = minstret_low_q;
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
