#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define PRINT
#define error_quit

static inline uint8_t inb(uintptr_t addr) { return *(volatile uint8_t *)addr; }
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

static inline void test4(uint32_t start, uint32_t end)
{
  for (uint32_t addr = start; addr < end; addr = addr + 4)
  {
    outl(addr, addr);
  }
  for (uint32_t addr = start; addr < end; addr = addr + 4)
  {
    #ifdef PRINT
      printf("addr: 0x%08x value: 0x%08x\n", addr, inl(addr));
      #endif
      #ifdef error_quit
    if (inl(addr) != (addr))
      halt(1);
      #endif
  }
}

static inline void test2(uint32_t start, uint32_t end)
{
  for (uint32_t addr = start; addr < end; addr = addr + 2)
  {
    outw(addr, addr & 0xffff);
  }
  for (uint32_t addr = start; addr < end; addr = addr + 2)
  {
    #ifdef PRINT
      printf("addr: 0x%08x value: 0x%08x\n", addr, inw(addr));
      #endif
       #ifdef error_quit
    if (inw(addr) != (addr & 0xffff))
      halt(1);
      #endif
  }
}

static inline void test1(uint32_t start, uint32_t end)
{
  for (uint32_t addr = start; addr < end; addr = addr + 1)
  {
    outb(addr, addr & 0xff);
  }
  for (uint32_t addr = start; addr < end; addr = addr + 1)
  {
    #ifdef PRINT
      printf("addr: 0x%08x value: 0x%08x\n", addr, inb(addr));
      #endif
      #ifdef error_quit
    if (inb(addr) != (addr & 0xff))
      halt(1);
      #endif
  }
}


#define START_ADDR 0xa0000300u
#define END_ADDR   0xa0ffffffu
#define EACH_PART 0x250b00u
#define EACH_PART0 0x8u
extern char _heap_start;
extern char _heap_end;
int main()
{
  for (uint32_t main_loop = START_ADDR; main_loop < END_ADDR; main_loop += EACH_PART)
  {
    test4(main_loop, main_loop + EACH_PART0);
    // printf("----------------------------------\n");
     test2(main_loop-0x2, main_loop-0x2+ EACH_PART0);
    // printf("----------------------------------\n");
   test1(main_loop-0x3, main_loop-0x3 + EACH_PART0);
    // printf("==================================\n");
  }

  // for (uint32_t i = START_ADDR; i < END_ADDR; i += 1)
  // {
  //   inb(i);
  // }

  // init_spi();
  // for (uint32_t i = 0; i < 7; i++)
  // {
  //   uint32_t tmp = flash_read(i*4);
  //   printf("read%08x\n",tmp);
  //   //codebuf[i] = tmp;
  // }

  // void (*f)() = (void *)codebuf;
  // f();
  return 0;
}

// typedef void (*func_ptr)();

// uint32_t main() {
//     unsigned uint32_t target_address = START_ADDR;
//     func_ptr jump_to_func = (func_ptr)target_address;

//     printf("Jumping to address 0x%08X\n", target_address);
//     jump_to_func();
//     printf("This line should not be reached\n");
//     return 0;
// }



// #define SPI_BASE 0x10001000
// #define SPI_RX0 (SPI_BASE + 0x00)
// #define SPI_RX1 (SPI_BASE + 0x04)
// #define SPI_RX2 (SPI_BASE + 0x08)
// #define SPI_RX3 (SPI_BASE + 0x0c)
// #define SPI_CTRL (SPI_BASE + 0x10)
// #define SPI_DIV (SPI_BASE + 0x14)
// #define SPI_SS (SPI_BASE + 0x18)
// static void init_spi()
// {
//   //outl(SPI_DIV, 0);
//   outl(SPI_CTRL, 1<<13|64);
//   outl(SPI_SS, 1);
// }

// static inline uint32_t swap_bits(uint32_t data)
// {
//   // 提取31-24位和7-0位
//   uint32_t high_byte = (data >> 24) & 0xFF;
//   uint32_t low_byte = data & 0xFF;

//   // 提取23-16位和15-8位
//   uint32_t mid_high_byte = (data >> 8) & 0xFF;
//   uint32_t mid_low_byte = (data >> 16) & 0xFF;

//   // 交换31-24位和7-0位
//   uint32_t swapped_data = (low_byte << 24) | (high_byte);

//   // 交换23-16位和15-8位
//   swapped_data |= (mid_low_byte << 8) | (mid_high_byte << 16);

//   return swapped_data;
// }

// uint32_t flash_read(uint32_t addr)
// {
//   //outb(SPI_SS, 1);
//   outl(SPI_RX1, (0x03 << 24) | (0xffffff & addr));
//   outl(SPI_CTRL, 1<<13|(1 << 8) | 64);
//   while (inl(SPI_CTRL) & (1 << 8))
//     ;
//   //outb(SPI_SS, 0);
//   return swap_bits(inl(SPI_RX0));
// }
// uint32_t codebuf[100] = {};