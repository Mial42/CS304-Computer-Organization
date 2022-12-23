#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void){
    //Signed mins and maxes
    printf("Char Min: %d\n", CHAR_MIN);
    printf("Char Max: %d\n",CHAR_MAX);
    printf("Short Min: %d\n",SHRT_MIN);
    printf("Short Max: %d\n",SHRT_MAX);
    printf("Int Min: %d\n",INT_MIN);
    printf("Int Max: %d\n",INT_MAX);
    printf("Long Min: %ld\n",LONG_MIN);
    printf("Long Max: %ld\n",LONG_MAX);
    //Unsigned maxes
    printf("UChar Max: %d\n",UCHAR_MAX);
    printf("UShort Max: %d\n",USHRT_MAX);
    printf("UInt Max: %d\n",UINT_MAX);
    printf("ULong Max: %d\n",ULONG_MAX);
    //Unsigned mins are all 0
    return 0;
}