#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define DIGITS "0123456789abcdef"

static void __attribute__((section(".klib"))) ltoa(long value, char *string, int radix)
{
    char tmp[20];
    char *tp = tmp;
    long i;
    unsigned long v;
    int sign;
    char *sp;

    if (string == NULL)
    {
        return;
    }

    sign = (radix == 10 && value < 0);
    if (sign)
    {
        v = -value;
    }
    else
    {
        v = (unsigned long)value;
    }

    while (v || tp == tmp)
    {
        i = v % radix;
        v = v / radix;
        *tp++ = DIGITS[i];
    }

    sp = string;

    if (sign)
        *sp++ = '-';
    while (tp > tmp)
        *sp++ = *--tp;
    *sp = '\0';
}

int __attribute__((section(".klib"))) vsnprintf(char *str, size_t n, const char *fmt, va_list ap)
{
    const char *f = fmt;
    int count = 0;

    while (*f != '\0' && count < n - 1)
    {
        if (*f == '%')
        {
            f++;
            int width = 0;
            int zero_pad = 0;

            if (*f >= '0' && *f <= '9')
            {
                zero_pad = (*f == '0');
                while (*f >= '0' && *f <= '9')
                {
                    width = width * 10 + (*f - '0');
                    f++;
                }
            }

            switch (*f)
            {
            case 'd':
            {
                int value = va_arg(ap, int);
                char buffer[20];
                ltoa(value, buffer, 10);
                int len = strlen(buffer);
                if (zero_pad && width > len)
                {
                    int pad_len = width - len;
                    if (pad_len > n - count - 1)
                    {
                        pad_len = n - count - 1;
                    }
                    while (pad_len-- > 0)
                    {
                        *str++ = '0';
                        count++;
                    }
                }
                if (len > n - count - 1)
                {
                    len = n - count - 1;
                }
                strncpy(str, buffer, len);
                str += len;
                count += len;
                break;
            }
            case 'l':
                f++;
                if (*f == 'd')
                {
                    long value = va_arg(ap, long);
                    char buffer[30];
                    ltoa(value, buffer, 10);
                    int len = strlen(buffer);
                    if (zero_pad && width > len)
                    {
                        int pad_len = width - len;
                        if (pad_len > n - count - 1)
                        {
                            pad_len = n - count - 1;
                        }
                        while (pad_len-- > 0)
                        {
                            *str++ = '0';
                            count++;
                        }
                    }
                    if (len > n - count - 1)
                    {
                        len = n - count - 1;
                    }
                    strncpy(str, buffer, len);
                    str += len;
                    count += len;
                    break;
                }
                *str++ = '%';
                *str++ = 'l';
                count += 2;
                break;
            case 'p':
            {
                zero_pad = 1;
                width = 8;
                strncpy(str, "0x", 2);
                str += 2;
                count += 2;
            }
            case 'x':
            case 'X':
            {
                unsigned int value = va_arg(ap, unsigned int);
                char buffer[20];
                ltoa(value, buffer, 16);
                int len = strlen(buffer);
                if (zero_pad && width > len)
                {
                    int pad_len = width - len;
                    if (pad_len > n - count - 1)
                    {
                        pad_len = n - count - 1;
                    }
                    while (pad_len-- > 0)
                    {
                        *str++ = '0';
                        count++;
                    }
                }
                if (len > n - count - 1)
                {
                    len = n - count - 1;
                }
                strncpy(str, buffer, len);
                str += len;
                count += len;
                break;
            }
            case 's':
            {
                const char *value = va_arg(ap, const char *);
                int len = strlen(value);
                if (len > n - count - 1)
                {
                    len = n - count - 1;
                }
                strncpy(str, value, len);
                str += len;
                count += len;
                break;
            }
            case 'c':
            {
                char value = (char)va_arg(ap, int);
                if (count < n - 1)
                {
                    *str++ = value;
                    count++;
                }
                break;
            }
            case '%':
            {
                if (count < n - 1)
                {
                    *str++ = '%';
                    count++;
                }
                break;
            }
            default:
                if (count < n - 2)
                {
                    *str++ = '%';
                    *str++ = *f;
                    count += 2;
                }
                break;
            }
        }
        else
        {
            if (count < n - 1)
            {
                *str++ = *f;
                count++;
            }
        }
        f++;
    }

    if (count < n)
    {
        *str = '\0';
    }
    else
    {
        str[n - 1] = '\0';
    }

    return count;
}

int __attribute__((section(".klib"))) vsprintf(char *str, const char *fmt, va_list ap)
{
    return vsnprintf(str, 128, fmt, ap);
}

int __attribute__((section(".klib"))) snprintf(char *str, size_t n, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(str, n, fmt, ap);
    va_end(ap);
    return result;
}

int __attribute__((section(".klib"))) sprintf(char *str, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int result = vsprintf(str, fmt, ap);
    va_end(ap);
    return result;
}

int __attribute__((section(".klib"))) printf(const char *fmt, ...)
{
    char buffer[512];
    va_list ap;
    va_start(ap, fmt);
    int result = vsnprintf(buffer, 512, fmt, ap);
    va_end(ap);
    putstr(buffer);
    return result;
}
#endif
