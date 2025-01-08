#include "trap.h"

#define STACK_SIZE 1024
typedef union
{
  uint8_t stack[STACK_SIZE];
  struct
  {
    Context *cp;
  };
} PCB;
static PCB pcb[5], pcb_boot, *current = &pcb_boot;

static int8_t cnt = 15;

static void f(void *arg)
{
  while (1)
  {
    putch("?PASS "[(uintptr_t)arg > 5 ? 0 : (uintptr_t)arg]);
    yield();
  }
}

static Context *schedule(Event ev, Context *prev)
{
  current->cp = prev;
  if (current == &pcb[0])
    current = &pcb[1];
  else if (current == &pcb[1])
    current = &pcb[2];
  else if (current == &pcb[2])
    current = &pcb[3];
  else if (current == &pcb[3])
    current = &pcb[4];
  else if (current == &pcb[4])
    current = &pcb[0];
  else
  {
    printf("initial begin\n\t");
    current = &pcb[0];
  }
  if (cnt-- <= 0)
  {
    printf("\nend\n");
    halt(0);
  }
  return current->cp;
}

int main()
{
  cte_init(schedule);
  pcb[0].cp = kcontext((Area){pcb[0].stack, &pcb[0] + 1}, f, (void *)1L);
  pcb[1].cp = kcontext((Area){pcb[1].stack, &pcb[1] + 1}, f, (void *)2L);
  pcb[2].cp = kcontext((Area){pcb[2].stack, &pcb[2] + 1}, f, (void *)3L);
  pcb[3].cp = kcontext((Area){pcb[3].stack, &pcb[3] + 1}, f, (void *)4L);
  pcb[4].cp = kcontext((Area){pcb[4].stack, &pcb[4] + 1}, f, (void *)5L);
  yield();
  return 0;
}
