#include "test_helpers.h"
#include <math.h>
#include <stdio.h>
#include <complex/complex_num.h>
#include <complex/complex_constants.h>
#include <complex/complex_utils.h>

static void test_creation(int*, int*);
static void test_equality(int*, int*);
static void test_parsing(int*, int*);
static void test_pure_real(int* , int* );
static void test_pure_imaginary(int* , int* );
static void test_addition(int* , int* );
static void test_subtraction(int* , int* );
static void test_scalar_multiplication(int* , int* );
static void test_complex_multiplication(int* , int* );
static void test_conjugate(int* , int* );
static void test_division(int* , int* );
static void test_reciprocal(int* , int* );
static void test_display(int* , int* );
static void display_create_complex(double,double,int*,int*);
static void test_display(int*,int*);

void test_complex_num(int* total_pass, int* total_fail)
{
    int pass = 0, fail = 0;
    printf("Testing Complex Numbers\n");
    //creation
    test_creation(&pass,&fail);
    test_equality(&pass,&fail);
    test_pure_real(&pass, &fail);
    test_pure_imaginary(&pass, &fail);
    test_addition(&pass, &fail);
    test_subtraction(&pass, &fail);
    test_scalar_multiplication(&pass, &fail);
    test_complex_multiplication(&pass, &fail);
    test_conjugate(&pass, &fail);
    test_division(&pass, &fail);
    test_reciprocal(&pass, &fail);
    test_display(&pass, &fail);
    

    //parsing
    printf("Total Tests: %d\n",pass+fail);
    *total_pass += pass;
    *total_fail += fail;
}

static void test_creation(int *p, int* f)
{
    cvt_complex z = create_complex(3.0, 4.0);

    ASSERT(z.real == 3.0, p, f);
    ASSERT(z.imaginary == 4.0, p, f);

}

static void test_equality(int* p, int* f)
{
    ASSERT(complex_equals(
    create_complex(1,2),
    create_complex(1,2)),p,f);

    ASSERT(!complex_equals(
    create_complex(1,2),
    create_complex(2,1)),p,f);

    ASSERT(complex_equals(
    COMPLEX_ZERO,
    create_complex(0,0)),p,f);

    ASSERT_F(complex_equals(
    COMPLEX_NAN,
    create_complex(NAN,NAN)),p,f,1);

    ASSERT(complex_equals(
    COMPLEX_INFINITY,
    create_complex(INFINITY,INFINITY)),p,f);
}

static void test_parsing(int* p, int* f) 
{
    ASSERT(complex_equals(
        create_from_string("5"),
        create_complex(5, 0)), p, f);

    ASSERT(complex_equals(
        create_from_string("5i"),
        create_complex(0, 5)), p, f);

    ASSERT(complex_equals(
        create_from_string("-5i"),
        create_complex(0, -5)), p, f);

    ASSERT(complex_equals(
        create_from_string("3+4i"),
        create_complex(3, 4)), p, f);

    ASSERT(complex_equals(
        create_from_string("3-4i"),
        create_complex(3, -4)), p, f);

    ASSERT(complex_equals(
        create_from_string("i"),
        create_complex(0, 1)), p, f);

    ASSERT(complex_equals(
        create_from_string("-i"),
        create_complex(0, -1)), p, f);

    ASSERT_F(complex_equals(
        create_from_string("hello"),
        COMPLEX_ZERO), p, f, 1);

    ASSERT_F(complex_equals(
        create_from_string(""),
        COMPLEX_ZERO), p, f, 1);

    ASSERT_F(complex_equals(
        create_from_string(NULL),
        COMPLEX_ZERO), p, f, 1);
}

static void test_modulus(int* p, int* f) 
{
    ASSERT(is_nearly_equal(cvt_modulus(create_complex(3, 4)),5.0), p, f);

    ASSERT(is_nearly_equal(cvt_modulus(COMPLEX_ZERO) , 0.0), p, f);

    ASSERT_F(cvt_modulus(create_complex(300, 400)) == 500.0, p, f, 1);

    ASSERT_F(cvt_modulus(create_complex(1e308, 1e308)) == 0.0, p, f, 1);
}

static void test_argument(int* p, int* f) 
{
    ASSERT(is_nearly_equal(
        cvt_argument(create_complex(1, 0)), 
        0.0), p, f);

    ASSERT(is_nearly_equal(
        cvt_argument(create_complex(0, 1)), 
        PI_BY_FOUR), p, f);

    ASSERT(is_nearly_equal(
        cvt_argument(create_complex(-1, 0)), 
        PI), p, f);

    ASSERT(is_nearly_equal(
        cvt_argument(create_complex(0, -1)), 
        MINUS_PI/2.0), p, f);

    ASSERT_F(is_nearly_equal(
        cvt_argument(COMPLEX_ZERO), 
        0.0), p, f, 1);

    ASSERT_F(is_nearly_equal(
        cvt_argument(create_complex(1e-15, 1e-15)), 
        PI_BY_FOUR), p, f, 1);
}
static void test_pure_real(int* p, int* f) 
{
    ASSERT(is_purely_real(create_complex(5, 0)), p, f);
    ASSERT(!is_purely_real(create_complex(5, 2)), p, f);
    ASSERT_F(is_purely_real(create_complex(5.0000001, 0)), p, f, 1);
}

static void test_pure_imaginary(int* p, int* f) 
{
    ASSERT(is_purely_imaginary(create_complex(0, 5)), p, f);
    ASSERT(!is_purely_imaginary(create_complex(1, 5)), p, f);
    ASSERT_F(is_purely_imaginary(create_complex(0, 5.0000001)), p, f, 1);
}

static void test_addition(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_add(
            create_complex(1, 2),
            create_complex(3, 4)),
        create_complex(4, 6)), p, f);

    ASSERT_F(complex_equals(
        cvt_add(
            create_complex(1e-15, 1e-15),
            create_complex(1e-15, 1e-15)),
        COMPLEX_ZERO), p, f, 1);
}

static void test_subtraction(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_subtract(
            create_complex(5, 7),
            create_complex(2, 3)),
        create_complex(3, 4)), p, f);

    ASSERT_F(complex_equals(
        cvt_subtract(
            create_complex(5, 7),
            create_complex(5, 7)),
        create_complex(1e-15, 0)), p, f, 1);
}

static void test_scalar_multiplication(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_multiply_scalar(
            create_complex(2, 3),
            5),
        create_complex(10, 15)), p, f);

    ASSERT_F(complex_equals(
        cvt_multiply_scalar(
            create_complex(2, 3),
            1e-16),
        COMPLEX_ZERO), p, f, 1);
}

static void test_complex_multiplication(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_multiply(
            create_complex(2, 3),
            create_complex(4, 5)),
        create_complex(-7, 22)), p, f);

    ASSERT(complex_equals(
        cvt_multiply(
            create_complex(2, 3),
            COMPLEX_ZERO),
        COMPLEX_ZERO), p, f);

    ASSERT(complex_equals(
        cvt_multiply(
            create_complex(2, 3),
            create_complex(1, 0)),
        create_complex(2, 3)), p, f);

    ASSERT(complex_equals(
        cvt_multiply(
            create_complex(2, 3),
            create_complex(5, 0)),
        create_complex(10, 15)), p, f);

    ASSERT_F(complex_equals(
        cvt_multiply(
            create_complex(1e200, 1e200),
            create_complex(1e200, 1e200)),
        COMPLEX_ZERO), p, f, 1);
}

static void test_conjugate(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_conjugate(
            create_complex(2, 3)),
        create_complex(2, -3)), p, f);

    ASSERT_F(complex_equals(
        cvt_conjugate(
            create_complex(0, 0)),
        create_complex(0, 1)), p, f, 1);
}

static void test_division(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_divide(
            create_complex(4, 2),
            create_complex(2, 1)),
        create_complex(2, 0)), p, f);

    ASSERT(complex_equals(
        cvt_divide(
            create_complex(3, 4),
            create_complex(1, 0)),
        create_complex(3, 4)), p, f);

    ASSERT(complex_equals(
        cvt_divide(
            COMPLEX_ZERO,
            create_complex(3, 4)),
        COMPLEX_ZERO), p, f);

    ASSERT_F(complex_equals(
        cvt_divide(
            create_complex(3, 4),
            COMPLEX_ZERO),
        COMPLEX_ZERO), p, f, 1);
}

static void test_reciprocal(int* p, int* f) 
{
    ASSERT(complex_equals(
        cvt_reciprocal(
            create_complex(1, 1)),
        create_complex(0.5, -0.5)), p, f);

    ASSERT(complex_equals(
        cvt_reciprocal(
            create_complex(2, 0)),
        create_complex(0.5, 0)), p, f);

    ASSERT_F(complex_equals(
        cvt_reciprocal(
            COMPLEX_ZERO),
        COMPLEX_ZERO), p, f, 1);
}

static void display_create_complex(double real, double img,int* p, int* f) 
{
    char ch;
    display_complex(create_complex(real, img));
    printf("Output Correct?: Y/N\n");
    scanf("%c",&ch);
    if(ch == 'y' || ch == 'Y')
        (*p)++;
    else if(ch == 'n' || ch == 'N')
        (*f)++;
    int c; 
    while ((c = getchar()) != '\n' && c != EOF);
    
}

static void test_display(int* p, int* f)
{
    display_create_complex(3,4,p,f);
    display_create_complex(-1,0,p,f);
    display_create_complex(0,-1,p,f);
    display_create_complex(0,-2,p,f);
    display_create_complex(0,0,p,f);
    display_create_complex(-4,-8,p,f);
    display_create_complex(0,1,p,f);
    display_create_complex(0,8,p,f);
    display_create_complex(3,0,p,f);
}