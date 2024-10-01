interface ysyx_24080006_uif;

logic valid;
logic ready;

logic [31:0] pc, inst, imm, dnpc;

logic [31:0] sdata; // store data, i.e., rs2_val

logic [31:0] alu_src1;
logic [31:0] alu_src2;
logic [3:0]  alu_ctrl;//opcode
logic [1:0]  alu_set;//set output
logic [31:0] alu_res;

logic [4:0]  rd_addr;

logic [11:0] csr_addr;
logic        csr_we, ecall;
logic [31:0] csr_wdata;

logic [2:0] funct3;//cn be merged into load / store
logic load, store, wb, jump, branch;

modport prev(
	input  valid,
	output ready,
	
	input  pc,
	input  inst,
	input  imm,
	input  dnpc,

	input  sdata,

	input  alu_src1,
	input  alu_src2,
	input  alu_ctrl,
	input  alu_set,
	input  alu_res,
	input  rd_addr,

	input  csr_addr, csr_we, ecall, csr_wdata,

	input  funct3,
	input  load, store, wb, jump, branch
	);

modport next(
	output valid,
	input  ready,
	
	output pc,
	output inst,
	output imm,
	output dnpc,

	output sdata,

	output alu_src1,
	output alu_src2,
	output alu_ctrl,
	output alu_set,
	output alu_res,
	output rd_addr,

	output csr_addr, csr_we, ecall, csr_wdata,

	output funct3,
	output load, store, wb, jump, branch
	);
	
endinterface
