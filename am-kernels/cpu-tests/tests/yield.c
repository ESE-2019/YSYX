#include "trap.h"

#define IOE ({ ioe_init(); })
#define CTE(h)                                                                 \
  ({                                                                           \
    Context *h(Event, Context *);                                              \
    cte_init(h);                                                               \
  })

void (*entry)() = NULL; // mp entry

#define CASE(id, entry_, ...)                                                  \
  case id: {                                                                   \
    void entry_();                                                             \
    entry = entry_;                                                            \
    __VA_ARGS__;                                                               \
    entry_();                                                                  \
    break;                                                                     \
  }
  
Context *simple_trap(Event ev, Context *ctx) {
  switch (ev.event) {
  case EVENT_YIELD:
    putch('y');
    break;
  default:
    panic("Unhandled event");
    break;
  }
  return ctx;
}

void hello_intr() {
  io_read(AM_INPUT_CONFIG);
  iset(1);
  int cnt = 10;
  while (cnt--) {
    yield();
  }
}

int main(const char *args) {

  switch ('i') {
    CASE('i', hello_intr, IOE, CTE(simple_trap));
  default: break;
  }
  return 0;
}
