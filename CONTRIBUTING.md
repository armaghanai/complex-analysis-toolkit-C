# Contributing

Thank you for your interest in contributing to Complex Analysis Toolkit C.

Contributions are welcome, including bug fixes, tests, documentation improvements, examples, and new functionality.

## Before Contributing

Before making changes:

1. Check the existing issues and pull requests to avoid duplicating work.
2. Make sure you understand the existing project structure.
3. Keep changes focused on a specific feature or problem.

## Development Setup

The project requires:

* C17-compatible compiler
* CMake 3.15+
* Ninja
* Git
* Python 3.x for `gen_file.py`

Clone the repository:

```bash
git clone <repository-url>
cd complex-analysis-toolkit-c
```

Configure and build:

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

Run the tests:

```powershell
.\build\complex_tests.exe
```

Make sure all tests pass before submitting changes.

## Project Structure

```text
include/       Public header files
src/           Library implementations
tests/         Test suite
examples/      Example programs
docs/          Documentation
boilerplate/   Module templates
gen_file.py    File-generation utility
```

## Adding a New Module

When adding a new library component, create:

```text
include/complex/<module>.h
src/complex/<module>.c
tests/test_complex/test_<module>.c
```

You can use `gen_file.py` to generate these files automatically.

Alternatively, copy the templates from:

```text
boilerplate/
```

The project's CMake configuration automatically discovers source files, so new `.c` files do not normally need to be manually added to `CMakeLists.txt`.

## Writing Code

Keep new code consistent with the existing project.

### C Standard

Use **C17**.

### Naming

Follow the existing naming conventions for:

* Functions
* Types
* Constants
* Header files
* Source files

Public API names should use the existing `cvt_` / `complex_` naming conventions where appropriate.

### Headers

Public declarations belong in:

```text
include/
```

Implementations belong in:

```text
src/
```

If you are adding new functionality then you may add it in a new directory:

```text
include/fft
src/fft
test/test_fft
```

Avoid placing implementation details in public headers unless necessary.

## Testing

New functionality should include tests.

Tests use the project's custom testing framework rather than `<assert.h>` or a third-party testing framework.

Test:

* Normal cases
* Boundary cases
* Invalid inputs
* Zero
* Negative values
* NaN
* Infinity
* Floating-point precision where applicable
* Dynamic-memory failure cases where applicable

Use the existing:

```c
ASSERT(expr, pass, fail)
```

and appropriate `ASSERT_F` cases.

Run the complete test suite before submitting a pull request.

## Documentation

If you add or modify public functionality, update the relevant documentation.

Depending on the change, this may include:

* `docs/api.md`
* `docs/getting_started.md`
* `README.md`
* Example programs
* `CHANGELOG.md`

## Examples

New functionality that is particularly useful for users may also include an example in:

```text
examples/
```

Examples should be small and demonstrate practical use of the API.

## Commit Guidelines

Keep commits focused and descriptive.

Good:

```text
Add complex logarithm implementation
```

```text
Add tests for complex division
```

```text
Fix principal argument conversion
```

Avoid vague messages such as:

```text
update
```

```text
stuff
```

```text
changes
```

## Pull Requests

When submitting a pull request:

1. Describe what was changed.
2. Explain why the change is needed.
3. Include tests for new functionality.
4. Make sure the existing test suite passes.
5. Update documentation when necessary.
6. Keep unrelated changes out of the pull request.

## Bug Reports

When reporting a bug, include:

* A description of the problem
* Expected behavior
* Actual behavior
* Steps to reproduce the issue
* Relevant code or input
* Compiler and operating-system information
* Build configuration, if relevant

A minimal reproducible example is especially helpful.

## Code of Conduct

Please be respectful and constructive when participating in the project.

Contributors are expected to communicate professionally and focus discussions on improving the project.

## License

By contributing to this project, you agree that your contributions will be licensed under the project's [MIT License](../LICENSE).

