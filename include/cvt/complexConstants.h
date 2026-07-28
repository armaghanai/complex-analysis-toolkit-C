#ifndef COMPLEX_CONSTANTS_H 
#define COMPLEX_CONSTANTS_H 

#ifdef __cplusplus // makes it compatible for C++
extern "C" {
#endif
//start from here 
#include <complex.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EULER 2.71828182845904523536

#define MINUS_PI (-1.0*PI)
#define TWO_PI (2.0*PI)
#define PI_BY_TWO (PI/2)

#define COMPLEX_ZERO create_complex(0,0)
#define COMPLEX_ONE create_complex(1,0)
#define IOTA create_complex(0,1)

#define COMPLEX_ZERO_POLAR create_complex_polar(0,0)
#define COMPLEX_ONE_POLAR create_complex(1,0)
#define IOTA_POLAR create_complex(1,PI_BY_TWO)

#define COMPLEX_POLAR_MAX create_complex_polar(INFINITY,0)


#ifdef __cplusplus
}
#endif


#endif /*COMPLEX_CONSTANTS_H*/