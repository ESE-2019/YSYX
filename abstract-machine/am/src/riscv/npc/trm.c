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

//volatile uint8_t *output_char_address = (volatile uint8_t *)(0xa00003f8);
void putch(char ch) {
outb(0xa00003f8, ch);
}

void halt(int code) {
  __asm__ volatile("mv a0, %0; ebreak" : :"r"(code));
  while(1)
  ;
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}

   /*__asm__ volatile (
        "lui t0, 0xa0000\n"      // 加载高 20 位地址
        "addi t0, t0, 0x3f8\n"   // 加载低 12 位地址
        "sb %0, 0(t0)\n"         // 存储字节
        :
        : "r" (ch)            // 输入操作数，value 存储在寄存器中
        : "t0"                   // 声明寄存器 t0 被修改
    );*/
