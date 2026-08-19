/*
 * Program Name: 017_swap_notemp.c
 * Question: Swap variables without temp?
 * Reasoning: Uses arithmetic addition/subtraction.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=10, b=20; a=a+b; b=a-b; a=a-b; printf("a=%d, b=%d\n", a, b);
    return 0;
}
