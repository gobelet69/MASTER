// Exercice 11 : Read an integer and print whether it is positive, negative, or zero.
#include <stdio.h>

int main() {
    int myInt;

    // Read the integer
    scanf("%d", &myInt);

    // Check conditions using if-else
    if (myInt > 0) {
        printf("Positive\n");
    } else if (myInt < 0) {
        printf("Negative\n");
    } else {
        printf("Zero\n");
    }

    return 0;
}
