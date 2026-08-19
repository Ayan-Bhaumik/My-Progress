/*
 * Program Name: 090_pointer_to_pointer.c
 * Question: Pointer to a pointer?
 * Reasoning: Uses ** for double indirection.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=5; int *p=&n; int **pp=&p; printf("Value: %d\n", **pp);
    return 0;
}
