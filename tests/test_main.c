#include <stdio.h>
//#include <../test_helpers.h>

void test_complex_num(int*, int*);
void test_complex_polar(int*, int*);
void test_constants(int*,int*);
void test_conversion(int*, int*);
void test_utils(int*, int*);

int main(void)
{
    int pass = 0, fail = 0;
    printf("Running tests...\n");

    // Call your test functions here
    test_complex_num(&pass,&fail);
    test_complex_polar(&pass,&fail);
    test_constants(&pass,&fail);
    test_conversion(&pass, &fail);
    test_utils(&pass, &fail);

    printf("\n\nTOTAL TESTS: %d\nPASSED: %d\nFAILED: %d\n",pass+fail,pass,fail);

    return 0;
}
