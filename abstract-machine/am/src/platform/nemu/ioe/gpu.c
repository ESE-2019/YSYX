#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
static uint32_t screen_w, screen_h;
static uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
void __am_gpu_init()
{
  uint32_t tmp = inl(VGACTL_ADDR);
  screen_w = (tmp >> 16);
  screen_h = tmp & 0xFFFF;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = screen_w,
                           .height = screen_h,
                           .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  for (int i = 0; i < h; i++)
  {
    uint32_t *fb_row = &fb[screen_w * (y + i) + x];
    uint32_t *pixels_row = &pixels[w * i];
    for (int j = 0; j < w; j++)
    {
      fb_row[j] = pixels_row[j];
    }
  }
  if (ctl->sync)
  {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
