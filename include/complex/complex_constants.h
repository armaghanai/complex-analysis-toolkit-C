#ifndef COMPLEX_CONSTANTS_H 
#define COMPLEX_CONSTANTS_H 

#ifdef __cplusplus // makes it compatible for C++
extern "C" {
#endif
//start from here 
#include <complex/complex_num.h>
#include <complex/complex_polar.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EULER 2.71828182845904523536

#define MINUS_PI (-1.0*PI)
#define TWO_PI (2.0*PI)
#define PI_BY_TWO (PI/2)

#define COMPLEX_EPSILON 1e-12

extern const cvt_complex COMPLEX_ZERO;
extern const cvt_complex COMPLEX_ONE;
extern const cvt_complex COMPLEX_I;

extern const cvt_complex COMPLEX_NAN;
extern const cvt_complex COMPLEX_INFINITY;

extern const cvt_complex_polar COMPLEX_ZERO_POLAR;
extern const cvt_complex_polar COMPLEX_ONE_POLAR;
extern const cvt_complex_polar COMPLEX_I_POLAR;

extern const cvt_complex_polar COMPLEX_NAN_POLAR;
extern const cvt_complex_polar COMPLEX_INFINITY_POLAR;


#ifdef __cplusplus
}
#endif


#endif /*COMPLEX_CONSTANTS_H*/