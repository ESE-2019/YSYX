// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// Base class for directed debug and irq test scenarios
class core_ibex_directed_test extends core_ibex_debug_intr_basic_test;

  `uvm_component_utils(core_ibex_directed_test)
  `uvm_component_new

  instr_t        seen_instr           [$];
  bit     [15:0] seen_compressed_instr[$];

  virtual task send_stimulus();
    fork
      begin
        vseq.start(env.vseqr);
      end
      begin
        if (!cfg.require_signature_addr) begin
          clk_vif.wait_clks(stimulus_delay);
          fork
            begin
              if (enable_irq_seq) begin
                forever begin
                  send_irq_stimulus();
                end
              end
            end
            begin
              if (cfg.enable_debug_seq) begin
                stress_debug();
              end
            end
          join_none
        end else begin
          // Wait for core initialization before starting the stimulus check loop - first write
          // to signature address is guaranteed to be core initialization info
          wait_for_core_setup();
          // Wait for a little bit to guarantee that the core has started executing <main>
          // before starting to generate stimulus for the core.
          clk_vif.wait_clks(50);
          // Should be extended by derived classes.
          // DO NOT use this test class directly.
          fork
            check_stimulus();
          join_none
          wait (test_done === 1'b1);
          // disable below can kill processes that are running sequences. As a result they never
          // stop and the simulation never ends. So wait for all sequences to stop before doing the
          // disable.
          vseq.wait_for_stop();
          disable fork;
          if (cur_run_phase.get_objection_count(this) > 1) begin
            cur_run_phase.drop_objection(this);
          end
        end
      end
    join_none
  endtask

  virtual task check_stimulus();
    `uvm_fatal(`gfn, "Base class task should not be used")
  endtask

  // Check if we have seen the same type of instruction before by comparing the instruction
  // currently in the ID stage against the global seen_instr[$] queue.
  // If we've seen the same type of instruction before, return 0, otherwise add it to the
  // seen_instr[$] queue and return 1.
  virtual function bit decode_instr(bit [ibex_mem_intf_agent_pkg::DATA_WIDTH-1:0] instr);
    ibex_pkg::opcode_e        opcode;
    bit                [ 2:0] funct3;
    bit                [ 6:0] funct7;
    bit                [12:0] system_imm;
    instr_t                   instr_fields;

    opcode     = ibex_pkg::opcode_e'(instr[6:0]);
    funct3     = instr[14:12];
    funct7     = instr[31:25];
    system_imm = instr[31:20];

    // Now we search seen_instr[$] to check if a same instruction has been seen before.
    case (opcode)
      OPCODE_LUI, OPCODE_AUIPC, OPCODE_JAL: begin
        // these instructions only depend on opcode.
        foreach (seen_instr[i]) begin
          if (opcode == seen_instr[i].opcode) begin
            return 0;
          end
        end
      end
      OPCODE_JALR, OPCODE_BRANCH, OPCODE_LOAD, OPCODE_STORE, OPCODE_MISC_MEM: begin
        // these instructions only depend on opcode and funct3
        // to be identified.
        foreach (seen_instr[i]) begin
          if (opcode == seen_instr[i].opcode && funct3 == seen_instr[i].funct3) begin
            return 0;
          end
        end
      end
      OPCODE_OP_IMM: begin
        // register-immediate arithmetic instructions are handled separately
        // as slli/srli/srai rely on funct7 in addition to opcode/funct3.
        foreach (seen_instr[i]) begin
          if (opcode == seen_instr[i].opcode && funct3 == seen_instr[i].funct3) begin
            // handle slli/srli/srai instructions.
            if (funct3 inside {3'b001, 3'b101}) begin
              if (funct7 == seen_instr[i].funct7) begin
                return 0;
              end
            end else begin
              return 0;
            end
          end
        end
      end
      OPCODE_OP: begin
        // all register-register arithmetic instructions rely on
        // opcode/funct3/funct7 for identification.
        foreach (seen_instr[i]) begin
          if (opcode == seen_instr[i].opcode &&
              funct3 == seen_instr[i].funct3 &&
              funct7 == seen_instr[i].funct7) begin
            return 0;
          end
        end
      end
      OPCODE_SYSTEM: begin
        // explicitly set is_seen to 0 and return on WFI instructions,
        // as if we don't interrupt them, every test will timeout.
        if (funct3 == 3'b000 && system_imm == 12'h105) begin
          return 1;
        end else if (funct3 == 3'b000 && system_imm != 12'h001) begin
          // raise is_seen if ecall/mret/dret is detected,
          // we exclude them for now (this leads to nested traps).
          return 0;
        end else begin
          foreach (seen_instr[i]) begin
            if (opcode == seen_instr[i].opcode &&
                funct3 == seen_instr[i].funct3 &&
                system_imm == seen_instr[i].system_imm) begin
              return 0;
            end
          end
        end
      end
      default: begin
        `uvm_fatal(`gfn, "Illegal instruction detected")
      end
    endcase

    // We haven't seen this type of instruction before, so add it to seen_instr[$]
    // to flag it as 'seen' the next time we decode an instruction.
    instr_fields = '{opcode, funct3, funct7, system_imm};
    seen_instr.push_back(instr_fields);
    return 1;

  endfunction

  // Similarly to decode_instr(...), this function checks whether we have seen the
  // compressed instruction currently in the ID stage before by comparing it to the
  // global seen_compressed_instr[$] queue.
  // If we have seen it before, it returns 0, otherwise the instruction is added to the
  // and it returns 1.
  virtual function bit decode_compressed_instr(bit [15:0] instr);

    foreach (seen_compressed_instr[i]) begin
      if (instr[1:0] == seen_compressed_instr[i][1:0]) begin
        case (instr[1:0])
          2'b00: begin
            if (instr[15:13] == seen_compressed_instr[i][15:13]) begin
              return 0;
            end
          end
          2'b01: begin
            if (instr[15:13] == seen_compressed_instr[i][15:13]) begin
              case (instr[15:13])
                3'b000, 3'b001, 3'b010, 3'b011, 3'b101, 3'b110, 3'b111: begin
                  return 0;
                end
                3'b100: begin
                  if (instr[11:10] == seen_compressed_instr[i][11:10]) begin
                    case (instr[11:10])
                      2'b00, 2'b01, 2'b10: begin
                        return 0;
                      end
                      2'b11: begin
                        if (instr[12] == seen_compressed_instr[i][12] &&
                            instr[6:5] == seen_compressed_instr[i][6:5]) begin
                          return 0;
                        end
                      end
                    endcase
                  end
                end
                default: begin
                  `uvm_fatal(`gfn, "Invalid C1 compressed instruction")
                end
              endcase
            end
          end
          2'b10: begin
            if (instr[15:13] == seen_compressed_instr[i][15:13]) begin
              case (instr[15:13])
                3'b000, 3'b010, 3'b110: begin
                  return 0;
                end
                3'b100: begin
                  if (instr[12] == seen_compressed_instr[i][12]) begin
                    return 0;
                  end
                end
                default: begin
                  `uvm_fatal(`gfn, "Illegal C2 compressed instruction")
                end
              endcase
            end
          end
          default: begin
            `uvm_fatal(`gfn, "Instruction is not compressed")
          end
        endcase
      end
    end

    // If we get here we have not seen the current instruction before,
    // so add it to seen_compressed_instr[$].
    seen_compressed_instr.push_back(instr);
    return 1'b1;

  endfunction

endclass

