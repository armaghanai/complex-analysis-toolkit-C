#ifndef COMPLEX_COMPLEX_FUNC_H
#define COMPLEX_COMPLEX_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <complex/complex_num.h>


// Types


// Function declarations

cvt_complex complex_exp(cvt_complex);
cvt_complex complex_principal_log(cvt_complex);
cvt_complex complex_power(cvt_complex,cvt_complex);

cvt_complex complex_sin(cvt_complex);
cvt_complex complex_cos(cvt_complex);
cvt_complex complex_tan(cvt_complex);
cvt_complex complex_cot(cvt_complex);
cvt_complex complex_sec(cvt_complex);
cvt_complex complex_cosec(cvt_complex);

cvt_complex complex_sinh(cvt_complex);
cvt_complex complex_cosh(cvt_complex);
cvt_complex complex_tanh(cvt_complex);
cvt_complex complex_coth(cvt_complex);
cvt_complex complex_sech(cvt_complex);
cvt_complex complex_cosech(cvt_complex);



#ifdef __cplusplus
}
#endif

#endif /* COMPLEX_COMPLEX_FUNC_H */
