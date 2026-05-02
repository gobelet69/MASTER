// Exercice 15 : Write a while loop that prints even numbers from 2 to 40.

#include <stdio.h>


int main() {
    int i;
    for (i=2; i <= 40; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}