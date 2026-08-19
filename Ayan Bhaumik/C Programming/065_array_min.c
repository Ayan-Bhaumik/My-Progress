/*
 * Program Name: 065_array_min.c
 * Question: Find min in array?
 * Reasoning: Iterates keeping track of lowest.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={8,2,7}, min=arr[0]; for(int i=1;i<3;i++) if(arr[i]<min) min=arr[i]; printf("Min: %d\n", min);
    return 0;
}
