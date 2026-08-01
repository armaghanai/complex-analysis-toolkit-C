cmake_minimum_required(VERSION 3.15)

project(
    complex-analysis-toolkit-c
    VERSION 0.1.0
    DESCRIPTION "A C library for complex numbers and complex analysis"
    LANGUAGES C
)

# --------------------------------------------------------------------
# C Standard
# --------------------------------------------------------------------

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# --------------------------------------------------------------------
# Library
# --------------------------------------------------------------------

add_library(cvt STATIC
    src/complex/complex_num.c
    src/complex/complex_polar.c
    src/complex/complex_conversion.c
    src/complex/complex_constants.c
)

target_include_directories(cvt
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Link the math library where required (Linux/MinGW)
target_link_libraries(cvt
    PUBLIC
        m
)

# --------------------------------------------------------------------
# Test Executable
# --------------------------------------------------------------------

add_executable(complex_tests
    tests/main.c
)

target_link_libraries(complex_tests
    PRIVATE
        cvt
)

# --------------------------------------------------------------------
# Example Executable
# --------------------------------------------------------------------

# Uncomment this once you create examples/basic.c
#
# add_executable(basic_example
#     examples/basic.c
# )
#
# target_link_libraries(basic_example
#     PRIVATE
#         cvt
# )

# --------------------------------------------------------------------
# Compiler Warnings
# --------------------------------------------------------------------

if(MSVC)
    target_compile_options(cvt PRIVATE /W4)
else()
    target_compile_options(cvt PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()