#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c) {
  /*printf("mcause: %d, mstatus: %d, mepc: %d\n", c->mcause, c->mstatus, c->mepc);
  for (size_t i = 0; i < NR_REGS; i++)
  {
    printf("gpr%d: %d\n", i, c->gpr[i]);
  }*/
  
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
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

bool cte_init(Context *(*handler)(Event, Context *)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context * ret = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  //printf("%x %x\n", (uintptr_t)kstack.end, (uintptr_t)ret);
  ret->mepc = (uintptr_t)entry;
  ret->mstatus = 0x1800;
  ret->gpr[10] = (uintptr_t)arg;
  return ret;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, 11; ecall");
#else
  asm volatile("li a7, 11; ecall");
#endif
}

bool ienabled() { return false; }

void iset(bool enable) {}
