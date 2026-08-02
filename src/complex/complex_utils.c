#include <complex/complex_utils.h>
#include <complex/complex_constants.h>
#include <stdbool.h>
#include <math.h>

bool is_zero(double value)
{
    return fabs(value) < COMPLEX_EPSILON;
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

bool is_nearly_equal(double a, double b)
{
    return fabs(a - b) < COMPLEX_EPSILON;
}

// Function definitions

