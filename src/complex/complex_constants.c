#include <complex/complex_constants.h>
#include <math.h>

const cvt_complex COMPLEX_ZERO = {0.0, 0.0};
const cvt_complex COMPLEX_ONE = {1.0, 0.0};
const cvt_complex COMPLEX_I = {0.0, 1.0};

const cvt_complex COMPLEX_NAN = {NAN, NAN};
const cvt_complex COMPLEX_INFINITY = {INFINITY, INFINITY};

const cvt_complex_polar COMPLEX_ZERO_POLAR = {0.0, 0.0};
const cvt_complex_polar COMPLEX_ONE_POLAR = {1.0, 0.0};
const cvt_complex_polar COMPLEX_I_POLAR = {1.0, PI_BY_TWO};

const cvt_complex_polar COMPLEX_POLAR_NAN = {
    NAN,
    NAN
};
const cvt_complex_polar COMPLEX_POLAR_INFINITY = {
    INFINITY,
    NAN
};