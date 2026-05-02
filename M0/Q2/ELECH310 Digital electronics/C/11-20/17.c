// Exercice 17 : Compute n! iteratively.

#include <stdio.h>

// int mult(int a, int b) {
//     return(a*b);
// }
int n;
int main() {
    int nfact = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        nfact = nfact*i;
        printf("%d", nfact);
    }
    
    return 0;
}

// N*lastN
