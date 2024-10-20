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

#include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t soc_sram[SOC_SRAM_MSIZE] PG_ALIGN = {};
static uint8_t soc_mrom[SOC_MROM_MSIZE] PG_ALIGN = {};
#endif

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }

paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len)
{
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data)
{
  host_write(guest_to_host(addr), len, data);
}

// mrom
uint8_t *mrom_guest_to_host(paddr_t paddr) { return soc_mrom + paddr - SOC_MROM_MBASE; }
static word_t soc_mrom_read(paddr_t addr, int len)
{
  word_t ret = host_read(mrom_guest_to_host(addr), len);
  return ret;
}
static void soc_mrom_write(paddr_t addr, int len, word_t data)
{
  host_write(mrom_guest_to_host(addr), len, data);
}

// sram
uint8_t *sram_guest_to_host(paddr_t paddr) { return soc_sram + paddr - SOC_SRAM_MBASE; }

static word_t soc_sram_read(paddr_t addr, int len)
{
  word_t ret = host_read(sram_guest_to_host(addr), len);
  return ret;
}

static void soc_sram_write(paddr_t addr, int len, word_t data)
{
  host_write(sram_guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr)
{
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR
        ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem()
{
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT,
      PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len)
{
  if (likely(in_pmem(addr)))
  {
    word_t ret = pmem_read(addr, len);
#ifdef CONFIG_MTRACE
    Log("[paddr_read] addr: " FMT_PADDR " len: %d data: " FMT_WORD " pc = " FMT_WORD, addr, len, ret, cpu.pc);
#endif
    return ret;
  }
  else if (in_soc_mrom(addr))
  {
    word_t ret = soc_mrom_read(addr, len);
    return ret;
  }
  else if (in_soc_sram(addr))
  {
    word_t ret = soc_sram_read(addr, len);
    return ret;
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data)
{
#ifdef CONFIG_MTRACE
  Log("[paddr_write] addr: " FMT_PADDR " len: %d data: " FMT_WORD " pc = " FMT_WORD, addr, len, data, cpu.pc);
#endif
  if (likely(in_pmem(addr)))
  {
    pmem_write(addr, len, data);
    return;
  }
  else if (in_soc_mrom(addr))
  {
    soc_mrom_write(addr, len, data);
    return;
  }
  else if (in_soc_sram(addr))
  {
    soc_sram_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
