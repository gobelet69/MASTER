// Exercice 19 : Count how many digits are in an input integer.

#include <stdio.h>

int main() {
    int myInt;
    int count = 0;
    scanf("%d", &myInt);
    do{
        myInt = myInt/10;
        printf("%d\n", myInt);
        count++;
    } while (myInt != 0);
    printf("%d\n", count);
    return 0;
}
