module ysyx_24080006_zcu
  import ysyx_24080006_pkg::*;
(
    input logic [31:0] zc_val,
    output logic [31:0] inst,
    output logic is_zc,
    output logic zc_err
);

  always_comb begin
    inst   = zc_val;
    zc_err = 1'b0;

    unique case (zc_val[1:0])
      // C0
      2'b00: begin
        unique case (zc_val[15:13])
          3'b000: begin  // c.addi4spn -> addi rd', x2, imm
            inst = {
              2'b0,
              zc_val[10:7],
              zc_val[12:11],
              zc_val[5],
              zc_val[6],
              2'b00,
              5'h02,
              3'b000,
              2'b01,
              zc_val[4:2],
              {OP_IMM}
            };
            if (zc_val[12:5] == 8'b0) zc_err = 1'b1;
          end

          3'b010: begin  // c.lw -> lw rd', imm(rs1')
            inst = {
              5'b0,
              zc_val[5],
              zc_val[12:10],
              zc_val[6],
              2'b00,
              2'b01,
              zc_val[9:7],
              3'b010,
              2'b01,
              zc_val[4:2],
              {LOAD}
            };
          end

          3'b100: begin  // zcb
            case (zc_val[12:10])
              3'b000: begin  // c.lbu -> lbu rd', imm(rs1')
                inst = {
                  10'b0,
                  zc_val[5],
                  zc_val[6],
                  2'b01,
                  zc_val[9:7],
                  3'b100,
                  2'b01,
                  zc_val[4:2],
                  {LOAD}
                };
              end

              3'b001: begin
                unique if (zc_val[6] == 1'b0) begin  // c.lhu -> lhu rd', imm(rs1')
                  inst = {
                    10'b0, zc_val[5], 1'b0, 2'b01, zc_val[9:7], 3'b101, 2'b01, zc_val[4:2], {LOAD}
                  };

                end else if (zc_val[6] == 1'b1) begin  // c.lh -> lh rd', imm(rs1')
                  inst = {
                    10'b0, zc_val[5], 1'b0, 2'b01, zc_val[9:7], 3'b001, 2'b01, zc_val[4:2], {LOAD}
                  };
                end
              end

              3'b010: begin  // c.sb -> sb rs2', imm(rs1')
                inst = {
                  7'b0,
                  2'b01,
                  zc_val[4:2],
                  2'b01,
                  zc_val[9:7],
                  3'b000,
                  3'b0,
                  zc_val[5],
                  zc_val[6],
                  {STORE}
                };
              end

              3'b011: begin  // c.sh -> sh rs2', imm(rs1')
                if (zc_val[6] == 1'b0) begin
                  inst = {
                    7'b0,
                    2'b01,
                    zc_val[4:2],
                    2'b01,
                    zc_val[9:7],
                    3'b001,
                    3'b0,
                    zc_val[5],
                    1'b0,
                    {STORE}
                  };
                end else begin
                  zc_err = 1'b1;
                end
              end

              default: begin
                zc_err = 1'b1;
              end
            endcase
          end

          3'b110: begin  // c.sw -> sw rs2', imm(rs1')
            inst = {
              5'b0,
              zc_val[5],
              zc_val[12],
              2'b01,
              zc_val[4:2],
              2'b01,
              zc_val[9:7],
              3'b010,
              zc_val[11:10],
              zc_val[6],
              2'b00,
              {STORE}
            };
          end

          3'b001, 3'b011, 3'b101, 3'b111: begin
            zc_err = 1'b1;
          end

          default: begin
            zc_err = 1'b1;
          end
        endcase
      end

      // C1
      //
      // Register address checks for RV32E are performed in the regular instruction decoder.
      // If this check fails, an illegal instruction exception is triggered and the controller
      // writes the actual faulting instruction to mtval.
      2'b01: begin
        unique case (zc_val[15:13])
          3'b000: begin
            // c.addi -> addi rd, rd, nzimm
            // c.nop
            inst = {
              {6{zc_val[12]}}, zc_val[12], zc_val[6:2], zc_val[11:7], 3'b0, zc_val[11:7], {OP_IMM}
            };
          end

          3'b001, 3'b101: begin
            // 001: c.jal -> jal x1, imm
            // 101: c.j   -> jal x0, imm
            inst = {
              zc_val[12],
              zc_val[8],
              zc_val[10:9],
              zc_val[6],
              zc_val[7],
              zc_val[2],
              zc_val[11],
              zc_val[5:3],
              {9{zc_val[12]}},
              4'b0,
              ~zc_val[15],
              {JAL}
            };
          end

          3'b010: begin
            // c.li -> addi rd, x0, nzimm
            // (c.li hints are translated into an addi hint)
            inst = {{6{zc_val[12]}}, zc_val[12], zc_val[6:2], 5'b0, 3'b0, zc_val[11:7], {OP_IMM}};
          end

          3'b011: begin
            // c.lui -> lui rd, imm
            // (c.lui hints are translated into a lui hint)
            inst = {{15{zc_val[12]}}, zc_val[6:2], zc_val[11:7], {LUI}};

            if (zc_val[11:7] == 5'h02) begin
              // c.addi16sp -> addi x2, x2, nzimm
              inst = {
                {3{zc_val[12]}},
                zc_val[4:3],
                zc_val[5],
                zc_val[2],
                zc_val[6],
                4'b0,
                5'h02,
                3'b000,
                5'h02,
                {OP_IMM}
              };
            end

            if ({zc_val[12], zc_val[6:2]} == 6'b0) zc_err = 1'b1;
          end

          3'b100: begin
            unique case (zc_val[11:10])
              2'b00, 2'b01: begin
                // 00: c.srli -> srli rd, rd, shamt
                // 01: c.srai -> srai rd, rd, shamt
                // (c.srli/c.srai hints are translated into a srli/srai hint)
                inst = {
                  1'b0,
                  zc_val[10],
                  5'b0,
                  zc_val[6:2],
                  2'b01,
                  zc_val[9:7],
                  3'b101,
                  2'b01,
                  zc_val[9:7],
                  {OP_IMM}
                };
                if (zc_val[12] == 1'b1) zc_err = 1'b1;
              end

              2'b10: begin
                // c.andi -> andi rd, rd, imm
                inst = {
                  {6{zc_val[12]}},
                  zc_val[12],
                  zc_val[6:2],
                  2'b01,
                  zc_val[9:7],
                  3'b111,
                  2'b01,
                  zc_val[9:7],
                  {OP_IMM}
                };
              end

              2'b11: begin
                unique case ({
                  zc_val[12], zc_val[6:5]
                })
                  3'b000: begin
                    // c.sub -> sub rd', rd', rs2'
                    inst = {
                      2'b01,
                      5'b0,
                      2'b01,
                      zc_val[4:2],
                      2'b01,
                      zc_val[9:7],
                      3'b000,
                      2'b01,
                      zc_val[9:7],
                      {OP}
                    };
                  end

                  3'b001: begin
                    // c.xor -> xor rd', rd', rs2'
                    inst = {
                      7'b0, 2'b01, zc_val[4:2], 2'b01, zc_val[9:7], 3'b100, 2'b01, zc_val[9:7], {OP}
                    };
                  end

                  3'b010: begin
                    // c.or  -> or  rd', rd', rs2'
                    inst = {
                      7'b0, 2'b01, zc_val[4:2], 2'b01, zc_val[9:7], 3'b110, 2'b01, zc_val[9:7], {OP}
                    };
                  end

                  3'b011: begin
                    // c.and -> and rd', rd', rs2'
                    inst = {
                      7'b0, 2'b01, zc_val[4:2], 2'b01, zc_val[9:7], 3'b111, 2'b01, zc_val[9:7], {OP}
                    };
                  end

                  3'b110: begin
                    // c.mul -> mul rd', rd', rs2'
                    inst = {
                      7'b1, 2'b01, zc_val[4:2], 2'b01, zc_val[9:7], 3'b000, 2'b01, zc_val[9:7], {OP}
                    };
                    if (zc_val[11:10] != 2'b11) zc_err = 1'b1;
                  end

                  3'b111: begin
                    unique case ({
                      zc_val[11:10], zc_val[4:2]
                    })
                      5'b11000: begin  // c.zext.b -> andi rd'/rs1', rd'/rs1', 0xff
                        inst = {12'hff, 2'b01, zc_val[9:7], 3'b111, 2'b01, zc_val[9:7], {OP_IMM}};
                      end
                      //todo zbb
                      5'b11101: begin  // c.not -> xori rd'/rs1', rd'/rs1', -1
                        inst = {12'hfff, 2'b01, zc_val[9:7], 3'b100, 2'b01, zc_val[9:7], {OP_IMM}};
                      end

                      default: begin
                        zc_err = 1'b1;
                      end
                    endcase
                  end

                  default: begin
                    zc_err = 1'b1;
                  end
                endcase
              end

              default: begin
                zc_err = 1'b1;
              end
            endcase
          end

          3'b110, 3'b111: begin
            // 0: c.beqz -> beq rs1', x0, imm
            // 1: c.bnez -> bne rs1', x0, imm
            inst = {
              {4{zc_val[12]}},
              zc_val[6:5],
              zc_val[2],
              5'b0,
              2'b01,
              zc_val[9:7],
              2'b00,
              zc_val[13],
              zc_val[11:10],
              zc_val[4:3],
              zc_val[12],
              {BRANCH}
            };
          end

          default: begin
            zc_err = 1'b1;
          end
        endcase
      end

      // C2
      //
      // Register address checks for RV32E are performed in the regular instruction decoder.
      // If this check fails, an illegal instruction exception is triggered and the controller
      // writes the actual faulting instruction to mtval.
      2'b10: begin
        unique case (zc_val[15:13])
          3'b000: begin
            // c.slli -> slli rd, rd, shamt
            // (c.ssli hints are translated into a slli hint)
            inst = {7'b0, zc_val[6:2], zc_val[11:7], 3'b001, zc_val[11:7], {OP_IMM}};
            if (zc_val[12] == 1'b1) zc_err = 1'b1;  // reserved for custom extensions
          end

          3'b010: begin
            // c.lwsp -> lw rd, imm(x2)
            inst = {
              4'b0, zc_val[3:2], zc_val[12], zc_val[6:4], 2'b00, 5'h02, 3'b010, zc_val[11:7], LOAD
            };
            if (zc_val[11:7] == 5'b0) zc_err = 1'b1;
          end

          3'b100: begin
            if (zc_val[12] == 1'b0) begin
              if (zc_val[6:2] != 5'b0) begin
                // c.mv -> add rd/rs1, x0, rs2
                // (c.mv hints are translated into an add hint)
                inst = {7'b0, zc_val[6:2], 5'b0, 3'b0, zc_val[11:7], {OP}};
              end else begin
                // c.jr -> jalr x0, rd/rs1, 0
                inst = {12'b0, zc_val[11:7], 3'b0, 5'b0, {JALR}};
                if (zc_val[11:7] == 5'b0) zc_err = 1'b1;
              end
            end else begin
              if (zc_val[6:2] != 5'b0) begin
                // c.add -> add rd, rd, rs2
                // (c.add hints are translated into an add hint)
                inst = {7'b0, zc_val[6:2], zc_val[11:7], 3'b0, zc_val[11:7], {OP}};
              end else begin
                if (zc_val[11:7] == 5'b0) begin
                  // c.ebreak -> ebreak
                  inst = {32'h00_10_00_73};
                end else begin
                  // c.jalr -> jalr x1, rs1, 0
                  inst = {12'b0, zc_val[11:7], 3'b000, 5'b00001, {JALR}};
                end
              end
            end
          end

          3'b110: begin
            // c.swsp -> sw rs2, imm(x2)
            inst = {
              4'b0,
              zc_val[8:7],
              zc_val[12],
              zc_val[6:2],
              5'h02,
              3'b010,
              zc_val[11:9],
              2'b00,
              {STORE}
            };
          end

          3'b001, 3'b011, 3'b101, 3'b111: begin
            zc_err = 1'b1;
          end

          default: begin
            zc_err = 1'b1;
          end
        endcase
      end

      // Incoming instruction is not compressed.
      2'b11: ;

      default: begin
        zc_err = 1'b1;
      end
    endcase
  end

  assign is_zc = (zc_val[1:0] != 2'b11);

endmodule
