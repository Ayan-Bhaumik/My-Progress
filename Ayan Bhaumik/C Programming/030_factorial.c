/*
 * Program Name: 030_factorial.c
 * Question: Find factorial of a number?
 * Reasoning: Iterative multiplication.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=5, fact=1; for(int i=1; i<=n; i++) fact*=i; printf("Factorial: %d\n", fact);
    return 0;
}
