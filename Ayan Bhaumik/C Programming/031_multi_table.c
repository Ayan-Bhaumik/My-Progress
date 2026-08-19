/*
 * Program Name: 031_multi_table.c
 * Question: Print multiplication table?
 * Reasoning: Loops 1 to 10 for a specific number.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=5; for(int i=1; i<=10; i++) printf("%d x %d = %d\n", n, i, n*i);
    return 0;
}
