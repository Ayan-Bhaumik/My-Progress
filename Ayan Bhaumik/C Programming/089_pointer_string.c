/*
 * Program Name: 089_pointer_string.c
 * Question: Print string via pointer?
 * Reasoning: Iterates char pointer.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char *str = "Pointer String"; while(*str) { printf("%c", *str); str++; } printf("\n");
    return 0;
}
