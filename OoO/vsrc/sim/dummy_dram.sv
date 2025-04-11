module dummy_dram
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic data_req_o,
    output logic data_gnt_i,
    output logic data_rvalid_i,

    input  logic [31:0] data_addr_o,
    input  logic        data_we_o,
    input  logic [ 3:0] data_be_o,
    input  logic [31:0] data_wdata_o,
    output logic [31:0] data_rdata_i
);

  import "DPI-C" function void ebreak();
  import "DPI-C" function int pmem_read(input int raddr);
  import "DPI-C" function void pmem_write_new(
    input int waddr,
    input int wdata,
    input int wmask
  );

  logic rden;

  always_ff @(posedge clock) begin
    if (reset) begin
      data_gnt_i <= 1'b0;
      data_rvalid_i <= 1'b0;
      data_rdata_i <= 32'b0;
      rden <= 1'b0;
    end else begin
      if (data_req_o) begin
        data_gnt_i <= 1'b1;
        rden <= ~data_we_o;
        if (data_we_o) pmem_write_new(data_addr_o, data_wdata_o, {28'b0, data_be_o});
        data_rdata_i <= pmem_read(data_addr_o);
        if (data_addr_o == 32'h87ff_fff4 && data_wdata_o == 32'h12345678) begin
          $display("[HTIF] finish call");
`ifdef SIM_MODE
          ebreak();
`else
          $finish;
`endif
        end
      end else begin
        data_gnt_i <= 1'b0;
      end
      if (rden) begin
        data_rvalid_i <= 1'b1;
        rden <= 1'b0;
      end else begin
        data_rvalid_i <= 1'b0;
      end
      if (data_req_o && data_gnt_i && data_addr_o == 32'h87ff_fff0) $write("%c", data_wdata_o[7:0]);
    end
  end

endmodule
