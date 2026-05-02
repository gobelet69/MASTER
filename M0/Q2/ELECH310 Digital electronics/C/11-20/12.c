// Exercice 12 : Read two integers and print the larger one.

#include <stdio.h>

int main() {
    int myInt1;
    int myInt2;
    scanf("%d", &myInt1);
    scanf("%d", &myInt2);

    if (myInt1 > myInt2) {
        printf("%d\n", myInt1);
    }
    else {
        printf("%d\n", myInt2);
    }
    return 0;
}