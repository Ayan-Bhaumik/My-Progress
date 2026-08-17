/*
 * Program Name: 048_upper_to_lower.c
 * Question: Uppercase to lowercase?
 * Reasoning: Adds 32 to ASCII value.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char c="G"; printf("Lower: %c\n", c+32);
    return 0;
}
