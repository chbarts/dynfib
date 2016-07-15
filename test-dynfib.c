#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "dynfib.h"

static int read_ulli(char *str, ulli * res)
{
    char *endptr = NULL;

    if (((*res = strtoull(str, &endptr, 0)) == 0) && (endptr == str)) {
        return -1;
    }

    if (ERANGE == errno) {
        if (ULLONG_MAX == *res) {
            return -2;
        } else {
            return -3;
        }
    }

    return 0;
}

#define get_ulli(str, num) do { switch (read_ulli(str, &num)) {     \
case 0: goto num ## goodend; \
case -1: fprintf(stderr, "%s: %s invalid input\n", argv[0], str); goto num ## end; \
case -2: fprintf(stderr, "%s: %s is bigger than positive infinity\n", argv[0], str); goto num ## end; \
default: fprintf(stderr, "%s: %s is bigger than Jesus\n", argv[0], str); goto num ## end; \
      } } while (0); num ## end: continue; num ## goodend:

int main(int argc, char *argv[])
{
    int i;
    ulli val, res;

    if (1 == argc) {
        puts("usage: test-dynfib [int...]");
        return 0;
    }

    for (i = 1; i < argc; i++) {
        get_ulli(argv[i], val);
        res = dynfib(val);
        printf("%llu %llu\n", val, res);
    }

    return 0;
}
