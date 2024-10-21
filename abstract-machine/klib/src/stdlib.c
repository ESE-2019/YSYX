#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void)
{
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) { next = seed; }

int abs(int x) { return (x < 0 ? -x : x); }

int atoi(const char *nptr)
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

// #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
// #define HEAP_SIZE 0x2A00000
// static char my_heap[HEAP_SIZE];
// static char *addr = my_heap;
// #endif

// void *malloc(size_t size) {
//   // On native, malloc() will be called during initializaion of C runtime.
//   // Therefore do not call panic() here, else it will yield a dead recursion:
//   //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
// #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
//     if (addr + size > my_heap + HEAP_SIZE) {
//         //printf("[stdlib]malloc failed\n"); panic(0);//full
//         return NULL;
//     }
//     void *allocated = addr;
//     addr += size;
//     return allocated;
// #endif
//   return NULL;
// }
static char *heap_ = NULL;
void *malloc(size_t size)
{
  if (heap_ == NULL)
  {
    heap_ = heap.start;
  }
  if (heap_ + size > (char *)heap.end)
  {
    return NULL;
  }
  else
  {
    char *ret = heap_;
    heap_ += size;
    return ret;
  }
}

void free(void *ptr) {}

#endif
