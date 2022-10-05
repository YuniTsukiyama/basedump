#include <err.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"

#include "atoi.h"

static void display_help(void)
{
    puts("Usage: basedump [OPTION]... INPUT\n"
         "Display input number in various bases.\n"
         "\n"
         "  -b [BASE]  give the input's base\n"
         "  -h         display this help");
}

int parse_options(int argc, char **argv, struct options *options)
{
    int c;

    while ((c = getopt(argc, argv, "b:h")) != -1)
    {
        switch (c)
        {
        case 'b':
            options->base = atoi_base(optarg, 10);
            break;
        case 'h':
            display_help();
            exit(0);
        case '?':
            display_help();
            return -1;
            break;
        default:
            abort();
        }
    }

    if (optind < argc)
        options->input = argv[optind];

    if (!options->input)
    {
        warnx("missing operand");
        display_help();
        return -1;
    }

    return 0;
}
