module alu (
    input  sw,
input [23:0] A, B,
    output reg [23:0] C,

);

//ex3 sel:sw[15:13] A:sw[7:4] B:sw[3:0] out:led[3:0]
//reg signed [3:0] led;
//assign ledr=led;


always@(*) begin
	case(sw)
		//0:	C=A<B?1:0;
		1:	C=A-B;
		//2'b10:	C=A+B;
		//3'b010:	led=~A;
		//3'b011:	led=A&B;
		//3'b100:	led=A|B;
		//3'b101:	led=A^B;
		//3'b110:	led=(A<B)?4'b1:4'b0;
		//3'b111:	led=(A==B)?4'b1:4'b0;
		default: C=0;
	endcase
end
//assign C=A+B;
endmodule
