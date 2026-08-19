/*
 * Program Name: 063_array_avg.c
 * Question: Average of array elements?
 * Reasoning: Divides array sum by size.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={2,4,6}, sum=0; for(int i=0;i<3;i++) sum+=arr[i]; printf("Avg: %.2f\n", (float)sum/3);
    return 0;
}
