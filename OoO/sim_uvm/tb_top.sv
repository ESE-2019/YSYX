module tb_top;
  import OoO_pkg::*;

  import uvm_pkg::*;
  import core_ibex_test_pkg::*;

  wire clk;
  wire rst_n;

  clk_rst_if ibex_clk_if (
      .clk  (clk),
      .rst_n(rst_n)
  );
  irq_if irq_vif (.clk(clk));
  ibex_mem_intf data_mem_vif (.clk(clk));
  ibex_mem_intf instr_mem_vif (.clk(clk));

  axi_r_m2s_t ifu_r_m2s;
  axi_r_s2m_t ifu_r_s2m;

  axi_w_m2s_t lsu_w_m2s;
  axi_w_s2m_t lsu_w_s2m;
  axi_r_m2s_t lsu_r_m2s;
  axi_r_s2m_t lsu_r_s2m;



  // Data load/store vif connection
  assign data_mem_vif.reset = ~rst_n;
  assign data_mem_vif.rintg = '0;
  assign data_mem_vif.wintg= '0;
  assign data_mem_vif.error = '0;
  assign data_mem_vif.misaligned_first ='0;
  assign data_mem_vif.misaligned_second ='0;
  assign data_mem_vif.misaligned_first_saw_error ='0;
  assign data_mem_vif.m_mode_access ='1;
  // Instruction fetch vif connnection
  assign instr_mem_vif.reset = ~rst_n;
  assign instr_mem_vif.we    = 0;
  assign instr_mem_vif.be    = 0;
  assign instr_mem_vif.wdata = 0;
  assign instr_mem_vif.rintg = '0;
  assign instr_mem_vif.error = '0;

  logic [ 0:0] rvfi_valid;
  logic [63:0] rvfi_order;
  logic [31:0] rvfi_insn;
  logic [ 0:0] rvfi_trap;
  logic [ 0:0] rvfi_halt;
  logic [ 0:0] rvfi_intr;
  logic [ 1:0] rvfi_mode;
  logic [ 4:0] rvfi_rs1_addr;
  logic [ 4:0] rvfi_rs2_addr;
  logic [31:0] rvfi_rs1_rdata;
  logic [31:0] rvfi_rs2_rdata;
  logic [ 4:0] rvfi_rd_addr;
  logic [31:0] rvfi_rd_wdata;
  logic [31:0] rvfi_pc_rdata;
  logic [31:0] rvfi_pc_wdata;
  logic [31:0] rvfi_mem_addr;
  logic [ 3:0] rvfi_mem_rmask;
  logic [ 3:0] rvfi_mem_wmask;
  logic [31:0] rvfi_mem_rdata;
  logic [31:0] rvfi_mem_wdata;
  logic [ 0:0] rvfi_mem_extamo;
  logic [15:0] errcode;

  ysyx_24080006_core CORE (
      .*,
      .clock(clk),
      .reset(~rst_n),

      .instr_req_o   (instr_mem_vif.request),
      .instr_gnt_i   (instr_mem_vif.grant),
      .instr_rvalid_i(instr_mem_vif.rvalid),
      .instr_addr_o  (instr_mem_vif.addr),
      .instr_rdata_i (instr_mem_vif.rdata),

      .data_req_o   (data_mem_vif.request),
      .data_gnt_i   (data_mem_vif.grant),
      .data_rvalid_i(data_mem_vif.rvalid),
      .data_addr_o  (data_mem_vif.addr),
      .data_we_o    (data_mem_vif.we),
      .data_be_o    (data_mem_vif.be),
      .data_rdata_i (data_mem_vif.rdata),
      .data_wdata_o (data_mem_vif.wdata)
  );

  rvfimon RVFIMON (
      .*,
      .clock(clk),
      .reset(~rst_n)
  );

  ibex_tracer TRACER (
      .*,
      .clk_i(clk),
      .rst_ni(rst_n),
      .hart_id_i('0),
      .rvfi_ixl('0),
      .rvfi_rs3_addr('0),
      .rvfi_rs3_rdata('0)
  );
  dummy_iram IRAM (.*);


  assign core_w_s2m.awready = io_master_awready;
  assign io_master_awvalid = core_w_m2s.awvalid;
  assign io_master_awaddr = core_w_m2s.awaddr;
  assign io_master_awid = '0;  //core_w_m2s.awid;
  assign io_master_awlen = core_w_m2s.awlen;
  assign io_master_awsize = core_w_m2s.awsize;
  assign io_master_awburst = core_w_m2s.awburst;

  assign core_w_s2m.wready = io_master_wready;
  assign io_master_wvalid = core_w_m2s.wvalid;
  assign io_master_wdata = core_w_m2s.wdata;
  assign io_master_wstrb = core_w_m2s.wstrb;
  assign io_master_wlast = core_w_m2s.wlast;

  assign io_master_bready = core_w_m2s.bready;
  assign core_w_s2m.bvalid = io_master_bvalid;
  //assign core_w_s2m.bresp = io_master_bresp;
  //assign core_w_s2m.bid = io_master_bid;

  assign core_r_s2m.arready = io_master_arready;
  assign io_master_arvalid = core_r_m2s.arvalid;
  assign io_master_araddr = core_r_m2s.araddr;
  assign io_master_arid = '0;  //core_r_m2s.arid;
  assign io_master_arlen = core_r_m2s.arlen;
  assign io_master_arsize = core_r_m2s.arsize;
  assign io_master_arburst = core_r_m2s.arburst;

  assign io_master_rready = core_r_m2s.rready;
  assign core_r_s2m.rvalid = io_master_rvalid;
  //assign core_r_s2m.rresp = io_master_rresp;
  assign core_r_s2m.rdata = io_master_rdata;
  assign core_r_s2m.rlast = io_master_rlast;
  //assign core_r_s2m.rid = io_master_rid;

endmodule
