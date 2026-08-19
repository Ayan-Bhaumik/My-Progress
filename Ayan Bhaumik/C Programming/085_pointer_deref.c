/*
 * Program Name: 085_pointer_deref.c
 * Question: Dereference a pointer?
 * Reasoning: Uses * operator to get value.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=10; int *p=&n; printf("Value via pointer: %d\n", *p);
    return 0;
}
