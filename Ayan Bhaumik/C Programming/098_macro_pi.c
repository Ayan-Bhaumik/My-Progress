/*
 * Program Name: 098_macro_pi.c
 * Question: Define and use macro?
 * Reasoning: Uses #define for constants.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    #define PI 3.14159
    printf("PI is %.5f\n", PI);
    return 0;
}
