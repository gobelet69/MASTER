//
// Created by Theo Deville on 5/2/26.
//Rewrite Exercise 9 using switch.

#include <stdio.h>
int main() {
    char myChar;
    scanf("%c", &myChar);
    switch (myChar) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("vowel");
            break;
        default:
            printf("consonant");
            break;
    }
    // switch (myChar) {
    //     case 'A':
    //         printf("vowel");
    //         break;
    //     case 'E':
    //         printf("vowel");
    //         break;
    //     case 'I':
    //         printf("vowel");
    //         break;
    //     case 'O':
    //         printf("vowel");
    //         break;
    //     case 'U':
    //         printf("vowel");
    //         break;
    //     default:
    //         printf("consonant");
    //         break;
    // }

    return 0;
}
