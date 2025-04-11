// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

class core_ibex_env_cfg extends uvm_object;
  bit[31:0]                     max_interval;
  bit                           require_signature_addr;
  string                        signature_addr_str;
  bit[31:0]                     signature_addr;

  // If '1', reaching the timeout in seconds fatally ends the test.
  // If '0', we end the test with a pass.
  bit                          is_timeout_s_fatal = 0;


  `uvm_object_utils_begin(core_ibex_env_cfg)
    `uvm_field_int(max_interval, UVM_DEFAULT)
    `uvm_field_int(require_signature_addr, UVM_DEFAULT)
    `uvm_field_int(signature_addr, UVM_DEFAULT)
  `uvm_object_utils_end

  function new(string name = "");
    super.new(name);
    void'($value$plusargs("is_timeout_s_fatal=%0d", is_timeout_s_fatal));
    void'($value$plusargs("max_interval=%0d", max_interval));
    void'($value$plusargs("require_signature_addr=%0d", require_signature_addr));
    void'($value$plusargs("signature_addr=%s", signature_addr_str));
    signature_addr = signature_addr_str.atohex();
  endfunction

endclass
