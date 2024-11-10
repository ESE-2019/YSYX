#include <am.h>

bool __attribute__((section(".klib"))) vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *))
{
  return false;
}

void __attribute__((section(".klib"))) protect(AddrSpace *as) {}

void __attribute__((section(".klib"))) unprotect(AddrSpace *as) {}

void __attribute__((section(".klib"))) map(AddrSpace *as, void *va, void *pa, int prot) {}

__attribute__((section(".klib"))) Context *ucontext(AddrSpace *as, Area kstack, void *entry) { return NULL; }
