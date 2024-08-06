module ps2_display(clk, rst, ps2_clk, ps2_data, dout, douten);
input clk, rst, ps2_clk, ps2_data;
output [31:0] dout;
output douten;
wire [7:0] data;
wire ready, overflow;
reg nextdata_n;
reg [7:0] tmp, cnt;
reg hold;
wire [7:0] scan_to_ascii [255:0];
ps2_keyboard ps2_keyboard(
    .clk(clk),
    .clrn(~rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .data(data),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .overflow(overflow)
);

always@(posedge clk) begin
  if(rst) begin
    tmp <= 8'h00;
    nextdata_n <= 1'b0;
    hold <= 1'b0;
    cnt <= 8'b0;
  end else begin
  	if(ready ==1 && overflow == 0) begin
  	  tmp <= data;
      if(tmp != data) begin
        if(tmp == 8'hf0) begin
          hold <= 1'b0;
          cnt <= cnt + 8'b1;
        end else
          hold <= 1'b1;
      end
    end else if (hold == 0)
      tmp <= 8'h00;
  end
end

assign dout = { data, cnt, scan_to_ascii[tmp], tmp};
assign douten = hold;


assign scan_to_ascii[8'h1C] = 8'h61; // a
assign scan_to_ascii[8'h32] = 8'h62; // b
assign scan_to_ascii[8'h21] = 8'h63; // c
assign scan_to_ascii[8'h23] = 8'h64; // d
assign scan_to_ascii[8'h24] = 8'h65; // e
assign scan_to_ascii[8'h2B] = 8'h66; // f
assign scan_to_ascii[8'h34] = 8'h67; // g
assign scan_to_ascii[8'h33] = 8'h68; // h
assign scan_to_ascii[8'h43] = 8'h69; // i
assign scan_to_ascii[8'h3B] = 8'h6A; // j
assign scan_to_ascii[8'h42] = 8'h6B; // k
assign scan_to_ascii[8'h4B] = 8'h6C; // l
assign scan_to_ascii[8'h3A] = 8'h6D; // m
assign scan_to_ascii[8'h31] = 8'h6E; // n
assign scan_to_ascii[8'h44] = 8'h6F; // o
assign scan_to_ascii[8'h4D] = 8'h70; // p
assign scan_to_ascii[8'h15] = 8'h71; // q
assign scan_to_ascii[8'h2D] = 8'h72; // r
assign scan_to_ascii[8'h1B] = 8'h73; // s
assign scan_to_ascii[8'h2C] = 8'h74; // t
assign scan_to_ascii[8'h3C] = 8'h75; // u
assign scan_to_ascii[8'h2A] = 8'h76; // v
assign scan_to_ascii[8'h1D] = 8'h77; // w
assign scan_to_ascii[8'h22] = 8'h78; // x
assign scan_to_ascii[8'h35] = 8'h79; // y
assign scan_to_ascii[8'h1A] = 8'h7A; // z

assign scan_to_ascii[8'h45] = 8'h30; // 0
assign scan_to_ascii[8'h16] = 8'h31; // 1
assign scan_to_ascii[8'h1E] = 8'h32; // 2
assign scan_to_ascii[8'h26] = 8'h33; // 3
assign scan_to_ascii[8'h25] = 8'h34; // 4
assign scan_to_ascii[8'h2E] = 8'h35; // 5
assign scan_to_ascii[8'h36] = 8'h36; // 6
assign scan_to_ascii[8'h3D] = 8'h37; // 7
assign scan_to_ascii[8'h3E] = 8'h38; // 8
assign scan_to_ascii[8'h46] = 8'h39; // 9









endmodule
