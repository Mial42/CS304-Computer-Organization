/*Author: Nicholas Wilson
Goal: Get inputs from the user with scanf, perform an operation, and print the results with printf
Method: Create three functions that each prompt the user with printf, then 
ask the user for the requisite information using scanf, perform an operation, and output the ansewer
*/
#include <stdio.h>
void scInts(void){
    //Prompt the user
    printf("Give two integers: ");
    int a, b;
    //Get inputs
    scanf("%d", &a);
    scanf("%d", &b);
    //Perform operation and output
    printf("You entered %d and %d, their sum is: %d\n", a, b, a+b);
}
void scFloats(void){
    //Prompt the user
    printf("Give two floats: ");
    float a, b;
    //Get inputs
    scanf("%f", &a);
    scanf("%f", &b);
    //Perform operation and output
    printf("You entered %f and %f, their product is: %f\n", a, b, a*b);
}
void scStr(void){
    //Prompt the user
    printf("Give a word: ");
    char str[100];
    //Get inputs
    scanf("%s", str);
    //Perform operation and output
    printf("%s %s\n", str, str);
}
int main(void){
    scInts();
    scFloats();
    scStr();
    return 0;
}