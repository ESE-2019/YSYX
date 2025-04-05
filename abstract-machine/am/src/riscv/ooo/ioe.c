#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <stdio.h>

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_uart_rx(AM_UART_RX_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg)
{
  cfg->present = true;
  cfg->has_rtc = true;
}
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true; }
static void __am_uart_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true; }

void __am_gpu_init() {}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = 640,
                           .height = 480,
                           .vmemsz = 0};
}

static uint32_t cast_color(uint32_t input)
{
  uint32_t part1 = (input >> 20) & 0xF;
  uint32_t part2 = (input >> 12) & 0xF;
  uint32_t part3 = (input >> 4) & 0xF;
  uint32_t result = (part1 << 8) | (part2 << 4) | part3;
  return result;
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  uint32_t addr, value;
  for (int j = 0; j < h; j = j + 3)
  {
    uint32_t *tmp = &pixels[w * j];
    for (int i = 0; i < w; i = i + 6)
    {
      addr = 0x21000000 | ((x + i) << 11) | ((y + j) << 2);
      value = (cast_color(tmp[i + 3]) << 16) | cast_color(tmp[i]);
      outl(addr, value);
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
    [AM_TIMER_CONFIG] = __am_timer_config,
    [AM_TIMER_RTC] = __am_timer_rtc,
    [AM_TIMER_UPTIME] = __am_timer_uptime,
    [AM_INPUT_CONFIG] = __am_input_config,
    [AM_INPUT_KEYBRD] = __am_input_keybrd,
    [AM_UART_CONFIG] = __am_uart_config,
    [AM_UART_RX] = __am_uart_rx,
    [AM_GPU_CONFIG] = __am_gpu_config,
    [AM_GPU_FBDRAW] = __am_gpu_fbdraw,
    [AM_GPU_STATUS] = __am_gpu_status};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init()
{
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i])
      lut[i] = fail;
  __am_timer_init();
  return true;
}

void ioe_read(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
