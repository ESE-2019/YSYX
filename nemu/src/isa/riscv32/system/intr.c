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

#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
  cpu.mepc = epc;
  cpu.mcause = NO;
  cpu.mstatus = 0x1800 | (BITS(cpu.mstatus, 3, 3) << 7);
  IFDEF(CONFIG_ETRACE, Log("[ISA_RAISE_INTR] NO%X EPC%X MTVEC%X", NO, epc, cpu.mtvec));
  return cpu.mtvec;
}

word_t isa_query_intr() { return INTR_EMPTY; }
