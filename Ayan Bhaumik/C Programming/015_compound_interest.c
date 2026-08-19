/*
 * Program Name: 015_compound_interest.c
 * Question: Calculate compound interest?
 * Reasoning: Uses math.h pow() function.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float p=1000, r=5.0, t=2; printf("CI: %.2f\n", p*pow((1+r/100), t)-p);
    return 0;
}
