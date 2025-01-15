#include <common.h>
#include "syscall.h"

static uintptr_t a[4];

static void strace(uintptr_t code)
{
#ifdef STRACE
  const char *SyscallNames[] = {
      "SYS_exit",
      "SYS_yield",
      "SYS_open",
      "SYS_read",
      "SYS_write",
      "SYS_kill",
      "SYS_getpid",
      "SYS_close",
      "SYS_lseek",
      "SYS_brk",
      "SYS_fstat",
      "SYS_time",
      "SYS_signal",
      "SYS_execve",
      "SYS_fork",
      "SYS_link",
      "SYS_unlink",
      "SYS_wait",
      "SYS_times",
      "SYS_gettimeofday"};
  Log("%p = %s(%p, %p, %p)", code, SyscallNames[a[0]], a[1], a[2], a[3]);
#endif
}

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

  strace(c->GPRx);
}
