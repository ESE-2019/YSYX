
#include "trap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED 31
#define ANSI_COLOR_GREEN 32
#define ANSI_COLOR_WHITE 37
#define ANSI_COLOR_RESET 0

#define TILE_W 4
#define SCREEN_W 320
#define SCREEN_H 200
    static inline void
    set_color(int c)
{
}

static inline void print_char(char c, int y, int x)
{
  static char last_c = 0xff;
  static uint32_t buf[TILE_W * TILE_W];
  if (last_c != c)
  {
    last_c = c;
    uint32_t color = 0x0;
    if (c != ' ')
    { // convert different character to different color
      uint8_t r = c / 25;
      c -= r * 25;
      uint8_t g = c / 5;
      c -= g * 5;
      uint8_t b = c;
      r = r * 0x100 / 5;
      g = g * 0x100 / 5;
      b = b * 0x100 / 5;
      color = (r << 16) | (g << 8) | b;
    }
    int i;
    for (i = 0; i < TILE_W * TILE_W; i++)
    {
      buf[i] = color;
    }
  }
  io_write(AM_GPU_FBDRAW, x * TILE_W, y * TILE_W, buf, TILE_W, TILE_W, false);
}

static inline void screen_clear()
{
  static uint32_t buf[SCREEN_W];
  int i;
  for (i = 0; i < SCREEN_H; i++)
  {
    io_write(AM_GPU_FBDRAW, 0, i, buf, SCREEN_W, 1, false);
  }
}

static inline void screen_refresh()
{
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
}

static inline int screen_tile_height()
{
  return io_read(AM_GPU_CONFIG).height / TILE_W;
}

static inline int screen_tile_width()
{
  return io_read(AM_GPU_CONFIG).width / TILE_W;
}

static inline void usleep(int us)
{
  uint64_t now = io_read(AM_TIMER_UPTIME).us;
  uint64_t next = now + us;
  while (io_read(AM_TIMER_UPTIME).us < next)
    ;
}

#define H 5

typedef struct
{
  int *x, n, cap[H];
} tower;
static tower t[3];

static void init_tower(tower *t)
{
  memset(t, 0, sizeof(*t));
  t->x = &t->cap[0];
}

static void text(int y, int i, int d, const char *s)
{
  int yy = H - y + 1;
  int xx = (H + 1) * (2 * i + 1) - d;
  while (d--)
  {
    for (const char *p = s; *p; p++)
    {
      print_char(*p, yy, xx++);
    }
  }
}

static void add_disk(int i, int d)
{
  t[i].x[t[i].n++] = d;
  text(t[i].n, i, d, "==");
  screen_refresh();
  usleep(100000);
}

int remove_disk(int i)
{
  int d = t[i].x[--t[i].n];
  text(t[i].n + 1, i, d, "  ");
  return d;
}

void move(int n, int from, int to, int via)
{
  if (!n)
    return;

  move(n - 1, from, via, to);
  add_disk(to, remove_disk(from));
  move(n - 1, via, to, from);
}

void hanoi()
{
  screen_clear();

  int c;
  for (c = 0; c < 3; c++)
    init_tower(&t[c]);
  for (c = H; c; c--)
    add_disk(0, c);

  move(H, 0, 2, 1);
}

int main(const char *args)
{
  ioe_init();
  hanoi();
  return 0;
}