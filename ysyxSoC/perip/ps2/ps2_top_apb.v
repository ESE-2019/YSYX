module ps2_top_apb (
    input  logic        clock,
    input  logic        reset,
    input  logic [31:0] in_paddr,
    input  logic        in_psel,
    input  logic        in_penable,
    input  logic [ 2:0] in_pprot,
    input  logic        in_pwrite,
    input  logic [31:0] in_pwdata,
    input  logic [ 3:0] in_pstrb,
    output logic        in_pready,
    output logic [31:0] in_prdata,
    output logic        in_pslverr,

    input logic ps2_clk,
    input logic ps2_data
);

  assign in_pslverr = 1'b0;

  reg [9:0] buffer;
  reg [7:0] fifo[7:0];
  reg [2:0] w_ptr, r_ptr;
  reg [3:0] count;
  reg [2:0] ps2_clk_sync;

  always @(posedge clock) ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
  wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

  always @(posedge clock) begin
    if (reset) begin
      count <= 0;
      w_ptr <= 0;
      r_ptr <= 0;
    end else begin
      if (in_psel & in_penable & !in_pready) begin
        in_pready <= 1'b1;
        if (w_ptr == r_ptr) begin
          in_prdata <= 32'b0;
        end else begin
          r_ptr <= r_ptr + 3'b1;
          in_prdata <= {24'b0, fifo[r_ptr]};
        end
      end else begin
        in_pready <= 1'b0;
      end

      if (sampling) begin
        if (count == 4'd10) begin
          if ((buffer[0] == 0) && (ps2_data) && (^buffer[9:1])) begin
            fifo[w_ptr] <= buffer[8:1];
            w_ptr <= w_ptr + 3'b1;
          end
          count <= 0;
        end else begin
          buffer[count] <= ps2_data;
          if (count == 0 && ps2_data == 1) count <= 0;
          else count <= count + 3'b1;
        end
      end
    end
  end

endmodule
