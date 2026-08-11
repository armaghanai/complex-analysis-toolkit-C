# Getting Started

This guide walks through building Complex Analysis Toolkit C and using it in a simple C program.

## Prerequisites

Make sure the following are installed:

* C compiler with C17 support
* CMake 3.15 or newer
* Ninja
* Git

The project is currently developed and tested with GCC through MinGW/UCRT64 on Windows.

## Clone the Repository

Clone the repository and enter the project directory:

```bash
git clone <repository-url>
cd complex-analysis-toolkit-c
```

## Build the Library

Create a build directory and configure the project with CMake:

```bash
cmake -S . -B build -G Ninja
```

Build the project:

```bash
cmake --build build
```

The build produces the library and test executable inside the `build` directory.

## Run the Tests

Run the test executable after building.

On Windows PowerShell:

```powershell
.\build\complex_tests.exe
```

The test suite reports the number of passed and failed tests.

A successful run should end with:

```text
Passed: ...
Failed: 0
```

## Using the Library

The public headers are located in:

```text
include/complex/
```

For example:

```c
#include <complex/complex_num.h>
#include <complex/complex_constants.h>
```

Create a complex number:

```c
cvt_complex z = create_complex(3.0, 4.0);
```

Calculate its modulus:

```c
double modulus = cvt_modulus(z);
```

Calculate its argument:

```c
double argument = cvt_argument(z);
```

Perform arithmetic:

```c
cvt_complex z1 = create_complex(2.0, 3.0);
cvt_complex z2 = create_complex(1.0, 4.0);

cvt_complex sum = complex_add(z1, z2);
cvt_complex product = complex_multiply(z1, z2);
```

## Using Polar Representation

Include the polar header:

```c
#include <complex/complex_polar.h>
```

Create a polar complex number:

```c
cvt_complex_polar z =
    create_complex_polar(2.0, PI_BY_FOUR);
```

Polar numbers use the representation:

[
z = re^{i\theta}
]

where `modulus` represents (r) and `argument` represents (\theta).

For example:

```c
cvt_complex_polar z =
    create_complex_polar(1.0, PI_BY_TWO);
```

represents:

[
i
]

## Converting Between Representations

Include:

```c
#include <complex/complex_conversion.h>
```

Convert polar to Cartesian:

```c
cvt_complex_polar polar =
    create_complex_polar(2.0, PI_BY_FOUR);

cvt_complex cartesian =
    create_complex_from_polar(polar);
```

Convert Cartesian to polar:

```c
cvt_complex cartesian =
    create_complex(3.0, 4.0);

cvt_complex_polar polar =
    create_complex_polar_from_cartesian(cartesian);
```

## Calculating Complex Roots

The library can calculate all `n` roots of a polar complex number.

```c
#include <stdlib.h>
#include <complex/complex_polar.h>

cvt_complex_polar z =
    create_complex_polar(1.0, 0.0);

cvt_complex_polar *roots =
    complex_roots(z, 4);
```

The result contains four roots.

Always check the returned pointer before using it:

```c
if (roots != NULL) {
    for (int i = 0; i < 4; i++) {
        display_complex_polar(roots[i]);
    }

    free(roots);
}
```

`complex_roots()` returns `NULL` when the requested power is less than or equal to zero or when memory allocation fails.

## Creating New Library Modules

The project provides two ways to create new modules.

### Using `gen_file.py`

`gen_file.py` can generate the files needed for a new module:

* Header file
* Source file
* Test file

This is the preferred method when adding a new component because it automatically follows the project's file structure and naming conventions.

Run:

```bash
python gen_file.py
```

Follow the prompts provided by the script.

### Using the Boilerplate Files

Reusable templates are also available in:

```text
boilerplate/
```

The directory contains:

```text
boilerplate/
├── boilerplate.h
├── boilerplate.c
└── test_boilerplate.c
```

These files can be copied and adapted when creating a new module manually.

## Project Structure

The main directories are:

```text
include/       Public header files
src/           Library implementations
tests/         Test suite
examples/      Example programs
docs/          Documentation
boilerplate/   Module templates
```

The `build/` directory contains generated CMake/Ninja build files and compiled binaries and is not part of the library source code.

## Next Steps

After completing the basic setup, see:

* [`api.md`](api.md) — Complete API reference
* [`CONTRIBUTING.md`](../CONTRIBUTING.md) — Contribution guidelines
* [`CHANGELOG.md`](../CHANGELOG.md) — Project changes
- `examples/` — Example programs demonstrating the library
