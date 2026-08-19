/*
 * Program Name: 050_sizeof_int.c
 * Question: Size of integer?
 * Reasoning: Uses sizeof() operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    printf("Size of int: %zu bytes\n", sizeof(int));
    return 0;
}
