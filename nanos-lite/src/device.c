#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
#define MULTIPROGRAM_YIELD() yield()
#else
#define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
    [AM_KEY_NONE] = "NONE",
    AM_KEYS(NAME)};

size_t serial_write(const void *buf, size_t offset, size_t len)
{
  //yield();
  size_t ret = 0;
  char *str = (char *)buf;
  for (int i = 0; i < len; i++)
  {
    putch(str[i]);
    ret++;
  }
  return ret;
}

size_t events_read(void *buf, size_t offset, size_t len)
{
  //yield();
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  if (ev.keycode != 0)
  {
    return snprintf((char *)buf, len, "%s %s\n", ev.keydown ? "kd" : "ku", keyname[ev.keycode]);
  }
  return 0;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len)
{
  return snprintf((char *)buf, len, "WIDTH: %d\nHEIGHT: %d\n", screen_w, screen_h);
}

size_t fb_write(const void *buf, size_t offset, size_t len)
{
  //yield();
  io_write(AM_GPU_FBDRAW, offset % screen_w, offset / screen_w, (void *)buf, len, 1, true);
  return 0;
}

void init_device()
{
  Log("Initializing devices...");
  ioe_init();
}
