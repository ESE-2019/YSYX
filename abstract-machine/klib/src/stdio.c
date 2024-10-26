#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char __attribute__((section(".klib"))) *ltoa(long value, char *string, int radix) {
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

static char __attribute__((section(".klib"))) *itoa(int value, char *string, int radix) {
    return ltoa((long)value, string, radix);
}

int __attribute__((section(".klib"))) vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    const char *f = fmt;
    int count = 0;

    while (*f != '\0' && count < n - 1) {
        if (*f == '%') {
            f++;
            int width = 0;
            int zero_pad = 0;

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
                    int pad_len = width - len;
                    if (pad_len > n - count - 1) {
                        pad_len = n - count - 1;
                    }
                    while (pad_len-- > 0) {
                        *out++ = '0';
                        count++;
                    }
                }
                if (len > n - count - 1) {
                    len = n - count - 1;
                }
                strncpy(out, buffer, len);
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
                        int pad_len = width - len;
                        if (pad_len > n - count - 1) {
                            pad_len = n - count - 1;
                        }
                        while (pad_len-- > 0) {
                            *out++ = '0';
                            count++;
                        }
                    }
                    if (len > n - count - 1) {
                        len = n - count - 1;
                    }
                    strncpy(out, buffer, len);
                    out += len;
                    count += len;
                    break;
                }
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
                    int pad_len = width - len;
                    if (pad_len > n - count - 1) {
                        pad_len = n - count - 1;
                    }
                    while (pad_len-- > 0) {
                        *out++ = '0';
                        count++;
                    }
                }
                if (len > n - count - 1) {
                    len = n - count - 1;
                }
                strncpy(out, buffer, len);
                out += len;
                count += len;
                break;
            }
            case 's': {
                const char *value = va_arg(ap, const char *);
                int len = strlen(value);
                if (len > n - count - 1) {
                    len = n - count - 1;
                }
                strncpy(out, value, len);
                out += len;
                count += len;
                break;
            }
            case 'c': {
                char value = (char)va_arg(ap, int);
                if (count < n - 1) {
                    *out++ = value;
                    count++;
                }
                break;
            }
            case '%': {
                if (count < n - 1) {
                    *out++ = '%';
                    count++;
                }
                break;
            }
            default:
                if (count < n - 2) {
                    *out++ = '%';
                    *out++ = *f;
                    count += 2;
                }
                break;
            }
        } else {
            if (count < n - 1) {
                *out++ = *f;
                count++;
            }
        }
        f++;
    }

    if (count < n) {
        *out = '\0';
    } else {
        out[n-1] = '\0';
    }

    return count;
}


int __attribute__((section(".klib"))) vsprintf(char *out, const char *fmt, va_list ap) {
    return vsnprintf(out, 512, fmt, ap);
}

int __attribute__((section(".klib"))) snprintf(char *out, size_t n, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(out, n, fmt, ap);
    va_end(ap);
    return result;
}

int __attribute__((section(".klib"))) sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vsprintf(out, fmt, ap);
    va_end(ap);
    return result;
}

int __attribute__((section(".klib"))) printf(const char *fmt, ...) {
    char buffer[256];
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(buffer, 256, fmt, ap);
    va_end(ap);
    putstr(buffer);
    return result;
}
#endif
