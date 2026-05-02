// Exercice 20 : Reverse the digits of an input integer.

#include <stdio.h>

int main() {
    int myInt, inverse = 0, chiffre_extrait = 0;
    scanf("%d", &myInt);

    while (myInt != 0) {
        chiffre_extrait = myInt%10;
        myInt = myInt/10;
        inverse = (inverse * 10) + chiffre_extrait;
    }
    printf("%d\n", inverse);
    return 0;
}
