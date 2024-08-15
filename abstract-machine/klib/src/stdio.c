#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#include <stdarg.h>
#include <stdio.h>

static void itoa(int value, char *str) {
  char buffer[20];
  int i = 0, j = 0, is_negative = 0;
  if (value < 0) {
    is_negative = 1;
    value = -value;
  }
  do {
    buffer[i++] = (char)('0' + (value % 10));
    value /= 10;
  } while (value > 0);

  if (is_negative) {
    buffer[i++] = '-';
  }
  while (i > 0) {
    str[j++] = buffer[--i];
  }
  str[j] = '\0';
}

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  const char *f = fmt;
  int count = 0;

  while (*f != '\0') {
    if (*f == '%') {
      f++;
      switch (*f) {
      case 'd': {
        int value = va_arg(args, int);
        char buffer[20];
        itoa(value, buffer);
        putstr(buffer);
        count += strlen(buffer);
        break;
      }
      case 's': {
        const char *value = va_arg(args, const char *);
        putstr(value);
        count += strlen(value);
        break;
      }
      case 'c': {
        char value = (char)va_arg(args, int);
        putch(value);
        count++;
        break;
      }
      case '%': {
        putch('%');
        count++;
        break;
      }
      default:
        putstr("[unsupported]");
        putch('%');
        putch(*f);
        count += 2;
        break;
      }
    } else {
      putch(*f);
      count++;
    }
    f++;
  }

  va_end(args);
  return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  char *p = out;
  const char *f = fmt;

  while (*f != '\0') {
    if (*f == '%') {
      f++;
      switch (*f) {
      case 'd': {
        int value = va_arg(args, int);
        char buffer[20];
        itoa(value, buffer);
        for (char *b = buffer; *b != '\0'; b++) {
          *p++ = *b;
        }
        break;
      }
      case 's': {
        const char *value = va_arg(args, const char *);
        while (*value != '\0') {
          *p++ = *value++;
        }
        break;
      }
      case 'c': {
        char value = (char)va_arg(args, int);
        *p++ = value;
        break;
      }
      case '%': {
        *p++ = '%';
        break;
      }
      default:
        *p++ = '%';
        *p++ = *f;
        break;
      }
    } else {
      *p++ = *f;
    }
    f++;
  }

  *p = '\0';
  va_end(args);
  return p - out;
}
int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
