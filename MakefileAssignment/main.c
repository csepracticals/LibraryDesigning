#include "common_math/common_math.h"
#include "complex_math/complex_math.h"
#include "trig_math/trig_math.h"
#include <stdio.h>

int main(int argc, char **argv){
    double res, a = 45.0, b = 90.0;
    complex_n_t cres, ca,cb;
    res = a + b;
    printf("two numbers added = %f\n", res);
    printf("sine of %f = %f\n", a, sine(a));
    ca.re = 1.0, ca.imag = 2.0;
    cb.re = 2.0, cb.imag = 3.0;
    cres = cadd(ca, cb);
    printf("adding two complex numbers : %f + %f\n", cres.re, cres.imag);


    return 0;
}
