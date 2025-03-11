#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;

void switch_boot_pcb()
{
  Log("switch_boot_pcb");
  current = &pcb_boot;
}

void hello_fun(void *arg)
{
  int i = 0, j = 1;
  while (1)
  {
    if (i++ > 10000)
    {
      Log("Hello World from Nanos-lite with arg '%s' for the %dth time!", (char *)arg, j);
      j++;
      i = 0;
    }
    yield();
  }
}

void init_proc()
{
  switch_boot_pcb();
  Log("Initializing processes...");

  // context_kload(&pcb[0], hello_fun, "pcb0");
  char *argv[] = {"/bin/menu", NULL};
  context_uload(&pcb[0], argv[0], argv, (char *[]){NULL});
  context_uload(&pcb[1], argv[0], argv, (char *[]){NULL});
  context_uload(&pcb[2], argv[0], argv, (char *[]){NULL});
  context_uload(&pcb[3], argv[0], argv, (char *[]){NULL});
}

Context *schedule(Context *prev)
{
  current->cp = prev;
  if (current == &pcb[0])
  {
    Log("pcb0 to pcb1");
    current = &pcb[1];
  }
  else if (current == &pcb[1])
  {
    Log("pcb1 to pcb2");
    current = &pcb[2];
  }
  else if (current == &pcb[2])
  {
    Log("pcb2 to pcb3");
    current = &pcb[3];
  }
  else if (current == &pcb[3])
  {
    Log("pcb3 to pcb0");
    current = &pcb[0];
  }
  else
  {
    Log("pcb_boot to pcb0");
    current = &pcb[0];
  }
  return current->cp;
}
