#include <common.h>
#include "syscall.h"

static uintptr_t a[4];

#ifdef STRACE
static void strace(uintptr_t code)
{
  Log("%p = %s(%p, %p, %p)", code, SyscallNames[a[0]], a[1], a[2], a[3]);
}
#endif

void do_syscall(Context *c)
{
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  switch (a[0])
  {
  case SYS_exit:
  {
    halt(a[1]);
    break;
  }
  case SYS_yield:
  {
    yield();
    c->GPRx = 0;
    break;
  }
  case SYS_write:
  {
    char *str = (char *)a[2];
    c->GPRx = 0;
    if (a[1] == 1 || a[1] == 2)
    {
      for (int i = 0; i < a[3]; i++)
      {
        putch(str[i]);
        c->GPRx++;
      }
    }
    else
    {
      c->GPRx = -1;
    }
    break;
  }
  case SYS_brk:
  {
    c->GPRx = 0;
    break;
  }
  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }

#ifdef STRACE
  strace(c->GPRx);
#endif
}
