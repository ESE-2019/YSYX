#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <stdio.h>
#include <string.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t) & _pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch)
{
    while ((inb(SOC_UART_LSR) & (1 << 5)) == 0)
        ;
    outb(SOC_UART_THR, ch);
}

void halt(int code)
{
    __asm__ volatile("mv a0, %0; ebreak" : : "r"(code));
    while (1)
        ;
}

static void uart_init()
{

    uint16_t divisor = 1;
    uint8_t tmp = inb(SOC_UART_LCR);
    outb(SOC_UART_LCR, (1 << 7) | tmp);
    outb(SOC_UART_DLH, (uint8_t)((divisor >> 8) & 0xFF));
    outb(SOC_UART_DLL, (uint8_t)(divisor & 0xFF));
    outb(SOC_UART_LCR, tmp);
}
// static uint32_t decimalTo32Bit(uint32_t decimal) {
//     uint32_t result = 0;
//     uint32_t shift = 0;

//     while (decimal > 0 && shift < 32) {
//         uint32_t digit = decimal % 10;
//         result |= (digit << shift);
//         decimal /= 10;
//         shift += 4;
//     }
//     return result;
// }

// static void print_ysyx() {
//     uint32_t mvendorid;
//     uint32_t marchid;
//     char ysyx[5];

//     __asm__ volatile (
//         "csrr %0, 0xF11"
//         : "=r" (mvendorid)
//     );

//     __asm__ volatile (
//         "csrr %0, 0xF12"
//         : "=r" (marchid)
//     );

//     for (int i = 0; i < 4; i++) {
//         ysyx[3-i] = (mvendorid >> (8 * i)) & 0xFF;
//     }

//     ysyx[4] = '\0';

//     printf("%s_%d\n", ysyx, marchid);
//     outl(0x10002008, decimalTo32Bit(marchid));
// }

extern unsigned int _data;     // 数据段在 SRAM 的开始地址
extern unsigned int edata;    // 数据段在 SRAM 的结束地址
extern unsigned int _rom_data; // 数据段在 ROM 的开始地址

void init_data_segment(void)
{
    // 获取数据段的大小
    unsigned int size = (unsigned int)(&edata - &_data);

    // 使用 memcpy 从 ROM 复制到 SRAM
    memcpy((void *)&_data, (const void *)&_rom_data, size);
}

void _trm_init()
{
    init_data_segment();
    uart_init();
    // print_ysyx();
    int ret = main(mainargs);
    halt(ret);
}
