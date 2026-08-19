/*
 * Program Name: 002_add.c
 * Question: How to add two integers?
 * Reasoning: Demonstrates the addition (+) operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=5, b=10; printf("Sum: %d\n", a+b);
    return 0;
}
