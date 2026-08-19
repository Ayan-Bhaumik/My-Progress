/*
 * Program Name: 045_sqrt.c
 * Question: Find square root?
 * Reasoning: Uses math.h sqrt().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    double n=16.0; printf("Sqrt: %.2f\n", sqrt(n));
    return 0;
}
