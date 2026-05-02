#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Tableau contenant les 100 énoncés (les guillemets internes sont échappés)
    const char *exercices[] = {
        "Write a C program that prints Hello, C world! on one line.", // 1
        "Declare an int variable, assign it a value, and print it with printf.", // 2
        "Declare char, int, and float variables and print all of them with correct format specifiers.", // 3
        "Write a program that reads an integer using scanf and echoes it.", // 4
        "Read two integers and print their sum, difference, product, and integer quotient.", // 5
        "Read one character with scanf(\"%c\", ...) and print it.", // 6
        "Read one character with getchar() and print it with putchar().", // 7
        "Print the return value of printf for a short output string.", // 8
        "Write a program that checks if an input character is a vowel using if/else.", // 9
        "Rewrite Exercise 9 using switch.", // 10
        "Read an integer and print whether it is positive, negative, or zero.", // 11
        "Read two integers and print the larger one.", // 12
        "Read three integers and print the maximum.", // 13
        "Write a for loop that prints numbers from 1 to 20.", // 14
        "Write a while loop that prints even numbers from 2 to 40.", // 15
        "Compute the sum of integers from 1 to n.", // 16
        "Compute n! iteratively.", // 17
        "Print a multiplication table for numbers 1 through 10.", // 18
        "Count how many digits are in an input integer.", // 19
        "Reverse the digits of an input integer.", // 20
        "Write a function int square(int x) and call it from main.", // 21
        "Write a function int max2(int a, int b).", // 22
        "Write a function that returns 1 if an integer is even, otherwise 0.", // 23
        "Write a function that takes no arguments and prints a fixed message.", // 24
        "Write a function that takes two integers and returns their GCD.", // 25
        "Write a recursive function to compute factorial.", // 26
        "Write a recursive function to compute Fibonacci(n).", // 27
        "Write a recursive function that computes x^n.", // 28
        "Split a program into at least two user-defined functions and call them from main.", // 29
        "Time a function call using clock() and print elapsed time in seconds.", // 30
        "Declare an integer array of size 10 and initialize it with values 1..10.", // 31
        "Read 10 integers into an array and print them in order.", // 32
        "Read 10 integers into an array and print them in reverse order.", // 33
        "Compute the average of values in an integer array.", // 34
        "Find the minimum and maximum element of an array.", // 35
        "Count occurrences of a target value in an array.", // 36
        "Compute the sum of all odd values in an array.", // 37
        "Copy one array into another using a loop.", // 38
        "Compare two arrays and print whether they are identical.", // 39
        "Shift all array elements one position to the right.", // 40
        "Build a frequency table for values in range 0..255 using an array of 256 counters.", // 41
        "For a static array, print each distinct value and its frequency.", // 42
        "Sort an integer array in ascending order using nested loops.", // 43
        "Sort an integer array in descending order.", // 44
        "Remove duplicates from an array and print the unique values.", // 45
        "Merge two sorted arrays into one sorted array.", // 46
        "Find the second largest value in an array.", // 47
        "Rotate an array left by k positions.", // 48
        "Implement linear search and print the found index or -1.", // 49
        "Count inversions in a small array using two nested loops.", // 50
        "Declare a 2D array int m[3][4] and initialize it.", // 51
        "Read a 3x3 matrix and print it row by row.", // 52
        "Compute the sum of each row in a 2D array.", // 53
        "Compute the sum of each column in a 2D array.", // 54
        "Compute the trace of a square matrix.", // 55
        "Add two matrices of equal dimensions.", // 56
        "Subtract two matrices of equal dimensions.", // 57
        "Multiply two matrices after validating dimensions.", // 58
        "Store a 2D matrix in a 1D array and access element (i, j) via index formula.", // 59
        "Transpose a matrix.", // 60
        "Declare an int variable and an int* pointer that stores its address.", // 61
        "Print the address of a variable and the value through its pointer.", // 62
        "Show that pointers themselves have addresses by printing &p.", // 63
        "Assign one pointer to another and explain observed printed values.", // 64
        "Write a function that changes an integer by receiving int*.", // 65
        "Swap two integers using a function with pointer parameters.", // 66
        "Write a function that fills an array passed as pointer argument.", // 67
        "Write a function that computes array average using pointer traversal.", // 68
        "Demonstrate safe use of NULL before dereferencing a pointer.", // 69
        "Write a function that returns a pointer to the largest element in an array.", // 70
        "Dynamically allocate an integer array of size n with malloc.", // 71
        "Check malloc return value and terminate with an error message if allocation fails.", // 72
        "Fill a dynamically allocated array and print all values.", // 73
        "Compute average of a dynamically allocated array.", // 74
        "Allocate memory for a dynamic character buffer and read a short string.", // 75
        "Dynamically allocate two integer arrays, copy one into the other, then free both.", // 76
        "Allocate a dynamic array, sort it, print it, and free it.", // 77
        "Create and free a dynamic 2D matrix using a flat 1D allocation.", // 78
        "Write a program that intentionally leaks memory, then fix it.", // 79
        "Write a program that demonstrates why using memory after free is dangerous (without crashing intentionally).", // 80
        "Define a struct fraction with numerator and denominator.", // 81
        "Read two fractions and print them.", // 82
        "Add two fractions and print non-simplified result.", // 83
        "Subtract two fractions and print non-simplified result.", // 84
        "Multiply and divide two fractions.", // 85
        "Implement a function to simplify a fraction using GCD.", // 86
        "Compare two fractions and print which is larger.", // 87
        "Demonstrate struct assignment by copying one struct to another.", // 88
        "Declare a pointer to struct and access fields with ->.", // 89
        "Dynamically allocate a struct fraction, assign fields, print, and free it.", // 90
        "Use typedef to create an alias for a struct and rewrite Exercise 81 with the alias.", // 91
        "Build an array of structs and print all records.", // 92
        "Pass a struct by value to a function and print fields inside function.", // 93
        "Pass a struct by pointer to a function and modify one field.", // 94
        "Write a program using const variable and show compiler-protected immutability.", // 95
        "Write a function with a static local variable that counts calls.", // 96
        "Benchmark two loop variants with clock() and compare execution times.", // 97
        "For input size n, implement an O(n) algorithm and an O(n^2) algorithm and compare timing growth.", // 98
        "Write a polling loop that checks a flag and exits when it changes.", // 99
        "Simulate an interrupt-like event using a flag updated by a helper routine and process it in the main loop." // 100
    };

    // La consigne demande de commencer à l'exercice 11
    for (int i = 1; i <= 100; i++) {
        // Calcul du dossier cible (ex: pour 11 -> 11-20)
        int dir_start = ((i - 1) / 10) * 10 + 1;
        int dir_end = dir_start + 9;
        
        char dir_name[50];
        sprintf(dir_name, "%d-%d", dir_start, dir_end);

        // Création du dossier (0777 donne les droits de lecture/écriture)
        // Si le dossier existe déjà, mkdir renverra une erreur qu'on ignore silencieusement
        mkdir(dir_name, 0777);

        // Création du chemin complet du fichier
        char file_name[100];
        sprintf(file_name, "%s/%d.c", dir_name, i);

        // Ouverture et écriture dans le fichier
        FILE *file = fopen(file_name, "w");
        if (file == NULL) {
            printf("Erreur lors de la création du fichier %s\n", file_name);
            continue;
        }

        // Écriture du contenu
        fprintf(file, "// Exercice %d : %s\n\n", i, exercices[i - 1]);
        fprintf(file, "#include <stdio.h>\n\n");
        fprintf(file, "int main() {\n");
        fprintf(file, "    \n");
        fprintf(file, "    return 0;\n");
        fprintf(file, "}\n");

        fclose(file);
        printf("Créé : %s\n", file_name);
    }

    printf("\nTerminé ! Tous les dossiers et fichiers ont été générés avec succès.\n");
    return 0;
}