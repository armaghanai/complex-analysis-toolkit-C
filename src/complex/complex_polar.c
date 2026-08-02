#include <complex/complex_polar.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <complex/complex_constants.h>
#include <stdlib.h>
#include <complex/complex_utils.h>

cvt_complex_polar create_complex_polar(double modulus,double argument)
{
    cvt_complex_polar z;
    z.modulus = modulus;
    z.argument = argument;

    return z;
}

cvt_complex_polar create_complex_polar_from_string(const char *str)
{
    if (str == NULL)
        return COMPLEX_NAN_POLAR;

    char *end;

    errno = 0;
    double modulus = strtod(str, &end);

    if (end == str || errno == ERANGE)
        return COMPLEX_NAN_POLAR;

    while (isspace((unsigned char)*end))
        end++;

    if (strncmp(end, "exp(", 4) != 0)
        return COMPLEX_NAN_POLAR;

    end += 4;

    while (isspace((unsigned char)*end))
        end++;

    double argument;

    if (*end == 'i')
    {
        /* exp(iθ) */

        end++;

        errno = 0;
        argument = strtod(end, &end);

        if (errno == ERANGE)
            return COMPLEX_NAN_POLAR;
    }
    else
    {
        /* exp(θi) */

        errno = 0;
        argument = strtod(end, &end);

        if (errno == ERANGE)
            return COMPLEX_NAN_POLAR;

        while (isspace((unsigned char)*end))
            end++;

        if (*end != 'i')
            return COMPLEX_NAN_POLAR;

        end++;
    }

    while (isspace((unsigned char)*end))
        end++;

    if (*end != ')')
        return COMPLEX_NAN_POLAR;

    end++;

    while (isspace((unsigned char)*end))
        end++;

    if (*end != '\0')
        return COMPLEX_NAN_POLAR;

    if (modulus < 0)
    {
        modulus = -modulus;
        argument += PI;
    }

    return create_complex_polar(
        modulus,
        convert_to_principal_argument(argument)
    );
}

bool complex_polar_equals(cvt_complex_polar z1, cvt_complex_polar z2)
{
    if (is_zero(z1.modulus) && is_zero(z2.modulus))
        return true;

    return (is_zero(z1.modulus-z2.modulus) && is_zero(
        convert_to_principal_argument(z1.argument)-convert_to_principal_argument(z2.argument)));
        //since one complex number can have different agrs so we convert to principal one
        //then compare
}

void display_complex_polar(cvt_complex_polar z)
{
    if(complex_polar_equals(z,COMPLEX_INFINITY_POLAR))
    {
        printf("INF");
        return;
    }

    if(complex_polar_equals(z,COMPLEX_NAN_POLAR))
    {
        printf("NAN");
        return;
    }

    if(is_zero(z.modulus))
    {
        printf("0");
        return;
    }

    if(!is_zero(z.modulus - 1) || is_zero(z.argument))
    {
        printf("%.2f",z.modulus);
    }

    if(!is_zero(z.argument))
    {
        printf("exp(i%.2f)",z.argument);
        return;
    }

}
cvt_complex_polar complex_square(cvt_complex_polar z)
{
    return complex_power(z,2);
}

double convert_to_principal_argument(double argument)
{
    // converts any angle in the range of (-PI,PI]
    argument = fmod(argument, TWO_PI);

    if(argument < 0.0)
        argument += TWO_PI;

    if(argument > PI)
        argument -= TWO_PI;

    return argument;

}

double multiply_argument(double argument, double factor)
{
    if (factor == 1)
        return argument;

    if (factor == 0)
        return 0;

    argument *= factor;

    return convert_to_principal_argument(argument);
}

cvt_complex_polar complex_polar_multiply(cvt_complex_polar z1, cvt_complex_polar z2)
{
    if(complex_polar_equals(z1,COMPLEX_ZERO_POLAR) || complex_polar_equals(z2,COMPLEX_ZERO_POLAR))
        return COMPLEX_ZERO_POLAR;
    
    if(complex_polar_equals(z1,COMPLEX_ONE_POLAR))
        return z2;

    if(complex_polar_equals(z2,COMPLEX_ONE_POLAR))
        return z1;

    double mod = z1.modulus * z2.modulus;
    double arg = convert_to_principal_argument(z1.argument+z1.argument);

    return create_complex_polar(mod,arg);
}

cvt_complex_polar complex_polar_divide(cvt_complex_polar z1, cvt_complex_polar z2)
{
    if(complex_equals(z1,COMPLEX_ZERO_POLAR))
        return COMPLEX_ZERO_POLAR;

    if(complex_equals(z2,COMPLEX_ONE_POLAR))
        return z1;

    if(complex_equals(z2,COMPLEX_ZERO_POLAR))
        return COMPLEX_INFINITY_POLAR;

    double mod = z1.modulus / z2.modulus;
    double arg = convert_to_principal_argument(z1.argument - z2.argument);

    return create_complex_polar(mod, arg);
}

cvt_complex_polar complex_polar_conjugate(cvt_complex_polar z)
{
    return create_complex_polar(z.modulus, 
        convert_to_principal_argument(-1*z.argument));
}

cvt_complex_polar complex_power(cvt_complex_polar z, int power)
{
    if (complex_polar_equals(z, COMPLEX_NAN_POLAR))
        return COMPLEX_NAN_POLAR;

    if(complex_polar_equals(z,COMPLEX_ZERO_POLAR))
    {
        if(power == 0)
            return COMPLEX_NAN_POLAR;
        else if(power > 0)
            return COMPLEX_ZERO_POLAR;
        else
            return COMPLEX_INFINITY_POLAR;
    }

    if(power == 0)
        return COMPLEX_ONE_POLAR;
    
    if(power == 1)
        return z;
    
    return create_complex_polar(pow(z.modulus,power),multiply_argument(z.argument,power));
}

cvt_complex_polar* complex_roots(cvt_complex_polar z, int power)
{
    if(power <= 0)
        return NULL;

    cvt_complex_polar* roots = malloc(power * sizeof(cvt_complex_polar));

    if(roots == NULL)
        return NULL;

    if (complex_polar_equals(z, COMPLEX_ZERO_POLAR))
    {
        for (int i = 0; i < power; i++)
            *(roots + i) = COMPLEX_ZERO_POLAR;

        return roots;
    }

    z.modulus = pow(z.modulus, 1.0/power);

    for(int i = 0; i < power; i++)
        *(roots+i) = create_complex_polar(z.modulus,convert_to_principal_argument((z.argument+TWO_PI*i)/power));

    return roots;
}