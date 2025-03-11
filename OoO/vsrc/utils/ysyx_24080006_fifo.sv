module ysyx_24080006_fifo #(
    parameter int unsigned FIFO_DEPTH = 2,
    parameter int unsigned ADDR_DEPTH = $clog2(FIFO_DEPTH)
) (
    input logic clock,
    input logic reset,
    input logic fifo_flush,
    input logic fifo_wren,
    input logic fifo_rden,
    input logic [31:0] fifo_wdata,
    output logic [31:0] fifo_rdata,
    output logic fifo_full,
    output logic fifo_empty,
    output logic [ADDR_DEPTH:0] fifo_data_avail
);

  logic [ADDR_DEPTH - 1:0] rd_ptr_d, rd_ptr_q, wr_ptr_d, wr_ptr_q;
  logic [ADDR_DEPTH:0] num_entries_d, num_entries_q;
  logic [31:0] fifo_ram[FIFO_DEPTH];

  assign fifo_rdata = fifo_ram_q[rd_ptr_q];
  assign fifo_data_avail = num_entries_q;
  assign fifo_full = num_entries_q == (ADDR_DEPTH + 1)'(FIFO_DEPTH);
  assign fifo_empty = num_entries_q == 0;


  always_comb begin
    num_entries_d = num_entries_q;
    if (fifo_wren && fifo_rden && ~fifo_full && ~fifo_empty) begin
      num_entries_d = num_entries_q;
    end else if (fifo_wren && ~fifo_full) begin
      num_entries_d = num_entries_q + 1;
    end else if (fifo_rden && ~fifo_empty) begin
      num_entries_d = num_entries_q - 1;
    end
  end

  always_comb begin
    rd_ptr_d = rd_ptr_q;
    if (fifo_rden && ~fifo_empty) begin
      if (rd_ptr_d == ADDR_DEPTH'(FIFO_DEPTH - 1)) rd_ptr_d = '0;
      else rd_ptr_d = rd_ptr_q + 1;
    end
  end

  always_comb begin
    wr_ptr_d = wr_ptr_q;
    if (fifo_wren && ~fifo_full) begin
      if (wr_ptr_q == ADDR_DEPTH'(FIFO_DEPTH - 1)) wr_ptr_d = '0;
      else wr_ptr_d = wr_ptr_q + 1;
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      rd_ptr_q <= '0;
      wr_ptr_q <= '0;
      num_entries_q <= '0;
    end else begin
      if (fifo_flush) begin
        rd_ptr_q <= '0;
        wr_ptr_q <= '0;
        num_entries_q <= '0;
      end else begin
        rd_ptr_q <= rd_ptr_d;
        wr_ptr_q <= wr_ptr_d;
        num_entries_q <= num_entries_d;
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      foreach (fifo_ram[i]) fifo_ram[i] <= '0;
    end else begin
      if (fifo_wren && ~fifo_full) begin
        fifo_ram[wr_ptr_q] <= fifo_wdata;
      end
    end
  end

endmodule
