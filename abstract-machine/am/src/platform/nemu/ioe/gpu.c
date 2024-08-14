#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  uint32_t V = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = ((uint16_t)(V >> 16)),
                           .height = ((uint16_t)V),
                           .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  if (!ctl->sync && (w == 0 || h == 0))
    return;

  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t screen_w = inl(VGACTL_ADDR) >> 16;

  for (int i = 0; i < h; i++)
  {
    uint32_t *fb_row = &fb[screen_w * (y + i) + x];
    uint32_t *pixels_row = &pixels[w * i];
    for (int j = 0; j < w; j++)
    {
      fb_row[j] = pixels_row[j];
    }
  }
    outl(SYNC_ADDR, 1);
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
