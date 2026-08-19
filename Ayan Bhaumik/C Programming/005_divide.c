/*
 * Program Name: 005_divide.c
 * Question: How to perform division?
 * Reasoning: Demonstrates the division (/) operator with floats.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float a=20.0, b=4.0; printf("Quotient: %.2f\n", a/b);
    return 0;
}
