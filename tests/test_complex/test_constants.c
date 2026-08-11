#include <stdio.h>
#include <complex/complex_constants.h>
#include "../test_helpers.h"
#include <complex/complex_utils.h>
#include <complex/complex_num.h>
#include <complex/complex_polar.h>

static void test_math_constants(int*, int*);
static void test_cartesian_constants(int*, int*);
static void test_polar_constants(int*, int*);

void test_constants(int* total_pass, int* total_fail)
{
    printf("Testing Constants\n");

    int pass = 0,fail =0;

    test_math_constants(&pass, &fail);
    test_cartesian_constants(&pass, &fail);
    test_polar_constants(&pass, &fail);


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

static void test_cartesian_constants(int *pass, int *fail)
{
    ASSERT(is_nearly_equal(COMPLEX_ZERO.real, 0.0) &&
    is_nearly_equal(COMPLEX_ZERO.imaginary, 0.0),pass,fail);

    ASSERT(is_nearly_equal(COMPLEX_ONE.real, 1.0) &&
    is_nearly_equal(COMPLEX_ONE.imaginary, 0.0),pass,fail);

    ASSERT(is_nearly_equal(COMPLEX_I.real, 0.0) &&
    is_nearly_equal(COMPLEX_I.imaginary, 1.0),pass,fail);

    ASSERT(isnan(COMPLEX_NAN.real) &&isnan(COMPLEX_NAN.imaginary),
    pass,fail);

    ASSERT(isinf(COMPLEX_INFINITY.real) &&isinf(COMPLEX_INFINITY.imaginary),
    pass,fail);

    ASSERT_F(complex_equals(create_complex(NAN,NAN),COMPLEX_NAN),pass,fail);
}

static void test_polar_constants(int *pass, int *fail)
{
    ASSERT(is_nearly_equal(COMPLEX_ZERO_POLAR.modulus, 0.0) &&
    is_nearly_equal(COMPLEX_ZERO_POLAR.argument, 0.0),pass,fail);

    ASSERT(is_nearly_equal(COMPLEX_ONE_POLAR.modulus, 1.0) &&
    is_nearly_equal(COMPLEX_ONE_POLAR.argument, 0.0),pass,fail);

    ASSERT(is_nearly_equal(COMPLEX_I_POLAR.modulus, 1.0) &&
    is_nearly_equal(COMPLEX_I_POLAR.argument, PI_BY_TWO),pass,fail);

    ASSERT(isnan(COMPLEX_NAN_POLAR.modulus) &&isnan(COMPLEX_NAN_POLAR.argument),
    pass,fail);

    ASSERT(isinf(COMPLEX_INFINITY_POLAR.modulus) &&isnan(
    COMPLEX_INFINITY_POLAR.argument),pass,fail);

    ASSERT_F(complex_polar_equals(create_complex_polar(NAN,NAN),COMPLEX_NAN_POLAR)
    ,pass,fail);
}