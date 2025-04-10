// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------
// CLASS: ibex_mem_intf_response_driver
//------------------------------------------------------------------------------

class ibex_mem_intf_response_driver extends uvm_driver #(ibex_mem_intf_seq_item);

  ibex_mem_intf_response_agent_cfg cfg;

  `uvm_component_utils(ibex_mem_intf_response_driver)
  `uvm_component_new

  mailbox #(ibex_mem_intf_seq_item) rdata_queue;

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    rdata_queue = new();
  endfunction : build_phase

  virtual task run_phase(uvm_phase phase);
    reset_signals();
    wait (cfg.vif.response_driver_cb.reset === 1'b0);
    forever begin
      fork
        begin : isolation_fork
          fork : drive_stimulus
            send_grant();
            get_and_drive();
            wait (cfg.vif.response_driver_cb.reset === 1'b1);
          join_any
          // Will only be reached after mid-test reset
          disable fork;
        end
      join
      handle_reset();
    end
  endtask : run_phase

  virtual protected task handle_reset();
    ibex_mem_intf_seq_item req;
    // Clear mailbox
    while (rdata_queue.try_get(req));
    // Clear seq_item_port
    do begin
      seq_item_port.try_next_item(req);
      if (req != null) begin
        seq_item_port.item_done();
      end
    end while (req != null);
    reset_signals();
    wait (cfg.vif.response_driver_cb.reset === 1'b0);
  endtask

  virtual protected task reset_signals();
    cfg.vif.response_driver_cb.rvalid <= 1'b0;
    cfg.vif.response_driver_cb.grant  <= 1'b0;
    cfg.vif.response_driver_cb.rdata  <= 'b0;
  endtask : reset_signals

  virtual protected task get_and_drive();
    wait (cfg.vif.response_driver_cb.reset === 1'b0);

    fork
      begin
        forever begin
          ibex_mem_intf_seq_item req, req_c;
          @(cfg.vif.response_driver_cb);
          seq_item_port.get_next_item(req);
          $cast(req_c, req.clone());
          if (~cfg.vif.response_driver_cb.reset) begin
            rdata_queue.put(req_c);
          end
          seq_item_port.item_done();
        end
      end
      begin
        send_read_data();
      end
    join
  endtask : get_and_drive

  virtual protected task send_grant();
    int gnt_delay;
    forever begin
      while (cfg.vif.response_driver_cb.request !== 1'b1) begin
        cfg.vif.wait_neg_clks(1);
      end
      if (cfg.zero_delays) begin
        gnt_delay = 0;
      end else begin
        if (!std::randomize(
                gnt_delay
            ) with {
              gnt_delay dist {
                cfg.gnt_delay_min :/ 10,
                [cfg.gnt_delay_min+1 : cfg.gnt_delay_max-1] :/ cfg.valid_pick_medium_speed_weight,
                cfg.gnt_delay_max :/ cfg.valid_pick_slow_speed_weight
              };
            }) begin
          `uvm_fatal(`gfn, $sformatf("Cannot randomize grant"))
        end
      end
      cfg.vif.wait_neg_clks(gnt_delay);
      if (~cfg.vif.response_driver_cb.reset) begin
        cfg.vif.response_driver_cb.grant <= 1'b1;
        cfg.vif.wait_neg_clks(1);
        cfg.vif.response_driver_cb.grant <= 1'b0;
      end
    end
  endtask : send_grant

  virtual protected task send_read_data();
    ibex_mem_intf_seq_item tr;
    forever begin
      @(cfg.vif.response_driver_cb);
      cfg.vif.response_driver_cb.rvalid <= 1'b0;
      cfg.vif.response_driver_cb.rdata  <= 'x;

      rdata_queue.get(tr);

      `uvm_info(`gfn, $sformatf("Got response for addr %x", tr.addr), UVM_HIGH)

      if (cfg.vif.response_driver_cb.reset) continue;

      repeat (tr.rvalid_delay) @(cfg.vif.response_driver_cb);

      if (~cfg.vif.response_driver_cb.reset) begin

        `uvm_info(`gfn, $sformatf("Driving response for addr %x", tr.addr), UVM_HIGH)
        cfg.vif.response_driver_cb.rvalid <= 1'b1;
        if (tr.read_write == READ) begin
          cfg.vif.response_driver_cb.rdata <= tr.data;
        end else begin
          // drive the irrelevant fields to x.
          cfg.vif.response_driver_cb.rdata <= 'x;
        end
      end
    end
  endtask : send_read_data

endclass : ibex_mem_intf_response_driver
