/*
Author: Nicholas Wilson
Goal: Encode messages according to certain rules
Method: Read in the messages from a file, perform the requisite operations on them, then
output the resulting encoded messages to another file
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*Functions takes the whole line, the start of the word, and the length of the word.
Reverses the word and inserts it back into the whole line.
*/
void reverseWord(char mline[], int start, int length){
    if(length == 0){ //For multiple nonalpha characters in sequence
        return;
    }
    char word[length]; //Temporary array representing the word
    char *wordptr = word;
    char *ptr = mline + start;
    char *newptr = word+length-1;
    //Copy over the word to the temporary array
    int i;
    for(i = 0; i < length; i++){
        *wordptr = *ptr;
        wordptr++;
        ptr++;
    }

    char *revptr = mline + start;
    for(i = start; i < start + length; i++){
        *revptr = *newptr;
        newptr--;
        revptr++;
    }
}
//Reverses the words in the input char array
void reverseWords(char mline[]){
    char *ptr = mline; //Set the pointer to the first element of the array
    int length = 0; //Length of the word
    int start = 0; //Index of the character before the first letter of the word
    int i;
    for(i = 0; i < strlen(mline); i++){

        if(!isalpha(*ptr) && *ptr != '\0'){ //If the character is not a letter, cut off the temporary array, reverse it, 
        //and add it back in 
            reverseWord(mline, start, length);
            length = 0;
            start = i+1;
        }
        else{ //If the character is a letter, add it to the temporary array
            length++;
        }
        ptr++;
    }
}

//Removes the underscores in the input char array
//And turns the letters to upper case
void removeUnderscoresToUpperCase(char mline[]){
    char *ptr = mline; //Set the pointer to the first element of the array
    //Loop through the array, turning letters uppercase and
    //underscores to spaces
    for(int i = 0; i < strlen(mline); i++){
        if(isalpha(*ptr)){
            *ptr = toupper(*ptr);
        }
        if(*ptr == '_'){
            *ptr = ' ';
        }
        ptr++;
    }
}
int main(void){
    //Set up the input and output file streams
    FILE *input = fopen("lab1p3in.txt", "r");
    FILE *output = fopen("lab1p3out.txt", "w");
    char line[100]; 
    //Loop through the whole input file
    //Get the next line of the file and put it in the line[] array
    while(fgets(line, sizeof(line), input) != NULL){  
        //Encode the line appropriately
        reverseWords(line);
        removeUnderscoresToUpperCase(line);
        //Send the encoded message to the output file
        fputs(line, output);
    }
    fclose(input);
    fclose(output);
    return 0;
}