module seg(
  input clk,
  input rst,
  input [31:0] data,
  output [7:0] o_seg0,
  output [7:0] o_seg1,
  output [7:0] o_seg2,
  output [7:0] o_seg3,
  output [7:0] o_seg4,
  output [7:0] o_seg5,
  output [7:0] o_seg6,
  output [7:0] o_seg7
);

wire [7:0] segs [15:0];
assign segs[0] = 8'b1111_1100;
assign segs[1] = 8'b0110_0000;
assign segs[2] = 8'b1101_1010;
assign segs[3] = 8'b1111_0010;
assign segs[4] = 8'b0110_0110;
assign segs[5] = 8'b1011_0110;
assign segs[6] = 8'b1011_1110;
assign segs[7] = 8'b1110_0000;
assign segs[8] = 8'b1111_1110;
assign segs[9] = 8'b1111_0110;
assign segs[10] = 8'b1110_1110;
assign segs[11] = 8'b0011_1110;
assign segs[12] = 8'b1001_1100;
assign segs[13] = 8'b0111_1010;
assign segs[14] = 8'b1001_1110;
assign segs[15] = 8'b1000_1110;

assign o_seg0 = ~segs[data[3:0]];
assign o_seg1 = ~segs[data[7:4]];
assign o_seg2 = ~segs[data[11:8]];
assign o_seg3 = ~segs[data[15:12]];
assign o_seg4 = ~segs[data[19:16]];
assign o_seg5 = ~segs[data[23:20]];
assign o_seg6 = ~segs[data[27:24]];
assign o_seg7 = ~segs[data[31:28]];

endmodule
