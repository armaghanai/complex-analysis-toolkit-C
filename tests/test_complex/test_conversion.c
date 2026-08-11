#include <stdio.h>
#include <complex/complex_conversion.h>
#include "../test_helpers.h"
#include <complex/complex_constants.h>
#include <complex/complex_utils.h>

static void test_cartesian_from_polar(int *, int *);
static void test_polar_from_cartesian(int *, int *);

void test_conversion(int *total_pass, int *total_fail)
{
    printf("Testing complex conversion\n");
    int pass = 0, fail = 0;

    test_cartesian_from_polar(&pass,&fail);
    test_polar_from_cartesian(&pass,&fail);

    *total_pass += pass;
    *total_fail += fail;

    printf("\nTotal Tests: %d\n", pass + fail);
}

static void test_cartesian_from_polar(int *pass, int *fail)
{
    cvt_complex_polar z;
    cvt_complex result;

    z = create_complex_polar(1.0, 0.0);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, 1.0) &&
               is_nearly_equal(result.imaginary, 0.0),
           pass, fail);

    z = create_complex_polar(1.0, PI_BY_TWO);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, 0.0) &&
               is_nearly_equal(result.imaginary, 1.0),
           pass, fail);

    z = create_complex_polar(1.0, PI);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, -1.0) &&
               is_nearly_equal(result.imaginary, 0.0),
           pass, fail);

    z = create_complex_polar(1.0, -PI_BY_TWO);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, 0.0) &&
               is_nearly_equal(result.imaginary, -1.0),
           pass, fail);

    z = create_complex_polar(2.0, PI_BY_FOUR);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, sqrt(2.0)) &&
               is_nearly_equal(result.imaginary, sqrt(2.0)),
           pass, fail);

    z = create_complex_polar(0.0, PI_BY_FOUR);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, 0.0) &&
               is_nearly_equal(result.imaginary, 0.0),
           pass, fail);

    z = create_complex_polar(2.0, -PI_BY_FOUR);
    result = create_complex_from_polar(z);
    ASSERT(is_nearly_equal(result.real, sqrt(2.0)) &&
               is_nearly_equal(result.imaginary, -sqrt(2.0)),
           pass, fail);

    z = create_complex_polar(NAN, 0.0); 
    result = create_complex_from_polar(z); 
    ASSERT_F(!isnan(result.real) && !isnan(result.imaginary), pass, fail);
}

static void test_polar_from_cartesian(int *pass,int *fail)
{
    cvt_complex z;
    cvt_complex_polar result;

    z = create_complex(1.0, 0.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 1.0) &&
               is_nearly_equal(result.argument, 0.0),
           pass, fail);

    z = create_complex(0.0, 1.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 1.0) &&
               is_nearly_equal(result.argument, PI_BY_TWO),
           pass, fail);

    z = create_complex(-1.0, 0.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 1.0) &&
               is_nearly_equal(result.argument, PI),
           pass, fail);

    z = create_complex(0.0, -1.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 1.0) &&
               is_nearly_equal(result.argument, -PI_BY_TWO),
           pass, fail);

    z = create_complex(3.0, 4.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 5.0) &&
               is_nearly_equal(result.argument, atan2(4.0, 3.0)),
           pass, fail);

    z = create_complex(-3.0, 4.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 5.0) &&
               is_nearly_equal(result.argument, atan2(4.0, -3.0)),
           pass, fail);

    z = create_complex(-3.0, -4.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 5.0) &&
               is_nearly_equal(result.argument, atan2(-4.0, -3.0)),
           pass, fail);

    z = create_complex(3.0, -4.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 5.0) &&
               is_nearly_equal(result.argument, atan2(-4.0, 3.0)),
           pass, fail);

    z = create_complex(0.0, 0.0);
    result = create_complex_polar_from_cartesian(z);
    ASSERT(is_nearly_equal(result.modulus, 0.0), pass, fail);

    z = create_complex(NAN, 1.0); 
    result = create_complex_polar_from_cartesian(z); 
    ASSERT_F(!isnan(result.modulus), pass, fail);
}
