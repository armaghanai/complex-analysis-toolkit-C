#include <complex/complex_func.h>
#include <complex/complex_num.h>
#include <complex/complex_constants.h>
#include <math.h>


// Function definitions

cvt_complex complex_exp(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return COMPLEX_ONE;

    double exp_factor = exp(z.real);

    return create_complex(exp_factor*cos(z.imaginary),exp_factor*sin(z.imaginary));
}

cvt_complex complex_natural_Log(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return create_complex(-INFINITY,NAN);
    
    if(complex_equals(z,COMPLEX_ONE))
        return COMPLEX_ZERO;

    double real = cvt_modulus(z);
    double imaginary = cvt_argument(z);

    return create_complex(real, imaginary);
}

cvt_complex complex_power(cvt_complex base, cvt_complex power)
{
    if (complex_equals(base, COMPLEX_ZERO))
    {
        if (complex_equals(power, COMPLEX_ZERO))
            return COMPLEX_NAN;

        if (is_purely_real(power))
        {
            if (power.real > 0.0)
                return COMPLEX_ZERO;

            if (power.real < 0.0)
                return COMPLEX_INFINITY;
        }
        return COMPLEX_NAN;
    }

    if (complex_equals(power, COMPLEX_ZERO))
        return COMPLEX_ONE;

    return complex_exp(cvt_multiply(power,complex_natural_Log(base)));
}

cvt_complex complex_sin(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(is_purely_real(z))
        return create_complex(sin(z.real),0);
    
    cvt_complex iota_z = cvt_multiply(COMPLEX_I,z);
    cvt_complex minus_iota_z = cvt_multiply_scalar(iota_z,-1);
    cvt_complex difference = cvt_subtract(complex_exp(iota_z),complex_exp(minus_iota_z));

    cvt_complex TWO_IOTA = create_complex(0,2);

    return cvt_divide(difference,TWO_IOTA);
}

cvt_complex complex_cos(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return COMPLEX_ONE;

    if(is_purely_real(z))
        return create_complex(cos(z.real),0);
    
    cvt_complex iota_z = cvt_multiply(COMPLEX_I,z);
    cvt_complex minus_iota_z = cvt_multiply_scalar(iota_z,-1);
    cvt_complex sum = cvt_add(complex_exp(iota_z),complex_exp(minus_iota_z));

    return cvt_multiply_scalar(sum,0.5);
}

cvt_complex complex_tan(cvt_complex z)
{
    return cvt_divide(complex_sin(z),complex_cos(z));
}

cvt_complex complex_cot(cvt_complex z)
{
    return cvt_divide(complex_cos(z),complex_sin(z));
}

cvt_complex complex_sec(cvt_complex z)
{
    return cvt_reciprocal(complex_cos(z));
}

cvt_complex complex_cosec(cvt_complex z)
{
    return cvt_reciprocal(complex_sin(z));
}

cvt_complex complex_sinh(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return COMPLEX_ZERO;

    if(is_purely_real(z))
        return create_complex(sinh(z.real),0);

    cvt_complex minus_z = cvt_multiply_scalar(z,-1);
    
    cvt_complex difference = cvt_subtract(complex_exp(z),complex_exp(minus_z));

    return cvt_multiply_scalar(difference,0.5);
}

cvt_complex complex_cosh(cvt_complex z)
{
    if(complex_equals(z,COMPLEX_ZERO))
        return COMPLEX_ONE;

    if(is_purely_real(z))
        return create_complex(cosh(z.real),0);
    
    cvt_complex minus_z = cvt_multiply_scalar(z,-1);
    
    cvt_complex sum = cvt_add(complex_exp(z),complex_exp(minus_z));

    return cvt_multiply_scalar(sum,0.5);
}

cvt_complex complex_tanh(cvt_complex z)
{
    return cvt_divide(complex_sinh(z),complex_cosh(z));
}

cvt_complex complex_coth(cvt_complex z)
{
    return cvt_divide(complex_cosh(z),complex_sinh(z));
}

cvt_complex complex_sech(cvt_complex z)
{
    return cvt_reciprocal(complex_cosh(z));
}

cvt_complex complex_cosech(cvt_complex z)
{
    return cvt_reciprocal(complex_sinh(z));
}

