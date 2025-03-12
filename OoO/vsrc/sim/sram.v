module sram
  import OoO_pkg::*;
(
    input  logic       clock,
    input  logic       reset,
    input  axi_w_m2s_t sram_w_m2s,
    output axi_w_s2m_t sram_w_s2m,
    input  axi_r_m2s_t sram_r_m2s,
    output axi_r_s2m_t sram_r_s2m
);

  import "DPI-C" function int pmem_read(input int raddr);
  import "DPI-C" function void pmem_write(
    input int waddr,
    input int wdata,
    input int wmask
  );

  always_ff @(posedge clock) begin  // write / store
    if (reset) begin
      sram_w_s2m.awready <= 1;
      sram_w_s2m.wready  <= 1;
      sram_w_s2m.bvalid  <= 0;
    end else begin
      if (sram_w_m2s.awvalid && sram_w_m2s.wvalid) begin
        sram_w_s2m.awready <= 0;
        sram_w_s2m.wready  <= 0;
        sram_w_s2m.bvalid  <= 1;
        pmem_write(sram_w_m2s.awaddr, sram_w_m2s.wdata, {28'b0, sram_w_m2s.wstrb});
      end else if (sram_w_m2s.bready) begin
        sram_w_s2m.awready <= 1;
        sram_w_s2m.wready  <= 1;
        sram_w_s2m.bvalid  <= 0;
      end
    end
  end

  always_ff @(posedge clock) begin  // read / load
    if (reset) begin
      sram_r_s2m.arready <= 1;
      sram_r_s2m.rvalid  <= 0;
      sram_r_s2m.rlast <= 1;
    end else begin
      if (sram_r_m2s.arvalid) begin
        sram_r_s2m.arready <= 0;
        sram_r_s2m.rdata   <= pmem_read(sram_r_m2s.araddr);
        sram_r_s2m.rvalid  <= 1;
      end else if (sram_r_m2s.rready) begin
        sram_r_s2m.arready <= 1;
        sram_r_s2m.rvalid  <= 0;
      end
    end
  end
endmodule
