/*
 * Program Name: 023_max_three.c
 * Question: Find max of three numbers?
 * Reasoning: Uses nested ternary operators.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=5, b=9, c=2; printf("Max: %d\n", (a>b)?((a>c)?a:c):((b>c)?b:c));
    return 0;
}
