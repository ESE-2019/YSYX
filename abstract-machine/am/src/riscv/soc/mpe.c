#include <am.h>

bool __attribute__((section(".klib"))) mpe_init(void (*entry)()) { return false; }

int __attribute__((section(".klib"))) cpu_count() { return 1; }

int __attribute__((section(".klib"))) cpu_current() { return 0; }

int __attribute__((section(".klib"))) atomic_xchg(int *addr, int newval) { return 0; }
