#include <stdio.h>

#include <complex/complex_num.h>

int main(void)
{
    cvt_complex z1 = create_complex(3.0, 4.0);
    cvt_complex z2 = create_complex(1.0, 2.0);

    cvt_complex sum = cvt_add(z1, z2);
    cvt_complex product = cvt_multiply(z1, z2);

    printf("z1 = ");
    display_complex(z1);

    printf("z2 = ");
    display_complex(z2);

    printf("z1 + z2 = ");
    display_complex(sum);

    printf("z1 * z2 = ");
    display_complex(product);

    printf("|z1| = %f\n", cvt_modulus(z1));
    printf("arg(z1) = %f\n", cvt_argument(z1));

    return 0;
}