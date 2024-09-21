module top (
	clk,
	rst
);
	input wire clk;
	input wire rst;
	generate
		if (1) begin : axi_sram
			wire aclk;
			wire aresetn;
			reg awready;
			wire awvalid;
			wire [31:0] awaddr;
			wire [3:0] awid;
			wire [7:0] awlen;
			wire [2:0] awsize;
			wire [1:0] awburst;
			reg wready;
			wire wvalid;
			wire [31:0] wdata;
			wire [3:0] wstrb;
			wire wlast;
			wire bready;
			reg bvalid;
			reg [1:0] bresp;
			wire [3:0] bid;
			reg arready;
			wire arvalid;
			wire [31:0] araddr;
			wire [3:0] arid;
			wire [7:0] arlen;
			wire [2:0] arsize;
			wire [1:0] arburst;
			wire rready;
			reg rvalid;
			reg [1:0] rresp;
			reg [31:0] rdata;
			wire rlast;
			wire [3:0] rid;
		end
	endgenerate
	assign axi_sram.aclk = clk;
	assign axi_sram.aresetn = !rst;
	generate
		if (1) begin : sram
			reg _sv2v_0;
			import "DPI-C"  function signed [31:0] pmem_read(
				input wire signed [31:0] raddr
			);
			import "DPI-C"  function void pmem_write(
				input wire signed [31:0] waddr,
				input wire signed [31:0] wdata,
				input wire signed [31:0] wmask
			);
			reg [63:0] mtime;
			reg [31:0] dout;
			always @(posedge top.axi_sram.aclk)
				if (!top.axi_sram.aresetn)
					mtime <= 1'sb0;
				else
					mtime <= mtime + 64'b0000000000000000000000000000000000000000000000000000000000000001;
			always @(*) begin
				if (_sv2v_0)
					;
				dout = 1'sb0;
				(* full_case, parallel_case *)
				case (top.axi_sram.araddr)
					32'ha0000048: dout = mtime[31:0];
					32'ha000004c: dout = mtime[63:32];
					default:
						;
				endcase
			end
			always @(posedge top.axi_sram.aclk)
				if (!top.axi_sram.aresetn) begin
					top.axi_sram.awready <= 1;
					top.axi_sram.wready <= 1;
					top.axi_sram.bvalid <= 0;
				end
				else if ((((top.axi_sram.awvalid && top.axi_sram.wvalid) && top.axi_sram.awready) && top.axi_sram.wready) && !top.axi_sram.bvalid) begin
					top.axi_sram.awready <= 0;
					top.axi_sram.wready <= 0;
					top.axi_sram.bvalid <= 1;
					top.axi_sram.bresp <= 2'b00;
					if (top.axi_sram.awaddr == 32'ha00003f8)
						$write("%c", top.axi_sram.wdata[7:0]);
					else
						pmem_write(top.axi_sram.awaddr, top.axi_sram.wdata, {28'b0000000000000000000000000000, top.axi_sram.wstrb});
				end
				else if (top.axi_sram.bready) begin
					top.axi_sram.awready <= 1;
					top.axi_sram.wready <= 1;
					top.axi_sram.bvalid <= 0;
				end
			always @(posedge top.axi_sram.aclk)
				if (!top.axi_sram.aresetn) begin
					top.axi_sram.arready <= 1;
					top.axi_sram.rvalid <= 0;
				end
				else if ((top.axi_sram.arvalid && top.axi_sram.arready) && !top.axi_sram.rvalid) begin
					top.axi_sram.arready <= 0;
					top.axi_sram.rdata <= (top.axi_sram.araddr >= 32'ha0000000 ? dout : pmem_read(top.axi_sram.araddr));
					top.axi_sram.rvalid <= 1;
					top.axi_sram.rresp <= 2'b00;
				end
				else if (top.axi_sram.rready) begin
					top.axi_sram.arready <= 1;
					top.axi_sram.rvalid <= 0;
				end
			initial _sv2v_0 = 0;
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
				wire [1:0] alu_set;
				wire [31:0] alu_res;
				reg [4:0] rd_addr;
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
				wire [2:0] funct3;
				wire load;
				wire store;
				wire wb;
				reg jump;
				reg branch;
			end
			if (1) begin : axi_ifu
				wire aclk;
				wire aresetn;
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
			assign axi_ifu.aclk = clock;
			assign axi_ifu.aresetn = !reset;
			if (1) begin : axi_lsu
				wire aclk;
				wire aresetn;
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
			assign axi_lsu.aclk = clock;
			assign axi_lsu.aresetn = !reset;
			if (1) begin : ARB
				reg [1:0] arbiter_state;
				localparam IDLE = 2'b00;
				localparam M0_ACTIVE = 2'b01;
				localparam M1_ACTIVE = 2'b10;
				always @(posedge top.CORE.axi_ifu.aclk)
					if (!top.CORE.axi_ifu.aresetn)
						arbiter_state <= IDLE;
					else
						case (arbiter_state)
							IDLE:
								if (top.CORE.axi_ifu.awvalid || top.CORE.axi_ifu.arvalid)
									arbiter_state <= M0_ACTIVE;
								else if (top.CORE.axi_lsu.awvalid || top.CORE.axi_lsu.arvalid)
									arbiter_state <= M1_ACTIVE;
							M0_ACTIVE:
								if ((top.CORE.axi_ifu.bvalid && top.CORE.axi_ifu.bready) || (top.CORE.axi_ifu.rready && top.CORE.axi_ifu.rvalid))
									arbiter_state <= IDLE;
							M1_ACTIVE:
								if ((top.CORE.axi_lsu.bvalid && top.CORE.axi_lsu.bready) || (top.CORE.axi_lsu.rready && top.CORE.axi_lsu.rvalid))
									arbiter_state <= IDLE;
							default: arbiter_state <= IDLE;
						endcase
				assign top.CORE.axi_ifu.awready = (arbiter_state == M0_ACTIVE ? top.axi_sram.awready : 1'b0);
				assign top.CORE.axi_ifu.wready = (arbiter_state == M0_ACTIVE ? top.axi_sram.wready : 1'b0);
				assign top.CORE.axi_ifu.bresp = top.axi_sram.bresp;
				assign top.CORE.axi_ifu.bvalid = (arbiter_state == M0_ACTIVE ? top.axi_sram.bvalid : 1'b0);
				assign top.CORE.axi_ifu.arready = (arbiter_state == M0_ACTIVE ? top.axi_sram.arready : 1'b0);
				assign top.CORE.axi_ifu.rdata = top.axi_sram.rdata;
				assign top.CORE.axi_ifu.rresp = top.axi_sram.rresp;
				assign top.CORE.axi_ifu.rvalid = (arbiter_state == M0_ACTIVE ? top.axi_sram.rvalid : 1'b0);
				assign top.CORE.axi_lsu.awready = (arbiter_state == M1_ACTIVE ? top.axi_sram.awready : 1'b0);
				assign top.CORE.axi_lsu.wready = (arbiter_state == M1_ACTIVE ? top.axi_sram.wready : 1'b0);
				assign top.CORE.axi_lsu.bresp = top.axi_sram.bresp;
				assign top.CORE.axi_lsu.bvalid = (arbiter_state == M1_ACTIVE ? top.axi_sram.bvalid : 1'b0);
				assign top.CORE.axi_lsu.arready = (arbiter_state == M1_ACTIVE ? top.axi_sram.arready : 1'b0);
				assign top.CORE.axi_lsu.rdata = top.axi_sram.rdata;
				assign top.CORE.axi_lsu.rresp = top.axi_sram.rresp;
				assign top.CORE.axi_lsu.rvalid = (arbiter_state == M1_ACTIVE ? top.axi_sram.rvalid : 1'b0);
				assign top.axi_sram.awaddr = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.awaddr : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.awaddr : 32'b00000000000000000000000000000000));
				assign top.axi_sram.awvalid = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.awvalid : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.awvalid : 1'b0));
				assign top.axi_sram.wdata = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.wdata : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.wdata : 32'b00000000000000000000000000000000));
				assign top.axi_sram.wstrb = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.wstrb : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.wstrb : 4'b0000));
				assign top.axi_sram.wvalid = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.wvalid : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.wvalid : 1'b0));
				assign top.axi_sram.bready = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.bready : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.bready : 1'b0));
				assign top.axi_sram.araddr = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.araddr : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.araddr : 32'b00000000000000000000000000000000));
				assign top.axi_sram.arvalid = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.arvalid : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.arvalid : 1'b0));
				assign top.axi_sram.rready = (arbiter_state == M0_ACTIVE ? top.CORE.axi_ifu.rready : (arbiter_state == M1_ACTIVE ? top.CORE.axi_lsu.rready : 1'b0));
			end
			wire we;
			wire [4:0] rs1_addr;
			wire [4:0] rs2_addr;
			wire [4:0] rd;
			wire [31:0] wdata;
			wire [31:0] rs1_val;
			wire [31:0] rs2_val;
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
			if (1) begin : IFU
				reg _sv2v_0;
				wire clock;
				wire reset;
				reg [31:0] pc;
				localparam RST_ADDR = 32'h80000000;
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
									top.CORE.axi_ifu.arvalid <= 0;
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
									top.CORE.idu2exu.valid <= 0;
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
				assign rs1_addr = top.CORE.ifu2idu.inst[19:15];
				assign rs2_addr = top.CORE.ifu2idu.inst[24:20];
				assign rd_addr = top.CORE.ifu2idu.inst[11:7];
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
					if (opcode == jalr)
						dnpc = rs1_val + imm;
					else
						dnpc = top.CORE.ifu2idu.pc + imm;
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.idu2exu.alu_src1 <= 1'sb0;
						top.CORE.idu2exu.alu_src2 <= 1'sb0;
						top.CORE.idu2exu.alu_ctrl <= 1'sb0;
						top.CORE.idu2exu.imm <= 1'sb0;
						top.CORE.idu2exu.rd_addr <= 1'sb0;
						top.CORE.idu2exu.dnpc <= 1'sb0;
						top.CORE.idu2exu.sdata <= 1'sb0;
					end
					else if ((curr == 2'd0) && top.CORE.ifu2idu.valid) begin
						top.CORE.idu2exu.alu_src1 <= alu_src1;
						top.CORE.idu2exu.alu_src2 <= alu_src2;
						top.CORE.idu2exu.alu_ctrl <= alu_ctrl;
						top.CORE.idu2exu.imm <= imm;
						top.CORE.idu2exu.rd_addr <= rd_addr;
						top.CORE.idu2exu.dnpc <= dnpc;
						top.CORE.idu2exu.sdata <= rs2_val;
					end
				always @(posedge clock)
					if (reset) begin
						top.CORE.idu2exu.funct3 <= 1'sb0;
						top.CORE.idu2exu.load <= 1'sb0;
						top.CORE.idu2exu.store <= 1'sb0;
						top.CORE.idu2exu.wb <= 1'sb0;
						top.CORE.idu2exu.jump <= 1'sb0;
						top.CORE.idu2exu.branch <= 1'sb0;
					end
					else if ((curr == 2'd0) && top.CORE.ifu2idu.valid) begin
						top.CORE.idu2exu.funct3 <= funct3;
						top.CORE.idu2exu.load <= opcode == load;
						top.CORE.idu2exu.store <= opcode == S_type;
						top.CORE.idu2exu.wb <= |{opcode == auipc, opcode == lui, opcode == jal, opcode == jalr, opcode == I_type, opcode == R_type, opcode == load};
						top.CORE.idu2exu.jump <= |{opcode == jal, opcode == jalr};
						top.CORE.idu2exu.branch <= opcode == B_type;
					end
				always @(posedge clock)
					if (opcode == system)
						$finish;
				initial _sv2v_0 = 0;
			end
			assign IDU.clock = clock;
			assign IDU.reset = reset;
			assign rs1_addr = IDU.rs1_addr;
			assign rs2_addr = IDU.rs2_addr;
			assign IDU.rs1_val = rs1_val;
			assign IDU.rs2_val = rs2_val;
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
									top.CORE.exu2lsu.valid <= 0;
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
				reg [31:0] alu_res;
				reg [31:0] ldata;
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
						ldata <= 0;
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
										top.CORE.axi_lsu.araddr <= {top.CORE.exu2lsu.alu_res[31:2], 2'b00};
									end
									else if (top.CORE.exu2lsu.store) begin
										top.CORE.axi_lsu.arvalid <= 0;
										top.CORE.axi_lsu.rready <= 0;
										top.CORE.axi_lsu.awvalid <= 1;
										top.CORE.axi_lsu.wvalid <= 1;
										top.CORE.axi_lsu.bready <= 1;
										top.CORE.axi_lsu.awaddr <= {top.CORE.exu2lsu.alu_res[31:2], 2'b00};
										top.CORE.axi_lsu.wdata <= top.CORE.exu2lsu.sdata;
										top.CORE.axi_lsu.wstrb <= (top.CORE.exu2lsu.funct3 == 3'b000 ? 4'b0001 : (top.CORE.exu2lsu.funct3 == 3'b001 ? 4'b0011 : (top.CORE.exu2lsu.funct3 == 3'b010 ? 4'b1111 : 4'b0000)));
									end
									else begin
										top.CORE.axi_lsu.arvalid <= 0;
										top.CORE.axi_lsu.rready <= 0;
										top.CORE.axi_lsu.awvalid <= 0;
										top.CORE.axi_lsu.wvalid <= 0;
										top.CORE.axi_lsu.bready <= 0;
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
									ldata <= top.CORE.axi_lsu.rdata;
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
					if (top.CORE.exu2lsu.load)
						alu_res = ldata >> rshamt;
					else
						alu_res = top.CORE.exu2lsu.alu_res;
				end
				always @(posedge clock)
					if (reset) begin
						top.CORE.lsu2wbu.dnpc <= 1'sb0;
						top.CORE.lsu2wbu.rd_addr <= 1'sb0;
						top.CORE.lsu2wbu.alu_res <= 1'sb0;
						top.CORE.lsu2wbu.wb <= 1'sb0;
						top.CORE.lsu2wbu.jump <= 1'sb0;
						top.CORE.lsu2wbu.branch <= 1'sb0;
					end
					else begin
						top.CORE.lsu2wbu.dnpc <= top.CORE.exu2lsu.dnpc;
						top.CORE.lsu2wbu.rd_addr <= top.CORE.exu2lsu.rd_addr;
						top.CORE.lsu2wbu.alu_res <= alu_res;
						top.CORE.lsu2wbu.wb <= top.CORE.exu2lsu.wb;
						top.CORE.lsu2wbu.jump <= top.CORE.exu2lsu.jump;
						top.CORE.lsu2wbu.branch <= top.CORE.exu2lsu.branch;
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
					end
					else if ((curr == 2'd0) && top.CORE.lsu2wbu.valid) begin
						if (top.CORE.lsu2wbu.wb) begin
							rd <= top.CORE.lsu2wbu.rd_addr;
							wdata <= top.CORE.lsu2wbu.alu_res;
							we <= 1'b1;
						end
						else begin
							rd <= 1'sb0;
							wdata <= 1'sb0;
							we <= 1'sb0;
						end
					end
					else begin
						rd <= 1'sb0;
						wdata <= 1'sb0;
						we <= 1'sb0;
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
		end
	endgenerate
	assign CORE.clock = clk;
	assign CORE.reset = rst;
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
			SRA: shift_res = $signed(shift_src) >>> shift;
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
	input wire clock;
	input wire reset;
	input wire we;
	input wire [4:0] rs1_addr;
	input wire [4:0] rs2_addr;
	input wire [4:0] rd;
	input wire [31:0] wdata;
	output wire [31:0] rs1_val;
	output wire [31:0] rs2_val;
	reg [31:0] regfile [0:31];
	assign rs1_val = regfile[rs1_addr];
	assign rs2_val = regfile[rs2_addr];
	always @(posedge clock)
		if (reset) begin : sv2v_autoblock_1
			integer i;
			for (i = 0; i <= 31; i = i + 1)
				regfile[i] <= 1'sb0;
		end
		else if (we && (rd != 5'b00000))
			regfile[rd] <= wdata;
endmodule
