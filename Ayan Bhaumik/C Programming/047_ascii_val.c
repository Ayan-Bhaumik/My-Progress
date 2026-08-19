/*
 * Program Name: 047_ascii_val.c
 * Question: Print ASCII value of char?
 * Reasoning: Casts char to int.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char c="A"; printf("ASCII: %d\n", c);
    return 0;
}
