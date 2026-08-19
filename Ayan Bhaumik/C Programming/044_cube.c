/*
 * Program Name: 044_cube.c
 * Question: Calculate cube of number?
 * Reasoning: Multiplies number three times.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=3; printf("Cube: %d\n", n*n*n);
    return 0;
}
