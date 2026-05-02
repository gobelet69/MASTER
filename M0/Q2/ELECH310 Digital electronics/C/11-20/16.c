// Exercice 16 : Compute the sum of integers from 1 to n.

#include <stdio.h>

// int sumfct(int a, int b) {
//     return a + b;
// };

int main() {
    int myInt;
    int total = 0;
    scanf("%d", &myInt);
    for (int i = 1; i <= myInt; i++) {
        total += i;

    }
    printf("%d", total);
    return 0;
}
