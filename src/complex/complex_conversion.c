#include <complex/complex_conversion.h>
#include <math.h>

// Function definitions

cvt_complex create_complex_from_polar(cvt_complex_polar z)
{
    double real = z.modulus * cos(z.argument);
    double imaginary = z.modulus * sin(z.argument);

    return create_complex(real, imaginary);
}

cvt_complex_polar create_complex_polar_from_cartesian(cvt_complex z)
{
    cvt_complex_polar w;

    w.modulus = cvt_modulus(z);
    w.argument = cvt_argument(z);

    return w;
}