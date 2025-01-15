#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <assert.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;
static int canvas_x = 0, canvas_y = 0;

uint32_t NDL_GetTicks()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int NDL_PollEvent(char *buf, int len)
{
  return read(evtdev, buf, len);
}

void NDL_OpenCanvas(int *w, int *h)
{
  if (getenv("NWM_APP"))
  {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w;
    screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1)
    {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0)
        continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0)
        break;
    }
    close(fbctl);
  }
  else
  {
    if (*w == 0)
      *w = screen_w;
    if (*h == 0)
      *h = screen_h;
    assert(*w > 0 && *w <= screen_w);
    assert(*h > 0 && *h <= screen_h);
    canvas_x = (screen_w - *w) / 2;
    canvas_y = (screen_h - *h) / 2;
  }
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h)
{
  for (int i = 0; i < h; i++)
  {
    lseek(fbdev, canvas_x + x + (canvas_y + y + i) * screen_w, SEEK_SET);
    write(fbdev, pixels + i * w, w);
  }
}

void NDL_OpenAudio(int freq, int channels, int samples)
{
}

void NDL_CloseAudio()
{
}

int NDL_PlayAudio(void *buf, int len)
{
  return 0;
}

int NDL_QueryAudio()
{
  return 0;
}

int NDL_Init(uint32_t flags)
{
  if (getenv("NWM_APP"))
  {
    evtdev = 3;
  }
  else
  {
    evtdev = open("/dev/events", O_RDONLY);
    assert(evtdev != -1);
  }

  char dispinfo[64];
  int diproc = open("/proc/dispinfo", O_RDONLY);
  read(diproc, dispinfo, 64);
  sscanf(dispinfo, "WIDTH: %d\nHEIGHT: %d\n", &screen_w, &screen_h);
  close(diproc);

  fbdev = open("/dev/fb", O_WRONLY);

  return 0;
}

void NDL_Quit()
{
  close(evtdev);
  close(fbdev);
}
