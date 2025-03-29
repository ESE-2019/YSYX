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

#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
  uint32_t tmp = addr;
  uint32_t *buffer = (uint32_t *)buf;
  for (int i = 0; i < n; i++)
  {
    paddr_write(tmp, 4, buffer[i]);
    tmp += 4;
  }
  Log("nemu will start inst 0x%08x at 0x%08x", paddr_read(addr, 4), addr);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) // 0 for normal, 1 for skip
{
  uint32_t *tmp = dut;
  if (direction == 0)
  {
    for (int i = 0; i < 32; i++)
    {
      tmp[i] = cpu.gpr[i];
    }
    tmp[0] = cpu.pc;
  }
  else
  {
    cpu.pc = tmp[0];
    for (int i = 1; i < 32; i++)
    {
      cpu.gpr[i] = tmp[i];
    }
  }
}

__EXPORT void difftest_exec(uint64_t n) { cpu_exec(n); }

__EXPORT void difftest_raise_intr(word_t NO) { panic("4"); }

__EXPORT void difftest_init(int port)
{
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
