module ideal_itcm
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_frontend,

    input  logic [31:0] fetch_addr,
    output logic [31:0] ic_val,
    output logic [31:0] ic_addr,

    input  logic ifu2icu_valid,
    input  logic ifu2icu_ready,
    output logic icu2ifu_valid,
    output logic icu2ifu_ready,

    output logic icache_hit,
    output logic icache_miss,
    output logic icache_skip,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m
);

  import "DPI-C" function int pmem_read(input int raddr);

  always_ff @(posedge clock) begin
    if (reset) begin
      icu2ifu_ready <= 1'b1;
      icu2ifu_valid <= 1'b0;
      ic_val <= 32'b0;
      ic_addr <= 32'b0;
    end else begin
      if (ifu2icu_valid & icu2ifu_ready & !flush_frontend) begin
        icu2ifu_ready <= 1'b0;
        icu2ifu_valid <= 1'b1;
        ic_val <= pmem_read(fetch_addr);
        ic_addr <= fetch_addr;
      end else begin
        icu2ifu_ready <= 1'b1;
        icu2ifu_valid <= 1'b0;
      end
    end
  end

  always_comb begin
    ifu_r_m2s.arsize = 3'd2;
    ifu_r_m2s.arburst = 2'b10;
    ifu_r_m2s.arvalid = 1'b0;
    ifu_r_m2s.rready = 1'b0;
    ifu_r_m2s.araddr = 32'b0;
    ifu_r_m2s.arlen = 8'h0;
    icache_hit = 1'b0;
    icache_miss = 1'b0;
    icache_skip = 1'b0;
  end

endmodule
