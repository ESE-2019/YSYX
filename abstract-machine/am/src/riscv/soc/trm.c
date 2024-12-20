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

__attribute__((section(".klib"))) static void print_hpm()
{
    uint32_t value = -1;
    __asm__ volatile("csrw mcountinhibit, %0" : : "r"(value));

    uint32_t mcycleh, mcycle;
    uint32_t minstreth, minstret;
    __asm__ volatile("csrr %0, mcycleh" : "=r"(mcycleh));
    __asm__ volatile("csrr %0, mcycle" : "=r"(mcycle));
    __asm__ volatile("csrr %0, minstreth" : "=r"(minstreth));
    __asm__ volatile("csrr %0, minstret" : "=r"(minstret));
    uint64_t cycle = ((uint64_t)mcycleh << 32) | mcycle;
    uint64_t inst = ((uint64_t)minstreth << 32) | minstret;
    uint32_t ipc = (100000 * inst) / cycle;
    printf("minstret=0x%08x%08x\n", minstreth, minstret);
    printf("  mcycle=0x%08x%08x\n", mcycleh, mcycle);
    printf("     IPC=0.%05d\n", ipc);

    uint32_t is_compressed_high, is_compressed_low;
    __asm__ volatile("csrr %0, mhpmcounter10h" : "=r"(is_compressed_high));
    __asm__ volatile("csrr %0, mhpmcounter10" : "=r"(is_compressed_low));
    uint64_t is_compressed = ((uint64_t)is_compressed_high << 32) | is_compressed_low;
    uint32_t print = (100000 * is_compressed) / inst;
    printf("     RVC=0.%05d\n", print);

    uint32_t fetch_cycle_high, fetch_cycle_low;
    __asm__ volatile("csrr %0, mhpmcounter11h" : "=r"(fetch_cycle_high));
    __asm__ volatile("csrr %0, mhpmcounter11" : "=r"(fetch_cycle_low));
    uint64_t fetch_cycle = 100 * (((uint64_t)fetch_cycle_high << 32) | fetch_cycle_low);
    uint32_t fetch_delay = fetch_cycle / inst;
    printf("  DelayF=%d.%03d\n", fetch_delay / 100, fetch_delay % 100);

    uint32_t hith, hitl;
    uint32_t missh, missl;
    __asm__ volatile("csrr %0, mhpmcounter3h" : "=r"(hith));
    __asm__ volatile("csrr %0, mhpmcounter3" : "=r"(hitl));
    __asm__ volatile("csrr %0, mhpmcounter4h" : "=r"(missh));
    __asm__ volatile("csrr %0, mhpmcounter4" : "=r"(missl));
    uint64_t hit = ((uint64_t)hith << 32) | hitl;
    uint64_t miss = ((uint64_t)missh << 32) | missl;
    uint64_t total = hit + miss;
    uint64_t hit_tmp = 100000 * hit;
    uint32_t icache_hit = hit_tmp / total;
    printf("      I$=0.%05d\n", icache_hit);

    uint32_t load_num_high, load_num_low;
    uint32_t load_cycle_high, load_cycle_low;
    __asm__ volatile("csrr %0, mhpmcounter6h" : "=r"(load_num_high));
    __asm__ volatile("csrr %0, mhpmcounter6" : "=r"(load_num_low));
    __asm__ volatile("csrr %0, mhpmcounter7h" : "=r"(load_cycle_high));
    __asm__ volatile("csrr %0, mhpmcounter7" : "=r"(load_cycle_low));
    uint64_t load_num = ((uint64_t)load_num_high << 32) | load_num_low;
    uint64_t load_cycle = 100 * (((uint64_t)load_cycle_high << 32) | load_cycle_low);
    uint32_t load_delay = load_cycle / load_num;
    printf("  DelayL=%d.%03d\n", load_delay / 100, load_delay % 100);

    uint32_t store_num_high, store_num_low;
    uint32_t store_cycle_high, store_cycle_low;
    __asm__ volatile("csrr %0, mhpmcounter8h" : "=r"(store_num_high));
    __asm__ volatile("csrr %0, mhpmcounter8" : "=r"(store_num_low));
    __asm__ volatile("csrr %0, mhpmcounter9h" : "=r"(store_cycle_high));
    __asm__ volatile("csrr %0, mhpmcounter9" : "=r"(store_cycle_low));
    uint64_t store_num = ((uint64_t)store_num_high << 32) | store_num_low;
    uint64_t store_cycle = 100 * (((uint64_t)store_cycle_high << 32) | store_cycle_low);
    uint32_t store_delay = store_cycle / store_num;
    printf("  DelayS=%d.%03d\n", store_delay / 100, store_delay % 100);

    uint32_t aver_delay = (load_cycle + store_cycle) / (load_num + store_num);
    printf("  DelayA=%d.%03d\n", aver_delay / 100, aver_delay % 100);

    __asm__ volatile("csrwi mcountinhibit, 0");
}

__attribute__((section(".klib"))) void inline halt(int code)
{
    __asm__ volatile("mv a0, %0; wfi" : : "r"(code));
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

    __asm__ volatile("csrr %0, mvendorid" : "=r"(mvendorid));
    __asm__ volatile("csrr %0, marchid" : "=r"(marchid));

    for (int i = 0; i < 4; i++)
    {
        ysyx[3 - i] = (mvendorid >> (8 * i)) & 0xFF;
    }

    ysyx[4] = '\0';

    printf("%s_%d\n", ysyx, marchid);
    outl(0x10002008, decimalTo32Bit(marchid));
}

static void __attribute__((section(".klib"), noinline)) _trm_init()
{
    uart_init();
    print_ysyx();
    __asm__ volatile("fence.i");
    int ret = main(mainargs);
    print_hpm();
    halt(ret);
}

static void __attribute__((section(".bootloader"), noinline)) memcpy_bootloader(void *vma_start, void *vma_end, void *lma_start)
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