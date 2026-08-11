# API Reference

## Overview

Complex Analysis Toolkit C provides functionality for representing and manipulating complex numbers in both Cartesian and polar form.

The public API is organized into the following modules:

* `complex_num.h` — Cartesian complex numbers
* `complex_polar.h` — Polar complex numbers
* `complex_conversion.h` — Cartesian/polar conversions
* `complex_constants.h` — Mathematical and complex constants
* `complex_utils.h` — Numerical and argument utilities

---

# 1. Complex Numbers

Header:

```c
#include <complex/complex_num.h>
```

## `cvt_complex`

Represents a complex number in Cartesian form:

```c
typedef struct {
    double real;
    double imaginary;
} cvt_complex;
```

A complex number is represented as:

$$
z = a + bi
$$

where `real = a` and `imaginary = b`.

---

## `create_complex`

```c
cvt_complex create_complex(double real, double imaginary);
```

Creates a complex number from its real and imaginary components.

### Parameters

* `real` — Real component.
* `imaginary` — Imaginary component.

### Returns

A `cvt_complex` containing the specified components.

### Example

```c
cvt_complex z = create_complex(3.0, 4.0);
```

---

## `complex_equals`

```c
bool complex_equals(cvt_complex z1, cvt_complex z2);
```

Compares two complex numbers using the library's floating-point comparison rules.

### Parameters

* `z1` — First complex number.
* `z2` — Second complex number.

### Returns

`true` if both components are nearly equal; otherwise `false`.

---

## `create_from_string`

```c
cvt_complex create_from_string(const char *string);
```

Creates a Cartesian complex number from a string representation.

---

## `display_complex`

```c
void display_complex(cvt_complex z);
```

Displays a complex number.

---

## `cvt_modulus`

```c
double cvt_modulus(cvt_complex z);
```

Calculates the modulus:

$$
|z| = \sqrt{a^2+b^2}
$$

### Returns

The modulus of `z`.

---

## `cvt_argument`

```c
double cvt_argument(cvt_complex z);
```

Calculates the principal argument of a complex number.

The result is represented in the principal range:

$$
(-\pi,\pi]
$$

---

## `is_purely_imaginary`

```c
bool is_purely_imaginary(cvt_complex z);
```

Determines whether a complex number has a zero real component.

---

## `is_purely_real`

```c
bool is_purely_real(cvt_complex z);
```

Determines whether a complex number has a zero imaginary component.

---

## `complex_add`

```c
cvt_complex complex_add(cvt_complex z1, cvt_complex z2);
```

Adds two complex numbers.

$$
z_1+z_2
$$

---

## `complex_subtract`

```c
cvt_complex complex_subtract(cvt_complex z1, cvt_complex z2);
```

Subtracts `z2` from `z1`.

$$
z_1-z_2
$$

---

## `cvt_multiply_scalar`

```c
cvt_complex cvt_multiply_scalar(cvt_complex z, double scalar);
```

Multiplies a complex number by a real scalar.

---

## `complex_multiply`

```c
cvt_complex complex_multiply(cvt_complex z1, cvt_complex z2);
```

Multiplies two complex numbers.

$$
(ac-bd)+(ad+bc)i
$$

---

## `complex_conjugate`

```c
cvt_complex complex_conjugate(cvt_complex z);
```

Returns the complex conjugate:

$$
\overline{a+bi}=a-bi
$$

---

## `complex_divide`

```c
cvt_complex complex_divide(cvt_complex z1, cvt_complex z2);
```

Divides `z1` by `z2`.

$$
\frac{z_1}{z_2}
$$

---

## `complex_reciprocal`

```c
cvt_complex complex_reciprocal(cvt_complex z);
```

Returns the reciprocal:

$$
\frac{1}{z}
$$

---

# 2. Polar Complex Numbers

Header:

```c
#include <complex/complex_polar.h>
```

## `cvt_complex_polar`

Represents a complex number in polar form:

```c
typedef struct {
    double modulus;
    double argument;
} cvt_complex_polar;
```

A complex number is represented as:

$$
z = re^{i\theta}
$$

where:

* `modulus` represents $r$
* `argument` represents $\theta$

---

## `create_complex_polar`

```c
cvt_complex_polar create_complex_polar(
    double modulus,
    double argument
);
```

Creates a complex number in polar representation.

---

## `create_complex_polar_from_string`

```c
cvt_complex_polar create_complex_polar_from_string(
    const char *string
);
```

Creates a polar complex number from a string.

Supported formats:

```text
rexp(itheta)
rexp(thetai)
```

---

## `complex_polar_equals`

```c
bool complex_polar_equals(
    cvt_complex_polar z1,
    cvt_complex_polar z2
);
```

Compares two polar complex numbers using the library's floating-point comparison rules.

---

## `display_complex_polar`

```c
void display_complex_polar(cvt_complex_polar z);
```

Displays a polar complex number.

---

## `complex_square`

```c
cvt_complex_polar complex_square(
    cvt_complex_polar z
);
```

Calculates the square of a polar complex number.

For:

$$
z=re^{i\theta}
$$

the result is:

$$
z^2=r^2e^{i2\theta}
$$

---

## `complex_polar_multiply`

```c
cvt_complex_polar complex_polar_multiply(
    cvt_complex_polar z1,
    cvt_complex_polar z2
);
```

Multiplies two polar complex numbers.

$$
z = re^{i\theta}
$$

The resulting argument is converted to the principal argument range.

---

## `complex_polar_divide`

```c
cvt_complex_polar complex_polar_divide(
    cvt_complex_polar z1,
    cvt_complex_polar z2
);
```

Divides two polar complex numbers.

$$
\frac{r_1}{r_2}e^{i(\theta_1-\theta_2)}
$$

---

## `complex_polar_conjugate`

```c
cvt_complex_polar complex_polar_conjugate(
    cvt_complex_polar z
);
```

Returns the complex conjugate by negating the argument.

---

## `complex_power`

```c
cvt_complex_polar complex_power(
    cvt_complex_polar z,
    int power
);
```

Raises a polar complex number to an integer power.

$$
r^ne^{in\theta}
$$
The resulting argument is converted to the principal argument range.

---

## `complex_roots`

```c
cvt_complex_polar *complex_roots(
    cvt_complex_polar z,
    int power
);
```

Calculates all `power` complex roots of `z`.

The roots are:

The roots are:

$$
\sqrt[n]{r}e^{i(\theta+2\pi k)/n}
$$

where:

$$
k=0,1,\ldots,n-1
$$


### Return value

Returns a dynamically allocated array containing `power` roots.

The caller is responsible for freeing the returned memory:

```c
cvt_complex_polar *roots = complex_roots(z, 4);

if (roots != NULL)
    free(roots);
```

### Invalid power

If:

```c
power <= 0
```

the function returns `NULL`.

If memory allocation fails, the function also returns `NULL`.

---

# 3. Cartesian / Polar Conversion

Header:

```c
#include <complex/complex_conversion.h>
```

## `create_complex_from_polar`

```c
cvt_complex create_complex_from_polar(
    cvt_complex_polar z
);
```

Converts a polar complex number to Cartesian form.

Given:

$$
z=re^{i\theta}
$$

the Cartesian components are:

$$
a=r\cos(\theta)
$$
$$
b=r\sin(\theta)
$$

---

## `create_complex_polar_from_cartesian`

```c
cvt_complex_polar create_complex_polar_from_cartesian(
    cvt_complex z
);
```

Converts a Cartesian complex number to polar form.

The modulus is:

$$
r=\sqrt{a^2+b^2}
$$

and the argument is the principal argument of `z`.

---

# 4. Constants

Header:

```c
#include <complex/complex_constants.h>
```

## Mathematical Constants

```c
PI
EULER
MINUS_PI
TWO_PI
PI_BY_TWO
PI_BY_FOUR
COMPLEX_EPSILON
```

`COMPLEX_EPSILON` is used for floating-point comparisons throughout the library.

---

## Cartesian Constants

```c
extern const cvt_complex COMPLEX_ZERO;
extern const cvt_complex COMPLEX_ONE;
extern const cvt_complex COMPLEX_I;
extern const cvt_complex COMPLEX_NAN;
extern const cvt_complex COMPLEX_INFINITY;
```

### Values

| Constant           | Value                  |
| ------------------ | ---------------------- |
| `COMPLEX_ZERO`     | `0 + 0i`               |
| `COMPLEX_ONE`      | `1 + 0i`               |
| `COMPLEX_I`        | `0 + 1i`               |
| `COMPLEX_NAN`      | `NAN + NANi`           |
| `COMPLEX_INFINITY` | `INFINITY + INFINITYi` |

---

## Polar Constants

```c
extern const cvt_complex_polar COMPLEX_ZERO_POLAR;
extern const cvt_complex_polar COMPLEX_ONE_POLAR;
extern const cvt_complex_polar COMPLEX_I_POLAR;
extern const cvt_complex_polar COMPLEX_NAN_POLAR;
extern const cvt_complex_polar COMPLEX_INFINITY_POLAR;
```

### Values

| Constant                 |    Modulus | Argument |
| ------------------------ | ---------: | -------: |
| `COMPLEX_ZERO_POLAR`     |        `0` |      `0` |
| `COMPLEX_ONE_POLAR`      |        `1` |      `0` |
| `COMPLEX_I_POLAR`        |        `1` |    `π/2` |
| `COMPLEX_NAN_POLAR`      |      `NAN` |    `NAN` |
| `COMPLEX_INFINITY_POLAR` | `INFINITY` |    `NAN` |

---

# 5. Utility Functions

Header:

```c
#include <complex/complex_utils.h>
```

## `is_zero`

```c
bool is_zero(double value);
```

Determines whether a floating-point value is sufficiently close to zero.

The comparison uses `COMPLEX_EPSILON`.

---

## `convert_to_principal_argument`

```c
double convert_to_principal_argument(double argument);
```

Converts an angle to the principal argument range:

$$
(-\pi,\pi]
$$

Examples:

```text
0       → 0
2π      → 0
3π      → π
-π      → π
```

---

## `multiply_argument`

```c
double multiply_argument(
    double argument,
    double factor
);
```

Multiplies an argument by a factor and converts the result to the principal argument range.

Special cases:

```text
factor = 0 → 0
factor = 1 → original argument
```

---

## `is_nearly_equal`

```c
bool is_nearly_equal(double a, double b);
```

Compares two floating-point values using `COMPLEX_EPSILON`.

Exact equality is accepted first, allowing values such as:

```c
INFINITY == INFINITY
```

NaN values are never considered equal.

```c
is_nearly_equal(NAN, NAN)
```

returns `false`.

---

# Memory Management

Functions that return dynamically allocated memory document ownership explicitly.

Currently:

```c
complex_roots()
```

allocates an array dynamically.

The caller is responsible for releasing the returned memory using:

```c
free()
```

Do not call `free()` on objects returned directly by value, such as:

```c
create_complex()
create_complex_polar()
create_complex_from_polar()
```

---

# Error Handling

The library primarily uses return values to indicate failure.

For functions returning pointers, `NULL` indicates failure.

For example:

```c
cvt_complex_polar *roots = complex_roots(z, 0);

if (roots == NULL) {
    /* Handle invalid input or allocation failure */
}
```

Functions returning structures by value do not have a separate error return mechanism. Their behavior for invalid, NaN, infinity, and other special floating-point inputs is defined by the individual function and the library's numerical conventions.
