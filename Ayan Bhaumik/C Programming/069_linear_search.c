/*
 * Program Name: 069_linear_search.c
 * Question: Linear search in array?
 * Reasoning: Matches target iteratively.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int arr[]={5,1,9}, target=1, found=0; for(int i=0;i<3;i++) if(arr[i]==target) found=1; printf(found?"Found\n":"Not Found\n");
    return 0;
}
