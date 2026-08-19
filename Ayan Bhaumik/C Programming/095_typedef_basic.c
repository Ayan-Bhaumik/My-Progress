/*
 * Program Name: 095_typedef_basic.c
 * Question: Typedef alias creation?
 * Reasoning: Creates an alias for unsigned int.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    typedef unsigned int uint; uint age = 25; printf("Age: %u\n", age);
    return 0;
}
