/*
 * Program Name: 012_cel_to_fah.c
 * Question: Convert Celsius to Fahrenheit?
 * Reasoning: Uses formula (C * 9/5) + 32.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float c=32.0; printf("Fahrenheit: %.2f\n", (c*9.0/5.0)+32);
    return 0;
}
