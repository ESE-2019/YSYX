#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <stdio.h>
#include <string.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void __attribute__((section(".klib"))) putch(char ch)
{
    while ((inb(SOC_UART_LSR) & (1 << 5)) == 0)
        ;
    outb(SOC_UART_THR, ch);
}

__attribute__((section(".klib"))) void halt(int code)
{
    __asm__ volatile("mv a0, %0; ebreak" : : "r"(code));
    while (1)
        ;
}

static inline void uart_init()
{

    uint16_t divisor = 1;
    uint8_t tmp = inb(SOC_UART_LCR);
    outb(SOC_UART_LCR, (1 << 7) | tmp);
    outb(SOC_UART_DLH, (uint8_t)((divisor >> 8) & 0xFF));
    outb(SOC_UART_DLL, (uint8_t)(divisor & 0xFF));
    outb(SOC_UART_LCR, tmp);
}

static inline uint32_t decimalTo32Bit(uint32_t decimal)
{
    uint32_t result = 0;
    uint32_t shift = 0;

    while (decimal > 0 && shift < 32)
    {
        uint32_t digit = decimal % 10;
        result |= (digit << shift);
        decimal /= 10;
        shift += 4;
    }
    return result;
}

static inline void print_ysyx()
{
    uint32_t mvendorid;
    uint32_t marchid;
    char ysyx[5];

    __asm__ volatile(
        "csrr %0, 0xF11"
        : "=r"(mvendorid));

    __asm__ volatile(
        "csrr %0, 0xF12"
        : "=r"(marchid));

    for (int i = 0; i < 4; i++)
    {
        ysyx[3 - i] = (mvendorid >> (8 * i)) & 0xFF;
    }

    ysyx[4] = '\0';

    printf("%s_%d\n", ysyx, marchid);
    outl(0x10002008, decimalTo32Bit(marchid));
}

static inline void _trm_init()
{
    uart_init();
    print_ysyx();
    int ret = main(mainargs);
    halt(ret);
}

static inline void memcpy_bootloader(void *vma_start, void *vma_end, void *lma_start)
{
    while (vma_start < vma_end)
    {
        *(uint32_t *)vma_start = *(uint32_t *)lma_start;
        vma_start += 4;
        lma_start += 4;
    }
}

void __attribute__((section(".bootloader"))) _bootloader()
{
    extern char _klib_vma_start;
    extern char _klib_vma_end;
    extern char _klib_lma_start;
    memcpy_bootloader(&_klib_vma_start, &_klib_vma_end, &_klib_lma_start);

    extern char _text_vma_start;
    extern char _text_vma_end;
    extern char _text_lma_start;
    memcpy_bootloader(&_text_vma_start, &_text_vma_end, &_text_lma_start);

    extern char _data_vma_start;
    extern char _data_vma_end;
    extern char _data_lma_start;
    memcpy_bootloader(&_data_vma_start, &_data_vma_end, &_data_lma_start);

    _trm_init();
}