#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <stdio.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
outb(0xa00003f8, ch);
}

void halt(int code) {
  __asm__ volatile("mv a0, %0; ebreak" : :"r"(code));
  while(1)
  ;
}

void print_ysyx() {
    uint32_t mvendorid;
    uint32_t marchid;
    char ysyx[5];
    
    __asm__ volatile (
        "csrr %0, 0xF11"
        : "=r" (mvendorid)
    );

    __asm__ volatile (
        "csrr %0, 0xF12"
        : "=r" (marchid)
    );
    
    for (int i = 0; i < 4; i++) {
        ysyx[3-i] = (mvendorid >> (8 * i)) & 0xFF;
    }
    
    ysyx[4] = '\0';
    
    printf("%s_%d\n", ysyx, marchid);
}

void _trm_init() {
  print_ysyx();
  int ret = main(mainargs);
  halt(ret);
}
