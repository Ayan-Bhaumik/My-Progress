/*
 * Program Name: 064_array_max.c
 * Question: Find max in array?
 * Reasoning: Iterates keeping track of highest.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={1,9,3}, max=arr[0]; for(int i=1;i<3;i++) if(arr[i]>max) max=arr[i]; printf("Max: %d\n", max);
    return 0;
}
