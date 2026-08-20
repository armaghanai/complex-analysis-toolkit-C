# Complex Analysis Toolkit C

A lightweight, modular C library for working with complex numbers, polar representations, and complex-number operations.

## Features

### Complex Numbers

* Cartesian complex number representation
* Complex addition and subtraction
* Scalar multiplication
* Complex multiplication
* Complex division
* Complex conjugation
* Reciprocal
* Modulus
* Argument
* Real and imaginary number checks
* String parsing

### Polar Representation

* Polar complex number representation
* Cartesian ↔ polar conversion
* Polar multiplication and division
* Polar conjugation
* Complex powers
* Complex roots
* Principal argument handling

### Constants

The library provides commonly used complex-number constants:

* `COMPLEX_ZERO`
* `COMPLEX_ONE`
* `COMPLEX_I`
* `COMPLEX_NAN`
* `COMPLEX_INFINITY`
* Polar equivalents

It also provides mathematical constants such as:

* `PI`
* `TWO_PI`
* `PI_BY_TWO`
* `PI_BY_FOUR`
* `EULER`

### Testing

The project includes a custom lightweight testing framework with:

* Unit tests for library functions
* Edge-case testing
* NaN and infinity testing
* Floating-point comparison using epsilon
* Dynamic-memory tests
* Complex root testing

## Requirements

* C compiler with C17 support
* CMake `3.15+`
* Ninja
* Python 3.x for the file-generation script
* Standard C math library

The project is currently developed and tested using:

* GCC / MinGW UCRT64
* Windows
* CMake
* Ninja

## Building

Clone the repository:

```bash
git clone https://github.com/armaghanai/complex-analysis-toolkit-C.git
cd complex-analysis-toolkit-c
```

Configure the project:

```bash
cmake -S . -B build -G Ninja
```

Build:

```bash
cmake --build build
```

## Running Tests

After building:

```bash
./build/complex_tests
```

On Windows PowerShell:

```powershell
.\build\complex_tests.exe
```

The test program reports the total number of passed and failed tests.

## Generating New Files

The project includes `gen_file.py` to simplify adding new library components.

The script can be used to generate the corresponding:

* Header file
* Source file
* Test file

This helps maintain the project's naming and directory structure when adding new functionality.

The project also includes reusable templates in the `boilerplate` directory:

```text
boilerplate/
├── boilerplate.h
├── boilerplate.c
└── test_boilerplate.c
```

These can be copied and adapted manually when creating a new module.

## Basic Usage

Include the required headers:

```c
#include <complex/complex_num.h>
#include <complex/complex_polar.h>
#include <complex/complex_conversion.h>
#include <complex/complex_constants.h>
```

Create a complex number:

```c
cvt_complex z = create_complex(3.0, 4.0);
```

Calculate its modulus and argument:

```c
double modulus = cvt_modulus(z);
double argument = cvt_argument(z);
```

Perform complex arithmetic:

```c
cvt_complex z1 = create_complex(2.0, 3.0);
cvt_complex z2 = create_complex(1.0, 4.0);

cvt_complex sum = complex_add(z1, z2);
cvt_complex product = complex_multiply(z1, z2);
cvt_complex quotient = complex_divide(z1, z2);
```

Create a polar complex number:

```c
cvt_complex_polar z =
    create_complex_polar(2.0, PI_BY_FOUR);
```

Convert between representations:

```c
cvt_complex cartesian =
    create_complex_from_polar(z);

cvt_complex_polar polar =
    create_complex_polar_from_cartesian(cartesian);
```

Calculate roots:

```c
cvt_complex_polar z =
    create_complex_polar(1.0, 0.0);

cvt_complex_polar *roots =
    complex_roots(z, 4);
```

`complex_roots()` dynamically allocates the returned array. The caller is responsible for freeing it:

```c
free(roots);
```

## Project Structure

```text
complex-analysis-toolkit-c/
│
├── .gitignore
├── CHANGELOG.md
├── CMakeLists.txt
├── CONTRIBUTING.md
├── gen_file.py
├── LICENSE
├── README.md
│
├── boilerplate/
│   ├── boilerplate.c
│   ├── boilerplate.h
│   └── test_boilerplate.c
│
├── docs/
│   ├── api.md
│   └── getting_started.md
│
├── examples/
│
├── include/
│   └── complex/
│       ├── complex_constants.h
│       ├── complex_conversion.h
|       ├── complex_func.h
│       ├── complex_num.h
│       ├── complex_polar.h
│       └── complex_utils.h
│
├── src/
│   └── complex/
│       ├── complex_constants.c
│       ├── complex_conversion.c
|       ├── complex_func.c
│       ├── complex_num.c
│       ├── complex_polar.c
│       └── complex_utils.c
│
└── tests/
    ├── test_helpers.h
    ├── test_main.c
    │
    └── test_complex/
        ├── test_complex_num.c
        ├── test_complex_func.c
        ├── test_complex_polar.c
        ├── test_constants.c
        ├── test_conversion.c
        └── test_utils.c
```

### Directory Overview

| Directory/File    | Purpose                                      |
| ----------------- | -------------------------------------------- |
| `include/`        | Public library header files                  |
| `src/`            | Library implementation files                 |
| `tests/`          | Automated tests                              |
| `boilerplate/`    | Templates for creating new modules           |
| `examples/`       | Example programs using the library           |
| `docs/`           | Additional documentation                     |
| `gen_file.py`     | Generates new header, source, and test files |
| `CMakeLists.txt`  | CMake build configuration                    |
| `CHANGELOG.md`    | Record of project changes                    |
| `CONTRIBUTING.md` | Contribution guidelines                      |
| `LICENSE`         | Project license                              |

## Design Goals

The project aims to provide a:

* Lightweight C implementation
* Modular architecture
* Easy-to-use public API
* Numerically careful implementation
* Well-tested foundation for complex analysis
* C17-compatible open-source library

The long-term goal is to expand beyond basic complex arithmetic into functionality useful for **complex analysis and mathematical computing**.

## Examples

Example programs demonstrating the library can be found in the [`examples/`](../examples) directory.

Current examples include:

* `basic_complex.c` — Basic Cartesian complex-number operations
* `polar_complex.c` — Polar representation and Cartesian/polar conversion
* `complex_roots.c` — Calculating and handling complex roots

These examples can be used as starting points for integrating the library into your own C projects.


## Contributing

Contributions, bug reports, suggestions, and improvements are welcome.

Before submitting a contribution:

1. Make sure the project builds successfully.
2. Run the existing test suite.
3. Add tests for new functionality.
4. Keep changes focused and consistent with the existing API.

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for contribution guidelines.

## License

This project is licensed under the **MIT License**.

See [`LICENSE`](LICENSE) for the full license text.
