#include <complex/complex_num.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <complex/complex_constants.h>

cvt_complex create_complex(double real, double imaginary)
{
    cvt_complex z;
    z.real = real;
    z.imaginary = imaginary;

    return z;
}

bool complex_equals(cvt_complex z1, cvt_complex z2)
{
    return ((z1.real == z2.real) && (z1.imaginary == z2.imaginary));
}

//cvt_complex create_from_string(const char*);
void display_complex(cvt_complex z)
{
    printf("%.2f",z.real);
    if(z.imaginary >= 0)
        printf("+");
    printf("%.2fi",z.imaginary);

}

double cvt_argument(cvt_complex z)
{
    return atan2(z.imaginary, z.real);
}

double cvt_modulus(cvt_complex z)
{
    return hypot(z.real,z.imaginary);
}

cvt_complex cvt_add(cvt_complex z1, cvt_complex z2)
{
    return create_complex(z1.real+z2.real,z1.imaginary+z2.imaginary);
}

cvt_complex cvt_subtract(cvt_complex z1, cvt_complex z2)
{
    return create_complex(z1.real-z2.real,z1.imaginary-z2.imaginary);
}

cvt_complex cvt_multiply(cvt_complex z1, cvt_complex z2)
{
    if(complex_equals(z1,COMPLEX_ZERO)|| complex_equals(z2,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(complex_equals(z1,COMPLEX_ONE))
        return z2;

    if(complex_equals(z2,COMPLEX_ONE))
        return z1;

    double real = z1.real*z2.real - z1.imaginary*z2.imaginary;
    double imaginary = z1.real*z2.imaginary +z2.imaginary*z1.real;

    return create_complex(real, imaginary);
}

cvt_complex cvt_conjugate(cvt_complex z)
{
    return create_complex(z.real,-1*z.imaginary);
}


/*cvt_complex cvt_divide(cvt_complex z1, cvt_complex z2)// z1/z2
{
    if(complex_equals(z1,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(complex_equals(z2,COMPLEX_ONE))
        return z1;

    if(complex_equals(z2,COMPLEX_ZERO))
        return nullptr;

    double denom = pow(cvt_modulus(z2),2);

    double real = (z1.real*z2.real + z1.imaginary*z2.imaginary)/denom;
    double imaginary =  (z1.imaginary*z2.real - z2.real*z1.imaginary)/denom;

    return create_complex(real, imaginary);
}*/

cvt_complex complex_reciprocal(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ONE))
        return z;

    if(complex_equals(z,COMPLEX_ZERO));

    double denom = pow(cvt_modulus(z),2);
}