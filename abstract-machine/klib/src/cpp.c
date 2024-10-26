#include <am.h>
#include <klib.h>

#ifndef __ISA_NATIVE__

void __attribute__((section(".klib"))) __dso_handle() {
}

void __attribute__((section(".klib"))) __cxa_guard_acquire() {
}

void __attribute__((section(".klib"))) __cxa_guard_release() {
}

void __attribute__((section(".klib"))) __cxa_atexit() {
  assert(0);
}

#endif
