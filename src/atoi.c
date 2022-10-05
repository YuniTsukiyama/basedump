#include <err.h>

#include "atoi.h"

#define ARRAY_SIZE(arr) ((int)(sizeof(arr) / sizeof(*arr)))

static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static int my_pow(int lhs, int rhs)
{
    int res = 1;

    while (rhs--) { res *= lhs; }

    return res;
}

static int find_digit(char c, int base)
{
    char *p = digits;

    while (*p)
    {
        if (c == *p)
        {
            int pos = (p - digits);
            if (pos >= base)
                return -1;
            return pos;
        }
        ++p;
    }

    return -1;
}

size_t atoi_base(char *s, int base)
{
    if (base > ARRAY_SIZE(digits))
        errx(-1, "base must be between 1 and %d", ARRAY_SIZE(digits));

    size_t res = 0;
    char *end = s;
    while (*end) { ++end; }
    --end;

    while (*s)
    {
        int digit_pos = find_digit(*s, base) * my_pow(base, (end - s));

        if (digit_pos < 0)
            errx(-1, "invalid character `%c', valid characters are: `%.*s'",
                    *s, base, digits);

        res += digit_pos;
        ++s;
    }

    return res;
}
