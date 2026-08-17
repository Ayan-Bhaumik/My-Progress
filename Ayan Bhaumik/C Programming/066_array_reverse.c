/*
 * Program Name: 066_array_reverse.c
 * Question: Reverse print an array?
 * Reasoning: Loops backwards through indices.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={1,2,3}; for(int i=2; i>=0; i--) printf("%d ", arr[i]); printf("\n");
    return 0;
}
