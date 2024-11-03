module ysyx_24080006_csr (
    input logic clock,
    input logic reset,
    input logic csr_we,

    input logic [31:0] mepc_val,
    input logic        mepc_en,

    input  logic [11:0] csr_addr,
    input  logic [11:0] csr_waddr,
    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  logic [31:0] csr_reg[8];

  typedef enum logic [2:0] {
    mstatus   = 3'b000,
    mtvec     = 3'b001,
    mepc      = 3'b010,
    mcause    = 3'b011,
    mvendorid = 3'b100,
    marchid   = 3'b101
  } CSR;
  CSR csr_r, csr_w;

  always_comb begin
    unique case (csr_addr)
      12'h300: csr_r = mstatus;
      12'h305: csr_r = mtvec;
      12'h341: csr_r = mepc;
      12'h342: csr_r = mcause;
      12'hf11: csr_r = mvendorid;
      12'hf12: csr_r = marchid;
      default: csr_r = mstatus;
    endcase
  end

  always_comb begin
    unique case (csr_waddr)
      12'h300: csr_w = mstatus;
      12'h305: csr_w = mtvec;
      12'h341: csr_w = mepc;
      12'h342: csr_w = mcause;
      12'hf11: csr_w = mvendorid;
      12'hf12: csr_w = marchid;
      default: csr_w = mstatus;
    endcase
  end

  assign csr_rdata = csr_reg[csr_r];

  always_ff @(posedge clock) begin
    if (reset) begin
      csr_reg[0] <= 32'h1800;
      csr_reg[1] <= '0;
      csr_reg[2] <= '0;
      csr_reg[3] <= '0;
      csr_reg[4] <= 32'h79737978;
      csr_reg[5] <= 32'd24080006;
      csr_reg[6] <= '0;
      csr_reg[7] <= '0;
    end else if (csr_we) begin
      csr_reg[csr_w] <= csr_wdata;
    end else if (mepc_en) begin
      csr_reg[mepc] <= mepc_val;
    end
  end
endmodule
