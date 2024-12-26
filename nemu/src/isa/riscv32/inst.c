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
#include <isa.h>
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

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2,
                           word_t *imm, word_t *uimm, int type)
{
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd = BITS(i, 11, 7);
  *uimm = BITS(i, 19, 15);
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

static inline int32_t __mulh__(int32_t a, int32_t b)
{
  int64_t result = (int64_t)a * (int64_t)b;
  return (int32_t)(result >> 32);
}

static inline uint32_t __mulhu__(uint32_t a, uint32_t b)
{
  uint64_t result = (uint64_t)a * (uint64_t)b;
  return (uint32_t)(result >> 32);
}

static inline int32_t __mulhsu__(int32_t a, uint32_t b)
{
  int64_t result = (int64_t)a * (uint64_t)b;
  return (int32_t)(result >> 32);
}

static inline int32_t __div__(int32_t a, int32_t b)
{
  if (a == -1 << 31 && b == -1)
    return -1 << 31;
  else if (b != 0)
    return a / b;
  else
    return -1;
}

static inline uint32_t __divu__(uint32_t a, uint32_t b)
{
  if (b != 0)
    return a / b;
  else
    return -1;
}

static inline int32_t __rem__(int32_t a, int32_t b)
{
  if (a == -1 << 31 && b == -1)
    return 0;
  else if (b != 0)
    return a % b;
  else
    return a;
}

static inline uint32_t __remu__(uint32_t a, uint32_t b)
{
  if (b != 0)
    return a % b;
  else
    return a;
}

uint32_t CSR_r(uint32_t imm)
{
  int csr = imm & 0xFFF;
  vaddr_t *addr;
  switch (csr)
  {
  case 0x300:
    addr = &cpu.mstatus;
    break;
  case 0x305:
    addr = &cpu.mtvec;
    break;
  case 0x341:
    addr = &cpu.mepc;
    break;
  case 0x342:
    addr = &cpu.mcause;
    break;
  case 0xf11:
    addr = &cpu.mvendorid;
    break;
  case 0xf12:
    addr = &cpu.marchid;
    break;
  default:
    panic();
    break;
  }
#ifdef CONFIG_ETRACE
  Log(FMT_WORD "CSR_r csr%03X data" FMT_WORD, cpu.pc, imm, *addr);
#endif
  return *addr;
}

void CSR_w(uint32_t imm, uint32_t data)
{
  int csr = imm & 0xFFF;
  vaddr_t *addr;
  switch (csr)
  {
  case 0x300:
    addr = &cpu.mstatus;
    *addr = data;
    break;
  case 0x305:
    addr = &cpu.mtvec;
    *addr = data & 0xFFFFFFFC;
    break;
  case 0x341:
    addr = &cpu.mepc;
    *addr = data & 0xFFFFFFFE;
    break;
  case 0x342:
    addr = &cpu.mcause;
    *addr = data;
    break;
  case 0xf11:
    addr = &cpu.mvendorid;
    break;
  case 0xf12:
    addr = &cpu.marchid;
    break;
  default:
    panic();
    break;
  }
#ifdef CONFIG_ETRACE
  Log(FMT_WORD "CSR_w csr%03X data" FMT_WORD, cpu.pc, imm, *addr);
#endif
}

#ifdef CONFIG_FTRACE
extern char FT_name[][256];
extern uint32_t FT_addr[];
static uint32_t FT_local[4096] = {};
static uint32_t FT_ret[4096] = {};
static uint16_t FT_index = 0;
char ftrace_buf[16 * 65536] = "";
// jump to addr, curr pc, store to reg
static void ftrace_jump(const uint32_t addr, const uint32_t pc, const uint32_t reg)
{
  for (int i = 0; FT_addr[i] != 0; i++) // add
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
      snprintf(tmp2, 1024, FMT_WORD ": call [%s@" FMT_WORD "]\n", pc, FT_name[i], FT_addr[i]);
      strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
      strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf) - 1);
      return;
    }
  }
  for (int i = FT_index - 1; i >= 0; i--)
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
      snprintf(tmp2, 1024, FMT_WORD ": ret [%s]\n", pc, FT_name[FT_local[i]]);
      strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
      strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf) - 1);
      return;
    }
  }
}
static void ftrace_print(const uint32_t addr)
{
  Log("%s", ftrace_buf);
}
#endif

#define CACHE_SIZE 2 // index
#define CACHE_WAY 1
#define CACHE_LINE 3 // 0-4b 1-8b 2-16b 3-32b

typedef struct
{
  bool vld[CACHE_WAY];
  uint32_t pc[CACHE_WAY];
  uint8_t del;
} cachesim_t;

static cachesim_t dummy_cache[CACHE_SIZE];
static int hit_num = 0, miss_num = 0;
static void cache_sim(uint32_t pc)
{
  if (pc < 0x30000000)
    return;

  pc = pc >> 2;
  pc = pc >> CACHE_LINE;
  int index = pc & (CACHE_SIZE - 1);

  assert(index < CACHE_SIZE);
  assert(dummy_cache[index].del < CACHE_WAY);

  for (int i = 0; i < CACHE_WAY; i++)

  {
    if (dummy_cache[index].vld[i] && dummy_cache[index].pc[i] == pc)
    {
      hit_num++;
      // dummy_cache[index].del = 1 ^ i;
      return;
    }
  }

  miss_num++;
  dummy_cache[index].vld[dummy_cache[index].del] = 1;
  dummy_cache[index].pc[dummy_cache[index].del] = pc;

  dummy_cache[index].del ^= 1;
  // dummy_cache[index].del++;

  if (dummy_cache[index].del >= CACHE_WAY)
    dummy_cache[index].del = 0;
}

#define DCACHE_SIZE 1 // index
#define DCACHE_WAY 1
#define DCACHE_LINE 0 // 0-4b 1-8b 2-16b 3-32b

typedef struct
{
  bool vld[DCACHE_WAY];
  uint32_t addr[DCACHE_WAY];
  uint8_t del;
} Dcachesim_t;

static Dcachesim_t Ddummy_cache[DCACHE_SIZE];
static int Dhit_num = 0, Dmiss_num = 0;
static void Dcache_sim(uint32_t addr)
{
  if (addr < 0xa0000000)
    return;

  addr = addr >> 2;
  addr = addr >> DCACHE_LINE;
  int index = addr & (DCACHE_SIZE - 1);

  assert(index < DCACHE_SIZE);
  assert(Ddummy_cache[index].del < DCACHE_WAY);

  for (int i = 0; i < DCACHE_WAY; i++)

  {
    if (Ddummy_cache[index].vld[i] && Ddummy_cache[index].addr[i] == addr)
    {
      Dhit_num++;
      // dummy_cache[index].del = 1 ^ i;
      return;
    }
  }

  Dmiss_num++;
  Ddummy_cache[index].vld[Ddummy_cache[index].del] = 1;
  Ddummy_cache[index].addr[Ddummy_cache[index].del] = addr;

  // dummy_cache[index].del ^= 1;
  Ddummy_cache[index].del++;

  if (Ddummy_cache[index].del >= DCACHE_WAY)
    Ddummy_cache[index].del = 0;
}

uint32_t b_hit = 0, b_miss = 0;
void branch_sim(bool cond, int imm)
{
  bool pred = imm < 0;
  if (pred == cond)
  {
    b_hit++;
  }
  else
  {
    b_miss++;
  }
}

static void print_cachesim()
{
  double num = 100 * (double)hit_num / (double)(hit_num + miss_num);
  printf("I$ H/(H+M) = %.3f%% \n", num);
  num = 100 * (double)Dhit_num / (double)(Dhit_num + Dmiss_num);
  printf("D$ H/(H+M) = %.3f%% \n", num);
  num = 100 * (double)b_hit / (double)(b_hit + b_miss);
  printf("BRANCH H/(H+M) = %.3f%% \n", num);
}

extern void print_iringbuf();
void compressed_decoder(uint32_t zc_val, uint32_t *inst, uint32_t *is_zc, uint32_t *zc_err);

static int decode_exec(Decode *s)
{
  cache_sim(s->pc);
  uint32_t inst_c, is_zc_c, zc_err_c;
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0, uimm = 0, tmp = 0;
  compressed_decoder((s)->isa.inst.val, &inst_c, &is_zc_c, &zc_err_c);
  if (is_zc_c)
    s->snpc = s->pc + 0x2;
  s->dnpc = s->snpc;
  (s)->isa.inst.val = inst_c;
  if (zc_err_c)
    INV(s->pc);

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */)                \
  {                                                                         \
    decode_operand(s, &rd, &src1, &src2, &imm, &uimm, concat(TYPE_, type)); \
    __VA_ARGS__;                                                            \
  }

  INSTPAT_START();
  // Zicsr
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw, I, R(rd) = CSR_r(imm); CSR_w(imm, src1); IFDEF(CONFIG_ETRACE, Log(FMT_WORD "csrrw, R(%d) = " FMT_WORD " src" FMT_WORD, cpu.pc, rd, R(rd), src1)););
  INSTPAT("??????? ????? 00000 010 ????? 11100 11", csrrs_read, I, R(rd) = CSR_r(imm); IFDEF(CONFIG_ETRACE, Log(FMT_WORD "csrrs_read, R(%d) = " FMT_WORD " src" FMT_WORD " tmp" FMT_WORD, cpu.pc, rd, R(rd), src1, tmp)););
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs, I, tmp = CSR_r(imm); R(rd) = tmp; CSR_w(imm, src1 | tmp); IFDEF(CONFIG_ETRACE, Log(FMT_WORD "csrrs, R(%d) = " FMT_WORD " src" FMT_WORD " tmp" FMT_WORD, cpu.pc, rd, R(rd), src1, tmp)););
  INSTPAT("??????? ????? 00000 011 ????? 11100 11", csrrc_read, I, IFDEF(CONFIG_ETRACE, Log("csrrc_read")); R(rd) = CSR_r(imm););
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc, I, IFDEF(CONFIG_ETRACE, Log("csrrc")); tmp = CSR_r(imm); R(rd) = tmp; CSR_w(imm, (~src1) | tmp););
  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi, I, IFDEF(CONFIG_ETRACE, Log("csrrwi")); R(rd) = CSR_r(imm); CSR_w(imm, uimm););
  INSTPAT("??????? ????? 00000 110 ????? 11100 11", csrrsi_read, I, IFDEF(CONFIG_ETRACE, Log("csrrsi_read")); R(rd) = CSR_r(imm););
  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi, I, IFDEF(CONFIG_ETRACE, Log("csrrsi")); R(rd) = CSR_r(imm); CSR_w(imm, uimm | tmp););
  INSTPAT("??????? ????? 00000 111 ????? 11100 11", csrrci_read, I, IFDEF(CONFIG_ETRACE, Log("csrrci_read")); R(rd) = CSR_r(imm););
  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci, I, IFDEF(CONFIG_ETRACE, Log("csrrci")); R(rd) = CSR_r(imm); CSR_w(imm, (~uimm) | tmp););

  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(rd) = imm);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(rd) = s->snpc; s->dnpc = s->pc + imm; IFDEF(CONFIG_FTRACE, ftrace_jump(s->dnpc, s->pc, R(rd))));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, R(rd) = s->snpc; s->dnpc = (src1 + imm) & (int32_t)-2; IFDEF(CONFIG_FTRACE, ftrace_jump(s->dnpc, s->pc, R(rd))));

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, branch_sim(src1 == src2, imm); if (src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, branch_sim(src1 != src2, imm); if (src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B, branch_sim((int32_t)src1 < (int32_t)src2, imm); if ((int32_t)src1 < (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B, branch_sim((int32_t)src1 >= (int32_t)src2, imm); if ((int32_t)src1 >= (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B, branch_sim(src1 < src2, imm); if (src1 < src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B, branch_sim(src1 >= src2, imm); if (src1 >= src2) s->dnpc = s->pc + imm);

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb, I, Dcache_sim(src1 + imm); R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I, Dcache_sim(src1 + imm); R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I, Dcache_sim(src1 + imm); R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I, Dcache_sim(src1 + imm); R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I, Dcache_sim(src1 + imm); R(rd) = Mr(src1 + imm, 2));

  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S, Dcache_sim(src1 + imm); Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S, Dcache_sim(src1 + imm); Mw(src1 + imm, 4, src2));

  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I, Dcache_sim(src1 + imm); R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti, I, R(rd) = ((int32_t)src1 < (int32_t)imm) ? 1 : 0);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I, R(rd) = (src1 < (uint32_t)imm) ? 1 : 0);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori, I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I, R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli, I, R(rd) = src1 << BITS(imm, 4, 0));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli, I, R(rd) = src1 >> BITS(imm, 4, 0));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai, I, R(rd) = (int32_t)src1 >> BITS(imm, 4, 0));

  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll, R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, R, R(rd) = ((int32_t)src1 < (int32_t)src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, R, R(rd) = (src1 < src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor, R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl, R, R(rd) = src1 >> src2);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra, R, R(rd) = (int32_t)src1 >> src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and, R, R(rd) = src1 & src2);
  // fence
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall, N, s->dnpc = isa_raise_intr(11, s->pc));
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, IFDEF(CONFIG_FTRACE, ftrace_print(0)); IFDEF(CONFIG_ITRACE, print_iringbuf()); print_cachesim(); isa_raise_intr(3, s->pc); NEMUTRAP(s->pc, R(10)));

  // RV32M Standard Extension
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, R, R(rd) = (int64_t)src1 * (int64_t)src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh, R, R(rd) = __mulh__(src1, src2));
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu, R, R(rd) = __mulhsu__(src1, src2));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu, R, R(rd) = __mulhu__(src1, src2));
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div, R, R(rd) = __div__(src1, src2));
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu, R, R(rd) = __divu__(src1, src2));
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem, R, R(rd) = __rem__(src1, src2));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, R, R(rd) = __remu__(src1, src2));

  // others
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret, N, s->dnpc = cpu.mepc; cpu.mstatus = 0x1880 | (BITS(cpu.mstatus, 7, 7) << 3); IFDEF(CONFIG_ETRACE, Log("mret")););
  INSTPAT("??????? ????? ????? ??? ????? 00011 11", MISC_MEM, N, ;);

  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0
  return 0;
}

int isa_exec_once(Decode *s)
{
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}

void compressed_decoder(uint32_t zc_val, uint32_t *inst, uint32_t *is_zc, uint32_t *zc_err)
{
  *inst = zc_val;
  *is_zc = 1;
  *zc_err = 0;

  uint8_t c0 = zc_val & 0x3;
  uint8_t c1 = (zc_val >> 13) & 0x7;

  switch (c0)
  {
  case 0x0:
  {
    switch (c1)
    {
    case 0x0:
    {
      if (((zc_val >> 5) & 0xFF) == 0x0)
      {
        *zc_err = 1;
      }
      else
      {
        *inst = (0 << 30) |
                ((zc_val >> 7) & 0xF) << 26 |
                ((zc_val >> 11) & 0x3) << 24 |
                ((zc_val >> 5) & 0x1) << 23 |
                ((zc_val >> 6) & 0x1) << 22 |
                (0 << 20) |
                (0x2 << 15) |
                (0 << 12) |
                (0x1 << 10) |
                ((zc_val >> 2) & 0x7) << 7 |
                0x13;
      }
    }
    break;

    case 0x2:
    {
      *inst = (0 << 27) |
              ((zc_val >> 5) & 0x1) << 26 |
              ((zc_val >> 10) & 0x7) << 23 |
              ((zc_val >> 6) & 0x1) << 22 |
              (0 << 20) |
              (0x1 << 18) |
              ((zc_val >> 7) & 0x7) << 15 |
              (0x2 << 12) |
              (0x1 << 10) |
              ((zc_val >> 2) & 0x7) << 7 |
              0x03;
    }
    break;

    case 0x4:
    {
      uint8_t c2 = (zc_val >> 10) & 0x7;
      switch (c2)
      {
      case 0x0:
      {
        *inst = (0 << 22) |
                ((zc_val >> 5) & 0x1) << 21 |
                ((zc_val >> 6) & 0x1) << 20 |
                (0x1 << 18) |
                ((zc_val >> 7) & 0x7) << 15 |
                (0x4 << 12) |
                (0x1 << 10) |
                ((zc_val >> 2) & 0x7) << 7 |
                0x03;
      }
      break;
      case 0x1:
      {
        if (!((zc_val >> 6) & 0x1))
        {
          *inst = (0 << 22) |
                  ((zc_val >> 5) & 0x1) << 21 |
                  (0x1 << 18) |
                  ((zc_val >> 7) & 0x7) << 15 |
                  (0x5 << 12) |
                  (0x1 << 10) |
                  ((zc_val >> 2) & 0x7) << 7 |
                  0x03;
        }
        else
        {
          *inst = (0 << 22) |
                  ((zc_val >> 5) & 0x1) << 21 |
                  (0x1 << 18) |
                  ((zc_val >> 7) & 0x7) << 15 |
                  (0x1 << 12) |
                  (0x1 << 10) |
                  ((zc_val >> 2) & 0x7) << 7 |
                  0x03;
        }
      }
      break;
      case 0x2:
      {
        *inst = (0x0 << 12) |
                (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                ((zc_val >> 6) & 0x1) << 7 |
                ((zc_val >> 5) & 0x1) << 8 |
                0x23;
      }
      break;
      case 0x3:
      {
        if (!((zc_val >> 6) & 0x1))
        {
          *inst = (0x1 << 12) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  ((zc_val >> 5) & 0x1) << 8 |
                  0x23;
        }
        else
        {
          *zc_err = 1;
        }
      }
      break;
      default:
      {
        *zc_err = 1;
      }
      break;
      }
    }
    break;

    case 0x6:
    {
      *inst = (0x2 << 12) |
              (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
              (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
              ((zc_val >> 10) & 0x3) << 10 |
              ((zc_val >> 6) & 0x1) << 9 |
              ((zc_val >> 5) & 0x1) << 26 |
              ((zc_val >> 12) & 0x1) << 25 |
              0x23;
    }
    break;
    default:
    {
      *zc_err = 1;
    }
    break;
    }
  }
  break;
  case 0x1:
  {
    switch (c1)
    {
    case 0x0:
    {
      *inst = (0x0 << 12) |
              ((zc_val >> 7) & 0x1F) << 7 |
              ((zc_val >> 7) & 0x1F) << 15 |
              ((zc_val >> 2) & 0x1F) << 20 |
              ((zc_val >> 12) & 0x1) << 31 |
              ((zc_val >> 12) & 0x1) << 30 |
              ((zc_val >> 12) & 0x1) << 29 |
              ((zc_val >> 12) & 0x1) << 28 |
              ((zc_val >> 12) & 0x1) << 27 |
              ((zc_val >> 12) & 0x1) << 26 |
              ((zc_val >> 12) & 0x1) << 25 |
              0x13;
    }
    break;

    case 0x1:
    case 0x5:
    {
      *inst = ((zc_val >> 12) & 0x1) << 31 |
              ((zc_val >> 8) & 0x1) << 30 |
              ((zc_val >> 9) & 0x3) << 28 |
              ((zc_val >> 6) & 0x1) << 27 |
              ((zc_val >> 7) & 0x1) << 26 |
              ((zc_val >> 2) & 0x1) << 25 |
              ((zc_val >> 11) & 0x1) << 24 |
              ((zc_val >> 3) & 0x7) << 21 |
              ((zc_val >> 12) & 0x1) << 20 |
              ((zc_val >> 12) & 0x1) << 19 |
              ((zc_val >> 12) & 0x1) << 18 |
              ((zc_val >> 12) & 0x1) << 17 |
              ((zc_val >> 12) & 0x1) << 16 |
              ((zc_val >> 12) & 0x1) << 15 |
              ((zc_val >> 12) & 0x1) << 14 |
              ((zc_val >> 12) & 0x1) << 13 |
              ((zc_val >> 12) & 0x1) << 12 |
              (~(zc_val >> 15) & 0x1) << 7 |
              0x6F;
    }
    break;

    case 0x2:
    {
      *inst = (0x0 << 12) |
              ((zc_val >> 7) & 0x1F) << 7 |
              ((zc_val >> 2) & 0x1F) << 20 |
              ((zc_val >> 12) & 0x1) << 31 |
              ((zc_val >> 12) & 0x1) << 30 |
              ((zc_val >> 12) & 0x1) << 29 |
              ((zc_val >> 12) & 0x1) << 28 |
              ((zc_val >> 12) & 0x1) << 27 |
              ((zc_val >> 12) & 0x1) << 26 |
              ((zc_val >> 12) & 0x1) << 25 |
              0x13;
    }
    break;

    case 0x3:
    {
      if (((zc_val >> 7) & 0x1F) != 0x2)
      {
        *inst = ((zc_val >> 12) & 0x1) << 31 |
                ((zc_val >> 12) & 0x1) << 30 |
                ((zc_val >> 12) & 0x1) << 29 |
                ((zc_val >> 12) & 0x1) << 28 |
                ((zc_val >> 12) & 0x1) << 27 |
                ((zc_val >> 12) & 0x1) << 26 |
                ((zc_val >> 12) & 0x1) << 25 |
                ((zc_val >> 12) & 0x1) << 24 |
                ((zc_val >> 12) & 0x1) << 23 |
                ((zc_val >> 12) & 0x1) << 22 |
                ((zc_val >> 12) & 0x1) << 21 |
                ((zc_val >> 12) & 0x1) << 20 |
                ((zc_val >> 12) & 0x1) << 19 |
                ((zc_val >> 12) & 0x1) << 18 |
                ((zc_val >> 12) & 0x1) << 17 |
                ((zc_val >> 2) & 0x1F) << 12 |
                ((zc_val >> 7) & 0x1F) << 7 |
                0x37;
      }
      else
      {
        *inst = ((zc_val >> 12) & 0x1) << 31 |
                ((zc_val >> 12) & 0x1) << 30 |
                ((zc_val >> 12) & 0x1) << 29 |
                ((zc_val >> 3) & 0x3) << 27 |
                ((zc_val >> 5) & 0x1) << 26 |
                ((zc_val >> 2) & 0x1) << 25 |
                ((zc_val >> 6) & 0x1) << 24 |
                0x2 << 15 |
                0x2 << 7 |
                0x13;
      }
      if (!((zc_val >> 12) & 0x1) && !((zc_val >> 2) & 0x1F))
      {
        *zc_err = 1;
      }
    }
    break;

    case 0x4:
    {
      uint8_t c2 = (zc_val >> 10) & 0x3;
      switch (c2)
      {
      case 0x0:
      case 0x1:
      {
        *inst = ((zc_val >> 10) & 0x1) << 30 |
                ((zc_val >> 2) & 0x1F) << 20 |
                (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                0x5 << 12 |
                0x13;
        if ((zc_val >> 12) & 0x1)
        {
          *zc_err = 1;
        }
      }
      break;
      case 0x2:
      {
        *inst = (0x7 << 12) |
                (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                ((zc_val >> 2) & 0x1F) << 20 |
                ((zc_val >> 12) & 0x1) << 31 |
                ((zc_val >> 12) & 0x1) << 30 |
                ((zc_val >> 12) & 0x1) << 29 |
                ((zc_val >> 12) & 0x1) << 28 |
                ((zc_val >> 12) & 0x1) << 27 |
                ((zc_val >> 12) & 0x1) << 26 |
                ((zc_val >> 12) & 0x1) << 25 |
                0x13;
      }
      break;
      case 0x3:
      {
        uint8_t c3 = ((zc_val >> 12) & 0x1) << 2 | ((zc_val >> 5) & 0x3);
        switch (c3)
        {
        case 0x0:
        {
          *inst = (0x1 << 30) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                  0x33;
        }
        break;
        case 0x1:
        {
          *inst = (0x4 << 12) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                  0x33;
        }
        break;
        case 0x2:
        {
          *inst = (0x6 << 12) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                  0x33;
        }
        break;
        case 0x3:
        {
          *inst = (0x7 << 12) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                  0x33;
        }
        break;
        case 0x6:
        {
          *inst = (0x1 << 25) |
                  (0x8 + ((zc_val >> 2) & 0x7)) << 20 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                  (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                  0x33;
          if (((zc_val >> 10) & 0x3) != 0x3)
          {
            *zc_err = 1;
          }
        }
        break;
        case 0x7:
        {
          uint8_t c4 = (zc_val >> 2) & 0x7;
          switch (c4)
          {
          case 0x0:
          {
            *inst = (0x0FF << 20) |
                    (0x7 << 12) |
                    (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                    (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                    0x13;
          }
          break;
          case 0x5:
          {
            *inst = (0xFFF << 20) |
                    (0x4 << 12) |
                    (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
                    (0x8 + ((zc_val >> 7) & 0x7)) << 7 |
                    0x13;
          }
          break;
          default:
          {
            *zc_err = 1;
          }
          break;
          }
        }
        break;
        default:
        {
          *zc_err = 1;
        }
        break;
        }
      }
      break;
      default:
      {
        *zc_err = 1;
      }
      break;
      }
    }
    break;
    case 0x6:
    case 0x7:
    {
      *inst = ((zc_val >> 12) & 0x1) << 31 |
              ((zc_val >> 12) & 0x1) << 30 |
              ((zc_val >> 12) & 0x1) << 29 |
              ((zc_val >> 12) & 0x1) << 28 |
              ((zc_val >> 5) & 0x3) << 26 |
              ((zc_val >> 2) & 0x1) << 25 |
              (0x8 + ((zc_val >> 7) & 0x7)) << 15 |
              ((zc_val >> 13) & 0x1) << 12 |
              ((zc_val >> 10) & 0x3) << 10 |
              ((zc_val >> 3) & 0x3) << 8 |
              ((zc_val >> 12) & 0x1) << 7 |
              0x63;
    }
    break;
    default:
    {
      *zc_err = 1;
    }
    break;
    }
  }
  break;
  case 0x2:
  {
    switch (c1)
    {
    case 0x0:
    {
      *inst = (0x1 << 12) |
              ((zc_val >> 7) & 0x1F) << 15 |
              ((zc_val >> 7) & 0x1F) << 7 |
              ((zc_val >> 2) & 0x1F) << 20 |
              0x13;
      if ((zc_val >> 12) & 0x1)
      {
        *zc_err = 1;
      }
    }
    break;
    case 0x2:
    {
      *inst = (0x2 << 12) |
              (0x2 << 15) |
              ((zc_val >> 7) & 0x1F) << 7 |
              ((zc_val >> 4) & 0x7) << 22 |
              ((zc_val >> 12) & 0x1) << 25 |
              ((zc_val >> 2) & 0x3) << 26 |
              0x03;
      if (((zc_val >> 7) & 0x1F) == 0x0)
      {
        *zc_err = 1;
      }
    }
    break;
    case 0x4:
    {
      if (!((zc_val >> 12) & 0x1))
      {
        if ((zc_val >> 2) & 0x1F)
        {
          *inst = ((zc_val >> 2) & 0x1F) << 20 |
                  ((zc_val >> 7) & 0x1F) << 7 |
                  0x33;
        }
        else
        {
          *inst = ((zc_val >> 7) & 0x1F) << 15 |
                  0x67;
          if (((zc_val >> 7) & 0x1F) == 0x0)
          {
            *zc_err = 1;
          }
        }
      }
      else
      {
        if ((zc_val >> 2) & 0x1F)
        {
          *inst = ((zc_val >> 7) & 0x1F) << 7 |
                  ((zc_val >> 2) & 0x1F) << 20 |
                  ((zc_val >> 7) & 0x1F) << 15 |
                  0x33;
        }
        else
        {
          if (((zc_val >> 7) & 0x1F) == 0x0)
          {
            *inst = 0x00100073;
          }
          else
          {
            *inst = ((zc_val >> 7) & 0x1F) << 15 |
                    0x1 << 7 |
                    0x67;
          }
        }
      }
    }
    break;
    case 0x6:
    {
      *inst = (0x2 << 12) |
              ((zc_val >> 2) & 0x1F) << 20 |
              ((zc_val >> 7) & 0x3) << 26 |
              ((zc_val >> 12) & 0x1) << 25 |
              0x2 << 15 |
              ((zc_val >> 9) & 0x7) << 9 |
              0x23;
    }
    break;
    default:
    {
      *zc_err = 1;
    }
    break;
    }
  }
  break;
  case 0x3:
  {
    *is_zc = 0;
  }
  break;
  }
}
