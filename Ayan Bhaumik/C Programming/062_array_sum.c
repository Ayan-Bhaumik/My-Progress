/*
 * Program Name: 062_array_sum.c
 * Question: Sum of array elements?
 * Reasoning: Accumulates array values.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={1,2,3}, sum=0; for(int i=0; i<3; i++) sum+=arr[i]; printf("Sum: %d\n", sum);
    return 0;
}
