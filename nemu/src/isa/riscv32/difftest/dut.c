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

#include "../local-include/reg.h"
#include <cpu/difftest.h>
#include <isa.h>

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
    bool ret = true;
    int count = MUXDEF(CONFIG_RVE, 16, 32);
    if (ref_r->pc != cpu.pc)
        {
            Log(ANSI_FMT("pc = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), cpu.pc, ref_r->pc);
            ret =  false;
        }
    for (int i = 0; i < count; i++)
    {
        if (i == 2) continue;
        if (ref_r->gpr[i] != cpu.gpr[i])
        {
            Log(ANSI_FMT("gpr[%d] = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), i, cpu.gpr[i], ref_r->gpr[i]);
            ret =  false;
        }
        
    }
    if (ref_r->mepc != cpu.mepc)
        {
            Log(ANSI_FMT("mepc = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), cpu.mepc, ref_r->mepc);
            ret =  false;
        }
    if (ref_r->mstatus != cpu.mstatus)
        {
            Log(ANSI_FMT("mstatus = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), cpu.mstatus, ref_r->mstatus);
            ret = false;
        }
    if (ref_r->mcause != cpu.mcause)
        {
            Log(ANSI_FMT("mcause = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), cpu.mcause, ref_r->mcause);
            ret = false;
        }
    if (ref_r->mtvec != cpu.mtvec)
        {
            Log(ANSI_FMT("mtvec = "FMT_WORD" but ref is "FMT_WORD,ANSI_FG_RED), cpu.mtvec, ref_r->mtvec);
            ret = false;
        }
    return ret;
}

void isa_difftest_attach() {}
