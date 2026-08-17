/*
 * Program Name: 014_simple_interest.c
 * Question: Calculate simple interest?
 * Reasoning: Uses formula (P*R*T)/100.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float p=1000, r=5.0, t=2; printf("Interest: %.2f\n", (p*r*t)/100);
    return 0;
}
