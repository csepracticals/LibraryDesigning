#include <stdio.h>
#include <stdlib.h>

#define ITERATE_ARRAY_BEGIN(arrptr, array_size, start_index, scansize, out_index)    \
{                                                   \
    unsigned int _i = 0, next = 0;                  \
    out_index = start_index;                        \
    for( ; _i < scansize; _i++, out_index = next) {  \
        if(out_index == array_size -1)              \
            next = 0 ;                              \
        else                                        \
            next = out_index +1;

#define ITERATE_ARRAY_END   }}

int 
main(int argc, char **argv){

/*Problem 1  : */
    unsigned int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    unsigned int i;

    ITERATE_ARRAY_BEGIN(arr, 10, 5, 10, i){
        printf("arr[%u] = %u\n", i, arr[i]);
    } ITERATE_ARRAY_END;
    
    return 0;
}
