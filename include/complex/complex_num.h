#ifndef CVT_COMPLEX_NUM_H
#define CVT_COMPLEX_NUM_H

#ifdef __cplusplus // makes it compatible for C++
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
    double real;
    double imaginary;
}cvt_complex;

cvt_complex create_complex(double, double);
bool complex_equals(cvt_complex, cvt_complex);
cvt_complex create_from_string(const char*);

void display_complex(cvt_complex);

double cvt_argument(cvt_complex);
double cvt_modulus(cvt_complex);

bool is_purely_imaginary(cvt_complex);
bool is_purely_real(cvt_complex);

cvt_complex complex_add(cvt_complex, cvt_complex);
cvt_complex complex_subtract(cvt_complex, cvt_complex);

cvt_complex cvt_multiply_scalar(cvt_complex, double);
cvt_complex complex_multiply(cvt_complex, cvt_complex);

cvt_complex complex_conjugate(cvt_complex);

cvt_complex complex_divide(cvt_complex, cvt_complex);
cvt_complex complex_reciprocal(cvt_complex);

#ifdef __cplusplus
}
#endif

#endif /*CVT_COMPLEX_NUM_H*/