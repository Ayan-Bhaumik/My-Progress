/*
 * Program Name: 100_recursion.c
 * Question: Calculate factorial (recursion)?
 * Reasoning: Calls custom recursive function.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int result = factorial_recursive(5); printf("Factorial of 5 is %d\n", result);
    return 0;
}
