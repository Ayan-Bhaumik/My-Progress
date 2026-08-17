/*
 * Program Name: 046_power.c
 * Question: Calculate power (base^exp)?
 * Reasoning: Uses math.h pow().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    double base=2.0, exp=3.0; printf("Result: %.2f\n", pow(base, exp));
    return 0;
}
