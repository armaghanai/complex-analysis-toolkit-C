#include <stdio.h>
#include <complex/complex_func.h>
#include "../test_helpers.h"
#include <stdio.h>

void test_complex_func(int* total_pass, int* total_fail)
{
    int pass = 0, fail = 0;
    printf("Testing complex_func\n");

    printf("\nTotal Tests: %d\n",pass+fail);
    *total_pass += pass;
    *total_fail += fail;

    return 0;
}
