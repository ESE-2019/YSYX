#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
while ((inb(0x10000005) & (1 << 5)) == 0);
outb(0x10000000, ch);
}

void halt(int code) {
  __asm__ volatile("mv a0, %0; ebreak" : :"r"(code));
  while(1)
  ;
}

void uart_init() {

    uint16_t divisor = 1;//CLOCK_FREQUENCY / (BAUD_RATE * 16);

    outb(0x10000003, 1 << 7);
    outb(0x10000000, (uint8_t)(divisor & 0xFF));
    outb(0x10000001, (uint8_t)((divisor >> 8) & 0xFF));
    outb(0x10000003, 0);
}

void _trm_init() {
  uart_init();
  int ret = main(mainargs);
  halt(ret);
}
