//Read two integers and print their sum, difference, product, and integer quotient.

#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int myInt1;
    int myInt2;
    printf("entrez deux int");
    scanf("%d", &myInt1);
    printf("entrez deux int");
    scanf("%d", &myInt2);

    int mySum2 = myInt1 + myInt2;
    int mySum = sum(myInt1, myInt2);
    printf("sum = %d\n", mySum2);
    return 0;
}

