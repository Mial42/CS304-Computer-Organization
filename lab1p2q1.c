/*
Author: Nicholas Wilson
Goal: Print out a series of statements using the printf function involving various data types
Method: Create three functions that each print one of the required statements with the requisite
data types
*/
#include <stdio.h>
void printString(void){
    printf("One half is 50%%\n");
}
void printInts(int a, int b){
    printf("The difference between %d and %d is %d\n", a, b, a-b);
}
void printFloats(float a, float b){
    printf("%f / %f is %f\n", a, b, a/b);
}
int main(void){
    printString();
    printInts(10, 3);
    printFloats(1.0, 3.0);
    // printf("\n");
    return 0;
}