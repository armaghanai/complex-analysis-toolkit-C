#include <complex/complex_utils.h>
#include <stdbool.h>
#include <math.h>

bool is_zero(double value)
{
    return fabs(value) < COMPLEX_EPSILON;
}

// Function definitions

