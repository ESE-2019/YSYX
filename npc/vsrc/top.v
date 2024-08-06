module top (
    input clk,
    input rst,
    input [4:0] btn,
    input [15:0] sw,
    input ps2_clk,
    input ps2_data,
    input uart_rx,
    output uart_tx,
    output [15:0] ledr,
    output VGA_CLK,
    output VGA_HSYNC,
    output VGA_VSYNC,
    output VGA_BLANK_N,
    output [7:0] VGA_R,
    output [7:0] VGA_G,
    output [7:0] VGA_B,
    output [7:0] seg0,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7
);
//v1
//assign ledr[0] = sw[1] ^ sw [0];
//v2
//light light(clk, rst, ledr);
//ex1
/*reg [1:0] ex1;
assign ledr[1:0]=ex1;
always@(*) begin
	ex1=0;
	case(sw[1:0])
		2'b00:	ex1=sw[3:2];
		2'b01:	ex1=sw[5:4];
		2'b10:	ex1=sw[7:6];
		2'b11:	ex1=sw[9:8];
		default:;
	endcase
end*/
//ex2
/*wire [7:0] segs [15:0];
assign segs[0] = 8'b1111_1100;
assign segs[1] = 8'b0110_0000;
assign segs[2] = 8'b1101_1010;
assign segs[3] = 8'b1111_0010;
assign segs[4] = 8'b0110_0110;
assign segs[5] = 8'b1011_0110;
assign segs[6] = 8'b1011_1110;
assign segs[7] = 8'b1110_0000;
reg [7:0] seg00;
assign seg0=~seg00;
always@(*) begin
seg00=0;
	if(sw[7]==1)	seg00=segs[7];
	else if(sw[6]==1)	seg00=segs[6];
	else if(sw[5]==1)	seg00=segs[5];
	else if(sw[4]==1)	seg00=segs[4];
	else if(sw[3]==1)	seg00=segs[3];
	else if(sw[2]==1)	seg00=segs[2];
	else if(sw[1]==1)	seg00=segs[1];
	else if(sw[0]==1)	seg00=segs[0];
end*/
//ex3 sel:sw[15:13] A:sw[7:4] B:sw[3:0] out:led[3:0]
/*reg signed [3:0] led;
assign ledr[3:0]=led;
wire signed [3:0] A,B;
assign A=sw[7:4];
assign B=sw[3:0];
always@(*) begin
	led=0;
	case(sw[15:13])
		3'b000:	led=A+B;
		3'b001:	led=A-B;
		3'b010:	led=~A;
		3'b011:	led=A&B;
		3'b100:	led=A|B;
		3'b101:	led=A^B;
		3'b110:	led=(A<B)?4'b1:4'b0;
		3'b111:	led=(A==B)?4'b1:4'b0;
	endcase
end*/
//ex6 LFSR 1+x+x5+x6+x8
/*reg [7:0] LFSR;
reg [22:0] cnt;
always@(posedge clk) begin
	if(!sw[0]) begin
		LFSR<=8'hff;
		cnt<=0;
	end else begin
		cnt<=cnt+1;
		if(&cnt==1) begin
			LFSR[6:0]<=LFSR[7:1];
			LFSR[7]<=LFSR[0]^LFSR[1]^LFSR[5]^LFSR[6];
		end
	end
end
assign ledr[7:0]=LFSR;
seg seg(
    .clk(clk),
    .rst(rst),
    .data({24'b0,LFSR}),
    .o_seg0(seg0),
    .o_seg1(seg1),
    .o_seg2(seg2),
    .o_seg3(seg3),
    .o_seg4(seg4),
    .o_seg5(seg5),
    .o_seg6(seg6),
    .o_seg7(seg7)
);*/
//ex7
wire [31:0] dout;
wire douten;
wire [7:0] seg00, seg11, seg22, seg33;
ps2_display dut(clk, rst, ps2_clk, ps2_data, dout, douten);
assign seg0 = douten?seg00:8'hff;
assign seg1 = douten?seg11:8'hff;
assign seg2 = douten?seg22:8'hff;
assign seg3 = douten?seg33:8'hff;
seg seg(
    .clk(clk),
    .rst(rst),
    .data(dout),
    .o_seg0(seg00),
    .o_seg1(seg11),
    .o_seg2(seg22),
    .o_seg3(seg33),
    .o_seg4(seg4),
    .o_seg5(seg5),
    .o_seg6(seg6),
    .o_seg7(seg7)
);
endmodule
