#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t __attribute__((section(".klib"))) strlen(const char *s) {
  const char *p = s;
  while (*p) {
    p++;
  }
  return p - s;
}

char __attribute__((section(".klib"))) *strcpy(char *dst, const char *src) {
  char *d = dst;
  const char *s = src;

  while ((*d++ = *s++) != '\0')
    ;

  return dst;
}

char __attribute__((section(".klib"))) *strncpy(char *dst, const char *src, size_t n) {
  char *d = dst;
  const char *s = src;
  while (n > 0 && *s != '\0') {
        *d++ = *s++;
        n--;
    }
    while (n > 0) {
        *d++ = '\0';
        n--;
    }
  return dst;
}

char __attribute__((section(".klib"))) *strcat(char *dst, const char *src) {
  char *d = dst;
  const char *s = src;

  while (*d != '\0') {
    d++;
  }

  while (*s != '\0') {
    *d = *s;
    d++;
    s++;
  }
  *d = '\0';
  return dst;
}

int __attribute__((section(".klib"))) strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int __attribute__((section(".klib"))) strncmp(const char *s1, const char *s2, size_t n) {
  while (n-- > 0) {
    if (*s1 != *s2) {
      return *(unsigned char *)s1 - *(unsigned char *)s2;
    }
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return 0;
}

void __attribute__((section(".klib"))) *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  while (n-- > 0) {
    *p++ = (unsigned char)c;
  }
  return s;
}

void __attribute__((section(".klib"))) *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = dst;
  const unsigned char *s = src;
  if (d < s) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
    d += n;
    s += n;
    while (n--) {
      *--d = *--s;
    }
  }
  return dst;
}

void __attribute__((section(".klib"))) *memcpy(void *out, const void *in, size_t n) {
  unsigned char *s1 = out;
  const unsigned char *s2 = in;
  while (n-- > 0) {
    *s1++ = *s2++;
  }
  return out;
}

int __attribute__((section(".klib"))) memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  while (n-- > 0) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }
  return 0;
}

#endif
