#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(expr, passed_ptr, failed_ptr) \
    ASSERT_EX(expr, passed_ptr, failed_ptr, 0)\

#define ASSERT_F(expr, passed_ptr, failed_ptr) \
    ASSERT_EX(expr, passed_ptr, failed_ptr, 1)  \

#define ASSERT_EX(expr, passed_ptr, failed_ptr, fail_flag) \
do { \
    if (expr) { \
        (*(passed_ptr))++; \
    } \
    else if (!(expr) && (fail_flag)) { \
        (*(passed_ptr))++; \
    } \
    else { \
        printf("  [FAIL] %s\n", #expr); \
        (*(failed_ptr))++; \
    } \
} while (0)

#endif