#ifndef COMPLEX_POLAR_H //chnage
#define COMPLEX_POLAR_H //chnage

#ifdef __cplusplus // makes it compatible for C++
extern "C" {
#endif
//start from here 
typedef struct cvt_complex_polar;

cvt_complex_polar create_complex_polar(double,double);
//cvt_complex_polar create_complex_polar_from_cartesian(cvt_complex);
cvt_complex_polar create_from_string(const char*);
//cvt_complex convert_to_cartesian(cvt_complex_polar);
void display_complex_polar(cvt_complex_polar);
cvt_complex_polar complex_square(cvt_complex_polar);
cvt_complex_polar complex_power(cvt_complex_polar, int);
cvt_complex_polar* complex_roots(cvt_complex_polar, int);

#ifdef __cplusplus
}
#endif


#endif COMPLEX_POLAR_H //change