/*
 * Program Name: 070_bubble_sort.c
 * Question: Bubble sort an array?
 * Reasoning: Swaps adjacent out-of-order elements.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={3,1,2}; for(int i=0;i<2;i++) for(int j=0;j<2-i;j++) if(arr[j]>arr[j+1]){int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;} printf("Sorted: %d %d %d\n", arr[0],arr[1],arr[2]);
    return 0;
}
