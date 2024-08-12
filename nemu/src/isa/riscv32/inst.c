/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum
{
  TYPE_I,
  TYPE_U,
  TYPE_S,
  TYPE_B,
  TYPE_N,
  TYPE_J,
  TYPE_R
};

#define src1R()     \
  do                \
  {                 \
    *src1 = R(rs1); \
  } while (0)
#define src2R()     \
  do                \
  {                 \
    *src2 = R(rs2); \
  } while (0)
#define immI()                        \
  do                                  \
  {                                   \
    *imm = SEXT(BITS(i, 31, 20), 12); \
  } while (0)
#define immU()                              \
  do                                        \
  {                                         \
    *imm = SEXT(BITS(i, 31, 12), 20) << 12; \
  } while (0)
#define immS()                                               \
  do                                                         \
  {                                                          \
    *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); \
  } while (0)
#define immJ()                                                          \
  do                                                                    \
  {                                                                     \
    *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | \
           (BITS(i, 20, 20) << 11) | (BITS(i, 30, 21) << 1);            \
  } while (0)
#define immB()                                                        \
  do                                                                  \
  {                                                                   \
    *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 7, 7) << 11) | \
           (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1);            \
  } while (0)
int32_t sign_extend_20_to_32(int32_t data)
{ // will be aborted
  data &= 0xFFFFF;
  if (data & 0x80000)
  {
    return data | 0xFFF00000;
  }
  else
  {
    return data;
  }
}

int32_t sign_extend_13_to_32(int32_t data)
{
  data &= 0x1FFF;
  if (data & 0x1000)
  {
    return data | 0xFFFFE000;
  }
  else
  {
    return data;
  }
}

int32_t sign_extend_12_to_32(int32_t data)
{
  data &= 0xFFF;
  if (data & 0x800)
  {
    return data | 0xFFFFF000;
  }
  else
  {
    return data;
  }
}

int32_t sign_extend(uint32_t data, int bit_width)
{
  data &= (1 << bit_width) - 1;
  if (data & (1 << (bit_width - 1)))
  {
    return data | ~((1 << bit_width) - 1);
  }
  else
  {
    return data;
  }
}

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2,
                           word_t *imm, int type)
{
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd = BITS(i, 11, 7);
  switch (type)
  {
  case TYPE_I:
    src1R();
    immI();
    break;
  case TYPE_U:
    immU();
    break;
  case TYPE_S:
    src1R();
    src2R();
    immS();
    break;
  case TYPE_J:
    immJ();
    break;
  case TYPE_R:
    src1R();
    src2R();
    break;
  case TYPE_B:
    src1R();
    src2R();
    immB();
    break;
  }
}

int32_t mulh(int32_t a, int32_t b)
{
  int64_t result = (int64_t)a * (int64_t)b;
  return (int32_t)(result >> 32);
}

uint32_t mulhu(uint32_t a, uint32_t b)
{
  uint64_t result = (uint64_t)a * (uint64_t)b;
  return (uint32_t)(result >> 32);
}

int32_t mulhsu(int32_t a, uint32_t b)
{
  int64_t result = (int64_t)a * (uint64_t)b;
  return (int32_t)(result >> 32);
}

#ifdef CONFIG_FTRACE
extern char FT_name[][256];
extern uint32_t FT_addr[];
static uint32_t FT_local[4096] = {};
static uint32_t FT_ret[4096] = {};
static uint16_t FT_index = 0;
char ftrace_buf[16*65536] = "";
//jump to addr, curr pc, store to reg
static void ftrace_jump(const uint32_t addr, const uint32_t pc, const uint32_t reg)
{
  for (int i = 0; FT_addr[i] != 0; i++)//add
  {
    if (FT_addr[i] == addr)
    {
      FT_ret[FT_index] = reg;
      FT_local[FT_index++] = i;
      char tmp[4096] = "";
      for (int j = 0; j < FT_index - 1; j++)
      {
        strncat(tmp, "| ", sizeof(tmp) - strlen(tmp) - 1);
      }
      char tmp2[1024];
      snprintf(tmp2, 1024, FMT_WORD": call [%s@"FMT_WORD"]\n", pc, FT_name[i], FT_addr[i]);
      strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
      strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf)-1);
      return;
    }
  }
  for (int i = FT_index-1; i >= 0; i--)
  {
    if (FT_ret[i] == addr)
    {
      FT_index = i;
      char tmp[4096] = "";
      for (int j = 0; j < FT_index - 1; j++)
      {
        strncat(tmp, "| ", sizeof(tmp) - strlen(tmp) - 1);
      }
      char tmp2[1024];
      snprintf(tmp2, 1024, FMT_WORD": ret [%s]\n", pc, FT_name[FT_local[i]]);
      strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
      strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf)-1);
      return;
    }
    
  }
}
static void ftrace_print(const uint32_t addr)
{
  Log("%s", ftrace_buf);
}
#endif

static int decode_exec(Decode *s)
{
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */)         \
  {                                                                  \
    decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
    __VA_ARGS__;                                                     \
  }

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U,
          R(rd) = s->pc + imm /*; Log("auipc") */);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I,
          R(rd) = Mr(src1 + sign_extend(imm, 12), 1) /*; Log("lbu") */);
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S,
          Mw(src1 + sign_extend(imm, 12), 1, src2) /*; Log("sb") */);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, IFDEF(CONFIG_FTRACE, ftrace_print(0));
          NEMUTRAP(s->pc, R(10))); // R(10) is $a0

  // my code start
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U,
          R(rd) = imm /*; Log("lui") */);
  // auipc
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(rd) = s->snpc;
          s->dnpc = s->pc + imm; IFDEF(CONFIG_FTRACE, ftrace_jump(s->dnpc, s->pc, R(rd))) /*; Log("jal") */);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, R(rd) = s->snpc;
          s->dnpc = (src1 + sign_extend_12_to_32(imm)) &
                    (int32_t)-2; IFDEF(CONFIG_FTRACE, ftrace_jump(s->dnpc, s->pc, R(rd)))
           /*; Log("jalr") */);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B,
          if (src1 == src2) s->dnpc =
              s->pc + sign_extend_13_to_32(imm) /*; Log("beq") */);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B,
          if (src1 != src2) s->dnpc =
              ((int32_t)(s->pc) + sign_extend(imm, 13)) /*; Log("bne") */);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B,
          if ((int32_t)src1 < (int32_t)src2) s->dnpc =
              s->pc + sign_extend_13_to_32(imm) /*; Log("blt") */);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B,
          if ((int32_t)src1 >= (int32_t)src2) s->dnpc =
              s->pc + sign_extend_13_to_32(imm) /*; Log("bge") */);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B,
          if (src1 < src2) s->dnpc =
              s->pc + sign_extend_13_to_32(imm) /*; Log("bltu") */);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B,
          if (src1 >= src2) s->dnpc =
              s->pc + sign_extend_13_to_32(imm) /*; Log("bgeu") */);

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb, I,
          R(rd) = sign_extend(Mr(src1 + sign_extend(imm, 12), 1),
                              8) /*; Log("lb") */);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I,
          R(rd) = sign_extend(Mr(src1 + sign_extend(imm, 12), 2),
                              16) /*; Log("lh") */);
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I,
          R(rd) = Mr(src1 + sign_extend(imm, 12), 4) /*; Log("lw") */);
  // lbu
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I,
          R(rd) = Mr(src1 + sign_extend(imm, 12), 2) /*; Log("lhu") */);
  // sb
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S,
          Mw(src1 + sign_extend(imm, 12), 2, src2) /*; Log("sh") */);
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S,
          Mw(src1 + sign_extend(imm, 12), 4, src2) /*; Log("sw") */);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I,
          R(rd) = src1 + sign_extend(imm, 12) /*; Log("addi") */);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti, I,
          R(rd) = ((int32_t)src1 < (int32_t)sign_extend(imm, 12)) ? 1 : 0 /*; Log("slti") */);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I,
          R(rd) = (src1 < (uint32_t)sign_extend(imm, 12))
                      ? 1
                      : 0 /*; Log("sltiu") */);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I,
          R(rd) = src1 ^ sign_extend(imm, 12) /*; Log("xori") */);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori, I,
          R(rd) = src1 | sign_extend(imm, 12) /*; Log("ori") */);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I,
          R(rd) = src1 & sign_extend(imm, 12) /*; Log("andi") */);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli, I,
          R(rd) = src1 << BITS(imm, 4, 0) /*; Log("slli") */);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli, I,
          R(rd) = src1 >> BITS(imm, 4, 0) /*; Log("srli") */);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai, I,
          R(rd) = (int32_t)src1 >> BITS(imm, 4, 0) /*; Log("srai") */);
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R,
          R(rd) = src1 + src2 /*; Log("add") */);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R,
          R(rd) = src1 - src2 /*; Log("sub") */);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll, R,
          R(rd) = src1 << src2 /*; Log("sll") */);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, R,
          R(rd) = ((int32_t)src1 < (int32_t)src2) ? 1 : 0 /*; Log("slt") */);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, R,
          R(rd) = (src1 < src2) ? 1 : 0 /*; Log("sltu") */);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor, R,
          R(rd) = src1 ^ src2 /*; Log("xor") */);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl, R,
          R(rd) = src1 >> src2 /*; Log("srl") */);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra, R,
          R(rd) = (int32_t)src1 >> src2 /*; Log("sra") */);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R,
          R(rd) = src1 | src2 /*; Log("or") */);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and, R,
          R(rd) = src1 & src2 /*; Log("and") */);
  // fence TODO
  // ecall TODO
  // ebreak
  // RV32M Standard Extension
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, R,
          R(rd) = (int64_t)src1 * (int64_t)src2 /*; Log("mul") */);
  INSTPAT(
      "0000001 ????? ????? 001 ????? 01100 11", mulh, R,
      R(rd) = mulh(
          src1,
          src2)); // R (rd) = (uint32_t)(((int64_t)src1*(int64_t)src2)>>32)/*;
                  // Log("mulh")*/);
  INSTPAT(
      "0000001 ????? ????? 010 ????? 01100 11", mulhsu, R,
      R(rd) = mulhsu(
          src1,
          src2)); // R (rd) = (uint32_t)(((int64_t)src1*(uint64_t)src2)>>32)/*;
                  // Log("mulhsu")*/);
  INSTPAT(
      "0000001 ????? ????? 011 ????? 01100 11", mulhu, R,
      R(rd) = mulhu(
          src1,
          src2)); // R (rd) = (uint32_t)(((uint64_t)src1*(uint64_t)src2)>>32)/*;
                  // Log("mulhu")*/);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div, R,
          R(rd) = (int32_t)src1 / (int32_t)src2 /*; Log("div") */);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu, R,
          R(rd) = (int32_t)src1 / src2 /*; Log("divu") */);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem, R,
          R(rd) = (int32_t)src1 % (int32_t)src2 /*; Log("rem") */);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, R,
          R(rd) = (int32_t)src1 % src2 /*; Log("remu") */);
  // my code end

  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0
  // Log("0x%08x -> 0x%08x", s->pc, s->dnpc);
  return 0;
}

int isa_exec_once(Decode *s)
{
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
