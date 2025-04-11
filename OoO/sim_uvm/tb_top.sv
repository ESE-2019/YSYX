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
  ibex_mem_intf data_mem_vif (.clk(clk));
  ibex_mem_intf instr_mem_vif (.clk(clk));

  axi_r_m2s_t ifu_r_m2s;
  axi_r_s2m_t ifu_r_s2m;

  axi_w_m2s_t lsu_w_m2s;
  axi_w_s2m_t lsu_w_s2m;
  axi_r_m2s_t lsu_r_m2s;
  axi_r_s2m_t lsu_r_s2m;

  initial begin
    // Drive the clock and reset lines. Reset everything and start the clock at the beginning of
    // time
    ibex_clk_if.set_active();
    fork
      ibex_clk_if.apply_reset(.reset_width_clks(100));
    join_none

    uvm_config_db#(virtual clk_rst_if)::set(null, "*", "clk_if", ibex_clk_if);
    uvm_config_db#(virtual ibex_mem_intf)::set(null, "*data_if_response*", "vif", data_mem_vif);
    uvm_config_db#(virtual ibex_mem_intf)::set(null, "*instr_if_response*", "vif", instr_mem_vif);
    uvm_config_db#(virtual core_ibex_ifetch_if)::set(null, "*", "ifetch_if", ifetch_if);

    // Expose ISA config parameters to UVM DB
    uvm_config_db#(bit)::set(null, "*", "RV32E", RV32E);
    uvm_config_db#(ibex_pkg::rv32m_e)::set(null, "*", "RV32M", RV32M);
    uvm_config_db#(ibex_pkg::rv32b_e)::set(null, "*", "RV32B", RV32B);


    run_test();
  end

  // Data load/store vif connection
  assign data_mem_vif.reset = ~rst_n;
  //   assign data_mem_vif.rintg = '0;
  //   assign data_mem_vif.wintg= '0;
  //   assign data_mem_vif.error = '0;
  //   assign data_mem_vif.misaligned_first ='0;
  //   assign data_mem_vif.misaligned_second ='0;
  //   assign data_mem_vif.misaligned_first_saw_error ='0;
  //   assign data_mem_vif.m_mode_access ='1;
  // Instruction fetch vif connnection
  assign instr_mem_vif.reset = ~rst_n;
  assign instr_mem_vif.we    = 0;
  assign instr_mem_vif.be    = 0;
  assign instr_mem_vif.wdata = 0;
  //   assign instr_mem_vif.rintg = '0;
  //   assign instr_mem_vif.error = '0;

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

  ooo_core CORE (
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



endmodule
