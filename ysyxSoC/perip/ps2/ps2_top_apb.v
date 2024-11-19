module ps2_top_apb (
    input  logic        clock,
    input  logic        reset,
    input  logic [31:0] in_paddr,    // neglect
    input  logic        in_psel,
    input  logic        in_penable,
    input  logic [ 2:0] in_pprot,
    input  logic        in_pwrite,
    input  logic [31:0] in_pwdata,   // neglect
    input  logic [ 3:0] in_pstrb,
    output logic        in_pready,
    output logic [31:0] in_prdata,
    output logic        in_pslverr,

    input logic ps2_clk,
    input logic ps2_data
);

  assign in_pslverr = 1'b0;

  logic [7:0] data, tmp;
  logic clk, clrn, ready, nextdata_n, overflow, hold;
  ps2_keyboard PS2 (.*);
  assign clk = clock;
  always @(posedge clock) begin
    if (reset) begin
      clrn <= 0;
    end else begin
      if (overflow) clrn <= 0;
      else clrn <= 1;
    end
  end

  assign nextdata_n = 0;
  assign in_pready  = 1;

  always @(posedge clock) begin
    if (reset) begin
      tmp  <= 8'h00;
      hold <= 1'b0;
    end else begin
      if (ready == 1 && overflow == 0) begin
        tmp <= data;
        if (hold) in_prdata <= {24'b0, data};
        else in_prdata <= 0;
        if (tmp != data) begin
          if (tmp == 8'hf0) begin
            hold <= 1'b0;
          end else hold <= 1'b1;
        end
      end else if (hold == 0) begin
        tmp <= 8'h00;
        in_prdata <= 0;
      end
    end
  end

endmodule

module ps2_keyboard (
    clk,
    clrn,
    ps2_clk,
    ps2_data,
    data,
    ready,
    nextdata_n,
    overflow
);
  input clk, clrn, ps2_clk, ps2_data;
  input nextdata_n;
  output [7:0] data;
  output reg ready;
  output reg overflow;  // fifo overflow
  // internal signal, for test
  reg [9:0] buffer;  // ps2_data bits
  reg [7:0] fifo                     [7:0];  // data fifo
  reg [2:0] w_ptr, r_ptr;  // fifo write and read pointers
  reg [3:0] count;  // count ps2_data bits
  // detect falling edge of ps2_clk
  reg [2:0] ps2_clk_sync;

  always @(posedge clk) begin
    ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
  end

  wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];  //sample negedge of ps2_clk

  always @(posedge clk) begin
    if (clrn == 0) begin  // reset
      count <= 0;
      w_ptr <= 0;
      r_ptr <= 0;
      overflow <= 0;
      ready <= 0;
    end else begin
      if (ready) begin  // read to output next data
        if(nextdata_n == 1'b0) //read next data
                begin
          r_ptr <= r_ptr + 3'b1;
          if (w_ptr == (r_ptr + 1'b1))  //empty
            ready <= 1'b0;
        end
      end

      if (sampling) begin
        if (count == 4'd10) begin
          if ((buffer[0] == 0) &&  // start bit
              (ps2_data) &&  // stop bit
              (^buffer[9:1])) begin  // odd  parity
            fifo[w_ptr] <= buffer[8:1];  // kbd scan code
            w_ptr <= w_ptr + 3'b1;
            ready <= 1'b1;
            overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
          end
          count <= 0;  // for next
        end else begin
          buffer[count] <= ps2_data;  // store ps2_data
          count <= count + 3'b1;
        end
      end
    end
  end
  assign data = fifo[r_ptr];  //always set output data

endmodule
