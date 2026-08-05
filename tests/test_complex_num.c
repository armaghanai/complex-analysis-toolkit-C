#include "test_helpers.h"
#include <math.h>
#include <stdio.h>
#include <complex/complex_num.h>
#include <complex/complex_constants.h>

void test_creation();
void test_equality();

void test_complex_num(void)
{
    printf("Testing Complex Numbers\n");
    //creation
    test_creation();
    test_equality();

    //parsing
    printf("Complex Numbers Passed\n\n");
}

void test_creation()
{
    cvt_complex z = create_complex(3.0, 4.0);

    ASSERT(z.real == 3.0);
    ASSERT(z.imaginary == 4.0);

}

void test_equality()
{
    ASSERT(complex_equals(
    create_complex(1,2),
    create_complex(1,2)));

    ASSERT(!complex_equals(
    create_complex(1,2),
    create_complex(2,1)));

    ASSERT(complex_equals(
    COMPLEX_ZERO,
    create_complex(0,0)));

    /*ASSERT(complex_equals(
    COMPLEX_NAN,
    create_complex(NAN,NAN)));*/

    ASSERT(complex_equals(
    COMPLEX_INFINITY,
    create_complex(INFINITY,INFINITY)));
}

