#include <stdio.h>
#include <stdlib.h>

#include <complex/complex_polar.h>

int main(void)
{
    cvt_complex_polar z =
        create_complex_polar(1.0, 0.0);

    int power = 4;

    cvt_complex_polar *roots =
        complex_roots(z, power);

    if (roots == NULL)
    {
        printf("Failed to calculate roots.\n");
        return 1;
    }

    printf("Fourth roots of 1:\n");

    for (int i = 0; i < power; i++)
    {
        display_complex_polar(roots[i]);
    }

    free(roots);
    //must free the memory to prevent memory leak

    return 0;
}