#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char *ltoa(long value, char *string, int radix) {
    char tmp[33];
    char *tp = tmp;
    long i;
    unsigned long v;
    int sign;
    char *sp;

    if (string == NULL) {
        return NULL;
    }

    if (radix > 36 || radix <= 1) {
        return NULL;
    }

    sign = (radix == 10 && value < 0);
    if (sign) {
        v = -value;
    } else {
        v = (unsigned long)value;
    }

    while (v || tp == tmp) {
        i = v % radix;
        v = v / radix;
        if (i < 10)
            *tp++ = (char)(i + '0');
        else
            *tp++ = (char)(i + 'a' - 10);
    }

    sp = string;

    if (sign)
        *sp++ = '-';
    while (tp > tmp)
        *sp++ = *--tp;
    *sp = 0;

    return string;
}

static char *itoa(int value, char *string, int radix) {
    return ltoa((long)value, string, radix);
}
/*
static char *ultoa(unsigned long value, char *string, int radix) {
    char tmp[33];
    char *tp = tmp;
    long i;
    unsigned long v = value;
    char *sp;

    if (string == NULL) {
        return NULL;
    }

    if (radix > 36 || radix <= 1) {
        return NULL;
    }

    while (v || tp == tmp) {
        i = v % radix;
        v = v / radix;
        if (i < 10)
            *tp++ = (char)(i + '0');
        else
            *tp++ = (char)(i + 'a' - 10);
    }

    sp = string;

    while (tp > tmp)
        *sp++ = *--tp;
    *sp = 0;

    return string;
}

static char *utoa(unsigned value, char *string, int radix) {
    return ultoa((unsigned long)value, string, radix);
}*/

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    //char *out_start = out;
    const char *f = fmt;
    int count = 0;

    while (*f != '\0' && count < n - 1) {
        if (*f == '%') {
            f++;
            int width = 0;
            int zero_pad = 0;

            // 处理宽度说明符，如 %08x
            if (*f >= '0' && *f <= '9') {
                zero_pad = (*f == '0');
                while (*f >= '0' && *f <= '9') {
                    width = width * 10 + (*f - '0');
                    f++;
                }
            }

            switch (*f) {
            case 'd': {
                int value = va_arg(ap, int);
                char buffer[20];
                itoa(value, buffer, 10);
                int len = strlen(buffer);
                if (zero_pad && width > len) {
                    while (len < width && count < n - 1) {
                        *out++ = '0';
                        len++;
                        count++;
                    }
                }
                strncpy(out, buffer, n - count - 1);
                out += len;
                count += len;
                break;
            }
            case 'l':
                f++;
                if (*f == 'd') {
                    long value = va_arg(ap, long);
                    char buffer[30];
                    ltoa(value, buffer, 10);
                    int len = strlen(buffer);
                    if (zero_pad && width > len) {
                        while (len < width && count < n - 1) {
                            *out++ = '0';
                            len++;
                            count++;
                        }
                    }
                    strncpy(out, buffer, n - count - 1);
                    out += len;
                    count += len;
                    break;
                }
                // 如果 'l' 后面不是 'd'，则视为无效格式
                *out++ = '%';
                *out++ = 'l';
                count += 2;
                break;
            case 'x':
            case 'X': {
                unsigned int value = va_arg(ap, unsigned int);
                char buffer[20];
                itoa(value, buffer, 16);
                int len = strlen(buffer);
                if (zero_pad && width > len) {
                    while (len < width && count < n - 1) {
                        *out++ = '0';
                        len++;
                        count++;
                    }
                }
                strncpy(out, buffer, n - count - 1);
                out += len;
                count += len;
                break;
            }
            case '0':
                if (*(f + 1) >= '0' && *(f + 1) <= '9') {
                    f++;
                    width = 0;
                    while (*f >= '0' && *f <= '9') {
                        width = width * 10 + (*f - '0');
                        f++;
                    }
                    zero_pad = 1;
                    f--;
                } else {
                    *out++ = '%';
                    *out++ = '0';
                    count += 2;
                }
                break;
            case 's': {
                const char *value = va_arg(ap, const char *);
                int len = strlen(value);
                strncpy(out, value, n - count - 1);
                out += len;
                count += len;
                break;
            }
            case 'c': {
                char value = (char)va_arg(ap, int);
                *out++ = value;
                count++;
                break;
            }
            case '%': {
                *out++ = '%';
                count++;
                break;
            }
            default:
                *out++ = '%';
                *out++ = *f;
                count += 2;
                break;
            }
        } else {
            *out++ = *f;
            count++;
        }
        f++;
    }

    *out = '\0';
    return count;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    return vsnprintf(out, 512, fmt, ap);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(out, n, fmt, ap);
    va_end(ap);
    return result;
}

int sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vsprintf(out, fmt, ap);
    va_end(ap);
    return result;
}

int printf(const char *fmt, ...) {
    char buffer[512];
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(buffer, sizeof(buffer), fmt, ap);
    va_end(ap);
    putstr(buffer);
    return result;
}
#endif
