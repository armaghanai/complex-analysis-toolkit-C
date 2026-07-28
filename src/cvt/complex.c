#include <cvt/complex.h>
#include <cvt/complexPolar.h>
#include <math.h>
#include <stdbool.h>
#include <cvt/complexConstants.h>

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

cvt_complex create_complex_from_polar(cvt_complex_polar z)
{
    double real = z.modulus * cos(z.argument);
    double imaginary = z.modulus * sin(z.argument);

    return create_complex(real, imaginary);
}

//cvt_complex create_from_string(const char*);
void display_complex(cvt_complex z)
{
    printf("%.2f",z.real);
    if(z.imaginary >= 0)
        printf("+");
    printf("%.2f",z.imaginary);

}

double cvt_argument(cvt_complex z)
{
    return atan2(z.imaginary, z.real);
}

double cvt_modulus(cvt_complex z)
{
    return hypot(z.real,z.imaginary);
}

cvt_complex complex_reciprocal(cvt_complex z)
{
    cvt_complex_polar w;

    if (complex_equals(z,COMPLEX_ZERO))
        w = COMPLEX_POLAR_MAX;

    else
        w = create_complex_polar_from_cartesian(z);

    w = complex_power(w, -1);

    z = create_complex_from_polar(w);

    return z;
}