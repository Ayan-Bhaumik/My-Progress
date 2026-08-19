/*
 * Program Name: 061_array_init.c
 * Question: Initialize and print array?
 * Reasoning: Loops through array elements.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={1,2,3,4}; for(int i=0; i<4; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
