/*
 * Program Name: 013_fah_to_cel.c
 * Question: Convert Fahrenheit to Celsius?
 * Reasoning: Uses formula (F - 32) * 5/9.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float f=90.0; printf("Celsius: %.2f\n", (f-32)*5.0/9.0);
    return 0;
}
