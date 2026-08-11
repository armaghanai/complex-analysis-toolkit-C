# Changelog

All notable changes to Complex Analysis Toolkit C are documented in this file.

## [0.1.0] - 2026-08-11

Initial public release.

### Added

#### Complex Numbers

* Cartesian complex number representation using `cvt_complex`
* Complex number creation and comparison
* Complex addition and subtraction
* Scalar and complex multiplication
* Complex division and reciprocal
* Complex conjugate
* Modulus and argument calculation
* Purely real and purely imaginary checks
* Complex number string parsing
* Complex number display

#### Polar Complex Numbers

* Polar complex number representation using `cvt_complex_polar`
* Polar complex number creation and comparison
* Polar string parsing
* Complex multiplication and division in polar form
* Complex conjugation
* Complex squaring
* Integer powers
* Calculation of all complex roots
* Polar complex number display

#### Conversions

* Cartesian to polar conversion
* Polar to Cartesian conversion

#### Constants

* Zero, one, and imaginary unit constants
* NaN and infinity constants
* Polar equivalents of common constants
* Mathematical constants including π, 2π, π/2, π/4, and Euler's number
* Floating-point comparison tolerance

#### Utilities

* Zero-value checking
* Principal argument conversion
* Argument multiplication
* Nearly-equal floating-point comparison

#### Build System

* C17 support
* CMake build system
* Ninja build support
* Automatic source and test file discovery

#### Testing

* Custom lightweight testing framework
* Tests for complex numbers
* Tests for polar complex numbers
* Tests for conversions
* Tests for constants
* Tests for utility functions
* Edge-case testing including zero, negative values, NaN, infinity, and invalid inputs

#### Documentation

* API documentation
* Getting started guide
* Example programs
* Contribution guidelines

#### Development Tools

* `gen_file.py` for generating new header, source, and test files
* Boilerplate templates for new modules
