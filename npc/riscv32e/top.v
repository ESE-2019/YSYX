module top(
input  logic clk, rst,
input  logic [31:0] inst,
output logic [31:0] pc
);

import "DPI-C" function void ebreak();
import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(
  input int waddr, input int wdata, input byte wmask);

logic [4:0] rd_addr, rs1_addr, rs2_addr;
assign rd_addr = inst[11:7];
assign rs1_addr = inst[19:15];
assign rs2_addr = inst[24:20];
logic [31:0] regmap [32];
logic [31:0] immI, immU, immS, immJ, immB, rs1_val, rs2_val;
assign immI = {{20{inst[31]}}, inst[31:20]};
assign immU = {inst[31:12], 12'b0};
assign immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};
assign immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
assign immB = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
assign rs1_val = regmap[rs1_addr];
assign rs2_val = regmap[rs2_addr];
logic signed [31:0] rs1_s, rs2_s, immIs;
assign rs1_s = rs1_val;
assign rs2_s = rs2_val;
assign immIs = immI;
logic [6:0] opcode;
assign opcode = inst[6:0];
logic [2:0] funct3;
assign funct3 = inst[14:12];
logic [6:0] funct7;
assign funct7 = inst[31:25];
logic [4:0] shamt;//shamt[5] == 0
assign shamt = inst[24:20];
function automatic logic [31:0] Mr(input logic [31:0] Mr_addr, input logic [2:0] funct_3);
	logic [4:0] Mr_shamt;
	logic [31:0] tmp, temp;
	unique case (Mr_addr[1:0])
		2'b00: Mr_shamt = 0;
		2'b01: Mr_shamt = 8;
		2'b10: Mr_shamt = 16;
		2'b11: Mr_shamt = 24;
	endcase
	temp = pmem_read(Mr_addr);
	tmp = temp >> Mr_shamt;
	unique case (funct_3)
		3'b000: Mr = { {24{tmp[7]}}, tmp[7:0]};
		3'b001: Mr = { {16{tmp[15]}}, tmp[15:0]};
		3'b010: Mr = tmp[31:0];
		3'b100: Mr = {24'b0, tmp[7:0]};
		3'b101: Mr = {16'b0, tmp[15:0]};
		default: begin Mr = 0; $display("unknown type"); $finish; end
	endcase
endfunction



always_ff @(posedge clk) begin
	if(rst) begin
		pc <= 32'h8000_0000;
		foreach (regmap[i]) begin
			regmap[i] <= 0;
		end
	end
	else begin
	//$display("funct3: %b opcode: %b", funct3, opcode);
	//$display("r0: 0x%08x", regmap[0]);
		unique if(opcode == 7'b01101_11) begin//lui
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= immU;
		end
		else if (opcode == 7'b00101_11) begin//auipc
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= pc + immU;
		end
		else if(opcode == 7'b11011_11) begin//jal
			pc <= pc + immJ;
			if (rd_addr != 0) regmap[rd_addr] <= pc + 32'h4;
		end
		else if(funct3 == 3'b000 && opcode == 7'b11001_11) begin//jalr
			pc <= (rs1_val + immI) & 32'hffff_fffe;
			if (rd_addr != 0) regmap[rd_addr] <= pc + 32'h4;
		end
		else if(funct3 ==3'b000 && opcode == 7'b11000_11) begin//beq
			if (rs1_val == rs2_val)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(funct3 ==3'b001 && opcode == 7'b11000_11) begin//bne
			if (rs1_val != rs2_val)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(funct3 ==3'b100 && opcode == 7'b11000_11) begin//blt
			if (rs1_s < rs2_s)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(funct3 ==3'b101 && opcode == 7'b11000_11) begin//bge
			if (rs1_s >= rs2_s)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(funct3 ==3'b110 && opcode == 7'b11000_11) begin//bltu
			if (rs1_val < rs2_val)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(funct3 ==3'b111 && opcode == 7'b11000_11) begin//bgeu
			if (rs1_val >= rs2_val)
				pc <= pc + immB;
			else
				pc <= pc + 32'h4;
		end
		else if(opcode == 7'b00000_11) begin//lb lh lw lbu lhu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= Mr(rs1_val + immI, funct3); 
		end
		/*else if(funct3 == 3'b000 && opcode == 7'b00000_11) begin//lb
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= {{24{Mr(rs1_val + immI)[7]}}, Mr(rs1_val + immI)[7:0]}; 
		end
		else if(funct3 == 3'b001 && opcode == 7'b00000_11) begin//lh
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= {{16{Mr(rs1_val + immI)[7]}}, Mr(rs1_val + immI)[15:0]}; 
		end
		else if(funct3 == 3'b010 && opcode == 7'b00000_11) begin//lw
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= Mr(rs1_val + immI)[31:0]; 
		end
		else if(funct3 == 3'b100 && opcode == 7'b00000_11) begin//lbu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= {24'b0 , Mr(rs1_val + immI)[7:0]}; 
		end
		else if(funct3 == 3'b101 && opcode == 7'b00000_11) begin//lhu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= {16'b0, Mr(rs1_val + immI)[15:0]}; 
		end*/
		else if(funct3 == 3'b000 && opcode == 7'b01000_11) begin//sb
		//$display("%c", rs2_val[7:0]);
			pc <= pc + 32'h4;
			pmem_write( rs1_val + immS, rs2_val, 1);
		end
		else if(funct3 == 3'b001 && opcode == 7'b01000_11) begin//sh
			pc <= pc + 32'h4;
			pmem_write( rs1_val + immS, rs2_val, 2);
		end
		else if(funct3 == 3'b010 && opcode == 7'b01000_11) begin//sw
			pc <= pc + 32'h4;
			pmem_write( rs1_val + immS, rs2_val, 4);
		end
		else if(funct3 == 3'b000 && opcode == 7'b00100_11) begin//addi
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val + immI;
		end
		else if(funct3 == 3'b010 && opcode == 7'b00100_11) begin//slti
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= (rs1_s < immIs) ? 32'b1 : 32'b0;
		end
		else if(funct3 == 3'b011 && opcode == 7'b00100_11) begin//sltiu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= (rs1_val < immI) ? 32'b1 : 32'b0;
		end
		else if(funct3 == 3'b100 && opcode == 7'b00100_11) begin//xori
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val ^ immI;
		end
		else if(funct3 == 3'b110 && opcode == 7'b00100_11) begin//ori
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val | immI;
		end
		else if(funct3 == 3'b111 && opcode == 7'b00100_11) begin//andi
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val & immI;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b001 && opcode == 7'b00100_11) begin//slli
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val << shamt;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b101 && opcode == 7'b00100_11) begin//srli
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val >> shamt;
		end
		else if(funct7 == 7'b0100000 && funct3 == 3'b101 && opcode == 7'b00100_11) begin//srai
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_s >>> shamt;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b000 && opcode == 7'b01100_11) begin//add
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val + rs2_val;
		end
		else if(funct7 == 7'b0100000 && funct3 == 3'b000 && opcode == 7'b01100_11) begin//sub
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val - rs2_val;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b001 && opcode == 7'b01100_11) begin//sll
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val << rs2_val[4:0];
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b010 && opcode == 7'b01100_11) begin//slt
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= (rs1_s < rs2_s) ? 32'b1 : 32'b0;;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b011 && opcode == 7'b01100_11) begin//sltu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= (rs1_val < rs2_val) ? 32'b1 : 32'b0;;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b100 && opcode == 7'b01100_11) begin//xor
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val ^ rs2_val;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b101 && opcode == 7'b01100_11) begin//srl
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val >> rs2_val[4:0];
		end
		else if(funct7 == 7'b0100000 && funct3 == 3'b101 && opcode == 7'b01100_11) begin//sra
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_s >>> rs2_val[4:0];
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b110 && opcode == 7'b01100_11) begin//or
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val | rs2_val;
		end
		else if(funct7 == 7'b0000000 && funct3 == 3'b111 && opcode == 7'b01100_11) begin//and
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= rs1_val & rs2_val;
		end
		else if (inst == 32'b0000000_00001_00000_000_00000_11100_11) begin//ebreak
			ebreak();
		end
		else begin
			$display("invalid instruction 0x%08x: 0x%08x", pc, inst);
			$finish;
		end
	end
end
endmodule
