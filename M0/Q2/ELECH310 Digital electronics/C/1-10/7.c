//
// Created by Theo Deville on 5/2/26.
//Read one character with getchar() and print it with putchar()


#include <stdio.h>
int main() {
    char a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();
    putchar(a);
    putchar(b);
    putchar('\n');
    putchar(c);
}