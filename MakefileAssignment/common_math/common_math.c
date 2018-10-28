#include "common_math.h"
#include <stdio.h>

double add (double a, double b){return b + a;}
double sub (double a, double b){return a - b;}
double mul (double a, double b){return a * b;}
double div (double a, double b){
    if (b == 0){
        printf("divide by zero not allowed\n");
        return 0;
    }
    return a / b;
}

double max (double a, double b){
    if(a > b) 
        return a;
    return b;
}

double min (double a, double b){
    if(a > b)
        return b ;
    return a;
}

