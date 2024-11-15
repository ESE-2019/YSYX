#include "trap.h"

static inline uint8_t inb(uintptr_t addr)
{
  return *(volatile uint8_t *)addr;
}
static inline uint16_t inw(uintptr_t addr)
{
  return *(volatile uint16_t *)addr;
}
static inline uint32_t inl(uintptr_t addr)
{
  return *(volatile uint32_t *)addr;
}

static inline void outb(uintptr_t addr, uint8_t data)
{
  *(volatile uint8_t *)addr = data;
}
static inline void outw(uintptr_t addr, uint16_t data)
{
  *(volatile uint16_t *)addr = data;
}
static inline void outl(uintptr_t addr, uint32_t data)
{
  *(volatile uint32_t *)addr = data;
}

static inline void test4(uintptr_t start, uintptr_t end)
{
  for (uintptr_t addr = start; addr < end; addr = addr + 4)
  {
    outl(addr, addr);
  }
  for (uintptr_t addr = start; addr < end; addr = addr + 4)
  {
    printf("addr: 0x%08x value: 0x%08x\n", addr, inl(addr));
    check(inl(addr) == addr);
  }
}

static inline void test2(uintptr_t start, uintptr_t end)
{
  for (uintptr_t addr = start; addr < end; addr = addr + 2)
  {
    outw(addr, addr & 0xffff);
  }
  for (uintptr_t addr = start; addr < end; addr = addr + 2)
  {
    printf("addr: 0x%08x value: 0x%08x\n", addr, inw(addr));
    check(inw(addr) == (addr & 0xffff));
  }
}

static inline void test1(uintptr_t start, uintptr_t end)
{
  for (uintptr_t addr = start; addr < end; addr = addr + 1)
  {
    outb(addr, addr & 0xff);
  }
  for (uintptr_t addr = start; addr < end; addr = addr + 1)
  {
    printf("addr: 0x%08x value: 0x%08x\n", addr, inb(addr));
    check(inb(addr) == (addr & 0xff));
  }
}

#define TEST_SIZE 0x10

int main()
{
  uintptr_t addr = (uintptr_t)malloc(TEST_SIZE);
    test4(addr, TEST_SIZE);
    test2(addr, TEST_SIZE);
    test1(addr, TEST_SIZE);
  
  return 0;
}
