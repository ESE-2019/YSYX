module top (
	clock,
	reset,
	io_interrupt,
	io_master_awready,
	io_master_awvalid,
	io_master_awaddr,
	io_master_awid,
	io_master_awlen,
	io_master_awsize,
	io_master_awburst,
	io_master_wready,
	io_master_wvalid,
	io_master_wdata,
	io_master_wstrb,
	io_master_wlast,
	io_master_bready,
	io_master_bvalid,
	io_master_bresp,
	io_master_bid,
	io_master_arready,
	io_master_arvalid,
	io_master_araddr,
	io_master_arid,
	io_master_arlen,
	io_master_arsize,
	io_master_arburst,
	io_master_rready,
	io_master_rvalid,
	io_master_rresp,
	io_master_rdata,
	io_master_rlast,
	io_master_rid,
	io_slave_awready,
	io_slave_awvalid,
	io_slave_awaddr,
	io_slave_awid,
	io_slave_awlen,
	io_slave_awsize,
	io_slave_awburst,
	io_slave_wready,
	io_slave_wvalid,
	io_slave_wdata,
	io_slave_wstrb,
	io_slave_wlast,
	io_slave_bready,
	io_slave_bvalid,
	io_slave_bresp,
	io_slave_bid,
	io_slave_arready,
	io_slave_arvalid,
	io_slave_araddr,
	io_slave_arid,
	io_slave_arlen,
	io_slave_arsize,
	io_slave_arburst,
	io_slave_rready,
	io_slave_rvalid,
	io_slave_rresp,
	io_slave_rdata,
	io_slave_rlast,
	io_slave_rid
);
	input wire clock;
	input wire reset;
	input wire io_interrupt;
	input wire io_master_awready;
	output wire io_master_awvalid;
	output wire [31:0] io_master_awaddr;
	output wire [3:0] io_master_awid;
	output wire [7:0] io_master_awlen;
	output wire [2:0] io_master_awsize;
	output wire [1:0] io_master_awburst;
	input wire io_master_wready;
	output wire io_master_wvalid;
	output wire [31:0] io_master_wdata;
	output wire [3:0] io_master_wstrb;
	output wire io_master_wlast;
	output wire io_master_bready;
	input wire io_master_bvalid;
	input wire [1:0] io_master_bresp;
	input wire [3:0] io_master_bid;
	input wire io_master_arready;
	output wire io_master_arvalid;
	output wire [31:0] io_master_araddr;
	output wire [3:0] io_master_arid;
	output wire [7:0] io_master_arlen;
	output wire [2:0] io_master_arsize;
	output wire [1:0] io_master_arburst;
	output wire io_master_rready;
	input wire io_master_rvalid;
	input wire [1:0] io_master_rresp;
	input wire [31:0] io_master_rdata;
	input wire io_master_rlast;
	input wire [3:0] io_master_rid;
	output wire io_slave_awready;
	input wire io_slave_awvalid;
	input wire [31:0] io_slave_awaddr;
	input wire [3:0] io_slave_awid;
	input wire [7:0] io_slave_awlen;
	input wire [2:0] io_slave_awsize;
	input wire [1:0] io_slave_awburst;
	output wire io_slave_wready;
	input wire io_slave_wvalid;
	input wire [31:0] io_slave_wdata;
	input wire [3:0] io_slave_wstrb;
	input wire io_slave_wlast;
	input wire io_slave_bready;
	output wire io_slave_bvalid;
	output wire [1:0] io_slave_bresp;
	output wire [3:0] io_slave_bid;
	output wire io_slave_arready;
	input wire io_slave_arvalid;
	input wire [31:0] io_slave_araddr;
	input wire [3:0] io_slave_arid;
	input wire [7:0] io_slave_arlen;
	input wire [2:0] io_slave_arsize;
	input wire [1:0] io_slave_arburst;
	input wire io_slave_rready;
	output wire io_slave_rvalid;
	output wire [1:0] io_slave_rresp;
	output wire [31:0] io_slave_rdata;
	output wire io_slave_rlast;
	output wire [3:0] io_slave_rid;
	generate
		if (1) begin : axi
			wire awready;
			wire awvalid;
			wire [31:0] awaddr;
			wire [3:0] awid;
			wire [7:0] awlen;
			wire [2:0] awsize;
			wire [1:0] awburst;
			wire wready;
			wire wvalid;
			wire [31:0] wdata;
			wire [3:0] wstrb;
			wire wlast;
			wire bready;
			wire bvalid;
			wire [1:0] bresp;
			wire [3:0] bid;
			wire arready;
			reg arvalid;
			wire [31:0] araddr;
			wire [3:0] arid;
			wire [7:0] arlen;
			wire [2:0] arsize;
			wire [1:0] arburst;
			reg rready;
			wire rvalid;
			wire [1:0] rresp;
			wire [31:0] rdata;
			wire rlast;
			wire [3:0] rid;
		end
		if (1) begin : CORE
			wire clock;
			wire reset;
			if (1) begin : ifu2idu
				reg valid;
				reg ready;
				reg [31:0] pc;
				reg [31:0] inst;
				wire [31:0] imm;
				wire [31:0] dnpc;
				wire [31:0] sdata;
				wire [31:0] alu_src1;
				wire [31:0] alu_src2;
				wire [3:0] alu_ctrl;
				wire [1:0] alu_set;
				wire [31:0] alu_res;
				wire [4:0] rd_addr;
				wire [11:0] csr_addr;
				wire csr_we;
				wire ecall;
				wire [31:0] csr_wdata;
				wire [2:0] funct3;
				wire load;
				wire store;
				wire wb;
				wire jump;
				wire branch;
			end
			if (1) begin : idu2exu
				reg valid;
				reg ready;
				wire [31:0] pc;
				wire [31:0] inst;
				reg [31:0] imm;
				reg [31:0] dnpc;
				reg [31:0] sdata;
				reg [31:0] alu_src1;
				reg [31:0] alu_src2;
				reg [3:0] alu_ctrl;
				reg [1:0] alu_set;
				wire [31:0] alu_res;
				reg [4:0] rd_addr;
				reg [11:0] csr_addr;
				reg csr_we;
				reg ecall;
				reg [31:0] csr_wdata;
				reg [2:0] funct3;
				reg load;
				reg store;
				reg wb;
				reg jump;
				reg branch;
			end
			if (1) begin : exu2lsu
				reg valid;
				reg ready;
				wire [31:0] pc;
				wire [31:0] inst;
				wire [31:0] imm;
				reg [31:0] dnpc;
				reg [31:0] sdata;
				wire [31:0] alu_src1;
				wire [31:0] alu_src2;
				wire [3:0] alu_ctrl;
				wire [1:0] alu_set;
				reg [31:0] alu_res;
				reg [4:0] rd_addr;
				reg [11:0] csr_addr;
				reg csr_we;
				reg ecall;
				reg [31:0] csr_wdata;
				reg [2:0] funct3;
				reg load;
				reg store;
				reg wb;
				reg jump;
				reg branch;
			end
			if (1) begin : lsu2wbu
				reg valid;
				reg ready;
				wire [31:0] pc;
				wire [31:0] inst;
				wire [31:0] imm;
				reg [31:0] dnpc;
				wire [31:0] sdata;
				wire [31:0] alu_src1;
				wire [31:0] alu_src2;
				wire [3:0] alu_ctrl;
				wire [1:0] alu_set;
				reg [31:0] alu_res;
				reg [4:0] rd_addr;
				reg [11:0] csr_addr;
				reg csr_we;
				reg ecall;
				reg [31:0] csr_wdata;
				wire [2:0] funct3;
				wire load;
				wire store;
				reg wb;
				reg jump;
				reg branch;
			end
			if (1) begin : wbu2ifu
				reg valid;
				reg ready;
				wire [31:0] pc;
				wire [31:0] inst;
				wire [31:0] imm;
				reg [31:0] dnpc;
				wire [31:0] sdata;
				wire [31:0] alu_src1;
				wire [31:0] alu_src2;
				wire [3:0] alu_ctrl;
				wire [1:0] alu_set;
				wire [31:0] alu_res;
				wire [4:0] rd_addr;
				wire [11:0] csr_addr;
				wire csr_we;
				wire ecall;
				wire [31:0] csr_wdata;
				wire [2:0] funct3;
				wire load;
				wire store;
				wire wb;
				reg jump;
				reg branch;
			end
			if (1) begin : axi_ifu
				wire awready;
				wire awvalid;
				wire [31:0] awaddr;
				wire [3:0] awid;
				wire [7:0] awlen;
				wire [2:0] awsize;
				wire [1:0] awburst;
				wire wready;
				wire wvalid;
				wire [31:0] wdata;
				wire [3:0] wstrb;
				wire wlast;
				wire bready;
				wire bvalid;
				wire [1:0] bresp;
				wire [3:0] bid;
				wire arready;
				reg arvalid;
				wire [31:0] araddr;
				wire [3:0] arid;
				wire [7:0] arlen;
				wire [2:0] arsize;
				wire [1:0] arburst;
				reg rready;
				wire rvalid;
				wire [1:0] rresp;
				wire [31:0] rdata;
				wire rlast;
				wire [3:0] rid;
			end
			if (1) begin : axi_lsu
				wire awready;
				reg awvalid;
				reg [31:0] awaddr;
				wire [3:0] awid;
				wire [7:0] awlen;
				wire [2:0] awsize;
				wire [1:0] awburst;
				wire wready;
				reg wvalid;
				reg [31:0] wdata;
				reg [3:0] wstrb;
				wire wlast;
				reg bready;
				wire bvalid;
				wire [1:0] bresp;
				wire [3:0] bid;
				wire arready;
				reg arvalid;
				reg [31:0] araddr;
				wire [3:0] arid;
				wire [7:0] arlen;
				wire [2:0] arsize;
				wire [1:0] arburst;
				reg rready;
				wire rvalid;
				wire [1:0] rresp;
				wire [31:0] rdata;
				wire rlast;
				wire [3:0] rid;
			end
			if (1) begin : ARB
				reg _sv2v_0;
				wire clock;
				wire reset;
				assign top.CORE.axi_lsu.awready = top.axi.awready;
				assign top.axi.awvalid = top.CORE.axi_lsu.awvalid;
				assign top.axi.awaddr = top.CORE.axi_lsu.awaddr;
				assign top.axi.awid = top.CORE.axi_lsu.awid;
				assign top.axi.awlen = top.CORE.axi_lsu.awlen;
				assign top.axi.awsize = top.CORE.axi_lsu.awsize;
				assign top.axi.awburst = top.CORE.axi_lsu.awburst;
				assign top.CORE.axi_lsu.wready = top.axi.wready;
				assign top.axi.wvalid = top.CORE.axi_lsu.wvalid;
				assign top.axi.wdata = top.CORE.axi_lsu.wdata;
				assign top.axi.wstrb = top.CORE.axi_lsu.wstrb;
				assign top.axi.wlast = top.CORE.axi_lsu.wlast;
				assign top.axi.bready = top.CORE.axi_lsu.bready;
				assign top.CORE.axi_lsu.bvalid = top.axi.bvalid;
				assign top.CORE.axi_lsu.bresp = top.axi.bresp;
				assign top.CORE.axi_lsu.bid = top.axi.bid;
				assign top.CORE.axi_ifu.rresp = top.axi.rresp;
				assign top.CORE.axi_ifu.rdata = top.axi.rdata;
				assign top.CORE.axi_ifu.rlast = top.axi.rlast;
				assign top.CORE.axi_ifu.rid = top.axi.rid;
				assign top.CORE.axi_lsu.rresp = top.axi.rresp;
				assign top.CORE.axi_lsu.rdata = top.axi.rdata;
				assign top.CORE.axi_lsu.rlast = top.axi.rlast;
				assign top.CORE.axi_lsu.rid = top.axi.rid;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd0;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.axi_lsu.arvalid || top.CORE.axi_lsu.rvalid)
								next = 2'd2;
							else if (top.CORE.axi_ifu.arvalid || top.CORE.axi_ifu.rvalid)
								next = 2'd1;
							else
								next = 2'd0;
						2'd2:
							if (top.CORE.axi_lsu.rready && top.CORE.axi_lsu.rvalid)
								next = 2'd0;
							else
								next = 2'd2;
						2'd1:
							if (top.CORE.axi_ifu.rready && top.CORE.axi_ifu.rvalid)
								next = 2'd0;
							else
								next = 2'd1;
					endcase
				end
				assign top.CORE.axi_ifu.arready = (curr == 2'd1 ? top.axi.arready : 0);
				assign top.CORE.axi_lsu.arready = (curr == 2'd2 ? top.axi.arready : 0);
				assign top.CORE.axi_ifu.rvalid = (curr == 2'd1 ? top.axi.rvalid : 0);
				assign top.CORE.axi_lsu.rvalid = (curr == 2'd2 ? top.axi.rvalid : 0);
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0: begin
							top.axi.arvalid = 0;
							top.axi.rready = 0;
						end
						2'd2: begin
							top.axi.arvalid = top.CORE.axi_lsu.arvalid;
							top.axi.rready = top.CORE.axi_lsu.rready;
						end
						2'd1: begin
							top.axi.arvalid = top.CORE.axi_ifu.arvalid;
							top.axi.rready = top.CORE.axi_ifu.rready;
						end
					endcase
				end
				assign top.axi.araddr = (curr == 2'd2 ? top.CORE.axi_lsu.araddr : top.CORE.axi_ifu.araddr);
				assign top.axi.arid = (curr == 2'd2 ? top.CORE.axi_lsu.arid : top.CORE.axi_ifu.arid);
				assign top.axi.arlen = (curr == 2'd2 ? top.CORE.axi_lsu.arlen : top.CORE.axi_ifu.arlen);
				assign top.axi.arsize = (curr == 2'd2 ? top.CORE.axi_lsu.arsize : top.CORE.axi_ifu.arsize);
				assign top.axi.arburst = (curr == 2'd2 ? top.CORE.axi_lsu.arburst : top.CORE.axi_ifu.arburst);
				initial _sv2v_0 = 0;
			end
			assign ARB.clock = clock;
			assign ARB.reset = reset;
			wire we;
			wire [4:0] rs1_addr;
			wire [4:0] rs2_addr;
			wire [4:0] rd;
			wire [31:0] wdata;
			wire [31:0] rs1_val;
			wire [31:0] rs2_val;
			wire csr_we;
			wire [31:0] mepc_val;
			wire mepc_en;
			wire [11:0] csr_addr;
			wire [11:0] csr_waddr;
			wire [31:0] csr_wdata;
			wire [31:0] csr_rdata;
			ysyx_24080006_reg REG(
				.clock(clock),
				.reset(reset),
				.we(we),
				.rs1_addr(rs1_addr),
				.rs2_addr(rs2_addr),
				.rd(rd),
				.wdata(wdata),
				.rs1_val(rs1_val),
				.rs2_val(rs2_val)
			);
			ysyx_24080006_csr CSR(
				.clock(clock),
				.reset(reset),
				.csr_we(csr_we),
				.mepc_val(mepc_val),
				.mepc_en(mepc_en),
				.csr_addr(csr_addr),
				.csr_waddr(csr_waddr),
				.csr_wdata(csr_wdata),
				.csr_rdata(csr_rdata)
			);
			if (1) begin : IFU
				reg _sv2v_0;
				wire clock;
				wire reset;
				reg [31:0] pc;
				localparam RST_ADDR = 32'h80000000 - 32'h00000004;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd0;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.wbu2ifu.valid)
								next = 2'd1;
							else
								next = 2'd0;
						2'd1:
							if (top.CORE.axi_ifu.rvalid)
								next = 2'd2;
							else
								next = 2'd1;
						2'd2:
							if (top.CORE.ifu2idu.ready)
								next = 2'd0;
							else
								next = 2'd2;
					endcase
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.wbu2ifu.ready <= 1;
						top.CORE.ifu2idu.valid <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.wbu2ifu.valid) begin
									top.CORE.wbu2ifu.ready <= 0;
									top.CORE.ifu2idu.valid <= 0;
								end
								else begin
									top.CORE.wbu2ifu.ready <= 1;
									top.CORE.ifu2idu.valid <= 0;
								end
							2'd1:
								if (top.CORE.axi_ifu.rvalid) begin
									top.CORE.wbu2ifu.ready <= 0;
									top.CORE.ifu2idu.valid <= 1;
								end
								else begin
									top.CORE.wbu2ifu.ready <= 0;
									top.CORE.ifu2idu.valid <= 0;
								end
							2'd2:
								if (top.CORE.ifu2idu.ready) begin
									top.CORE.wbu2ifu.ready <= 1;
									top.CORE.ifu2idu.valid <= 0;
								end
								else begin
									top.CORE.wbu2ifu.ready <= 0;
									top.CORE.ifu2idu.valid <= 1;
								end
						endcase
				assign top.CORE.axi_ifu.araddr = pc;
				always @(posedge clock)
					if (reset) begin
						top.CORE.axi_ifu.arvalid <= 0;
						top.CORE.axi_ifu.rready <= 1;
						top.CORE.ifu2idu.inst <= 1'sb0;
						pc <= RST_ADDR;
						top.CORE.ifu2idu.pc <= 1'sb0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.wbu2ifu.valid) begin
									top.CORE.axi_ifu.arvalid <= 1;
									top.CORE.axi_ifu.rready <= 1;
									if (top.CORE.wbu2ifu.jump || top.CORE.wbu2ifu.branch)
										pc <= top.CORE.wbu2ifu.dnpc;
									else
										pc <= pc + 32'h00000004;
								end
								else begin
									top.CORE.axi_ifu.arvalid <= 0;
									top.CORE.axi_ifu.rready <= 1;
								end
							2'd1:
								if (top.CORE.axi_ifu.rvalid) begin
									top.CORE.axi_ifu.arvalid <= 0;
									top.CORE.axi_ifu.rready <= 0;
									top.CORE.ifu2idu.inst <= top.CORE.axi_ifu.rdata;
									top.CORE.ifu2idu.pc <= pc;
								end
								else begin
									top.CORE.axi_ifu.arvalid <= 1;
									top.CORE.axi_ifu.rready <= 1;
								end
							2'd2:
								if (top.CORE.ifu2idu.ready) begin
									top.CORE.axi_ifu.arvalid <= 0;
									top.CORE.axi_ifu.rready <= 0;
								end
								else begin
									top.CORE.axi_ifu.arvalid <= 0;
									top.CORE.axi_ifu.rready <= 1;
								end
						endcase
				initial _sv2v_0 = 0;
			end
			assign IFU.clock = clock;
			assign IFU.reset = reset;
			if (1) begin : IDU
				reg _sv2v_0;
				wire clock;
				wire reset;
				wire [4:0] rs1_addr;
				wire [4:0] rs2_addr;
				wire [31:0] rs1_val;
				wire [31:0] rs2_val;
				wire [11:0] csr_addr;
				wire [31:0] csr_rdata;
				wire [31:0] mepc_val;
				wire mepc_en;
				assign mepc_val = top.CORE.ifu2idu.pc;
				assign mepc_en = top.CORE.ifu2idu.inst == 32'b00000000000000000000000001110011;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd0;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.ifu2idu.valid)
								next = 2'd1;
							else
								next = 2'd0;
						2'd1, 2'd2:
							if (top.CORE.idu2exu.ready)
								next = 2'd0;
							else
								next = 2'd2;
					endcase
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.ifu2idu.ready <= 1;
						top.CORE.idu2exu.valid <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.ifu2idu.valid) begin
									top.CORE.ifu2idu.ready <= 0;
									top.CORE.idu2exu.valid <= 1;
								end
								else begin
									top.CORE.ifu2idu.ready <= 1;
									top.CORE.idu2exu.valid <= 0;
								end
							2'd1, 2'd2:
								if (top.CORE.idu2exu.ready) begin
									top.CORE.ifu2idu.ready <= 1;
									top.CORE.idu2exu.valid <= 0;
								end
								else begin
									top.CORE.ifu2idu.ready <= 0;
									top.CORE.idu2exu.valid <= 1;
								end
						endcase
				localparam B_type = 7'b1100011;
				localparam I_type = 7'b0010011;
				localparam R_type = 7'b0110011;
				localparam S_type = 7'b0100011;
				localparam load = 7'b0000011;
				localparam jal = 7'b1101111;
				localparam jalr = 7'b1100111;
				localparam lui = 7'b0110111;
				localparam auipc = 7'b0010111;
				localparam system = 7'b1110011;
				wire [31:0] imm;
				ysyx_24080006_imm Imm(
					.inst(top.CORE.ifu2idu.inst),
					.imm(imm)
				);
				wire [6:0] opcode;
				wire [2:0] funct3;
				wire [4:0] rd_addr;
				assign opcode = top.CORE.ifu2idu.inst[6:0];
				assign funct3 = top.CORE.ifu2idu.inst[14:12];
				assign rs1_addr = (top.CORE.ifu2idu.inst == 32'b00000000000000000000000001110011 ? 5'd15 : top.CORE.ifu2idu.inst[19:15]);
				assign rs2_addr = top.CORE.ifu2idu.inst[24:20];
				assign rd_addr = top.CORE.ifu2idu.inst[11:7];
				assign csr_addr = (top.CORE.ifu2idu.inst == 32'b00000000000000000000000001110011 ? 12'h305 : (top.CORE.ifu2idu.inst == 32'b00110000001000000000000001110011 ? 12'h341 : top.CORE.ifu2idu.inst[31:20]));
				reg [31:0] alu_src1;
				reg [31:0] alu_src2;
				reg [3:0] alu_ctrl;
				reg [1:0] alu_set;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (opcode)
						jal, jalr, auipc: alu_src1 = top.CORE.ifu2idu.pc;
						lui: alu_src1 = 1'sb0;
						default: alu_src1 = rs1_val;
					endcase
				end
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (opcode)
						auipc, lui, load, S_type, I_type: alu_src2 = imm;
						B_type, R_type: alu_src2 = rs2_val;
						jal, jalr: alu_src2 = 32'h00000004;
						system:
							if (funct3 == 3'b010)
								alu_src2 = csr_rdata;
							else
								alu_src2 = 1'sb0;
						default: alu_src2 = imm;
					endcase
				end
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (opcode)
						B_type:
							if (funct3[2:1] == 2'b00)
								alu_ctrl = {2'b10, funct3[2:1]};
							else
								alu_ctrl = {2'b00, funct3[2:1]};
						I_type:
							if (funct3[1:0] == 2'b01)
								alu_ctrl = {top.CORE.ifu2idu.inst[30], funct3};
							else
								alu_ctrl = {1'b0, funct3};
						R_type: alu_ctrl = {top.CORE.ifu2idu.inst[30], funct3};
						jal, jalr, lui, auipc, load, S_type: alu_ctrl = 1'sb0;
						system:
							if (funct3 == 3'b010)
								alu_ctrl = 4'b0110;
							else
								alu_ctrl = 1'sb0;
						default: alu_ctrl = 1'sb0;
					endcase
				end
				always @(*) begin
					if (_sv2v_0)
						;
					alu_set = 1'sb0;
					if (opcode == B_type)
						(* full_case, parallel_case *)
						case (funct3)
							3'b000: alu_set = 2'b01;
							3'b001: alu_set = 2'b10;
							3'b101, 3'b111: alu_set = 2'b11;
							default:
								;
						endcase
				end
				reg [31:0] dnpc;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (opcode)
						jalr: dnpc = (rs1_val + imm) & 32'hfffffffe;
						system: dnpc = csr_rdata;
						default: dnpc = top.CORE.ifu2idu.pc + imm;
					endcase
				end
				reg csr_we;
				always @(*) begin
					if (_sv2v_0)
						;
					if ((opcode == system) && (funct3 != 3'b000))
						csr_we = 1;
					else
						csr_we = 0;
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.idu2exu.alu_src1 <= 1'sb0;
						top.CORE.idu2exu.alu_src2 <= 1'sb0;
						top.CORE.idu2exu.alu_ctrl <= 1'sb0;
						top.CORE.idu2exu.alu_set <= 1'sb0;
						top.CORE.idu2exu.imm <= 1'sb0;
						top.CORE.idu2exu.rd_addr <= 1'sb0;
						top.CORE.idu2exu.dnpc <= 1'sb0;
						top.CORE.idu2exu.sdata <= 1'sb0;
						top.CORE.idu2exu.csr_addr <= 1'sb0;
						top.CORE.idu2exu.csr_we <= 1'sb0;
						top.CORE.idu2exu.csr_wdata <= 1'sb0;
					end
					else if ((curr == 2'd0) && top.CORE.ifu2idu.valid) begin
						top.CORE.idu2exu.alu_src1 <= alu_src1;
						top.CORE.idu2exu.alu_src2 <= alu_src2;
						top.CORE.idu2exu.alu_ctrl <= alu_ctrl;
						top.CORE.idu2exu.alu_set <= alu_set;
						top.CORE.idu2exu.imm <= imm;
						top.CORE.idu2exu.rd_addr <= rd_addr;
						top.CORE.idu2exu.dnpc <= dnpc;
						top.CORE.idu2exu.sdata <= rs2_val;
						top.CORE.idu2exu.csr_addr <= csr_addr;
						top.CORE.idu2exu.csr_we <= csr_we;
						top.CORE.idu2exu.csr_wdata <= csr_rdata;
					end
				always @(posedge clock)
					if (reset) begin
						top.CORE.idu2exu.funct3 <= 1'sb0;
						top.CORE.idu2exu.load <= 1'sb0;
						top.CORE.idu2exu.store <= 1'sb0;
						top.CORE.idu2exu.wb <= 1'sb0;
						top.CORE.idu2exu.jump <= 1'sb0;
						top.CORE.idu2exu.branch <= 1'sb0;
						top.CORE.idu2exu.ecall <= 1'sb0;
					end
					else if ((curr == 2'd0) && top.CORE.ifu2idu.valid) begin
						top.CORE.idu2exu.funct3 <= funct3;
						top.CORE.idu2exu.load <= opcode == load;
						top.CORE.idu2exu.store <= opcode == S_type;
						top.CORE.idu2exu.wb <= |{opcode == auipc, opcode == lui, opcode == jal, opcode == jalr, opcode == I_type, opcode == R_type, opcode == load};
						top.CORE.idu2exu.jump <= |{opcode == jal, opcode == jalr} || ((opcode == system) && !csr_we);
						top.CORE.idu2exu.branch <= opcode == B_type;
						top.CORE.idu2exu.ecall <= top.CORE.ifu2idu.inst == 32'b00000000000000000000000001110011;
					end
				initial _sv2v_0 = 0;
			end
			assign IDU.clock = clock;
			assign IDU.reset = reset;
			assign rs1_addr = IDU.rs1_addr;
			assign rs2_addr = IDU.rs2_addr;
			assign IDU.rs1_val = rs1_val;
			assign IDU.rs2_val = rs2_val;
			assign csr_addr = IDU.csr_addr;
			assign IDU.csr_rdata = csr_rdata;
			assign mepc_val = IDU.mepc_val;
			assign mepc_en = IDU.mepc_en;
			if (1) begin : EXU
				reg _sv2v_0;
				wire clock;
				wire reset;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd0;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.idu2exu.valid)
								next = 2'd1;
							else
								next = 2'd0;
						2'd1, 2'd2:
							if (top.CORE.exu2lsu.ready)
								next = 2'd0;
							else
								next = 2'd2;
					endcase
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.idu2exu.ready <= 1;
						top.CORE.exu2lsu.valid <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.idu2exu.valid) begin
									top.CORE.idu2exu.ready <= 0;
									top.CORE.exu2lsu.valid <= 1;
								end
								else begin
									top.CORE.idu2exu.ready <= 1;
									top.CORE.exu2lsu.valid <= 0;
								end
							2'd1, 2'd2:
								if (top.CORE.exu2lsu.ready) begin
									top.CORE.idu2exu.ready <= 1;
									top.CORE.exu2lsu.valid <= 0;
								end
								else begin
									top.CORE.idu2exu.ready <= 0;
									top.CORE.exu2lsu.valid <= 1;
								end
						endcase
				wire [31:0] alu_out;
				reg [31:0] alu_res;
				ysyx_24080006_alu ALU(
					.src1(top.CORE.idu2exu.alu_src1),
					.src2(top.CORE.idu2exu.alu_src2),
					.ctrl(top.CORE.idu2exu.alu_ctrl),
					.res(alu_out)
				);
				wire not_zero;
				assign not_zero = |alu_out;
				reg branch;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (top.CORE.idu2exu.alu_set)
						2'b00: alu_res = alu_out;
						2'b01: alu_res = {31'b0000000000000000000000000000000, ~not_zero};
						2'b10: alu_res = {31'b0000000000000000000000000000000, not_zero};
						2'b11: alu_res = {31'b0000000000000000000000000000000, ~alu_out[0]};
					endcase
					if ((top.CORE.idu2exu.branch == 1'b1) && (alu_res[0] == 1))
						branch = 1'b1;
					else
						branch = 1'b0;
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.exu2lsu.dnpc <= 1'sb0;
						top.CORE.exu2lsu.sdata <= 1'sb0;
						top.CORE.exu2lsu.rd_addr <= 1'sb0;
						top.CORE.exu2lsu.alu_res <= 1'sb0;
						top.CORE.exu2lsu.funct3 <= 1'sb0;
						top.CORE.exu2lsu.load <= 1'sb0;
						top.CORE.exu2lsu.store <= 1'sb0;
						top.CORE.exu2lsu.wb <= 1'sb0;
						top.CORE.exu2lsu.jump <= 1'sb0;
						top.CORE.exu2lsu.branch <= 1'sb0;
						top.CORE.exu2lsu.csr_addr <= 1'sb0;
						top.CORE.exu2lsu.csr_we <= 1'sb0;
						top.CORE.exu2lsu.csr_wdata <= 1'sb0;
						top.CORE.exu2lsu.ecall <= 1'sb0;
					end
					else begin
						top.CORE.exu2lsu.dnpc <= top.CORE.idu2exu.dnpc;
						top.CORE.exu2lsu.sdata <= top.CORE.idu2exu.sdata;
						top.CORE.exu2lsu.rd_addr <= top.CORE.idu2exu.rd_addr;
						top.CORE.exu2lsu.alu_res <= alu_res;
						top.CORE.exu2lsu.funct3 <= top.CORE.idu2exu.funct3;
						top.CORE.exu2lsu.load <= top.CORE.idu2exu.load;
						top.CORE.exu2lsu.store <= top.CORE.idu2exu.store;
						top.CORE.exu2lsu.wb <= top.CORE.idu2exu.wb;
						top.CORE.exu2lsu.jump <= top.CORE.idu2exu.jump;
						top.CORE.exu2lsu.branch <= branch;
						top.CORE.exu2lsu.csr_addr <= top.CORE.idu2exu.csr_addr;
						top.CORE.exu2lsu.csr_we <= top.CORE.idu2exu.csr_we;
						top.CORE.exu2lsu.csr_wdata <= top.CORE.idu2exu.csr_wdata;
						top.CORE.exu2lsu.ecall <= top.CORE.idu2exu.ecall;
					end
				initial _sv2v_0 = 0;
			end
			assign EXU.clock = clock;
			assign EXU.reset = reset;
			if (1) begin : LSU
				reg _sv2v_0;
				wire clock;
				wire reset;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd0;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.exu2lsu.valid) begin
								if (top.CORE.exu2lsu.load || top.CORE.exu2lsu.store)
									next = 2'd1;
								else
									next = 2'd2;
							end
							else
								next = 2'd0;
						2'd1:
							if (top.CORE.axi_lsu.rvalid || top.CORE.axi_lsu.bvalid)
								next = 2'd2;
							else
								next = 2'd1;
						2'd2:
							if (top.CORE.lsu2wbu.ready)
								next = 2'd0;
							else
								next = 2'd2;
					endcase
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.exu2lsu.ready <= 1;
						top.CORE.lsu2wbu.valid <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.exu2lsu.valid) begin
									if (top.CORE.exu2lsu.load || top.CORE.exu2lsu.store) begin
										top.CORE.exu2lsu.ready <= 0;
										top.CORE.lsu2wbu.valid <= 0;
									end
									else begin
										top.CORE.exu2lsu.ready <= 0;
										top.CORE.lsu2wbu.valid <= 1;
									end
								end
								else begin
									top.CORE.exu2lsu.ready <= 1;
									top.CORE.lsu2wbu.valid <= 0;
								end
							2'd1:
								if (top.CORE.axi_lsu.rvalid || top.CORE.axi_lsu.bvalid) begin
									top.CORE.exu2lsu.ready <= 0;
									top.CORE.lsu2wbu.valid <= 1;
								end
								else begin
									top.CORE.exu2lsu.ready <= 0;
									top.CORE.lsu2wbu.valid <= 0;
								end
							2'd2:
								if (top.CORE.lsu2wbu.ready) begin
									top.CORE.exu2lsu.ready <= 1;
									top.CORE.lsu2wbu.valid <= 0;
								end
								else begin
									top.CORE.exu2lsu.ready <= 0;
									top.CORE.lsu2wbu.valid <= 1;
								end
						endcase
				wire [31:0] alu_res;
				wire [31:0] ldata;
				reg [4:0] rshamt;
				always @(*) begin
					if (_sv2v_0)
						;
					case (top.CORE.exu2lsu.alu_res[1:0])
						2'b00: rshamt = 0;
						2'b01: rshamt = 8;
						2'b10: rshamt = 16;
						2'b11: rshamt = 24;
					endcase
				end
				function automatic [31:0] Mr;
					input reg [31:0] tmp;
					input reg [2:0] funct_3;
					(* full_case, parallel_case *)
					case (funct_3)
						3'b000: Mr = {{24 {tmp[7]}}, tmp[7:0]};
						3'b001: Mr = {{16 {tmp[15]}}, tmp[15:0]};
						3'b010: Mr = tmp[31:0];
						3'b100: Mr = {24'b000000000000000000000000, tmp[7:0]};
						3'b101: Mr = {16'b0000000000000000, tmp[15:0]};
						default: Mr = 0;
					endcase
				endfunction
				always @(posedge clock)
					if (reset) begin
						top.CORE.axi_lsu.arvalid <= 0;
						top.CORE.axi_lsu.rready <= 1;
						top.CORE.axi_lsu.awvalid <= 0;
						top.CORE.axi_lsu.wvalid <= 0;
						top.CORE.axi_lsu.bready <= 1;
						top.CORE.axi_lsu.araddr <= 0;
						top.CORE.axi_lsu.awaddr <= 0;
						top.CORE.axi_lsu.wdata <= 0;
						top.CORE.axi_lsu.wstrb <= 0;
						top.CORE.lsu2wbu.alu_res <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.exu2lsu.valid) begin
									if (top.CORE.exu2lsu.load) begin
										top.CORE.axi_lsu.arvalid <= 1;
										top.CORE.axi_lsu.rready <= 1;
										top.CORE.axi_lsu.awvalid <= 0;
										top.CORE.axi_lsu.wvalid <= 0;
										top.CORE.axi_lsu.bready <= 0;
										top.CORE.axi_lsu.araddr <= top.CORE.exu2lsu.alu_res;
									end
									else if (top.CORE.exu2lsu.store) begin
										top.CORE.axi_lsu.arvalid <= 0;
										top.CORE.axi_lsu.rready <= 0;
										top.CORE.axi_lsu.awvalid <= 1;
										top.CORE.axi_lsu.wvalid <= 1;
										top.CORE.axi_lsu.bready <= 1;
										top.CORE.axi_lsu.awaddr <= top.CORE.exu2lsu.alu_res;
										top.CORE.axi_lsu.wdata <= top.CORE.exu2lsu.sdata;
										top.CORE.axi_lsu.wstrb <= (top.CORE.exu2lsu.funct3 == 3'b000 ? 4'b0001 : (top.CORE.exu2lsu.funct3 == 3'b001 ? 4'b0011 : (top.CORE.exu2lsu.funct3 == 3'b010 ? 4'b1111 : 4'b0000)));
									end
									else begin
										top.CORE.axi_lsu.arvalid <= 0;
										top.CORE.axi_lsu.rready <= 0;
										top.CORE.axi_lsu.awvalid <= 0;
										top.CORE.axi_lsu.wvalid <= 0;
										top.CORE.axi_lsu.bready <= 0;
										top.CORE.lsu2wbu.alu_res <= top.CORE.exu2lsu.alu_res;
									end
								end
								else begin
									top.CORE.axi_lsu.arvalid <= 0;
									top.CORE.axi_lsu.rready <= 1;
									top.CORE.axi_lsu.awvalid <= 0;
									top.CORE.axi_lsu.wvalid <= 0;
									top.CORE.axi_lsu.bready <= 1;
								end
							2'd1:
								if (top.CORE.axi_lsu.rvalid || top.CORE.axi_lsu.bvalid) begin
									top.CORE.axi_lsu.arvalid <= 0;
									top.CORE.axi_lsu.rready <= 0;
									top.CORE.axi_lsu.awvalid <= 0;
									top.CORE.axi_lsu.wvalid <= 0;
									top.CORE.axi_lsu.bready <= 0;
									top.CORE.lsu2wbu.alu_res <= Mr(top.CORE.axi_lsu.rdata >> rshamt, top.CORE.exu2lsu.funct3);
								end
							2'd2:
								if (top.CORE.lsu2wbu.ready) begin
									top.CORE.axi_lsu.arvalid <= 0;
									top.CORE.axi_lsu.rready <= 1;
									top.CORE.axi_lsu.awvalid <= 0;
									top.CORE.axi_lsu.wvalid <= 0;
									top.CORE.axi_lsu.bready <= 1;
								end
								else begin
									top.CORE.axi_lsu.arvalid <= 0;
									top.CORE.axi_lsu.rready <= 0;
									top.CORE.axi_lsu.awvalid <= 0;
									top.CORE.axi_lsu.wvalid <= 0;
									top.CORE.axi_lsu.bready <= 0;
								end
						endcase
				always @(posedge clock)
					if (reset) begin
						top.CORE.lsu2wbu.dnpc <= 1'sb0;
						top.CORE.lsu2wbu.rd_addr <= 1'sb0;
						top.CORE.lsu2wbu.wb <= 1'sb0;
						top.CORE.lsu2wbu.jump <= 1'sb0;
						top.CORE.lsu2wbu.branch <= 1'sb0;
						top.CORE.lsu2wbu.csr_addr <= 1'sb0;
						top.CORE.lsu2wbu.csr_we <= 1'sb0;
						top.CORE.lsu2wbu.csr_wdata <= 1'sb0;
						top.CORE.lsu2wbu.ecall <= 1'sb0;
					end
					else begin
						top.CORE.lsu2wbu.dnpc <= top.CORE.exu2lsu.dnpc;
						top.CORE.lsu2wbu.rd_addr <= top.CORE.exu2lsu.rd_addr;
						top.CORE.lsu2wbu.wb <= top.CORE.exu2lsu.wb;
						top.CORE.lsu2wbu.jump <= top.CORE.exu2lsu.jump;
						top.CORE.lsu2wbu.branch <= top.CORE.exu2lsu.branch;
						top.CORE.lsu2wbu.csr_addr <= top.CORE.exu2lsu.csr_addr;
						top.CORE.lsu2wbu.csr_we <= top.CORE.exu2lsu.csr_we;
						top.CORE.lsu2wbu.csr_wdata <= top.CORE.exu2lsu.csr_wdata;
						top.CORE.lsu2wbu.ecall <= top.CORE.exu2lsu.ecall;
					end
				initial _sv2v_0 = 0;
			end
			assign LSU.clock = clock;
			assign LSU.reset = reset;
			if (1) begin : WBU
				reg _sv2v_0;
				wire clock;
				wire reset;
				reg [4:0] rd;
				reg [31:0] wdata;
				reg we;
				reg csr_we;
				reg [11:0] csr_waddr;
				reg [31:0] csr_wdata;
				reg [1:0] curr;
				reg [1:0] next;
				always @(posedge clock)
					if (reset)
						curr <= 2'd3;
					else
						curr <= next;
				always @(*) begin
					if (_sv2v_0)
						;
					(* full_case, parallel_case *)
					case (curr)
						2'd0:
							if (top.CORE.lsu2wbu.valid)
								next = 2'd1;
							else
								next = 2'd0;
						2'd1, 2'd2:
							if (top.CORE.wbu2ifu.ready)
								next = 2'd0;
							else
								next = 2'd2;
						2'd3: next = 2'd0;
					endcase
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.lsu2wbu.ready <= 0;
						top.CORE.wbu2ifu.valid <= 0;
					end
					else
						(* full_case, parallel_case *)
						case (curr)
							2'd0:
								if (top.CORE.lsu2wbu.valid) begin
									top.CORE.lsu2wbu.ready <= 0;
									top.CORE.wbu2ifu.valid <= 1;
								end
								else begin
									top.CORE.lsu2wbu.ready <= 1;
									top.CORE.wbu2ifu.valid <= 0;
								end
							2'd1, 2'd2:
								if (top.CORE.wbu2ifu.ready) begin
									top.CORE.lsu2wbu.ready <= 1;
									top.CORE.wbu2ifu.valid <= 0;
								end
								else begin
									top.CORE.lsu2wbu.ready <= 0;
									top.CORE.wbu2ifu.valid <= 1;
								end
							2'd3: begin
								top.CORE.lsu2wbu.ready <= 0;
								top.CORE.wbu2ifu.valid <= 1;
							end
						endcase
				always @(posedge clock)
					if (reset) begin
						rd <= 1'sb0;
						wdata <= 1'sb0;
						we <= 1'sb0;
						csr_we <= 1'sb0;
						csr_waddr <= 1'sb0;
						csr_wdata <= 1'sb0;
					end
					else if ((curr == 2'd0) && top.CORE.lsu2wbu.valid) begin
						if (top.CORE.lsu2wbu.wb) begin
							rd <= top.CORE.lsu2wbu.rd_addr;
							wdata <= top.CORE.lsu2wbu.alu_res;
							we <= top.CORE.lsu2wbu.wb;
						end
						else if (top.CORE.lsu2wbu.csr_we) begin
							rd <= top.CORE.lsu2wbu.rd_addr;
							wdata <= top.CORE.lsu2wbu.csr_wdata;
							we <= 1'b1;
							csr_we <= top.CORE.lsu2wbu.csr_we;
							csr_waddr <= top.CORE.lsu2wbu.csr_addr;
							csr_wdata <= top.CORE.lsu2wbu.alu_res;
						end
						else if (top.CORE.lsu2wbu.ecall) begin
							csr_we <= 1'b1;
							csr_waddr <= 12'h342;
							csr_wdata <= top.CORE.lsu2wbu.alu_res;
						end
						else begin
							rd <= 1'sb0;
							wdata <= 1'sb0;
							we <= 1'sb0;
							csr_we <= 1'sb0;
							csr_waddr <= 1'sb0;
							csr_wdata <= 1'sb0;
						end
					end
					else begin
						rd <= 1'sb0;
						wdata <= 1'sb0;
						we <= 1'sb0;
						csr_we <= 1'sb0;
						csr_waddr <= 1'sb0;
						csr_wdata <= 1'sb0;
					end
				always @(posedge clock)
					if (reset) begin
						top.CORE.wbu2ifu.dnpc <= 1'sb0;
						top.CORE.wbu2ifu.jump <= 1'sb0;
						top.CORE.wbu2ifu.branch <= 1'sb0;
					end
					else begin
						top.CORE.wbu2ifu.dnpc <= top.CORE.lsu2wbu.dnpc;
						top.CORE.wbu2ifu.jump <= top.CORE.lsu2wbu.jump;
						top.CORE.wbu2ifu.branch <= top.CORE.lsu2wbu.branch;
					end
				initial _sv2v_0 = 0;
			end
			assign WBU.clock = clock;
			assign WBU.reset = reset;
			assign rd = WBU.rd;
			assign wdata = WBU.wdata;
			assign we = WBU.we;
			assign csr_we = WBU.csr_we;
			assign csr_waddr = WBU.csr_waddr;
			assign csr_wdata = WBU.csr_wdata;
		end
	endgenerate
	assign CORE.clock = clock;
	assign CORE.reset = reset;
	assign axi.awready = io_master_awready;
	assign io_master_awvalid = axi.awvalid;
	assign io_master_awaddr = axi.awaddr;
	assign io_master_awid = axi.awid;
	assign io_master_awlen = axi.awlen;
	assign io_master_awsize = axi.awsize;
	assign io_master_awburst = axi.awburst;
	assign axi.wready = io_master_wready;
	assign io_master_wvalid = axi.wvalid;
	assign io_master_wdata = axi.wdata;
	assign io_master_wstrb = axi.wstrb;
	assign io_master_wlast = axi.wlast;
	assign io_master_bready = axi.bready;
	assign axi.bvalid = io_master_bvalid;
	assign axi.bresp = io_master_bresp;
	assign axi.bid = io_master_bid;
	assign axi.arready = io_master_arready;
	assign io_master_arvalid = axi.arvalid;
	assign io_master_araddr = axi.araddr;
	assign io_master_arid = axi.arid;
	assign io_master_arlen = axi.arlen;
	assign io_master_arsize = axi.arsize;
	assign io_master_arburst = axi.arburst;
	assign io_master_rready = axi.rready;
	assign axi.rvalid = io_master_rvalid;
	assign axi.rresp = io_master_rresp;
	assign axi.rdata = io_master_rdata;
	assign axi.rlast = io_master_rlast;
	assign axi.rid = io_master_rid;
endmodule
module ysyx_24080006_alu (
	src1,
	src2,
	ctrl,
	res
);
	reg _sv2v_0;
	input wire [31:0] src1;
	input wire [31:0] src2;
	input wire [3:0] ctrl;
	output reg [31:0] res;
	localparam ADD = 4'b0000;
	localparam SUB = 4'b1000;
	localparam SLL = 4'b0001;
	localparam SLT = 4'b0010;
	localparam SLTU = 4'b0011;
	localparam XOR = 4'b0100;
	localparam SRL = 4'b0101;
	localparam SRA = 4'b1101;
	localparam OR = 4'b0110;
	localparam AND = 4'b0111;
	wire [33:0] add_res_t;
	wire [32:0] srcA;
	reg [32:0] srcB;
	wire [32:0] srcB_t;
	wire [31:0] add_res;
	assign srcA = {src1, 1'b1};
	assign srcB_t = {src2, 1'b0};
	always @(*) begin
		if (_sv2v_0)
			;
		srcB = srcB_t;
		case (ctrl)
			ADD: srcB = srcB_t;
			SUB, SLT, SLTU: srcB = ~srcB_t;
			default:
				;
		endcase
	end
	assign add_res_t = {1'b0, srcA} + {1'b0, srcB};
	assign add_res = add_res_t[32:1];
	reg comp_res;
	always @(*) begin
		if (_sv2v_0)
			;
		comp_res = add_res_t[33];
		case (ctrl)
			SLT: comp_res = add_res_t[32] ^ (((!srcA[32] && srcB_t[32]) && add_res_t[32]) || ((srcA[32] && !srcB_t[32]) && !add_res_t[32]));
			SLTU: comp_res = !add_res_t[33];
			default:
				;
		endcase
	end
	reg [31:0] shift_res;
	wire [4:0] shift;
	assign shift = src2[4:0];
	reg [31:0] shift_src;
	always @(*) begin
		if (_sv2v_0)
			;
		shift_src = src1;
		case (ctrl)
			SLL: begin : sv2v_autoblock_1
				reg signed [31:0] i;
				for (i = 0; i < 32; i = i + 1)
					shift_src[i] = src1[31 - i];
			end
			SRL, SRA: shift_src = src1;
			default:
				;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		shift_res = src1 >> shift;
		case (ctrl)
			SLL, SRL: shift_res = shift_src >> shift;
			SRA: shift_res = ({32 {src1[31]}} << (31 - shift)) | (src1 >> shift);
			default:
				;
		endcase
	end
	reg [31:0] bit_res;
	always @(*) begin
		if (_sv2v_0)
			;
		bit_res = src1 & src2;
		case (ctrl)
			AND: bit_res = src1 & src2;
			OR: bit_res = src1 | src2;
			XOR: bit_res = src1 ^ src2;
			default:
				;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		res = add_res;
		case (ctrl)
			ADD, SUB: res = add_res;
			SLT, SLTU: res = {31'b0000000000000000000000000000000, comp_res};
			SLL: begin : sv2v_autoblock_2
				reg signed [31:0] i;
				for (i = 0; i < 32; i = i + 1)
					res[i] = shift_res[31 - i];
			end
			SRL, SRA: res = shift_res;
			AND, OR, XOR: res = bit_res;
			default:
				;
		endcase
	end
	initial _sv2v_0 = 0;
endmodule
module ysyx_24080006_csr (
	clock,
	reset,
	csr_we,
	mepc_val,
	mepc_en,
	csr_addr,
	csr_waddr,
	csr_wdata,
	csr_rdata
);
	reg _sv2v_0;
	input wire clock;
	input wire reset;
	input wire csr_we;
	input wire [31:0] mepc_val;
	input wire mepc_en;
	input wire [11:0] csr_addr;
	input wire [11:0] csr_waddr;
	input wire [31:0] csr_wdata;
	output wire [31:0] csr_rdata;
	reg [31:0] regfile [0:3];
	reg [1:0] csr_r;
	reg [1:0] csr_w;
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (csr_addr)
			12'h300: csr_r = 2'b00;
			12'h305: csr_r = 2'b01;
			12'h341: csr_r = 2'b10;
			12'h342: csr_r = 2'b11;
			default: csr_r = 2'b00;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (csr_waddr)
			12'h300: csr_w = 2'b00;
			12'h305: csr_w = 2'b01;
			12'h341: csr_w = 2'b10;
			12'h342: csr_w = 2'b11;
			default: csr_w = 2'b00;
		endcase
	end
	assign csr_rdata = regfile[csr_r];
	always @(posedge clock)
		if (reset) begin
			regfile[0] <= 32'h00001800;
			regfile[1] <= 1'sb0;
			regfile[2] <= 1'sb0;
			regfile[3] <= 1'sb0;
		end
		else if (csr_we)
			regfile[csr_w] <= csr_wdata;
		else if (mepc_en)
			regfile[2'b10] <= mepc_val;
	initial _sv2v_0 = 0;
endmodule
module ysyx_24080006_imm (
	inst,
	imm
);
	reg _sv2v_0;
	input wire [31:0] inst;
	output reg [31:0] imm;
	always @(*) begin
		if (_sv2v_0)
			;
		imm = {{20 {inst[31]}}, inst[31:20]};
		(* full_case, parallel_case *)
		case (inst[6:0])
			7'b0010011, 7'b0000011, 7'b1100111: imm = {{20 {inst[31]}}, inst[31:20]};
			7'b0100011: imm = {{20 {inst[31]}}, inst[31:25], inst[11:7]};
			7'b1100011: imm = {{20 {inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
			7'b0110111, 7'b0010111: imm = {inst[31:12], 12'b000000000000};
			7'b1101111: imm = {{12 {inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
			default:
				;
		endcase
	end
	initial _sv2v_0 = 0;
endmodule
module ysyx_24080006_reg (
	clock,
	reset,
	we,
	rs1_addr,
	rs2_addr,
	rd,
	wdata,
	rs1_val,
	rs2_val
);
	reg _sv2v_0;
	input wire clock;
	input wire reset;
	input wire we;
	input wire [4:0] rs1_addr;
	input wire [4:0] rs2_addr;
	input wire [4:0] rd;
	input wire [31:0] wdata;
	output reg [31:0] rs1_val;
	output reg [31:0] rs2_val;
	reg [31:0] regfile [0:31];
	always @(posedge clock)
		if (reset) begin : sv2v_autoblock_1
			integer i;
			for (i = 0; i <= 31; i = i + 1)
				regfile[i] <= 1'sb0;
		end
		else if (we && (rd != 5'b00000))
			regfile[rd] <= wdata;
	always @(*) begin
		if (_sv2v_0)
			;
		rs1_val = regfile[rs1_addr];
		rs2_val = regfile[rs2_addr];
	end
	initial _sv2v_0 = 0;
endmodule
