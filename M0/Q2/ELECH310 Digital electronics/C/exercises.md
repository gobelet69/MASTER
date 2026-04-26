# C Programming Exercises (1–100)

1. Write a C program that prints `Hello, C world!` on one line.
2. Declare an `int` variable, assign it a value, and print it with `printf`.
3. Declare `char`, `int`, and `float` variables and print all of them with correct format specifiers.
4. Write a program that reads an integer using `scanf` and echoes it.
5. Read two integers and print their sum, difference, product, and integer quotient.
6. Read one character with `scanf("%c", ...)` and print it.
7. Read one character with `getchar()` and print it with `putchar()`.
8. Print the return value of `printf` for a short output string.
9. Write a program that checks if an input character is a vowel using `if/else`.
10. Rewrite Exercise 9 using `switch`.

11. Read an integer and print whether it is positive, negative, or zero.
12. Read two integers and print the larger one.
13. Read three integers and print the maximum.
14. Write a `for` loop that prints numbers from 1 to 20.
15. Write a `while` loop that prints even numbers from 2 to 40.
16. Compute the sum of integers from 1 to `n`.
17. Compute `n!` iteratively.
18. Print a multiplication table for numbers 1 through 10.
19. Count how many digits are in an input integer.
20. Reverse the digits of an input integer.

21. Write a function `int square(int x)` and call it from `main`.
22. Write a function `int max2(int a, int b)`.
23. Write a function that returns 1 if an integer is even, otherwise 0.
24. Write a function that takes no arguments and prints a fixed message.
25. Write a function that takes two integers and returns their GCD.
26. Write a recursive function to compute factorial.
27. Write a recursive function to compute Fibonacci(`n`).
28. Write a recursive function that computes `x^n`.
29. Split a program into at least two user-defined functions and call them from `main`.
30. Time a function call using `clock()` and print elapsed time in seconds.

31. Declare an integer array of size 10 and initialize it with values 1..10.
32. Read 10 integers into an array and print them in order.
33. Read 10 integers into an array and print them in reverse order.
34. Compute the average of values in an integer array.
35. Find the minimum and maximum element of an array.
36. Count occurrences of a target value in an array.
37. Compute the sum of all odd values in an array.
38. Copy one array into another using a loop.
39. Compare two arrays and print whether they are identical.
40. Shift all array elements one position to the right.

41. Build a frequency table for values in range 0..255 using an array of 256 counters.
42. For a static array, print each distinct value and its frequency.
43. Sort an integer array in ascending order using nested loops.
44. Sort an integer array in descending order.
45. Remove duplicates from an array and print the unique values.
46. Merge two sorted arrays into one sorted array.
47. Find the second largest value in an array.
48. Rotate an array left by `k` positions.
49. Implement linear search and print the found index or `-1`.
50. Count inversions in a small array using two nested loops.

51. Declare a 2D array `int m[3][4]` and initialize it.
52. Read a 3x3 matrix and print it row by row.
53. Compute the sum of each row in a 2D array.
54. Compute the sum of each column in a 2D array.
55. Compute the trace of a square matrix.
56. Add two matrices of equal dimensions.
57. Subtract two matrices of equal dimensions.
58. Multiply two matrices after validating dimensions.
59. Store a 2D matrix in a 1D array and access element `(i, j)` via index formula.
60. Transpose a matrix.

61. Declare an `int` variable and an `int*` pointer that stores its address.
62. Print the address of a variable and the value through its pointer.
63. Show that pointers themselves have addresses by printing `&p`.
64. Assign one pointer to another and explain observed printed values.
65. Write a function that changes an integer by receiving `int*`.
66. Swap two integers using a function with pointer parameters.
67. Write a function that fills an array passed as pointer argument.
68. Write a function that computes array average using pointer traversal.
69. Demonstrate safe use of `NULL` before dereferencing a pointer.
70. Write a function that returns a pointer to the largest element in an array.

71. Dynamically allocate an integer array of size `n` with `malloc`.
72. Check `malloc` return value and terminate with an error message if allocation fails.
73. Fill a dynamically allocated array and print all values.
74. Compute average of a dynamically allocated array.
75. Allocate memory for a dynamic character buffer and read a short string.
76. Dynamically allocate two integer arrays, copy one into the other, then free both.
77. Allocate a dynamic array, sort it, print it, and free it.
78. Create and free a dynamic 2D matrix using a flat 1D allocation.
79. Write a program that intentionally leaks memory, then fix it.
80. Write a program that demonstrates why using memory after `free` is dangerous (without crashing intentionally).

81. Define a `struct fraction` with numerator and denominator.
82. Read two fractions and print them.
83. Add two fractions and print non-simplified result.
84. Subtract two fractions and print non-simplified result.
85. Multiply and divide two fractions.
86. Implement a function to simplify a fraction using GCD.
87. Compare two fractions and print which is larger.
88. Demonstrate struct assignment by copying one struct to another.
89. Declare a pointer to struct and access fields with `->`.
90. Dynamically allocate a struct fraction, assign fields, print, and free it.

91. Use `typedef` to create an alias for a struct and rewrite Exercise 81 with the alias.
92. Build an array of structs and print all records.
93. Pass a struct by value to a function and print fields inside function.
94. Pass a struct by pointer to a function and modify one field.
95. Write a program using `const` variable and show compiler-protected immutability.
96. Write a function with a `static` local variable that counts calls.
97. Benchmark two loop variants with `clock()` and compare execution times.
98. For input size `n`, implement an O(n) algorithm and an O(n²) algorithm and compare timing growth.
99. Write a polling loop that checks a flag and exits when it changes.
100. Simulate an interrupt-like event using a flag updated by a helper routine and process it in the main loop.
