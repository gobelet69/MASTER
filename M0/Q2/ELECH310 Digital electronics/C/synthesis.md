# C Programming Synthesis (ELECH310 Th01–Th04)

## 1) Why C matters and where it fits

C is a **general-purpose, compiled, strongly typed, low-level-ish language** designed to map efficiently to machine hardware while still supporting structured programming. In the course material, C is presented as a key language for:

- systems software (OS, drivers),
- performance-critical applications,
- embedded systems,
- and as a foundation for understanding what compilers/hardware actually do.

### Why this exists
C exists to give programmers control over memory and execution while preserving portability through standards (ANSI/ISO C).

### Best practices
- Prefer standard C constructs for portability.
- Avoid architecture-specific assumptions unless performance tuning requires it.
- Keep readability high (good naming, small functions, comments where needed).

---

## 2) Life cycle of a C program

Source code goes through:
1. **Preprocessing** (`#include`, `#define`, conditionals),
2. **Compilation** (to assembly/object),
3. **Assembling** (machine-level object code),
4. **Linking** (combining object files/libraries into executable).

### Why this matters
Understanding stages explains linker errors vs compiler errors, and why headers/libraries are required.

---

## 3) Program structure, functions, and headers

### `main` and function basics
A C program starts at `main`. Functions encapsulate logic for reuse and readability.

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    printf("%d\n", add(2, 3));
    return 0;
}
```

### Why functions exist
- Modular decomposition
- Reusability
- Testability
- Easier maintenance

### Pitfalls
- Missing prototypes can cause warnings/errors.
- Incorrect parameter types trigger undefined behavior.

---

## 4) Data types, variables, and formatting

Course examples use `int`, `char`, floating types, and show formatted I/O with `printf`/`scanf`.

- `%d` for `int`
- `%ld`, `%lld` for wider integer types
- `%f` for floating-point
- `%c` for characters
- `%s` for strings

### Important point
`scanf` needs **addresses** (use `&var`) except when passing arrays/strings already decayed to pointers.

```c
int x;
scanf("%d", &x);
```

### Pitfalls
- Wrong format specifier → undefined behavior.
- Forgetting `&` in `scanf` for scalar variables.
- Input buffering surprises with character reads.

---

## 5) Control flow: conditions and loops

### `if/else` and logical operators
Used for branching decisions:

```c
if (ch == 'a' || ch == 'A') {
    /* ... */
} else {
    /* ... */
}
```

### `switch`
Useful for many discrete value branches:

```c
switch (ch) {
    case 'a': case 'A':
        printf("vowel\n");
        break;
    default:
        printf("not vowel\n");
}
```

### Loops
`for`, `while`, and nested loops appear in array algorithms and matrix operations.

### Pitfalls
- Missing `break` in `switch` when fallthrough is unintended.
- Off-by-one errors in loops.
- Infinite loops due to wrong update condition.

---

## 6) Pointers (core concept)

A pointer stores a **memory address** of a typed object.

```c
int var = 20;
int *ip = &var;
printf("addr=%p val=%d\n", (void*)ip, *ip);
```

- `&x` gives address of `x`
- `*p` dereferences pointer `p`
- pointers themselves also have addresses (`&p`)

### Why pointers exist
- pass-by-reference behavior,
- dynamic memory,
- efficient data structure manipulation,
- low-level hardware/software interfacing.

### Critical pitfalls
- Uninitialized pointers
- Dangling pointers (after `free`)
- Null dereference
- Type mismatch in pointer arithmetic

### Best practices
- Initialize pointers (`NULL` or valid address).
- Validate before dereference.
- After `free(p)`, set `p = NULL`.

---

## 7) `NULL` pointer and safety checks

`NULL` denotes “points to no valid object”.

```c
int *ptr = NULL;
if (ptr == NULL) {
    /* handle error */
}
```

### Why this exists
Sentinel for invalid/unset pointer state.

---

## 8) Passing data to functions: value vs address

- Passing scalar by value copies data.
- To modify caller variable, pass pointer.

```c
void change_i(int *p) { *p = 42; }

int i = 5;
change_i(&i); // i becomes 42
```

### Variadic functions
Materials mention variable argument count (e.g., `printf`/`scanf`).

---

## 9) Arrays (1D and 2D)

### 1D arrays
Contiguous storage of same type.

```c
int a[100];
a[0] = 10;
```

### 2D arrays and linear indexing
For matrix-like data, index by row/column; if flattened, use formula:
`index = i + j * width` (or equivalent convention depending on layout definition).

### Why arrays exist
Efficient indexed collection storage.

### Pitfalls
- Out-of-bounds write/read (major source of bugs/security issues).
- Confusing row-major indexing in flattened arrays.

---

## 10) Example algorithmic patterns from the material

### Array input/output and average
Basic loops for reading and aggregating values.

### Matrix multiplication
Nested loops; dimension compatibility check (`C1 == R2`) before multiplication.

### Histogram/frequency counting
- Static or dynamic arrays for frequency bins.
- Choice of type should consider max count and value range.

### Sorting with nested loops
Simple O(n²) comparison/swap approach demonstrated.

### Complexity awareness
Big-O introduced:
- O(1), O(log n), O(n), O(n²), …

---

## 11) Dynamic memory allocation

Functions highlighted:
- `malloc`
- `free`

(implicitly related: `calloc`, `realloc` as common practice around same topic)

```c
int n = 10;
int *arr = (int*)malloc(n * sizeof(int));
if (arr == NULL) {
    /* no memory */
}
/* use arr */
free(arr);
arr = NULL;
```

### Why this exists
Allocate size known only at runtime.

### Pitfalls
- Memory leaks (`malloc` without `free`)
- Double free
- Use-after-free
- Allocating wrong size (`sizeof(pointer)` vs `sizeof(*pointer)`)

---

## 12) Structures (`struct`) and user-defined data

`struct` groups heterogeneous fields.

```c
struct fraction {
    int num;
    int den;
};
```

Access operators:
- `.` for structure variables
- `->` for structure pointers

```c
struct fraction f = {1, 2};
struct fraction *pf = &f;
printf("%d/%d\n", pf->num, pf->den);
```

### Copy behavior
- Direct struct assignment copies fields.
- If fields include pointers, assignment is shallow (pointer values copied, not pointed data).

### Best practices
- Normalize/validate fraction denominator.
- Encapsulate operations in helper functions.

---

## 13) Storage duration and memory regions

Material discusses stack behavior:
- Function-local variables live on stack frame.
- Freed automatically at function return.

Also discussed:
- `static` variables persist across calls.
- `register` as optimization hint.
- `const` values should not be modified.

### Why this matters
Choosing storage duration affects correctness, performance, and lifetime safety.

---

## 14) Standard I/O functions in practice

### `printf`
Formatted output to stdout; returns character count or negative on failure.

### `scanf`
Formatted input from stdin; returns number of successfully assigned items.

### `getchar`/`putchar` and `getc`/`putc`
Character-level I/O for standard streams and generic `FILE*` streams.

### Pitfalls
- `scanf("%c", &ch)` can read leftover newline.
- Ignoring return values can hide input errors.

---

## 15) Recursion and performance measurement

### Recursion
Example pattern: function calls itself with reduced problem until base case.

### Measuring time
Use `clock()` before/after code and compute elapsed CPU time.

```c
clock_t t0 = clock();
/* work */
clock_t t1 = clock();
double sec = (double)(t1 - t0) / CLOCKS_PER_SEC;
```

### Pitfalls
- Deep recursion can overflow stack.
- Microbenchmarks are noisy; run enough iterations and control optimization settings.

---

## 16) Pointers and data types (size and interpretation)

The material compares allocations for `unsigned char` vs `int` arrays to emphasize:
- element size impacts memory footprint,
- pointer type determines how memory is interpreted and stepped in arithmetic.

### Best practices
- Use fixed-width integer types when precision matters (`uint8_t`, `int32_t` etc., from `<stdint.h>`).
- Match format specifiers with actual types.

---

## 17) File access (topic introduced in Th02 agenda)

Even if details are lighter in visible excerpts, standard C file access typically includes:
- `fopen`, `fclose`
- `fprintf`, `fscanf`
- `fread`, `fwrite`
- `fgets`, `fputs`

### Core workflow
1. Open file.
2. Check handle for `NULL`.
3. Read/write.
4. Close file.

### Pitfalls
- Forgetting `fclose`
- Assuming reads always succeed
- Mode mismatch (`"r"`, `"w"`, `"a"`, binary variants)

---

## 18) Architecture context (Th04) and connection to C

Th04 expands beyond syntax into **computer architecture and embedded execution**:

- Von Neumann vs Harvard organization,
- memory hierarchy and cache,
- pipeline ideas,
- interrupt-driven execution,
- timer/counter peripherals,
- embedded platform blocks (PSoC/UDB/DFB-level overview).

### Why this matters for C programmers
C code behavior/performance depends on architecture:
- cache locality influences array-loop speed,
- ISR design affects latency and determinism,
- polling vs interrupts affects CPU utilization,
- timer registers/peripherals are often programmed via C in embedded systems.

### Embedded best practices from this context
- Keep ISRs short and deterministic.
- Use volatile for hardware-mapped registers/flags when needed.
- Prefer interrupt-driven design for rare asynchronous events.
- Understand response time budget (interrupt latency + ISR runtime).

---

## 19) Common mistakes checklist

- Dereferencing invalid pointer.
- Accessing arrays outside bounds.
- Forgetting to check `malloc` result.
- Memory leaks and double free.
- Wrong `printf`/`scanf` format.
- Passing value when address is required.
- Missing base case in recursion.
- Ignoring runtime complexity for larger inputs.

---

## 20) Practical study roadmap from these notes

1. Master syntax + I/O + control flow.
2. Practice arrays and function decomposition.
3. Internalize pointers (`&`, `*`, pointer-to-struct, pointer passing).
4. Build dynamic-memory discipline (`malloc`/`free` lifecycle).
5. Implement struct-based mini-projects.
6. Analyze complexity and timing (`clock`).
7. Connect C code decisions to CPU/memory/interrupt architecture.

This progression matches the course arc from language fundamentals to practical performance and embedded-system context.
