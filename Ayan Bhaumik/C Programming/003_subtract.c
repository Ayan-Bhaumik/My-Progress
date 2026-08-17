/*
 * Program Name: 003_subtract.c
 * Question: How to subtract numbers?
 * Reasoning: Demonstrates the subtraction (-) operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=15, b=5; printf("Difference: %d\n", a-b);
    return 0;
}
