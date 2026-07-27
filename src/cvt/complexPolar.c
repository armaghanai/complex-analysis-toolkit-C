#include <cvt/complexPolar.h>
#include <cvt/complex.h>
#include <math.h>
#include <cvt/complexConstants.h>
#include <stdlib.h>

cvt_complex_polar create_complex_polar(double modulus,double argument)
{
    cvt_complex_polar z;
    z.modulus = modulus;
    z.argument = argument;

    return z;
}
cvt_complex_polar create_complex_polar_from_cartesian(cvt_complex z)
{
    cvt_complex_polar w;

    w.modulus = cvt_modulus(z);
    w.argument = cvt_argument(z);

    return w;
}

cvt_complex_polar create_from_string(const char*);

void display_complex_polar(cvt_complex_polar z)
{
    if(z.modulus == 0)
    {
        printf('0');
        return;
    }

    if(z.modulus != 1 || z.argument == 0)
    {
        printf("%.2f",z.modulus);
    }

    if(z.argument != 0)
    {
        printf("exp(i%.2f)",z.argument);
        return;
    }

}
cvt_complex_polar complex_square(cvt_complex_polar z)
{
    return complex_power(z,2);
}

double multiply_argument(double argument, double factor)
{
    if (factor == 1)
        return argument;

    if (factor == 0)
        return 0;

    argument *= factor;

    argument = fmod(argument, TWO_PI);

    if(argument < 0.0)
        argument += TWO_PI;

    if(argument > PI)
        argument -= TWO_PI;

    return argument;
}
cvt_complex_polar complex_power(cvt_complex_polar z, int power)
{
    if(power == 0)
        return create_complex_polar(1,0);
    
    if(power == 1)
        return z;

    return create_complex_polar(pow(z.modulus,power),multiply_argument(z.argument,(double)power));
}
cvt_complex_polar* complex_roots(cvt_complex_polar z, int power)
{
    if(power <= 0)
        return NULL;

    cvt_complex_polar* roots = malloc(power * sizeof(cvt_complex_polar));

    z.modulus = pow(z.modulus, 1.0/power);

    for(int i = 0; i < power; i++)
    {
        //*(roots+i) = create_complex_polar(z.modulus, )
    }
}