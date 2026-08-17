/*
 * Program Name: 060_bitwise_even_odd.c
 * Question: Even/Odd using bitwise?
 * Reasoning: Checks LSB using & 1.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=4; printf((n&1)?"Odd\n":"Even\n");
    return 0;
}
