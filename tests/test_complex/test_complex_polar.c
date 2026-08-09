#include "../test_helpers.h"
#include <stdio.h>
#include <complex/complex_polar.h>
#include <complex/complex_constants.h>
#include <complex/complex_utils.h>

static void test_polar_creation(int*, int*);
static void test_polar_equality(int*, int*);
static void test_polar_string_parsing(int*, int*);
static void test_polar_square(int*, int*);
static void test_polar_multiply(int*, int*);
static void test_polar_divide(int*, int*);
static void test_polar_conjugate(int*, int*);
static void test_polar_power(int*, int*);
static void test_polar_roots(int*, int*);
static void display_create_complex_polar(double, double, int*, int*);
static void test_display_polar(int*, int*);

void test_complex_polar(int* total_pass, int* total_fail)
{
    int pass = 0, fail = 0;
    printf("Testing Complex Polar Numbers\n");

    test_polar_creation(&pass,&fail);
    test_polar_equality(&pass, &fail);
    test_polar_string_parsing(&pass, &fail);
    test_polar_square(&pass, &fail);
    test_polar_multiply(&pass, &fail);
    test_polar_divide(&pass, &fail);
    test_polar_conjugate(&pass, &fail);
    test_polar_power(&pass, &fail);
    test_polar_roots(&pass, &fail);
    test_display_polar(&pass, &fail);

    printf("\nTotal Tests: %d\n",pass+fail);
    *total_pass += pass;
    *total_fail += fail;

}

static void test_polar_creation(int *pass, int *fail)
{
    cvt_complex_polar z =
        create_complex_polar(5.0, PI_BY_FOUR);

    ASSERT(
        is_nearly_equal(z.modulus, 5.0) &&
        is_nearly_equal(z.argument, PI_BY_FOUR),
        pass,
        fail
    );

    /* Zero */

    z = create_complex_polar(0.0, 0.0);

    ASSERT(
        is_nearly_equal(z.modulus, 0.0) &&
        is_nearly_equal(z.argument, 0.0),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_polar_equals                                      */
/* --------------------------------------------------------- */

static void test_polar_equality(int *pass, int *fail)
{
    cvt_complex_polar z1 =
        create_complex_polar(5.0, PI_BY_FOUR);

    cvt_complex_polar z2 =
        create_complex_polar(5.0, PI_BY_FOUR);

    cvt_complex_polar z3 =
        create_complex_polar(3.0, PI_BY_FOUR);

    cvt_complex_polar z4 =
        create_complex_polar(5.0, -7.0 * PI_BY_FOUR);


    /* Same polar number */

    ASSERT(
        complex_polar_equals(z1, z2),
        pass,
        fail
    );


    /* Different modulus */

    ASSERT_F(
        complex_polar_equals(z1, z3),
        pass,
        fail
    );


    /*
     * Angles differing by 2π should represent
     * the same complex number.
     */

    ASSERT(
        complex_polar_equals(z1, z4),
        pass,
        fail
    );


    /* Constants */

    ASSERT(
        complex_polar_equals(
            COMPLEX_ZERO_POLAR,
            create_complex_polar(0.0, 0.0)
        ),
        pass,
        fail
    );

    ASSERT(
        complex_polar_equals(
            COMPLEX_ONE_POLAR,
            create_complex_polar(1.0, 2.0 * PI)
        ),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* create_complex_polar_from_string                          */
/* --------------------------------------------------------- */

static void test_polar_string_parsing(int *pass, int *fail)
{
    cvt_complex_polar z;


    /* rexp(itheta) */

    z = create_complex_polar_from_string(
        "5exp(i3.141592653589793)"
    );

    ASSERT(
        is_nearly_equal(z.modulus, 5.0) &&
        is_nearly_equal(z.argument, PI),
        pass,
        fail
    );


    /* rexp(thetai) */

    z = create_complex_polar_from_string(
        "5exp(3.141592653589793i)"
    );

    ASSERT(
        is_nearly_equal(z.modulus, 5.0) &&
        is_nearly_equal(z.argument, PI),
        pass,
        fail
    );


    /* Another valid value */

    z = create_complex_polar_from_string(
        "2exp(i1.5707963267948966)"
    );

    ASSERT(
        is_nearly_equal(z.modulus, 2.0) &&
        is_nearly_equal(z.argument, PI_BY_TWO),
        pass,
        fail
    );


    /*
     * Invalid strings should produce NAN polar.
     */

    z = create_complex_polar_from_string("hello");

    ASSERT(
        isnan(z.modulus) &&
        isnan(z.argument),
        pass,
        fail
    );


    z = create_complex_polar_from_string("");

    ASSERT(
        isnan(z.modulus) &&
        isnan(z.argument),
        pass,
        fail
    );


    z = create_complex_polar_from_string(NULL);

    ASSERT(
        isnan(z.modulus) &&
        isnan(z.argument),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_square                                            */
/* --------------------------------------------------------- */

static void test_polar_square(int *pass, int *fail)
{
    cvt_complex_polar z =
        create_complex_polar(2.0, PI_BY_FOUR);

    cvt_complex_polar result =
        complex_square(z);


    /*
     * (2e^(iπ/4))²
     *
     * = 4e^(iπ/2)
     */

    ASSERT(
        is_nearly_equal(result.modulus, 4.0) &&
        is_nearly_equal(
            convert_to_principal_argument(result.argument),
            PI_BY_TWO
        ),
        pass,
        fail
    );


    /* Square of ONE */

    result = complex_square(COMPLEX_ONE_POLAR);

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ONE_POLAR
        ),
        pass,
        fail
    );


    /* Square of ZERO */

    result = complex_square(COMPLEX_ZERO_POLAR);

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ZERO_POLAR
        ),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_polar_multiply                                    */
/* --------------------------------------------------------- */

static void test_polar_multiply(int *pass, int *fail)
{
    cvt_complex_polar z1 =
        create_complex_polar(2.0, PI_BY_FOUR);

    cvt_complex_polar z2 =
        create_complex_polar(3.0, PI_BY_FOUR);

    cvt_complex_polar result =
        complex_polar_multiply(z1, z2);


    /*
     * 2e^(iπ/4) × 3e^(iπ/4)
     *
     * = 6e^(iπ/2)
     */

    ASSERT(
        is_nearly_equal(result.modulus, 6.0) &&
        is_nearly_equal(
            convert_to_principal_argument(result.argument),
            PI_BY_TWO
        ),
        pass,
        fail
    );


    /* Multiplication by ONE */

    result =
        complex_polar_multiply(
            z1,
            COMPLEX_ONE_POLAR
        );

    ASSERT(
        complex_polar_equals(result, z1),
        pass,
        fail
    );


    /* Multiplication by ZERO */

    result =
        complex_polar_multiply(
            z1,
            COMPLEX_ZERO_POLAR
        );

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ZERO_POLAR
        ),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_polar_divide                                      */
/* --------------------------------------------------------- */

static void test_polar_divide(int *pass, int *fail)
{
    cvt_complex_polar z1 =
        create_complex_polar(6.0, PI_BY_TWO);

    cvt_complex_polar z2 =
        create_complex_polar(3.0, PI_BY_FOUR);

    cvt_complex_polar result =
        complex_polar_divide(z1, z2);


    /*
     * 6e^(iπ/2) / 3e^(iπ/4)
     *
     * = 2e^(iπ/4)
     */

    ASSERT(
        is_nearly_equal(result.modulus, 2.0) &&
        is_nearly_equal(
            convert_to_principal_argument(result.argument),
            PI_BY_FOUR
        ),
        pass,
        fail
    );


    /* Division by ONE */

    result =
        complex_polar_divide(
            z1,
            COMPLEX_ONE_POLAR
        );

    ASSERT(
        complex_polar_equals(result, z1),
        pass,
        fail
    );


    /* ZERO divided by non-zero */

    result =
        complex_polar_divide(
            COMPLEX_ZERO_POLAR,
            z1
        );

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ZERO_POLAR
        ),
        pass,
        fail
    );


    /*
     * Division by ZERO.
     *
     * Expected result depends on your implementation.
     */

    result =
        complex_polar_divide(
            z1,
            COMPLEX_ZERO_POLAR
        );

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_INFINITY_POLAR
        ),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_polar_conjugate                                   */
/* --------------------------------------------------------- */

static void test_polar_conjugate(int *pass, int *fail)
{
    cvt_complex_polar z =
        create_complex_polar(5.0, PI_BY_FOUR);

    cvt_complex_polar result =
        complex_polar_conjugate(z);


    /*
     * 5e^(iπ/4)
     *
     * conjugate
     *
     * = 5e^(-iπ/4)
     */

    ASSERT(
        is_nearly_equal(result.modulus, 5.0) &&
        is_nearly_equal(result.argument, -PI_BY_FOUR),
        pass,
        fail
    );


    /* Conjugate of ONE */

    result =
        complex_polar_conjugate(
            COMPLEX_ONE_POLAR
        );

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ONE_POLAR
        ),
        pass,
        fail
    );
}


/* --------------------------------------------------------- */
/* complex_power                                             */
/* --------------------------------------------------------- */

static void test_polar_power(int *pass, int *fail)
{
    cvt_complex_polar z =
        create_complex_polar(2.0, PI_BY_FOUR);

    cvt_complex_polar result;


    /* z^0 = 1 */

    result = complex_power(z, 0);

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ONE_POLAR
        ),
        pass,
        fail
    );


    /* z^1 = z */

    result = complex_power(z, 1);

    ASSERT(
        complex_polar_equals(result, z),
        pass,
        fail
    );


    /*
     * (2e^(iπ/4))³
     *
     * = 8e^(i3π/4)
     */

    result = complex_power(z, 3);

    ASSERT(
        is_nearly_equal(result.modulus, 8.0) &&
        is_nearly_equal(
            convert_to_principal_argument(result.argument),
            3.0 * PI_BY_FOUR
        ),
        pass,
        fail
    );


    /* z^2 */

    result = complex_power(z, 2);

    ASSERT(
        is_nearly_equal(result.modulus, 4.0) &&
        is_nearly_equal(
            convert_to_principal_argument(result.argument),
            PI_BY_TWO
        ),
        pass,
        fail
    );


    /*
     * ZERO^positive = ZERO
     */

    result =
        complex_power(
            COMPLEX_ZERO_POLAR,
            3
        );

    ASSERT(
        complex_polar_equals(
            result,
            COMPLEX_ZERO_POLAR
        ),
        pass,
        fail
    );


    /*
     * ZERO^0 is undefined in your implementation,
     * so it should return POLAR_NAN.
     */

    result =
        complex_power(
            COMPLEX_ZERO_POLAR,
            0
        );

    ASSERT(
        isnan(result.modulus) &&
        isnan(result.argument),
        pass,
        fail
    );


    /*
     * ZERO^negative = infinity
     */

    result =
        complex_power(
            COMPLEX_ZERO_POLAR,
            -1
        );

    ASSERT(
        isinf(result.modulus),
        pass,
        fail
    );
}


static void test_polar_roots(int *pass, int *fail)
{
    cvt_complex_polar z = create_complex_polar(1.0, 0.0);

    /*
     * --------------------------------------------------
     * 4th roots of 1
     * --------------------------------------------------
     *
     * Expected roots:
     *
     * 1
     * i
     * -1
     * -i
     */

    cvt_complex_polar *roots = complex_roots(z, 4);

    /* Allocation should succeed */
    ASSERT(
        roots != NULL,
        pass,
        fail
    );

    if (roots == NULL)
        return;


    /* Root 1: 1 */
    ASSERT(
        is_nearly_equal(roots[0].modulus, 1.0) &&
        is_nearly_equal(
            convert_to_principal_argument(roots[0].argument),
            0.0
        ),
        pass,
        fail
    );


    /* Root 2: i */
    ASSERT(
        is_nearly_equal(roots[1].modulus, 1.0) &&
        is_nearly_equal(
            convert_to_principal_argument(roots[1].argument),
            PI_BY_TWO
        ),
        pass,
        fail
    );


    /* Root 3: -1 */
    ASSERT(
        is_nearly_equal(roots[2].modulus, 1.0) &&
        is_nearly_equal(
            convert_to_principal_argument(roots[2].argument),
            PI
        ),
        pass,
        fail
    );


    /* Root 4: -i */
    ASSERT(
        is_nearly_equal(roots[3].modulus, 1.0) &&
        is_nearly_equal(
            convert_to_principal_argument(roots[3].argument),
            -PI_BY_TWO
        ),
        pass,
        fail
    );


    free(roots);

    z = create_complex_polar(0.0, 0.0);

    roots = complex_roots(z, 4);

    ASSERT(
        roots != NULL,
        pass,
        fail
    );

    if (roots != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            ASSERT(
                is_nearly_equal(roots[i].modulus, 0.0) &&
                is_nearly_equal(roots[i].argument, 0.0),
                pass,
                fail
            );
        }

        free(roots);
    }


    /*
     * --------------------------------------------------
     * Invalid power: 0
     * --------------------------------------------------
     *
     * Your implementation:
     *
     * if (power <= 0)
     *     return NULL;
     */

    z = create_complex_polar(1.0, 0.0);

    roots = complex_roots(z, 0);

    ASSERT(
        roots == NULL,
        pass,
        fail
    );


    /*
     * --------------------------------------------------
     * Invalid power: negative
     * --------------------------------------------------
     */

    roots = complex_roots(z, -2);

    ASSERT(
        roots == NULL,
        pass,
        fail
    );
}

static void display_create_complex_polar(
    double modulus,
    double argument,
    int* p,
    int* f
)
{
    char ch;

    display_complex_polar(
        create_complex_polar(modulus, argument)
    );

    printf("Output Correct?: Y/N\n");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y')
        (*p)++;
    else if (ch == 'n' || ch == 'N')
        (*f)++;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void test_display_polar(int* p, int* f)
{
    display_create_complex_polar(5, 0, p, f);
    display_create_complex_polar(5, PI_BY_TWO, p, f);
    display_create_complex_polar(5, PI, p, f);
    display_create_complex_polar(5, -PI_BY_TWO, p, f);

    display_create_complex_polar(1, 0, p, f);
    display_create_complex_polar(0, 0, p, f);

    display_create_complex_polar(3, PI_BY_FOUR, p, f);
    display_create_complex_polar(2, -PI_BY_FOUR, p, f);

    display_create_complex_polar(
        INFINITY,
        NAN,
        p,
        f
    );
}