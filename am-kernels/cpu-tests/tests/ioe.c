#include "trap.h"

#define IOE ({ ioe_init(); })

void (*entry)() = NULL; // mp entry

#define CASE(id, entry_, ...) \
  case id:                    \
  {                           \
    void entry_();            \
    entry = entry_;           \
    __VA_ARGS__;              \
    entry_();                 \
    break;                    \
  }

#define NAMEINIT(key) [AM_KEY_##key] = #key,
static const char *names[] = {AM_KEYS(NAMEINIT)};

static bool has_uart, has_kbd;

static void drain_keys()
{
  if (has_uart)
  {
    while (1)
    {
      char ch = io_read(AM_UART_RX).data;
      if (ch == (char)-1)
        break;
      printf("Got (uart): %c (%d)\n", ch, ch & 0xff);
    }
  }

  if (has_kbd)
  {
    while (1)
    {
      AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
      if (ev.keycode == AM_KEY_NONE)
        break;
      printf("Got  (kbd): %s (%02x) %s\n", names[ev.keycode], ev.keycode,
             ev.keydown ? "DOWN" : "UP");
    }
  }
}

void keyboard_test()
{
  printf("Try to press any key (uart or keyboard)...\n");
  has_uart = io_read(AM_UART_CONFIG).present;
  has_kbd = io_read(AM_INPUT_CONFIG).present;
  drain_keys();
}

int main(const char *args)
{

  switch ('k')
  {
    CASE('k', keyboard_test, IOE);
  default:
    break;
  }
  return 0;
}