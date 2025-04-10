// Copyright 2018 lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// ---------------------------------------------
// Core ibex test package
// ---------------------------------------------
package core_ibex_test_pkg;

  import uvm_pkg::*;
  import core_ibex_env_pkg::*;
  import ibex_mem_intf_pkg::*;
  import ibex_mem_intf_agent_pkg::*;
  import riscv_signature_pkg::*;
  import ibex_pkg::*;

  typedef struct {
    ibex_pkg::opcode_e  opcode;
    bit [2:0]           funct3;
    bit [6:0]           funct7;
    // 12-bit immediate, used only for SYSTEM instructions
    bit [11:0]          system_imm;
  } instr_t;

  typedef class core_ibex_vseq;

  // For new_seq_lib...

  typedef enum bit [1:0] {
    SingleRun,    // Single iteration
    InfiniteRuns, // Run forever until stop is specified
    MultipleRuns  // Multiple runs with configurable or randomizable iteration count
    } run_type_e;
  typedef enum bit [1:0] {
    IsideErr, // Inject error in instruction side memory.
    DsideErr, // Inject error in data side memory.
    PickErr   // Pick which memory to inject error in.
    } error_type_e;

  typedef virtual push_pull_if#(
    .DeviceDataWidth(ibex_pkg::SCRAMBLE_NONCE_W + ibex_pkg::SCRAMBLE_KEY_W)
    ) scrambling_key_vif;

  `include "core_ibex_report_server.sv"
  `include "core_ibex_seq_lib.sv"
  `include "core_ibex_new_seq_lib.sv"
  `include "core_ibex_vseq.sv"
  `include "core_ibex_base_test.sv"
  `include "core_ibex_test_lib.sv"

endpackage
