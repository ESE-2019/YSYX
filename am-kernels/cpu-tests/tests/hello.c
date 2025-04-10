#include "trap.h"

int main(const char *args) {
  const char *fmt = "Hello, AbstractMachine!\n"
                    "mainargs = '%'.\n";
  putstr("Hello, AM World @ " __ISA__ "\n");
  for (const char *p = fmt; *p; p++) {
    (*p == '%') ? putstr(args) : putch(*p);
  }
  return 0;
}
