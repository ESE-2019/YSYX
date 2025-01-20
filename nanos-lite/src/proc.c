#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;

void switch_boot_pcb()
{
  current = &pcb_boot;
}

void hello_fun(void *arg)
{
  int j = 1;
  while (1)
  {
    Log("Hello World from Nanos-lite with arg '%s' for the %dth time!", (char *)arg, j);
    j++;
    yield();
  }
}

void init_proc()
{
  context_kload(&pcb[0], hello_fun, "pcb0");
  char *argv[] = {"/bin/exec-test", NULL};
  context_uload(&pcb[1], "/bin/exec-test", argv, (char *[]){NULL});
  switch_boot_pcb();

  Log("Initializing processes...");
  yield();
  naive_uload(current, "/bin/menu");
}

Context *schedule(Context *prev)
{
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  current = &pcb[1];
  return current->cp;
}
