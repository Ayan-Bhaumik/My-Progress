/*
 * Program Name: 027_print_1_10.c
 * Question: Print numbers 1 to 10?
 * Reasoning: Demonstrates a basic for loop.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    for(int i=1; i<=10; i++) printf("%d ", i); printf("\n");
    return 0;
}
