#include "complex_math.h"
complex_n_t cadd(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re + b.re;
    res.imag = a.imag + b.imag;
    return res;
}


complex_n_t csub(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re - b.re;
    res.imag = a.imag - b.imag;
    return res;
}

