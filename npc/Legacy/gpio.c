#include "trap.h"
#define UART_BASE_ADDR 0x10000000
#define UART_DLL (UART_BASE_ADDR + 0x00)
#define UART_DLH (UART_BASE_ADDR + 0x01)
#define UART_LCR (UART_BASE_ADDR + 0x03)
#define UART_FCR (UART_BASE_ADDR + 0x02)
#define UART_IER (UART_BASE_ADDR + 0x01)
#define UART_MCR (UART_BASE_ADDR + 0x04)
#define UART_LSR (UART_BASE_ADDR + 0x05)
#define UART_THR (UART_BASE_ADDR + 0x00)
static inline uint8_t inb(uintptr_t addr) { return *(volatile uint8_t *)addr; }
static inline uint16_t inw(uintptr_t addr)
{
  return *(volatile uint16_t *)addr;
}
static inline uint32_t inl(uintptr_t addr)
{
  return *(volatile uint32_t *)addr;
}

static inline void outb(uintptr_t addr, uint8_t data)
{
  *(volatile uint8_t *)addr = data;
}
static inline void outw(uintptr_t addr, uint16_t data)
{
  *(volatile uint16_t *)addr = data;
}
static inline void outl(uintptr_t addr, uint32_t data)
{
  *(volatile uint32_t *)addr = data;
}
unsigned int decimalTo32Bit(unsigned int decimal)
{
  unsigned int result = 0;
  unsigned int shift = 0;

  while (decimal > 0 && shift < 32)
  {
    unsigned int digit = decimal % 10;
    result |= (digit << shift);
    decimal /= 10;
    shift += 4;
  }
  return result;
}

#define NAMEINIT(key) [AM_KEY_##key] = #key,
// static const char *names[] = {AM_KEYS(NAMEINIT)};

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
      printf("Got  (kbd):(%02x) %s\n", ev.keycode, ev.keydown ? "DOWN" : "UP");
    }
  }
}

void keyboard_test()
{
  printf("Try to press any key (uart or keyboard)...\n");
  has_uart = io_read(AM_UART_CONFIG).present;
  has_kbd = io_read(AM_INPUT_CONFIG).present;
  while (1)
  {
    drain_keys();
  }
}

void display_image()
{
  printf("display enter!\n");
  uint32_t image[64][48];
  memset(image, 0, sizeof(image));
  // for (int i = 0; i < 640; i++)
  //   for (int j = 0; j < 480; j++)
  //     image[i][j] = 0x00abcdef;
  printf("display start!\n");
  io_write(AM_GPU_FBDRAW, 0, 0, &image[0][0], 640, 480, true);
  printf("display done!\n");
}

int main()
{

  uint32_t marchid;

  __asm__ volatile(
      "csrr %0, 0xF12"
      : "=r"(marchid));
  marchid = decimalTo32Bit(marchid);
  int sec = 1;
  uint16_t num = 1;
  int tmp;
  while (1)
  {
    while (io_read(AM_TIMER_UPTIME).us / 100000 < sec)
      ;
    num = (num << 1) | (num >> 15);
    *(volatile uint16_t *)0x10002000 = num;
    sec++;
    tmp = *(volatile uint32_t *)0x10002004;

    if (tmp == 0x01)
    {
      keyboard_test();
    }
    else if (tmp == 0x02)
    {
      display_image();
    }
    else
    {
      printf("tmp = 0x%08x\n", tmp);
      //*(volatile uint32_t *)0x10002008 = 0xabcdef;
    }
  }

  return 0;
}
