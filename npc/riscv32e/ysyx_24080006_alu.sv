module ysyx_24080006_alu(
input logic [31:0] src1, src2,
input logic [3:0] ctrl,
output logic [31:0] res
);
localparam	ADD  = 4'b0000,
		SUB  = 4'b1000,
		SLL  = 4'b0001,
		SLT  = 4'b0010,
		SLTU = 4'b0011,
		XOR  = 4'b0100,
		SRL  = 4'b0101,
		SRA  = 4'b1101,
		OR   = 4'b0110,
		AND  = 4'b0111;
		
//add
logic [33:0] add_res_t;
logic [32:0] srcA, srcB, srcB_t;
logic [31:0] add_res;
assign srcA   = {src1, 1'b1};
assign srcB_t = {src2, 1'b0};
always_comb begin
	srcB = srcB_t;
	case (ctrl)
		ADD : srcB =  srcB_t;
		SUB ,	
		SLT ,
		SLTU: srcB = ~srcB_t;
		default:;
	endcase
end
assign add_res_t = {1'b0, srcA} + {1'b0, srcB};
assign add_res = add_res_t[32:1];
//comp
logic comp_res;
always_comb begin
	comp_res = add_res_t[33];
	case (ctrl)
		SLT : comp_res =  add_res_t[32] ^ //detect overflow
			( ( ! srcA[32] &&   srcB_t[32] &&   add_res_t[32] ) || 
			  (   srcA[32] && ! srcB_t[32] && ! add_res_t[32] ) );
		SLTU: comp_res = !add_res_t[33];//caution
		default:;
	endcase
end
//shift
logic [31:0] shift_res;
logic [4:0] shift;
assign shift = src2[4:0];

logic [31:0] shift_src;

always_comb begin
	shift_src = src1;
	case (ctrl)
		SLL: for(int i=0; i<32; i++) shift_src[i] = src1[31-i];
		SRL,
		SRA: shift_src = src1;
		default:;
        endcase
end

always_comb begin
	shift_res = src1 >> shift;
	case (ctrl)
		SLL,
		SRL: shift_res = shift_src >> shift;
		SRA: shift_res = $signed(shift_src) >>> shift;
		//SRA: shift_res = { 32 { src1[31] } } << (31 - shift) | src1 >> shift;
		default:;
        endcase
end

//and or xor
logic [31:0] bit_res;
always_comb begin
	bit_res = src1 & src2;
	case (ctrl)
		AND: bit_res = src1 & src2;
		OR : bit_res = src1 | src2;
		XOR: bit_res = src1 ^ src2;
		default:;
	endcase
end

always_comb begin
	res = add_res;
	case (ctrl)
		ADD ,
		SUB : res = add_res;
		SLT ,
		SLTU: res = {31'b0, comp_res};
		SLL : for(int i=0; i<32; i++) res[i] = shift_res[31-i];
		SRL ,
		SRA : res = shift_res;
		AND ,
		OR  ,
		XOR : res = bit_res;
		default:;
	endcase
end

endmodule
