//
// Created by Theo Deville on 5/2/26.
//Write a program that checks if an input character is a vowel using if/else

#include <stdio.h>
int main() {
    char myChar;
    scanf("%c", &myChar);

    if (myChar == 'A' || myChar == 'E' || myChar == 'I' || myChar == 'O' || myChar == 'U') {
        printf("%c is vowel", myChar);
    }
    else {
        printf("%c is consonant", myChar);
    }

}