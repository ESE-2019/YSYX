#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_uart_rx(AM_UART_RX_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) {
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

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  if (!ctl->sync || w == 0 || h == 0 || w > 640 || h > 480)
    return;

  uint32_t *pixels = ctl->pixels;

  for (int i = 0; i < h; i++)
  {
    uint32_t *pixels_row = &pixels[w * i];
    for (int j = 0; j < w; j++)
    {
      outl(0x21000000|((x+j)<<12)|((y+i)<<2),pixels_row[j]);
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
    [AM_GPU_STATUS] = __am_gpu_status,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i])
      lut[i] = fail;
  __am_timer_init();
  return true;
}

void ioe_read(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
