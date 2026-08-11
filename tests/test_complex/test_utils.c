#include <stdio.h>
#include "../test_helpers.h"
#include <complex/complex_utils.h>
#include <complex/complex_constants.h>

static void test_is_zero(int*, int*);
static void test_multiply_argument(int* ,int* );
static void test_is_nearly_equal(int*, int*);
static void test_convert_to_principal_argument(int*, int*);

void test_utils(int *total_pass, int *total_fail)
{
    printf("Testing Complex Utilities\n");
    int pass = 0, fail = 0;

    test_is_zero(&pass, &fail);
    test_is_nearly_equal(&pass, &fail);
    test_convert_to_principal_argument(&pass, &fail);
    test_multiply_argument(&pass,&fail);

    *total_pass += pass;
    *total_fail += fail;

    printf("\nTotal tests: %d\n", pass + fail);
}

static void test_is_zero(int *pass, int *fail)
{
    ASSERT(is_zero(0.0), pass, fail);
    ASSERT(is_zero(1e-13), pass, fail);
    ASSERT(!is_zero(1.0), pass, fail);
    ASSERT(!is_zero(-1.0), pass, fail);
    ASSERT_F(is_zero(1e-10), pass, fail);
}

static void test_convert_to_principal_argument(int *pass, int *fail)
{
    ASSERT(is_nearly_equal(convert_to_principal_argument(0.0), 0.0),
    pass, fail);

    ASSERT(is_nearly_equal(convert_to_principal_argument(PI), PI),
    pass, fail);

    ASSERT(is_nearly_equal(convert_to_principal_argument(-PI), PI),
    pass, fail);

    ASSERT(is_nearly_equal(convert_to_principal_argument(TWO_PI), 0.0),
    pass, fail);

    ASSERT(is_nearly_equal(convert_to_principal_argument(3.0 * PI), PI),
    pass, fail);

    ASSERT(is_nearly_equal(convert_to_principal_argument(-3.0 * PI), PI),
    pass, fail);

    ASSERT_F(convert_to_principal_argument(PI + 0.5) > PI,pass,fail);
}

static void test_multiply_argument(int *pass, int *fail)
{
    ASSERT(is_nearly_equal(multiply_argument(PI_BY_TWO, 1), PI_BY_TWO),
    pass, fail);

    ASSERT(is_nearly_equal(multiply_argument(PI_BY_TWO, 0), 0.0),
    pass, fail);

    ASSERT(is_nearly_equal(multiply_argument(PI_BY_TWO, 2), PI),
    pass, fail);

    ASSERT(is_nearly_equal(multiply_argument(PI, 2), 0.0),pass, fail);

    ASSERT(is_nearly_equal(multiply_argument(PI_BY_TWO, -1), -PI_BY_TWO),
    pass, fail);

    ASSERT_F(multiply_argument(PI_BY_TWO, 2) > PI,pass,fail);
}

static void test_is_nearly_equal(int *pass, int *fail)
{
    ASSERT(is_nearly_equal(1.0, 1.0), pass, fail);
    ASSERT(is_nearly_equal(1.0, 1.0 + 1e-13), pass, fail);
    ASSERT(!is_nearly_equal(1.0, 1.0 + 1e-10), pass, fail);
    ASSERT(!is_nearly_equal(NAN, 1.0), pass, fail);
    ASSERT(!is_nearly_equal(1.0, NAN), pass, fail);
    ASSERT(is_nearly_equal(INFINITY, INFINITY), pass, fail);
    ASSERT(is_nearly_equal(-INFINITY, -INFINITY), pass, fail);

    ASSERT_F(is_nearly_equal(NAN, NAN),pass,fail);
}

