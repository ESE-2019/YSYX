module top(
input  logic clk, rst
//input  logic [31:0] inst, output logic [31:0] pc
);
logic [31:0] inst, pc;
import "DPI-C" function void ebreak();

logic [4:0] rd_addr, rs1_addr, rs2_addr;
assign rd_addr = inst[11:7];
assign rs1_addr = inst[19:15];
assign rs2_addr = inst[24:20];
logic [31:0] regmap [32];
logic [31:0]  rs1_val, rs2_val;

logic [31:0] imm;
ysyx_24080006_imm Imm(inst, imm);

assign rs1_val = regmap[rs1_addr];
assign rs2_val = regmap[rs2_addr];
logic [31:0] mem_addr;
assign mem_addr = rs1_val + imm;

logic [6:0] opcode;
assign opcode = inst[6:0];
logic [2:0] funct3;
assign funct3 = inst[14:12];

logic [4:0] csr_reg;//use reg_map 16, 17, 18, 19

always_comb begin
	unique case(inst[31:20])
	12'h300: csr_reg = 5'b10000;//mstatus
	12'h305: csr_reg = 5'b10001;//mtvec
	12'h341: csr_reg = 5'b10010;//mepc
	12'h342: csr_reg = 5'b10011;//mcause
	default: csr_reg = 5'b0;
	endcase
end

logic [31:0] alu_1, alu_2, alu_3;
logic [3:0] alu_c;

ysyx_24080006_alu ysyx_24080006_alu(.src1(alu_1), .src2(alu_2), .ctrl(alu_c), .res(alu_3));
localparam	B_type	= 7'b1100011,
			I_type	= 7'b0010011,
			R_type	= 7'b0110011,
			Jal	 	= 7'b1101111,
			Jalr	= 7'b1100111;//TODO maybe enum is better
//alu in
always_comb begin
	alu_1 = rs1_val;
	if (opcode == Jal || opcode == Jalr)
		alu_1 = pc;//b, jalr
end
always_comb begin
	alu_2 = imm;
	unique case (opcode)
		I_type: alu_2 = imm;//I
		B_type,//B
		R_type: alu_2 = rs2_val;//R
		Jal,
		Jalr:   alu_2 = 32'h4;//jal, jalr
		default:;
	endcase
end
always_comb begin
	alu_c = {inst[30], funct3};
	unique case (opcode)
		B_type:	if (funct3[2:1] == 2'b00)//B
					alu_c = {  2'b10 , funct3[2:1]};
				else
					alu_c = {  2'b00 , funct3[2:1]};
		I_type:	if (funct3[1:0] == 2'b01)//I
					alu_c = {inst[30], funct3};
				else
					alu_c = {  1'b0  , funct3};
		R_type:		alu_c = {inst[30], funct3};//R
		Jalr:		alu_c = {  1'b0  , funct3};//jalr
		Jal:		alu_c =    4'b0;//jal
		default:;
	endcase
end

//alu_out
logic [31:0] alu_out;
logic  not_zero;
assign not_zero = |alu_3;
always_comb begin
	alu_out = alu_3;
	if(opcode == B_type)
		unique case (funct3)
			3'b000: alu_out = {31'b0, !not_zero};
			3'b001: alu_out = {31'b0,  not_zero};
			3'b101,
			3'b111: alu_out = {31'b0, !alu_3[0]};
			default:alu_out = alu_3;
		endcase
end
//alu end

//axi
axi_if axi_ifu (.aclk(clk), .aresetn(!rst));
axi_if axi_lsu (.aclk(clk), .aresetn(!rst));
axi_if axi_sram (.aclk(clk), .aresetn(!rst));
arb arb(axi_ifu, axi_lsu, axi_sram);
sram sram(axi_sram);

// ifu <--> idu <--> exu <--> lsu
logic iv, ir, dv, dr, ev, er, lv, lr;//valid ready
logic [1:0] ic, in, dc, dn, lc, ln;//curr next
localparam	IDLE = 2'b00,
			EXEC = 2'b01,
			WAIT = 2'b10;

//ifu

assign axi_ifu.araddr  = pc;
//assign inst = axi_ifu.rdata;

// assign iv = axi_ifu.rvalid;
// assign ir = axi_ifu.arready;
// assign axi_ifu.arvalid = lv;
// assign axi_ifu.rready = dr;

always_ff @(posedge clk) begin
	unique if (rst) begin
		ic <= IDLE;
	end
	else begin
		ic <= in;
	end
end

always_comb begin
	unique case (ic)
		IDLE:	if (lv) in=EXEC; else in=IDLE;
		EXEC:	if (axi_ifu.rvalid) in=WAIT; else in=EXEC;
		WAIT:	if (dr) in=IDLE; else in=WAIT;
		default:in=IDLE;
	endcase
end

always_ff @(posedge axi_ifu.aclk) begin
	unique if (!axi_ifu.aresetn) begin
		iv <= 0;
		ir <= 1;
		axi_ifu.arvalid <= 0;
		axi_ifu.rready  <= 1;
	end
	else begin
	unique case (ic)
		IDLE:	if (lv) begin
				iv <= 0;
				ir <= 0;
				axi_ifu.arvalid <= 1;
				axi_ifu.rready  <= 1;
			end else begin
				iv <= 0;
				ir <= 1;
				axi_ifu.arvalid <= 0;
				axi_ifu.rready  <= 1;
			end
		EXEC:	if (axi_ifu.rvalid) begin
				iv <= 1;
				ir <= 0;
				inst <= axi_ifu.rdata;
				axi_ifu.arvalid <= 0;
				axi_ifu.rready  <= 0;
			end else begin
				iv <= 0;
				ir <= 0;
				axi_ifu.arvalid <= 1;
				axi_ifu.rready  <= 1;
			end
		WAIT:	if (dr) begin
				iv <= 0;
				ir <= 1;
				axi_ifu.arvalid <= 0;
				axi_ifu.rready  <= 1;
			end else begin
				iv <= 1;
				ir <= 0;
				axi_ifu.arvalid <= 0;
				axi_ifu.rready  <= 0;
			end
		default:begin
				iv <= 0;
				ir <= 1;
				axi_ifu.arvalid <= 0;
				axi_ifu.rready  <= 1;
			end
	endcase	
	end
end

//IDU EXU
always_ff @(posedge clk) begin
	unique if (rst) begin
		dc <= IDLE;
	end
	else begin
		dc <= dn;
	end
end

always_comb begin
	unique case (dc)
		IDLE:	if (iv) dn=EXEC; else dn=IDLE;
		EXEC,
		WAIT:	if (er) dn=IDLE; else dn=WAIT;
		default:dn=IDLE;
	endcase
end

always_ff @(posedge clk) begin
	unique if (rst) begin
		dv <= 0;
		dr <= 1;
	end
	else begin
	unique case (dc)
		IDLE:	if (iv) begin
				dv <= 1;
				dr <= 0;
			end else begin
				dv <= 0;
				dr <= 1;
			end
		EXEC,
		WAIT:	if (er) begin
				dv <= 0;
				dr <= 1;
			end else begin
				dv <= 1;
				dr <= 0;
			end
		default:begin
				dv <= 0;
				dr <= 1;
			end
	endcase	
	end
end
assign ev = dv;
assign er = lr;
//LSU
logic [3:0] wstrb;
logic [4:0] rshamt;
logic [31:0] ldata;
assign ldata = axi_lsu.rdata >> rshamt;

always_ff @(posedge clk) begin
	unique if (rst) begin
		lc <= IDLE;
	end
	else begin
		lc <= ln;
	end
end

always_comb begin
	unique case (lc)
		IDLE:
				if (ev) begin
					if(opcode == 7'b00000_11 || opcode == 7'b01000_11)
						ln = EXEC;
					else
						ln = WAIT;
				end
				else
					ln=IDLE;
		EXEC:	if (axi_lsu.rvalid || axi_lsu.bvalid) ln=WAIT; else ln=EXEC;
		WAIT:	if (ir) ln=IDLE; else ln=WAIT;
		default:ln=IDLE;
	endcase
end

always_ff @(posedge clk) begin
	unique if (rst) begin
		lv <= 1;
		lr <= 1;
		axi_lsu.arvalid <= 0;
		axi_lsu.rready  <= 1;
		axi_lsu.awvalid <= 0;
		axi_lsu.wvalid  <= 0;
		axi_lsu.bready  <= 1;
	end
	else begin
	unique case (lc)
		IDLE:	if (ev) begin
				if(opcode == 7'b00000_11) begin//l read
				lv <= 0;
				lr <= 0;
				axi_lsu.arvalid <= 1;
				axi_lsu.rready  <= 1;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 0;
				axi_lsu.araddr  <= mem_addr;
				end
				else if(opcode == 7'b01000_11) begin//s write
				lv <= 0;
				lr <= 0;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 0;
				axi_lsu.awvalid <= 1;
				axi_lsu.wvalid  <= 1;
				axi_lsu.bready  <= 1;
				axi_lsu.awaddr  <= mem_addr;
				axi_lsu.wdata   <= rs2_val;
				axi_lsu.wstrb   <=  (funct3==3'b000)?4'b0001:
									(funct3==3'b001)?4'b0011:
									(funct3==3'b010)?4'b1111:4'b0;
				end
				else begin//bypass
					lv <= 1;
					lr <= 0;
					axi_lsu.arvalid <= 0;
					axi_lsu.rready  <= 0;
					axi_lsu.awvalid <= 0;
					axi_lsu.wvalid  <= 0;
					axi_lsu.bready  <= 0;
				end
			end else begin//next state IDLE
				lv <= 0;
				lr <= 1;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 1;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 1;
			end
		EXEC:	if (axi_lsu.rvalid) begin
				lv <= 1;
				lr <= 0;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 0;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 0;
				if (rd_addr != 0)
				unique case (funct3)
					3'b000: regmap[rd_addr] <= { {24{ldata[7]}}, ldata[7:0]};
					3'b001: regmap[rd_addr] <= { {16{ldata[15]}}, ldata[15:0]};
					3'b010: regmap[rd_addr] <= ldata[31:0];
					3'b100: regmap[rd_addr] <= {24'b0, ldata[7:0]};
					3'b101: regmap[rd_addr] <= {16'b0, ldata[15:0]};
					default: begin $display("unknown type"); $finish; end
				endcase

			end
				else if (axi_lsu.bvalid) begin
				lv <= 1;
				lr <= 0;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 0;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 0;
			end else begin
				lv <= 0;
				lr <= 0;
				//hold
			end
		WAIT:	if (ir) begin
				lv <= 0;
				lr <= 1;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 1;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 1;
			end else begin
				lv <= 1;
				lr <= 0;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 0;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 0;
			end
		default:begin
				lv <= 1;
				lr <= 1;
				axi_lsu.arvalid <= 0;
				axi_lsu.rready  <= 1;
				axi_lsu.awvalid <= 0;
				axi_lsu.wvalid  <= 0;
				axi_lsu.bready  <= 1;
			end
	endcase	
	end
end
//axi

//TODO
//sram sram(axi_lsu);

//main
assign regmap[0] = 0;
always_ff @(posedge clk) begin
	if(rst) begin
		pc <= 32'h8000_0000;
		
	end
	else if (dc == EXEC) begin
	//$display("funct3: %b opcode: %b", funct3, opcode);
	//$display("r0: 0x%08x", regmap[0]);
		unique if(opcode == 7'b01101_11) begin//lui
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= imm;
		end
		else if (opcode == 7'b00101_11) begin//auipc
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= pc + imm;
		end
		else if(opcode == 7'b11011_11) begin//jal
			pc <= pc + imm;
			if (rd_addr != 0) regmap[rd_addr] <= alu_3;
		end
		else if(opcode == 7'b11001_11) begin//jalr
			pc <= (rs1_val + imm) & 32'hffff_fffe;
			if (rd_addr != 0) regmap[rd_addr] <= alu_3;
		end
		else if(opcode == B_type) begin//B
		
			if (alu_out[0] == 1)
				pc <= pc + imm;
			else
				pc <= pc + 32'h4;
		end
		else if(opcode == 7'b00000_11) begin//lb lh lw lbu lhu TODO
			pc <= pc + 32'h4;
			case (mem_addr[1:0])
				2'b00: rshamt <= 0;
				2'b01: rshamt <= 8;
				2'b10: rshamt <= 16;
				2'b11: rshamt <= 24; 
				default: ;
			endcase
			//if (rd_addr != 0) regmap[rd_addr] <= Mr(rs1_val + imm, funct3); 
		end
		else if(opcode == 7'b01000_11) begin//sb sh sw TODO
			pc <= pc + 32'h4;
		end
		else if(opcode == 7'b00100_11 || opcode == 7'b01100_11) begin//alu
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= alu_out;
		end
		else if (inst == 32'b0000000_00001_00000_000_00000_11100_11) begin//ebreak
			ebreak();
		end
		else  if (funct3 == 3'b001 && opcode == 7'b11100_11) begin//csrrw
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= regmap[csr_reg];
			regmap[csr_reg] <= rs1_val;
		end
		else if (funct3 == 3'b010 && opcode == 7'b11100_11) begin//csrrs
			pc <= pc + 32'h4;
			if (rd_addr != 0) regmap[rd_addr] <= regmap[csr_reg];
			regmap[csr_reg] <= regmap[csr_reg] | rs1_val;
		end
		else if (inst == 32'b0000000_00000_00000_000_00000_11100_11) begin//ecall
			pc <= regmap[17];
			regmap[18] <= pc;
			regmap[19] <= regmap[15];
		end
		else if (inst == 32'b0011000_00010_00000_000_00000_11100_11) begin//mret
			pc <= regmap[18];
			//$display(" thispc 0x%08x retpc 0x%08x ", pc, regmap[18]);
		end
		else begin
			$display("invalid instruction 0x%08x: 0x%08x", pc, inst);
			$finish;
		end
	end

end

endmodule
