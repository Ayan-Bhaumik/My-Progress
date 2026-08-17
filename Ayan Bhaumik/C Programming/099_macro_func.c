/*
 * Program Name: 099_macro_func.c
 * Question: Macro function?
 * Reasoning: Uses macro with arguments.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    #define SQUARE(x) ((x)*(x))
    printf("Square of 4: %d\n", SQUARE(4));
    return 0;
}
