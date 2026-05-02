// Exercice 18 : Print a multiplication table for numbers 1 through 10.

#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int mult = (i * j);
            printf("%d * %d = %d\n", i, j,mult);
        }
    }
    return 0;
}
