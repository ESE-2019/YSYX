// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// ---------------------------------------------
// Ibex core virtual sequence
// ---------------------------------------------

class core_ibex_vseq extends uvm_sequence;

  ibex_mem_intf_response_seq                                           instr_intf_seq;
  ibex_mem_intf_response_seq                                           data_intf_seq;
  mem_model_pkg::mem_model                                             mem;
  core_ibex_env_cfg                                                    cfg;
  bit                        [ibex_mem_intf_agent_pkg::DATA_WIDTH-1:0] data;

  `uvm_object_utils(core_ibex_vseq)
  `uvm_declare_p_sequencer(core_ibex_vseqr)

  function new(string name = "");
    super.new(name);
    instr_intf_seq = ibex_mem_intf_response_seq::type_id::create("instr_intf_seq");
    data_intf_seq = ibex_mem_intf_response_seq::type_id::create("data_intf_seq");
    data_intf_seq.is_dmem_seq = 1'b1;
  endfunction

  // Start the memory-model sequences, which run forever() loops to respond to bus events
  virtual task pre_body();
    instr_intf_seq.m_mem = mem;
    instr_intf_seq.enable_spurious_response = 1'b0;

    data_intf_seq.m_mem = mem;

    fork
      instr_intf_seq.start(p_sequencer.instr_if_seqr);
      data_intf_seq.start(p_sequencer.data_if_seqr);
    join_none
  endtask  // pre_body

  virtual task body();
    
  endtask

  virtual task stop();

  endtask

  virtual task wait_for_stop();

  endtask


endclass
