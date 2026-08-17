/*
 * Program Name: 087_pointer_swap.c
 * Question: Swap using pointers?
 * Reasoning: Passes addresses to helper.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=5, b=9; swap_ptrs(&a, &b); printf("a=%d, b=%d\n", a, b);
    return 0;
}
