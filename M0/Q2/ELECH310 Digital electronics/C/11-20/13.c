// Exercice 13 : Read three integers and print the maximum.

#include <stdio.h>

int main() {
    int myInt1, myInt2, myInt3;
    scanf("%d %d %d", &myInt1, &myInt2, &myInt3);

    if (myInt1 > myInt2) {
        if (myInt1 > myInt3) {
            printf("%d", myInt1);
        }
        else {
            printf("%d", myInt3);
        }

    }
    else if (myInt2 > myInt3) {
        printf("%d", myInt2);
    }
    else {
        printf("%d", myInt3);
    }


    return 0;
}
