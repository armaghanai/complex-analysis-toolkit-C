#include <complex/complex_num.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <complex/complex_constants.h>
#include <complex/complex_utils.h>

cvt_complex create_complex(double real, double imaginary)
{
    cvt_complex z;
    z.real = real;
    z.imaginary = imaginary;

    return z;
}

bool complex_equals(cvt_complex z1, cvt_complex z2)
{
    return is_nearly_equal(z1.real,z2.real) && is_nearly_equal(z1.imaginary,z2.imaginary);
}

cvt_complex complex_from_string(const char* str)
{
    cvt_complex c = {0.0, 0.0};
    if (!str) return c;

    // Skip leading whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    if (*str == '\0')
        return c;

    char* endptr = NULL;

    // Check if string starts directly with 'i' or 'I' (e.g., "i")
    if (*str == 'i' || *str == 'I') {
        c.imaginary = 1.0;
        return c;
    }

    // Parse the first number with overflow checking
    errno = 0;
    double val1 = strtod(str, &endptr);
    if (errno == ERANGE) {
        // Handle overflow for val1 if needed (val1 will be HUGE_VAL or -HUGE_VAL)
    }

    if (endptr == str) {
        // Handle explicit signs without leading digits like "+i" or "-i"
        if (*str == '+') {
            str++;
            if (*str == 'i' || *str == 'I') {
                c.imaginary = 1.0;
                return c;
            }
        } else if (*str == '-') {
            str++;
            if (*str == 'i' || *str == 'I') {
                c.imaginary = -1.0;
                return c;
            }
        }
        return c; // Parsing failed
    }

    str = endptr;

    // Skip spaces after the first number
    while (*str == ' ' || *str == '\t')
        str++;

    // If we hit the end, it was just a real number
    if (*str == '\0') {
        c.real = val1;
        return c;
    }

    // Check if the first number was actually the coefficient of 'i' (e.g., "5i")
    if (*str == 'i' || *str == 'I') {
        c.imaginary = val1;
        return c;
    }

    // Otherwise, val1 is the real part, look for a '+' or '-' for the imaginary part
    c.real = val1;

    while (*str == ' ' || *str == '\t')
        str++;

    if (*str == '+' || *str == '-') {
        char op = *str;
        str++;

        while (*str == ' ' || *str == '\t')
            str++;

        // Check for pure 'i' after sign (e.g., "3 + i")
        if (*str == 'i' || *str == 'I') {
            c.imaginary = (op == '-') ? -1.0 : 1.0;
            return c;
        }

        errno = 0;
        double val2 = strtod(str, &endptr);
        if (errno == ERANGE) {
            // Handle overflow for val2 if needed
        }

        if (endptr != str) {
            c.imaginary = (op == '-') ? -val2 : val2;
        }
    }

    return c;
}

void display_complex(cvt_complex z)
{
    if (complex_equals(z, COMPLEX_NAN))
    {
        printf("NAN");
        return;
    }

    if (complex_equals(z, COMPLEX_INFINITY))
    {
        printf("INF");
        return;
    }

    if (is_zero(z.real) && is_zero(z.imaginary))
    {
        printf("0");
        return;
    }

    if (!is_zero(z.real))
        printf("%.2f", z.real);

    if (!is_zero(z.imaginary))
    {
        if (z.imaginary > 0 && !is_zero(z.real))
            printf("+");

        if (is_nearly_equal(z.imaginary,1))
            printf("i");
        else if (is_nearly_equal(z.imaginary,-1))
            printf("-i");
        else
            printf("%.2fi", z.imaginary);
    }
}

double cvt_argument(cvt_complex z)
{
    return atan2(z.imaginary, z.real);
}

double cvt_modulus(cvt_complex z)
{
    return hypot(z.real,z.imaginary);
}

bool is_purely_imaginary(cvt_complex z)
{// as we are comparing doubles
    return is_zero(z.real);
}

bool is_purely_real(cvt_complex z)
{// as we are comparing doubles
    return is_zero(z.imaginary);
}

cvt_complex cvt_add(cvt_complex z1, cvt_complex z2)
{
    return create_complex(z1.real+z2.real,z1.imaginary+z2.imaginary);
}

cvt_complex cvt_subtract(cvt_complex z1, cvt_complex z2)
{
    return create_complex(z1.real-z2.real,z1.imaginary-z2.imaginary);
}

cvt_complex cvt_multiply_scalar(cvt_complex z, double num)
{
    return create_complex(num*z.real,num*z.imaginary);
}

cvt_complex cvt_multiply(cvt_complex z1, cvt_complex z2)
{
    if(complex_equals(z1,COMPLEX_ZERO)|| complex_equals(z2,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(complex_equals(z1,COMPLEX_ONE))
        return z2;

    if(complex_equals(z2,COMPLEX_ONE))
        return z1;

    if(is_purely_real(z2))
        return cvt_multiply_scalar(z1,z2.real);

    if(is_purely_real(z1))
        return cvt_multiply_scalar(z2,z1.real);

    double real = z1.real*z2.real - z1.imaginary*z2.imaginary;
    double imaginary = z1.real*z2.imaginary +z1.imaginary*z2.real;

    return create_complex(real, imaginary);
}

cvt_complex cvt_conjugate(cvt_complex z) //z*
{
    return create_complex(z.real,-1*z.imaginary);
}

cvt_complex cvt_divide(cvt_complex z1, cvt_complex z2)// z1/z2
{
    if(complex_equals(z1,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(complex_equals(z2,COMPLEX_ONE))
        return z1;

    if(complex_equals(z2,COMPLEX_ZERO))
        return COMPLEX_INFINITY;

    double denom = z2.real*z2.real +z2.imaginary*z2.imaginary;

    double real =
    (z1.real * z2.real + z1.imaginary * z2.imaginary) / denom;

    double imaginary =
    (z1.imaginary * z2.real - z1.real * z2.imaginary) / denom;

    return create_complex(real, imaginary);
}

cvt_complex complex_reciprocal(cvt_complex z)
{
    return cvt_divide(COMPLEX_ONE,z);
}