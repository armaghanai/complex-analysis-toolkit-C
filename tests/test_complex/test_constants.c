#include <stdio.h>
#include <complex/complex_constants.h>
#include "../test_helpers.h"
#include <complex/complex_utils.h>

static void test_math_constants(int*, int*);

void test_constants(int* total_pass, int* total_fail)
{
    printf("Testing Constants\n");

    int pass = 0,fail =0;

    test_math_constants(&pass, &fail);


    printf("\nTotal Tests: %d\n",pass+fail);
    *total_pass += pass;
    *total_fail += fail;

}

static void test_math_constants(int *pass, int *fail)
{
    ASSERT( is_nearly_equal(PI, 3.14159265358979323846),
    pass,fail);

    ASSERT(is_nearly_equal(EULER, 2.71828182845904523536),
    pass,fail);

    ASSERT(is_nearly_equal(MINUS_PI, -1.0*3.14159265358979323846),pass,fail);

    ASSERT(is_nearly_equal(TWO_PI, 2.0 * 3.14159265358979323846),
    pass,fail);

    ASSERT(is_nearly_equal(PI_BY_TWO, 3.14159265358979323846 / 2.0),
    pass,fail);

    ASSERT(is_nearly_equal(PI_BY_FOUR, 3.14159265358979323846 / 4.0),
    pass,fail);

    ASSERT(is_nearly_equal(COMPLEX_EPSILON, 1e-12),pass,fail);
}