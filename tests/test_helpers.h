#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(expr)                           \
do {                                           \
    if (!(expr)) {                             \
        printf("FAILED: %s\n", #expr);         \
        exit(EXIT_FAILURE);                    \
    }                                          \
} while (0)

#endif