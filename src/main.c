#include <stdio.h>

#include "options.h"

#include "atoi.h"

#define DEFAULT_BASE 10
#define BYTE_SIZE    8

static void print_binary(size_t x)
{
    size_t bit_size = 0;
    size_t current_pow = 1;

    while (((size_t)1 << bit_size) <= x)
    {
        current_pow <<= 1;
        ++bit_size;
    }

    // Round up to byte size
    bit_size = (bit_size + BYTE_SIZE - 1) & ~(BYTE_SIZE - 1);
    if (!bit_size)
        bit_size = BYTE_SIZE;

    while (bit_size-- > 0)
    {
        size_t n = (1 << bit_size);
        if (n <= x)
        {
            putchar('1');
            x -= n;
        }
        else
            putchar('0');

        if ((!(bit_size % BYTE_SIZE)) && bit_size)
            putchar('.');
    }

    putchar('\n');
}

int main(int argc, char **argv)
{
    // Parse options
    struct options options = { .base = DEFAULT_BASE, .input = NULL };
    if (parse_options(argc, argv, &options))
        return -1;

    // Display in various bases
    size_t num = atoi_base(options.input, options.base);
    fputs("Binary:      ", stdout);
    print_binary(num);
    printf("Decimal:     %ld\n", num);
    printf("Octal:       %lo\n", num);
    printf("Hexadecimal: %lX\n", num);

    return 0;
}
