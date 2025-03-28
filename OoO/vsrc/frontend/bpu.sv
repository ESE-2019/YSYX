module bpu
  import OoO_pkg::*;
(
    input  logic                        clock,
    input  logic                        reset,
    input  bju_t                        bju,
    input  aligner_t [InstPerFetch-1:0] aligned,
    input  logic     [InstPerFetch-1:0] inst_queue_push,
    output logic                        bp_valid,
    output logic     [            31:0] predict_addr,
    output cf_e      [InstPerFetch-1:0] cf_type
);

  predecoder_t  [InstPerFetch-1:0] predecoded;

  // -----------------------
  // Ctrl Flow Speculation
  // -----------------------
  // BHT, BTB and RAS prediction
  bht_predict_t [InstPerFetch-1:0] bht_predict;
  btb_predict_t [InstPerFetch-1:0] btb_predict;
  ras_predict_t                    ras_predict;
  bht_update_t                     bht_update;
  btb_update_t                     btb_update;
  ras_update_t                     ras_update;

  // taken/not taken
  always_comb begin
    predict_addr = 32'b0;

    for (int i = 0; i < InstPerFetch; i++) cf_type[i] = CF_NONE;

    ras_update = '0;

    // lower most prediction gets precedence
    for (int i = InstPerFetch - 1; i >= 0; i--) begin
      if (aligned[i].valid) begin
        unique case ({
          predecoded[i].branch, predecoded[i].ret, predecoded[i].jal, predecoded[i].jalr
        })
          4'b0000: ;

          4'b0001: begin  // jalr
            ras_update.pop  = 1'b0;
            ras_update.push = 1'b0;
            if (btb_predict[i].valid) begin
              predict_addr = btb_predict[i].target_address;
              cf_type[i]   = CF_JALR;
            end
          end

          4'b0010: begin  // jal
            ras_update.pop = 1'b0;
            ras_update.push = 1'b0;
            predict_addr = aligned[i].pc + predecoded[i].imm;
            cf_type[i] = CF_JAL;
          end

          4'b0100: begin  // ret
            ras_update.pop = ras_predict.valid & inst_queue_push[i];
            ras_update.push = 1'b0;
            predict_addr = ras_predict.ra;
            cf_type[i] = CF_RET;
          end
          // branch prediction
          4'b1000: begin
            ras_update.pop  = 1'b0;
            ras_update.push = 1'b0;
            if (bht_predict[i].valid) begin  // BHT
              if (bht_predict[i].taken) begin
                predict_addr = aligned[i].pc + predecoded[i].imm;
                cf_type[i]   = CF_BRANCH;
              end
            end else begin  // BTFN
              if (predecoded[i].imm[31]) begin
                predict_addr = aligned[i].pc + predecoded[i].imm;
                cf_type[i]   = CF_BRANCH;
              end
            end
          end
          // default: ;
          default: $error("Decoded more than one control flow");
        endcase
        if (predecoded[i].call) begin
          ras_update.push = inst_queue_push[i];
          ras_update.ra   = aligned[i].pc + (aligned[i].inst[1:0] == 2'b11 ? 32'h4 : 32'h2);
        end
      end
    end
  end

  // or reduce struct
  always_comb begin
    bp_valid = 1'b0;
    // BP cannot be valid if we have a return instruction and the RAS is not giving a valid address
    // Check that we encountered a control flow and that for a return the RAS
    // contains a valid prediction.
    for (int i = 0; i < InstPerFetch; i++)
    bp_valid |= ((cf_type[i] != CF_NONE & cf_type[i] != CF_RET) | ((cf_type[i] == CF_RET) & ras_predict.valid));
  end

  // Update Control Flow Predictions
  assign bht_update.valid = bju.valid & (bju.cf == CF_BRANCH);
  assign bht_update.pc = bju.pc;
  assign bht_update.taken = bju.is_taken;
  // only update mispredicted branches e.g. no returns from the RAS
  assign btb_update.valid = bju.valid & bju.is_mispredict & (bju.cf == CF_JALR);
  assign btb_update.pc = bju.pc;
  assign btb_update.target_address = bju.target_address;

  for (genvar i = 0; i < InstPerFetch; i++) begin : gen_pre_decoder
    predecoder PreDecoder (
        .inst(aligned[i].inst),
        .predecoded(predecoded[i])
    );
  end

  wire [31:0] pc = aligned[0].pc;

  ras RAS (.*);
  btb BTB (.*);
  bht BHT (.*);

endmodule
