/*
 * Program Name: 067_array_even.c
 * Question: Count even numbers in array?
 * Reasoning: Checks modulo 2 for each element.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={1,2,3,4}, c=0; for(int i=0;i<4;i++) if(arr[i]%2==0) c++; printf("Evens: %d\n", c);
    return 0;
}
