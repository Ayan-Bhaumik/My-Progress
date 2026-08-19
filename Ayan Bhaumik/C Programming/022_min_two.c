/*
 * Program Name: 022_min_two.c
 * Question: Find min of two numbers?
 * Reasoning: Uses ternary operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=10, b=20; printf("Min: %d\n", (a<b)?a:b);
    return 0;
}
