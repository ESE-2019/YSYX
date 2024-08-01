module ps2_display(clk, rst, ps2_clk, ps2_data, dout, douten);
input clk, rst, ps2_clk, ps2_data;
output [31:0] dout;
output douten;
wire [7:0] data;
wire ready, overflow;
reg nextdata_n;
reg [7:0] tmp, cnt;
reg hold;
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

assign dout = {cnt, tmp, data, tmp};
assign douten = hold;












endmodule
