#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#include <stdarg.h>
#include <stdio.h>

// 辅助函数：将整数转换为字符串
static void itoa(int value, char *str) {
  char buffer[20];
  int i = 0, j = 0, is_negative = 0;

  // 处理负数
  if (value < 0) {
    is_negative = 1;
    value = -value;
  }

  // 生成数字字符
  do {
    buffer[i++] = (char)('0' + (value % 10));
    value /= 10;
  } while (value > 0);

  if (is_negative) {
    buffer[i++] = '-';
  }

  // 反转字符串
  while (i > 0) {
    str[j++] = buffer[--i];
  }
  str[j] = '\0';
}

// 辅助函数：输出字符串
static void put_str(const char *str) {
  while (*str) {
    putch(*str++);
  }
}

// 简化版 printf 实现
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
        put_str(buffer);
        count += strlen(buffer);
        break;
      }
      case 's': {
        const char *value = va_arg(args, const char *);
        put_str(value);
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
        // 不支持的格式符，直接输出
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
  return count; // 返回输出的字符数
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}
/*
static void itoa(int value, char *str) {
    char buffer[20];
    int i = 0, j = 0, is_negative = 0;

    // 处理负数
    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    // 生成数字字符
    do {
        buffer[i++] = (char)('0' + (value % 10));
        value /= 10;
    } while (value > 0);

    if (is_negative) {
        buffer[i++] = '-';
    }

    // 反转字符串
    while (i > 0) {
        str[j++] = buffer[--i];
    }
    str[j] = '\0';
}
*/
// 简化版 sprintf 实现
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
        // 不支持的格式符，直接输出
        *p++ = '%';
        *p++ = *f;
        break;
      }
    } else {
      *p++ = *f;
    }
    f++;
  }

  *p = '\0'; // 终止字符串
  va_end(args);
  return p - out; // 返回写入的字符数
}
int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
