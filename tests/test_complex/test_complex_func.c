#include <stdio.h>
#include <complex/complex_func.h>
#include "../test_helpers.h"
#include <stdio.h>
#include <complex/complex_constants.h>
#include <complex/complex_utils.h>

static void test_complex_exp(int*, int*);
static void test_complex_log(int *, int *);
static void test_complex_power(int *, int *);
static void test_complex_sin(int *, int *);
static void test_complex_cos(int *, int *);
static void test_complex_tan(int *, int *);
static void test_complex_cot(int *, int *);
static void test_complex_sec(int *, int *);
static void test_complex_cosec(int *, int *);
static void test_complex_sinh(int *, int *);
static void test_complex_cosh(int *, int *);
static void test_complex_tanh(int *, int *);
static void test_complex_coth(int *, int *);
static void test_complex_sech(int *, int *);
static void test_complex_cosech(int *, int *);

void test_complex_func(int* total_pass, int* total_fail)
{
    int pass = 0, fail = 0;
    printf("Testing complex_func\n");

    test_complex_exp(&pass,&fail);
    test_complex_log(&pass,&fail);
    test_complex_power(&pass,&fail);

    test_complex_sin(&pass,&fail);
    test_complex_cos(&pass,&fail);
    test_complex_tan(&pass,&fail);
    test_complex_cot(&pass,&fail);
    test_complex_sec(&pass,&fail);
    test_complex_cosec(&pass,&fail);

    test_complex_sinh(&pass,&fail);
    test_complex_cosh(&pass,&fail);
    test_complex_tanh(&pass,&fail);
    test_complex_coth(&pass,&fail);
    test_complex_sech(&pass,&fail);
    test_complex_cosech(&pass,&fail);

    printf("\nTotal Tests: %d\n",pass+fail);
    *total_pass += pass;
    *total_fail += fail;
}

static void test_complex_exp(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_exp(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(1, 0);
    result = complex_exp(z);
    ASSERT(is_nearly_equal(result.real, EULER) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI);
    result = complex_exp(z);
    ASSERT(is_nearly_equal(result.real, -1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI_BY_TWO);
    result = complex_exp(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 1), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_exp(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_log(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_principal_log(z);
    ASSERT(isinf(result.real) && result.real < 0 && isnan(result.imaginary), pass, fail);

    z = create_complex(1, 0);
    result = complex_principal_log(z);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(EULER, 0);
    result = complex_principal_log(z);
    ASSERT(is_nearly_equal(result.real, 1) && is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_principal_log(z);
    ASSERT(is_nearly_equal(result.real, 0) && is_nearly_equal(result.imaginary, PI_BY_TWO), pass, fail);

    z = create_complex(-1, 0);
    result = complex_principal_log(z);
    ASSERT(is_nearly_equal(result.real, 0) && is_nearly_equal(result.imaginary, PI), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_principal_log(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_power(int *pass, int *fail)
{
    cvt_complex z, p, result;

    z = create_complex(2, 0);
    p = create_complex(2, 0);
    result = complex_power(z, p);
    ASSERT(complex_equals(result, create_complex(4, 0)), pass, fail);

    z = create_complex(2, 0);
    p = create_complex(0, 0);
    result = complex_power(z, p);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(0, 0);
    p = create_complex(2, 0);
    result = complex_power(z, p);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(0, 0);
    p = create_complex(0, 0);
    result = complex_power(z, p);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_sin(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_sin(z);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(PI_BY_TWO, 0);
    result = complex_sin(z);
    ASSERT(is_nearly_equal(result.real, 1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(PI, 0);
    result = complex_sin(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_sin(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, sinh(1)), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_sin(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_cos(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_cos(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(PI_BY_TWO, 0);
    result = complex_cos(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(PI, 0);
    result = complex_cos(z);
    ASSERT(is_nearly_equal(result.real, -1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_cos(z);
    ASSERT(is_nearly_equal(result.real, cosh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_cos(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_tan(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_tan(z);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(PI_BY_FOUR, 0);
    result = complex_tan(z);
    ASSERT(is_nearly_equal(result.real, 1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_tan(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, tanh(1)), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_tan(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_cot(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(PI_BY_TWO, 0);
    result = complex_cot(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(PI_BY_FOUR, 0);
    result = complex_cot(z);
    ASSERT(is_nearly_equal(result.real, 1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_cot(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
       is_nearly_equal(result.imaginary, -1.0 / tanh(1)), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_cot(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_sec(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_sec(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(PI, 0);
    result = complex_sec(z);
    ASSERT(is_nearly_equal(result.real, -1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, 1);
    result = complex_sec(z);
    ASSERT(is_nearly_equal(result.real, 1.0 / cosh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_sec(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_cosec(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(PI_BY_TWO, 0);
    result = complex_cosec(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(PI, 0);
    result = complex_cosec(z);
    ASSERT_F(isinf(result.real) || isnan(result.real), pass, fail);

    z = create_complex(0, 1);
    result = complex_cosec(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, -1.0 / sinh(1)), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_cosec(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_sinh(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_sinh(z);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(1, 0);
    result = complex_sinh(z);
    ASSERT(is_nearly_equal(result.real, sinh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI_BY_TWO);
    result = complex_sinh(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 1), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_sinh(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_cosh(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_cosh(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(1, 0);
    result = complex_cosh(z);
    ASSERT(is_nearly_equal(result.real, cosh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI);
    result = complex_cosh(z);
    ASSERT(is_nearly_equal(result.real, -1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_cosh(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_tanh(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_tanh(z);
    ASSERT(complex_equals(result, COMPLEX_ZERO), pass, fail);

    z = create_complex(1, 0);
    result = complex_tanh(z);
    ASSERT(is_nearly_equal(result.real, tanh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI_BY_FOUR);
    result = complex_tanh(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, 1), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_tanh(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_coth(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(1, 0);
    result = complex_coth(z);
    ASSERT(is_nearly_equal(result.real, 1.0 / tanh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);
    
    z = create_complex(0, PI_BY_FOUR);
    result = complex_coth(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, -1), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_coth(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_sech(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(0, 0);
    result = complex_sech(z);
    ASSERT(complex_equals(result, COMPLEX_ONE), pass, fail);

    z = create_complex(1, 0);
    result = complex_sech(z);
    ASSERT(is_nearly_equal(result.real, 1.0 / cosh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI);
    result = complex_sech(z);
    ASSERT(is_nearly_equal(result.real, -1) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_sech(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

static void test_complex_cosech(int *pass, int *fail)
{
    cvt_complex z, result;

    z = create_complex(1, 0);
    result = complex_cosech(z);
    ASSERT(is_nearly_equal(result.real, 1.0 / sinh(1)) &&
           is_nearly_equal(result.imaginary, 0), pass, fail);

    z = create_complex(0, PI_BY_TWO);
    result = complex_cosech(z);
    ASSERT(is_nearly_equal(result.real, 0) &&
           is_nearly_equal(result.imaginary, -1), pass, fail);

    z = create_complex(NAN, 1);
    result = complex_cosech(z);
    ASSERT_F(isnan(result.real) && isnan(result.imaginary), pass, fail);
}

