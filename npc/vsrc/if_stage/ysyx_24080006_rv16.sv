`default_nettype none

module ysyx_24080006_rv16
  import ysyx_24080006_pkg::*;
(
    input  logic [31:0] inst_i,
    output logic [31:0] inst_o,
    output logic        rv16,
    output logic        rv16_err
);

  // Quadrant 0
  localparam logic [1:0] C0 = 2'b00;
  localparam logic [2:0] C0ADDI4SPN = 3'b000;
  localparam logic [2:0] C0LW = 3'b010;
  localparam logic [2:0] C0ZCB = 3'b100;
  localparam logic [2:0] C0SW = 3'b110;
  // Quadrant 1
  localparam logic [1:0] C1 = 2'b01;
  localparam logic [2:0] C1ADDI = 3'b000;
  localparam logic [2:0] C1JAL = 3'b001;
  localparam logic [2:0] C1LI = 3'b010;
  localparam logic [2:0] C1LUIADDI16SP = 3'b011;
  localparam logic [2:0] C1MISCALU = 3'b100;
  localparam logic [2:0] C1J = 3'b101;
  localparam logic [2:0] C1BEQZ = 3'b110;
  localparam logic [2:0] C1BNEZ = 3'b111;
  // Quadrant 2
  localparam logic [1:0] C2 = 2'b10;
  localparam logic [2:0] C2SLLI = 3'b000;
  localparam logic [2:0] C2LWSP = 3'b010;
  localparam logic [2:0] C2JALRMVADD = 3'b100;
  localparam logic [2:0] C2SWSP = 3'b110;

  localparam logic [4:0] X0 = 5'h0;
  localparam logic [4:0] RA = 5'h1;
  localparam logic [4:0] SP = 5'h2;
  wire [4:0] r11_7 = inst_i[11:7];
  wire [4:0] r9_7 = {2'b01, inst_i[9:7]};
  wire [4:0] r6_2 = inst_i[6:2];
  wire [4:0] r4_2 = {2'b01, inst_i[4:2]};

  always_comb begin
    inst_o = inst_i;
    rv16_err = 1'b0;
    rv16 = 1'b1;
    unique case (inst_i[1:0])
      C0: begin
        unique case (inst_i[15:13])
          C0ADDI4SPN: begin
            // c.addi4spn -> addi rd', x2, imm
            inst_o = {
              {2'b0, inst_i[10:7], inst_i[12:11], inst_i[5], inst_i[6], 2'b0},
              SP,
              3'b000,
              r4_2,
              OPCODE_OPIMM
            };
            if (inst_i[12:5] == 8'b0) rv16_err = 1'b1;
          end

          C0LW: begin
            // c.lw -> lw rd', imm(rs1')
            inst_o = {
              {5'b0, inst_i[5], inst_i[12:10], inst_i[6], 2'b0}, r9_7, 3'b010, r4_2, OPCODE_LOAD
            };
          end

          C0ZCB: begin
            case (inst_i[12:10])
              3'b000: begin
                // c.lbu -> lbu rd', uimm(rs1')
                inst_o = {{10'b0, inst_i[5], inst_i[6]}, r9_7, 3'b100, r4_2, OPCODE_LOAD};
              end

              3'b001: begin
                // c.lhu -> lhu rd', uimm(rs1')
                // c.lh -> lh rd', uimm(rs1')
                inst_o = {{10'b0, inst_i[5], 1'b0}, r9_7, {~inst_i[6], 2'b01}, r4_2, OPCODE_LOAD};
              end

              3'b010, 3'b011: begin
                // c.sb -> sb rs2', uimm(rs1')
                // c.sh -> sh rs2', uimm(rs1')
                inst_o = {
                  7'b0, r4_2, r9_7, {2'b00, inst_i[10]}, {3'b0, inst_i[5], inst_i[6]}, OPCODE_STORE
                };
              end

              default: begin
                rv16_err = 1'b1;
              end
            endcase
          end

          C0SW: begin  // c.sw -> sw rs2', imm(rs1')
            inst_o = {
              {5'b0, inst_i[5], inst_i[12]},
              r4_2,
              r9_7,
              3'b010,
              {inst_i[11:10], inst_i[6], 2'b0},
              OPCODE_STORE
            };
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      C1: begin
        unique case (inst_i[15:13])
          C1ADDI: begin
            // c.addi -> addi rd, rd, nzimm
            // c.nop -> addi 0, 0, 0
            inst_o = {{{7{inst_i[12]}}, r6_2}, r11_7, 3'b0, r11_7, OPCODE_OPIMM};
          end

          C1JAL, C1J: begin
            // c.jal -> jal x1, imm
            // c.j   -> jal x0, imm
            inst_o = {
              {
                inst_i[12],
                inst_i[8],
                inst_i[10:9],
                inst_i[6],
                inst_i[7],
                inst_i[2],
                inst_i[11],
                inst_i[5:3],
                {9{inst_i[12]}}
              },
              {4'b0, ~inst_i[15]},
              OPCODE_JAL
            };
          end

          C1LI: begin
            // c.li -> addi rd, x0, nzimm
            inst_o = {{{7{inst_i[12]}}, inst_i[6:2]}, X0, 3'b0, r11_7, OPCODE_OPIMM};
          end

          C1LUIADDI16SP: begin
            // c.lui -> lui rd, imm
            inst_o = {{{15{inst_i[12]}}, inst_i[6:2]}, r11_7, OPCODE_LUI};

            if (r11_7 == SP) begin
              // c.addi16sp -> addi x2, x2, nzimm
              inst_o = {
                {{3{inst_i[12]}}, inst_i[4:3], inst_i[5], inst_i[2], inst_i[6], 4'b0},
                SP,
                3'b000,
                SP,
                OPCODE_OPIMM
              };
            end

            if ({inst_i[12], inst_i[6:2]} == 6'b0) rv16_err = 1'b1;
          end

          C1MISCALU: begin
            unique case (inst_i[11:10])
              2'b00, 2'b01: begin
                // c.srli -> srli rd, rd, shamt
                // c.srai -> srai rd, rd, shamt
                inst_o = {{1'b0, inst_i[10], 5'b0}, inst_i[6:2], r9_7, 3'b101, r9_7, OPCODE_OPIMM};
                if (inst_i[12] == 1'b1) rv16_err = 1'b1;
              end

              2'b10: begin
                // c.andi -> andi rd, rd, imm
                inst_o = {
                  {{6{inst_i[12]}}, inst_i[12], inst_i[6:2]}, r9_7, 3'b111, r9_7, OPCODE_OPIMM
                };
              end

              2'b11: begin
                unique case ({
                  inst_i[12], inst_i[6:5]
                })
                  3'b000: begin
                    // c.sub -> sub rd', rd', rs2'
                    inst_o = {7'b0100000, r4_2, r9_7, 3'b000, r9_7, OPCODE_OP};
                  end

                  3'b001: begin
                    // c.xor -> xor rd', rd', rs2'
                    inst_o = {7'b0, r4_2, r9_7, 3'b100, r9_7, OPCODE_OP};
                  end

                  3'b010: begin
                    // c.or  -> or  rd', rd', rs2'
                    inst_o = {7'b0, r4_2, r9_7, 3'b110, r9_7, OPCODE_OP};
                  end

                  3'b011: begin
                    // c.and -> and rd', rd', rs2'
                    inst_o = {7'b0, r4_2, r9_7, 3'b111, r9_7, OPCODE_OP};
                  end

                  3'b110: begin
                    // c.mul -> mul rd', rd', rs2'
                    inst_o = {7'b0000001, r4_2, r9_7, 3'b000, r9_7, OPCODE_OP};
                    if (inst_i[11:10] != 2'b11) rv16_err = 1'b1;
                  end

                  3'b111: begin
                    unique case (inst_i[4:2])
                      3'b000: begin
                        // c.zext.b -> andi rd', rd', 0xff
                        inst_o = {12'h0FF, r9_7, 3'b111, r9_7, OPCODE_OPIMM};
                      end

                      3'b101: begin
                        // c.not -> xori rd', rd', -1
                        inst_o = {12'hFFF, r9_7, 3'b100, r9_7, OPCODE_OPIMM};
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

          C1BEQZ, C1BNEZ: begin
            // c.beqz -> beq rs1', x0, imm
            // c.bnez -> bne rs1', x0, imm
            inst_o = {
              {{4{inst_i[12]}}, inst_i[6:5], inst_i[2]},
              X0,
              r9_7,
              {2'b0, inst_i[13]},
              {inst_i[11:10], inst_i[4:3], inst_i[12]},
              OPCODE_BRANCH
            };
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      C2: begin
        unique case (inst_i[15:13])
          C2SLLI: begin
            // c.slli -> slli rd, rd, shamt
            inst_o = {7'b0, r6_2, r11_7, 3'b001, r11_7, OPCODE_OPIMM};
            if (inst_i[12] == 1'b1) rv16_err = 1'b1;
          end

          C2LWSP: begin
            // c.lwsp -> lw rd, imm(x2)
            inst_o = {
              {4'b0, inst_i[3:2], inst_i[12], inst_i[6:4], 2'b0}, SP, 3'b010, r11_7, OPCODE_LOAD
            };
            if (r11_7 == X0) rv16_err = 1'b1;
          end

          C2JALRMVADD: begin
            if (inst_i[12] == 1'b0) begin
              if (r6_2 != X0) begin
                // c.mv -> add rd/rs1, x0, rs2
                inst_o = {7'b0, r6_2, X0, 3'b0, r11_7, OPCODE_OP};
              end else begin
                // c.jr -> jalr x0, rd/rs1, 0
                inst_o = {12'b0, r11_7, 3'b0, X0, OPCODE_JALR};
                if (r11_7 == X0) rv16_err = 1'b1;
              end
            end else begin
              if (r6_2 != X0) begin
                // c.add -> add rd, rd, rs2
                inst_o = {7'b0, r6_2, r11_7, 3'b0, r11_7, OPCODE_OP};
              end else begin
                if (r11_7 == X0) begin
                  // c.ebreak -> ebreak
                  inst_o = riscv_instr::EBREAK;
                end else begin
                  // c.jalr -> jalr x1, rs1, 0
                  inst_o = {12'b0, r11_7, 3'b000, RA, OPCODE_JALR};
                end
              end
            end
          end

          C2SWSP: begin
            // c.swsp -> sw rs2, imm(x2)
            inst_o = {
              {4'b0, inst_i[8:7], inst_i[12]}, r6_2, SP, 3'b010, {inst_i[11:9], 2'b0}, OPCODE_STORE
            };
          end

          default: begin
            rv16_err = 1'b1;
          end
        endcase
      end

      default: rv16 = 1'b0;
    endcase
  end

endmodule

`default_nettype wire
