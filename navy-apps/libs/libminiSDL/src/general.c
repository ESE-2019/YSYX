#include <NDL.h>
#include <assert.h>

uint32_t ticks;
int SDL_Init(uint32_t flags)
{
  int ret = NDL_Init(flags);
  ticks = NDL_GetTicks();
  return ret;
}

void SDL_Quit()
{
  NDL_Quit();
}

char *SDL_GetError()
{
  return "Navy does not support SDL_GetError()";
}

int SDL_SetError(const char *fmt, ...)
{
  return -1;
}

int SDL_ShowCursor(int toggle)
{
  assert(0);
  return 0;
}

void SDL_WM_SetCaption(const char *title, const char *icon)
{
  assert(0);
}
