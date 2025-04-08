module dummy_ram
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic data_req_o,
    input logic [31:0] data_addr_o,
    output logic data_gnt_i,
    output logic data_rvalid_i,
    output logic [31:0] data_rdata_i
);

  import "DPI-C" function int pmem_read(input int raddr);

  logic rden;
  localparam int CNT_W = 2;
  logic [CNT_W-1:0] cnt;

  always_ff @(posedge clock) begin
    if (reset) begin
      data_gnt_i <= 1'b0;
      data_rvalid_i <= 1'b0;
      data_rdata_i <= 32'b0;
      rden <= 1'b0;
      cnt <= '0;
    end else begin
      cnt <= cnt + {{CNT_W - 1{1'b0}}, {1'b1}};
      if (data_req_o && &cnt) begin
        data_gnt_i <= 1'b1;
        rden <= 1'b1;
        data_rdata_i <= pmem_read(data_addr_o);
      end else begin
        data_gnt_i <= 1'b0;
      end
      if (rden && &cnt) begin
        data_rvalid_i <= 1'b1;
        rden <= 1'b0;
      end else begin
        data_rvalid_i <= 1'b0;
      end
    end
  end

endmodule
