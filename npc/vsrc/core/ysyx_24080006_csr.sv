module ysyx_24080006_csr (
    input logic clock,
    input logic reset,
    input logic csr_we,

    //tmp
    input logic [31:0] mepc_val,
    input logic        mepc_en,

    input  logic [11:0] csr_addr,
    input  logic [11:0] csr_waddr,
    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  logic [31:0] regfile[8];

  enum logic [2:0] {
    mstatus   = 3'b000,
    mtvec     = 3'b001,
    mepc      = 3'b010,
    mcause    = 3'b011,
    mvendorid = 3'b100,
    marchid   = 3'b101
  }
      csr_r, csr_w;

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

  assign csr_rdata = regfile[csr_r];

  always_ff @(posedge clock) begin
    if (reset) begin
      regfile[0] <= 32'h1800;
      regfile[1] <= '0;
      regfile[2] <= '0;
      regfile[3] <= '0;
      regfile[4] <= 32'h79737978;
      regfile[5] <= 32'd24080006;
      regfile[6] <= '0;
      regfile[7] <= '0;
    end else if (csr_we) begin
      regfile[csr_w] <= csr_wdata;
    end else if (mepc_en) begin
      regfile[mepc] <= mepc_val;
    end
  end
  // always_ff @(posedge clock) begin
  //     if (csr_we) begin
  //         $display("csr_we %d 0x%08x", csr_w, csr_wdata);
  //     end else if (mepc_en) begin
  //         $display("csr_mepc_en 0x%08x", mepc_val);
  //     end
  // end
endmodule
