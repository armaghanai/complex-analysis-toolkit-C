cmake_minimum_required(VERSION 3.15)

project(libcvt LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(cvt STATIC
    src/cvt/complex.c
)

target_include_directories(cvt
    PUBLIC
        include
)

add_executable(basic_example
    examples/basic.c
)

target_link_libraries(basic_example
    PRIVATE
        cvt
)