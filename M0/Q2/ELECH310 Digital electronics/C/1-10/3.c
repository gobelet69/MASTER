#include <stdio.h>

int myInt = 67;
char myChar = 'S';
float myFloat = 6.79;

int main() {
    printf("%d\n", myInt);
    printf("%c\n", myChar);
    printf("%f\n", myFloat);
    printf("myChar is %c, my int is %d and my float is %f", myChar, myInt, myFloat);
    return 0;
}
