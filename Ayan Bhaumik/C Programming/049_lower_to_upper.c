/*
 * Program Name: 049_lower_to_upper.c
 * Question: Lowercase to uppercase?
 * Reasoning: Subtracts 32 from ASCII value.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char c="m"; printf("Upper: %c\n", c-32);
    return 0;
}
