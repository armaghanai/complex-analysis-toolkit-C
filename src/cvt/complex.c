#include <cvt/complex.h>
#include <cvt/complexPolar.h>
#include <math.h>
#include <stdbool.h>

cvt_complex create_complex(double real, double imaginary)
{
    cvt_complex z;
    z.real = real;
    z.imaginary = imaginary;

    return z;
}

cvt_complex create_complex_from_polar(double modulus,double argument)
{
    if (modulus == 0)
        return create_complex(0,0);

    if (modulus < 0)
        modulus *= -1;
    
    return create_complex(modulus*cos(argument),modulus*sin(argument));
}
//cvt_complex create_complex_from_polar(cvt_complex_polar);
//cvt_complex_polar convert_to_polar(cvt_complex);
//cvt_complex create_from_string(const char*);
void display_complex(cvt_complex z)
{
    printf("%.2f",z.real);
    if(z.imaginary >= 0)
        printf('+');
    printf("%.2f",z.imaginary);

}

double cvt_argument(cvt_complex z)
{
    /*if(z.real == 0)
        return PI/2;

    if(z.imaginary == 0)
        return 0; atan2 handles this edge cases */

    return atan2(z.imaginary, z.real);
}

double cvt_modulus(cvt_complex z)
{
    return hypot(z.real,z.imaginary);
}

bool complex_equals(cvt_complex z1, cvt_complex z2)
{
    return ((z1.real == z2.real) && (z1.imaginary == z2.imaginary));
}