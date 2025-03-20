`default_nettype none

module rv16_decoder
  import OoO_pkg::*;
(
    input  logic [31:0] inst,
    output logic [31:0] instr,
    output logic        is_rv16,
    output logic        rv16_err
);

  import riscv_instr::*;

  localparam logic [4:0] X0 = 5'h0;
  localparam logic [4:0] RA = 5'h1;
  localparam logic [4:0] SP = 5'h2;
  wire [4:0] r11_7 = inst[11:7];
  wire [4:0] r9_7 = {2'b01, inst[9:7]};
  wire [4:0] r6_2 = inst[6:2];
  wire [4:0] r4_2 = {2'b01, inst[4:2]};

  always_comb begin
    instr = inst;
    rv16_err = 1'b0;
    is_rv16 = 1'b1;
    unique case (inst[1:0])
      C_ADDI4SPN[1:0]: begin
        // Quadrant 0
        unique case (inst[15:13])
          C_ADDI4SPN[15:13]: begin
            // c.addi4spn -> addi rd', x2, imm
            instr = {
              {2'b0, inst[10:7], inst[12:11], inst[5], inst[6], 2'b0}, SP, 3'b000, r4_2, ADDI[6:0]
            };
            if (inst[12:5] == 8'b0) rv16_err = 1'b1;
          end

          C_LW[15:13]: begin
            // c.lw -> lw rd', imm(rs1')
            instr = {{5'b0, inst[5], inst[12:10], inst[6], 2'b0}, r9_7, 3'b010, r4_2, LB[6:0]};
          end

          C_LBU[15:13]: begin
            case (inst[12:10])
              C_LBU[12:10]: begin
                // c.lbu -> lbu rd', uimm(rs1')
                instr = {{10'b0, inst[5], inst[6]}, r9_7, 3'b100, r4_2, LB[6:0]};
              end

              C_LHU[12:10]: begin
                // c.lhu -> lhu rd', uimm(rs1')
                // c.lh -> lh rd', uimm(rs1')
                instr = {{10'b0, inst[5], 1'b0}, r9_7, {~inst[6], 2'b01}, r4_2, LB[6:0]};
              end

              C_SB[12:10]: begin
                // c.sb -> sb rs2', uimm(rs1')
                instr = {7'b0, r4_2, r9_7, 3'b000, {3'b0, inst[5], inst[6]}, SB[6:0]};
              end

              C_SH[12:10]: begin
                // c.sh -> sh rs2', uimm(rs1')
                instr = {7'b0, r4_2, r9_7, 3'b001, {3'b0, inst[5], inst[6]}, SB[6:0]};
                if (inst[6] != 1'b0) rv16_err = 1'b1;
              end

              default: begin
                rv16_err = 1'b1;
              end
            endcase
          end

          C_SW[15:13]: begin  // c.sw -> sw rs2', imm(rs1')
            instr = {
              {5'b0, inst[5], inst[12]}, r4_2, r9_7, 3'b010, {inst[11:10], inst[6], 2'b0}, SB[6:0]
            };
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      C_ADDI[1:0]: begin
        // Quadrant 1
        unique case (inst[15:13])
          C_ADDI[15:13]: begin
            // c.addi -> addi rd, rd, nzimm
            // c.nop -> addi 0, 0, 0
            instr = {{{7{inst[12]}}, r6_2}, r11_7, 3'b0, r11_7, ADDI[6:0]};
          end

          C_JAL[15:13], C_J[15:13]: begin
            // c.jal -> jal x1, imm
            // c.j   -> jal x0, imm
            instr = {
              {
                inst[12],
                inst[8],
                inst[10:9],
                inst[6],
                inst[7],
                inst[2],
                inst[11],
                inst[5:3],
                {9{inst[12]}}
              },
              {4'b0, ~inst[15]},
              JAL[6:0]
            };
          end

          C_LI[15:13]: begin
            // c.li -> addi rd, x0, nzimm
            instr = {{{7{inst[12]}}, inst[6:2]}, X0, 3'b0, r11_7, ADDI[6:0]};
          end

          C_LUI[15:13]: begin
            // c.lui -> lui rd, imm
            instr = {{{15{inst[12]}}, inst[6:2]}, r11_7, LUI[6:0]};

            if (r11_7 == SP) begin
              // c.addi16sp -> addi x2, x2, nzimm
              instr = {
                {{3{inst[12]}}, inst[4:3], inst[5], inst[2], inst[6], 4'b0},
                SP,
                3'b000,
                SP,
                ADDI[6:0]
              };
            end

            if ({inst[12], inst[6:2]} == 6'b0) rv16_err = 1'b1;
          end

          C_SRLI[15:13]: begin
            unique case (inst[11:10])
              C_SRLI[11:10], C_SRAI[11:10]: begin
                // c.srli -> srli rd, rd, shamt
                // c.srai -> srai rd, rd, shamt
                instr = {{1'b0, inst[10], 5'b0}, inst[6:2], r9_7, 3'b101, r9_7, ADDI[6:0]};
                if (inst[12] == 1'b1) rv16_err = 1'b1;
              end

              C_ANDI[11:10]: begin
                // c.andi -> andi rd, rd, imm
                instr = {{{6{inst[12]}}, inst[12], inst[6:2]}, r9_7, 3'b111, r9_7, ADDI[6:0]};
              end

              C_SUB[11:10]: begin
                unique case ({
                  inst[12], inst[6:5]
                })
                  3'b000: begin
                    // c.sub -> sub rd', rd', rs2'
                    instr = {7'b0100000, r4_2, r9_7, 3'b000, r9_7, ADD[6:0]};
                  end

                  3'b001: begin
                    // c.xor -> xor rd', rd', rs2'
                    instr = {7'b0, r4_2, r9_7, 3'b100, r9_7, ADD[6:0]};
                  end

                  3'b010: begin
                    // c.or  -> or  rd', rd', rs2'
                    instr = {7'b0, r4_2, r9_7, 3'b110, r9_7, ADD[6:0]};
                  end

                  3'b011: begin
                    // c.and -> and rd', rd', rs2'
                    instr = {7'b0, r4_2, r9_7, 3'b111, r9_7, ADD[6:0]};
                  end

                  3'b110: begin
                    // c.mul -> mul rd', rd', rs2'
                    instr = {7'b0000001, r4_2, r9_7, 3'b000, r9_7, ADD[6:0]};
                    if (inst[11:10] != 2'b11) rv16_err = 1'b1;
                  end

                  3'b111: begin
                    unique case (inst[4:2])
                      3'b000: begin
                        // c.zext.b -> andi rd', rd', 0xff
                        instr = {12'h0FF, r9_7, 3'b111, r9_7, ADDI[6:0]};
                      end
                      3'b001: begin
                        // c.sext.b -> sext.b rd'/rs1', rd'/rs1'
                        instr = {7'b0110000, 5'b00100, r9_7, 3'b001, r9_7, ADDI[6:0]};
                      end
                      3'b010: begin
                        // c.zext.h -> zext.h rd'/rs1', rd'/rs1'
                        instr = {7'b0000100, 5'b00000, r9_7, 3'b100, r9_7, ADD[6:0]};
                      end
                      3'b011: begin
                        // c.sext.h -> sext.h rd'/rs1', rd'/rs1'
                        instr = {7'b0110000, 5'b00101, r9_7, 3'b001, r9_7, ADDI[6:0]};
                      end
                      3'b101: begin
                        // c.not -> xori rd', rd', -1
                        instr = {12'hFFF, r9_7, 3'b100, r9_7, ADDI[6:0]};
                      end

                      default: begin
                        rv16_err = 1'b1;
                      end
                    endcase
                  end

                  default: begin
                    rv16_err = 1'b1;
                  end
                endcase
              end

              default: begin
                rv16_err = 1'b1;
              end
            endcase
          end

          C_BEQZ[15:13], C_BNEZ[15:13]: begin
            // c.beqz -> beq rs1', x0, imm
            // c.bnez -> bne rs1', x0, imm
            instr = {
              {{4{inst[12]}}, inst[6:5], inst[2]},
              X0,
              r9_7,
              {2'b0, inst[13]},
              {inst[11:10], inst[4:3], inst[12]},
              BEQ[6:0]
            };
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      C_SLLI[1:0]: begin
        // Quadrant 2
        unique case (inst[15:13])
          C_SLLI[15:13]: begin
            // c.slli -> slli rd, rd, shamt
            instr = {7'b0, r6_2, r11_7, 3'b001, r11_7, ADDI[6:0]};
            if (inst[12] == 1'b1) rv16_err = 1'b1;
          end

          C_LWSP[15:13]: begin
            // c.lwsp -> lw rd, imm(x2)
            instr = {{4'b0, inst[3:2], inst[12], inst[6:4], 2'b0}, SP, 3'b010, r11_7, LB[6:0]};
            if (r11_7 == X0) rv16_err = 1'b1;
          end

          C_MV[15:13]: begin
            if (inst[12] == 1'b0) begin
              if (r6_2 != X0) begin
                // c.mv -> add rd/rs1, x0, rs2
                instr = {7'b0, r6_2, X0, 3'b0, r11_7, ADD[6:0]};
              end else begin
                // c.jr -> jalr x0, rd/rs1, 0
                instr = {12'b0, r11_7, 3'b0, X0, JALR[6:0]};
                if (r11_7 == X0) rv16_err = 1'b1;
              end
            end else begin
              if (r6_2 != X0) begin
                // c.add -> add rd, rd, rs2
                instr = {7'b0, r6_2, r11_7, 3'b0, r11_7, ADD[6:0]};
              end else begin
                // c.jalr -> jalr x1, rs1, 0
                instr = {12'b0, r11_7, 3'b000, RA, JALR[6:0]};
                if (r11_7 == X0) begin
                  // c.ebreak -> ebreak
                  instr = EBREAK;
                end
              end
            end
          end

          C_SWSP[15:13]: begin
            // c.swsp -> sw rs2, imm(x2)
            instr = {{4'b0, inst[8:7], inst[12]}, r6_2, SP, 3'b010, {inst[11:9], 2'b0}, SB[6:0]};
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      default: is_rv16 = 1'b0;
    endcase
  end

endmodule

`default_nettype wire
