/*
 * Program Name: 088_pointer_array.c
 * Question: Access array via pointer?
 * Reasoning: Pointer arithmetic on arrays.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={10,20}; int *p=arr; printf("First: %d, Second: %d\n", *p, *(p+1));
    return 0;
}
