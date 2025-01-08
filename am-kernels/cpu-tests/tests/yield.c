#include "trap.h"

static char *pass = "***YIELD PASS***\n";
int cnt = 0;
Context *simple_trap(Event ev, Context *ctx)
{
  switch (ev.event)
  {
  case EVENT_YIELD:
    putch(pass[cnt]);
    break;
  default:
    panic("Unhandled event");
    break;
  }
  return ctx;
}

int main(const char *args)
{
  ioe_init();
  cte_init(simple_trap);
  io_read(AM_INPUT_CONFIG);
  iset(1);
  for (; cnt < strlen(pass); cnt++)
  {
    yield();
  }
  return 0;
}
