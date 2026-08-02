#ifndef COMPLEX_COMPLEX_UTILS_H
#define COMPLEX_COMPLEX_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stdbool.h>

#define COMPLEX_EPSILON 1e-12


// Types


// Function declarations
bool is_zero(double);
double convert_to_principal_argument(double);
double multiply_argument(double,double);
bool is_nearly_equal(double, double);

#ifdef __cplusplus
}
#endif

#endif /* COMPLEX_COMPLEX_UTILS_H */
