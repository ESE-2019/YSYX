#include <NDL.h>
#include <SDL.h>
#include <assert.h>
#include <string.h>

#define keyname(k) #k,

static const char *keyname[] = {
    "NONE",
    _KEYS(keyname)};

int SDL_PushEvent(SDL_Event *ev)
{
  assert(0);
  return 0;
}

int SDL_PollEvent(SDL_Event *ev)
{
  char buf[64], type[10], keysym[32];

  if (NDL_PollEvent(buf, sizeof(buf)))
  {
    sscanf(buf, "%s %s", type, keysym);

    if (strcmp(type, "kd") == 0)
    {
      ev->type = SDL_KEYDOWN;
    }
    else if (strcmp(type, "ku") == 0)
    {
      ev->type = SDL_KEYUP;
    }
    else
      assert(0);

    for (size_t i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++)
    {
      if (strcmp(keysym, keyname[i]) == 0)
      {
        ev->key.keysym.sym = i;
        return 1;
      }
    }
    assert(0);
  }

  return 0;
}

int SDL_WaitEvent(SDL_Event *event)
{

  char buf[64], type[10], keysym[32];
  while (1)
  {
    if (NDL_PollEvent(buf, sizeof(buf)))
    {
      sscanf(buf, "%s %s", type, keysym);

      if (strcmp(type, "kd") == 0)
      {
        event->type = SDL_KEYDOWN;
      }
      else if (strcmp(type, "ku") == 0)
      {
        event->type = SDL_KEYUP;
      }
      else
        assert(0);

      for (size_t i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++)
      {
        if (strcmp(keysym, keyname[i]) == 0)
        {
          event->key.keysym.sym = i;
          return 1;
        }
      }
      assert(0);
    }
  }
  return 0;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask)
{
  assert(0);
  return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys)
{
  assert(0);
  return NULL;
}
