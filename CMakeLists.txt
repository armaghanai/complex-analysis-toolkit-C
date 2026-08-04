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
# Collect Source Files
# --------------------------------------------------------------------

file(GLOB_RECURSE COMPLEX_ANALYSIS_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

# --------------------------------------------------------------------
# Library
# --------------------------------------------------------------------

add_library(complex_analysis STATIC
    ${COMPLEX_ANALYSIS_SOURCES}
)

target_include_directories(complex_analysis
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(complex_analysis
    PUBLIC
        m
)

# --------------------------------------------------------------------
# Collect Test Files
# --------------------------------------------------------------------

file(GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/tests/*.c"
)

if(TEST_SOURCES)

    add_executable(complex_tests
        ${TEST_SOURCES}
    )

    target_link_libraries(complex_tests
        PRIVATE
            complex_analysis
    )

endif()

# --------------------------------------------------------------------
# Collect Example Files
# --------------------------------------------------------------------

file(GLOB
    EXAMPLE_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/examples/*.c"
)

foreach(example ${EXAMPLE_SOURCES})

    get_filename_component(example_name ${example} NAME_WE)

    add_executable(${example_name}
        ${example}
    )

    target_link_libraries(${example_name}
        PRIVATE
            complex_analysis
    )

endforeach()

# --------------------------------------------------------------------
# Compiler Warnings
# --------------------------------------------------------------------

if(MSVC)

    target_compile_options(complex_analysis PRIVATE /W4)

else()

    target_compile_options(complex_analysis PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

endif()