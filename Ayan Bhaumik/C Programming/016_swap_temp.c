/*
 * Program Name: 016_swap_temp.c
 * Question: Swap two variables using temp?
 * Reasoning: Standard swapping logic.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=1, b=2, temp; temp=a; a=b; b=temp; printf("a=%d, b=%d\n", a, b);
    return 0;
}
