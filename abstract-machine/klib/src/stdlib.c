#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int __attribute__((section(".klib"))) rand(void)
{
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void __attribute__((section(".klib"))) srand(unsigned int seed) { next = seed; }

int __attribute__((section(".klib"))) abs(int x) { return (x < 0 ? -x : x); }

int __attribute__((section(".klib"))) atoi(const char *nptr)
{
  int x = 0;
  while (*nptr == ' ')
  {
    nptr++;
  }
  while (*nptr >= '0' && *nptr <= '9')
  {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

static void *heap_ = NULL;
void __attribute__((section(".klib"))) *malloc(size_t size)
{
  if (heap_ == NULL)
  {
    heap_ = heap.start;
  }

  heap_ = (void *)(((uintptr_t)heap_+3) & ~0x3u);

  if (heap_ + size > heap.end)
  {
    printf("malloc failed\n");
    printf("0x%08x 0x%08x\n", heap.start, heap.end);
    return NULL;
  }
  else
  {
    char *ret = heap_;
    heap_ += size;
    return ret;
  }
}

void __attribute__((section(".klib"))) free(void *ptr) {}

#endif
