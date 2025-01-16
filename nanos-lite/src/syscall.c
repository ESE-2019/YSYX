#include <common.h>
#include <fs.h>
#include <proc.h>
#include <sys/time.h>
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
    if (a[1] == 0)
    {
      naive_uload(current, "/bin/menu");
    }
    else
    {
      Log("exit_code = %d", a[1]);
      halt(1);
    }
    break;
  }

  case SYS_yield:
  {
    yield();
    c->GPRx = 0;
    break;
  }

  case SYS_open:
  {
    c->GPRx = fs_open((char *)a[1], a[2], a[3]);
    break;
  }

  case SYS_read:
  {
    c->GPRx = fs_read(a[1], (void *)a[2], a[3]);
    break;
  }

  case SYS_write:
  {
    c->GPRx = fs_write(a[1], (void *)a[2], a[3]);
    break;
  }

  case SYS_close:
  {
    c->GPRx = fs_close(a[1]);
    break;
  }

  case SYS_lseek:
  {
    c->GPRx = fs_lseek(a[1], a[2], a[3]);
    break;
  }

  case SYS_brk:
  {
    c->GPRx = 0;
    break;
  }

  case SYS_execve:
  {
    c->GPRx = -1;
    naive_uload(current, (const char *)a[1]);
    break;
  }

  case SYS_gettimeofday:
  {
    if ((struct timeval *)a[1] == NULL)
    {
      c->GPRx = -1;
      break;
    }
    c->GPRx = 0;
    uint64_t time = io_read(AM_TIMER_UPTIME).us;
    struct timeval *tv = (struct timeval *)a[1];
    tv->tv_usec = time % 1000000;
    tv->tv_sec = time / 1000000;
    if ((struct timezone *)a[2] != NULL)
    {
      struct timezone *tz = (struct timezone *)a[2];
      tz->tz_minuteswest = 0;
      tz->tz_dsttime = 0;
    }
    break;
  }

  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }

  strace(c->GPRx);
}
