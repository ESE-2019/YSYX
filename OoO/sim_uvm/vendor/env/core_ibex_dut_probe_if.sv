// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// Interface to probe DUT internal signal
interface core_ibex_dut_probe_if (
    input logic clk
);

  import uvm_pkg::*;

  logic reset;
  logic rf_ren_a;
  logic rf_ren_b;
  logic rf_rd_a_wb_match;
  logic rf_rd_b_wb_match;
  logic rf_write_wb;


  clocking dut_cb @(posedge clk);
    input reset;
    input rf_ren_a;
    input rf_ren_b;
    input rf_rd_a_wb_match;
    input rf_rd_b_wb_match;
    input rf_write_wb;
  endclocking

  `DV_CREATE_SIGNAL_PROBE_FUNCTION(signal_probe_rf_ren_a, rf_ren_a)
  `DV_CREATE_SIGNAL_PROBE_FUNCTION(signal_probe_rf_ren_b, rf_ren_b)
  `DV_CREATE_SIGNAL_PROBE_FUNCTION(signal_probe_rf_rd_a_wb_match, rf_rd_a_wb_match)
  `DV_CREATE_SIGNAL_PROBE_FUNCTION(signal_probe_rf_rd_b_wb_match, rf_rd_b_wb_match)
  `DV_CREATE_SIGNAL_PROBE_FUNCTION(signal_probe_rf_write_wb, rf_write_wb)

endinterface
