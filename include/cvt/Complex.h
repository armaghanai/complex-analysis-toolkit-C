#ifndef CVT_COMPLEX_H
#define CVT_COMPLEX_H

#ifdef __cplusplus // makes it compatible for C++
extern "C" {
#endif

typedef struct {
    double real;
    double imaginary;
}cvt_complex;

cvt_complex create_complex(double, double);
cvt_complex create_complex_from_polar(double,double);
//cvt_complex create_complex_from_polar(cvt_complex_polar);
//cvt_complex_polar convert_to_polar(cvt_complex);
cvt_complex create_from_string(const char*);
void display_complex(double, double);
double cvt_argument(cvt_complex);
double cvt_modulus(cvt_complex);

#ifdef __cplusplus
}
#endif


#endif CVT_COMPLEX_H