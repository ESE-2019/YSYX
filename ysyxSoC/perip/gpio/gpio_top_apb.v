module gpio_top_apb(
  input  logic        clock,
  input  logic        reset,
  input  logic [31:0] in_paddr,
  input  logic        in_psel,
  input  logic        in_penable,
  input  logic [2:0]  in_pprot,
  input  logic        in_pwrite,
  input  logic [31:0] in_pwdata,
  input  logic [3:0]  in_pstrb, // TODO
  output logic        in_pready,
  output logic [31:0] in_prdata,
  output logic        in_pslverr,

  output logic [15:0] gpio_out,
  input  logic [15:0] gpio_in,
  output logic [7:0]  gpio_seg_0,
  output logic [7:0]  gpio_seg_1,
  output logic [7:0]  gpio_seg_2,
  output logic [7:0]  gpio_seg_3,
  output logic [7:0]  gpio_seg_4,
  output logic [7:0]  gpio_seg_5,
  output logic [7:0]  gpio_seg_6,
  output logic [7:0]  gpio_seg_7
);

assign in_pready = 1'b1;
assign in_pslverr = 1'b0;

logic [31:0] gpio [4];
assign gpio_out = gpio[0][15:0];
logic [7:0] segs [16];
assign segs[ 0] = 8'b1111_1100;
assign segs[ 1] = 8'b0110_0000;
assign segs[ 2] = 8'b1101_1010;
assign segs[ 3] = 8'b1111_0010;
assign segs[ 4] = 8'b0110_0110;
assign segs[ 5] = 8'b1011_0110;
assign segs[ 6] = 8'b1011_1110;
assign segs[ 7] = 8'b1110_0000;
assign segs[ 8] = 8'b1111_1110;
assign segs[ 9] = 8'b1111_0110;
assign segs[10] = 8'b1110_1110;
assign segs[11] = 8'b0011_1110;
assign segs[12] = 8'b1001_1100;
assign segs[13] = 8'b0111_1010;
assign segs[14] = 8'b1001_1110;
assign segs[15] = 8'b1000_1110;
assign gpio_seg_0 = ~segs[gpio[2][ 3-:4]];
assign gpio_seg_1 = ~segs[gpio[2][ 7-:4]];
assign gpio_seg_2 = ~segs[gpio[2][11-:4]];
assign gpio_seg_3 = ~segs[gpio[2][15-:4]];
assign gpio_seg_4 = ~segs[gpio[2][19-:4]];
assign gpio_seg_5 = ~segs[gpio[2][23-:4]];
assign gpio_seg_6 = ~segs[gpio[2][27-:4]];
assign gpio_seg_7 = ~segs[gpio[2][31-:4]];

logic [1:0] addr;
assign addr = in_paddr[3:2];
assign in_prdata = gpio[addr];

always_ff @ (posedge clock) begin
  if (reset) begin
    foreach (gpio[i])
      gpio[i] <= '0;
  end else if (in_psel && in_pwrite && in_penable) begin
    gpio[addr] <= in_pwdata;
  end else
    gpio[1] <= {16'b0, gpio_in};
end

endmodule
