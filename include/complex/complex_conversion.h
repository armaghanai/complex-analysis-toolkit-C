#ifndef CVT_COMPLEX_CONVERSION_H
#define CVT_COMPLEX_CONVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <complex/complex_num.h>
#include <complex/complex_polar.h>


// Types


// Function declarations
cvt_complex create_complex_from_polar(cvt_complex_polar);
cvt_complex_polar create_complex_polar_from_cartesian(cvt_complex);

#ifdef __cplusplus
}
#endif

#endif /* CVT_COMPLEX_CONVERSION_H */
