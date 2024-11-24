#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>

static Context *(*user_handler)(Event, Context *) = NULL;

__attribute__((section(".klib"))) Context *__am_irq_handle(Context *c)
{
  if (user_handler)
  {
    Event ev = {0};
    switch (c->mcause)
    {
    case 11:
      ev.event = EVENT_YIELD;
      c->mepc += 4;
      break;
    default:
      ev.event = EVENT_ERROR;
      break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

__attribute__((section(".klib"))) bool cte_init(Context *(*handler)(Event, Context *))
{
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  user_handler = handler;
  return true;
}
// this is npc
__attribute__((section(".klib"))) Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
  Context *ret = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  ret->mepc = (uintptr_t)entry;
  ret->mstatus = 0x1800;
  ret->gpr[10] = (uintptr_t)arg;
  return ret;
}

__attribute__((section(".klib"))) void yield()
{
#ifdef __riscv_e
  asm volatile("li a5, 11; ecall");
#else
  asm volatile("li a7, 11; ecall");
#endif
}

__attribute__((section(".klib"))) bool ienabled() { return false; }

__attribute__((section(".klib"))) void iset(bool enable) {}
