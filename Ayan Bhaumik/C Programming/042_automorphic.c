/*
 * Program Name: 042_automorphic.c
 * Question: Check Automorphic number?
 * Reasoning: Square ends with the number itself.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=25, sq=n*n; printf((sq%100==n)?"Automorphic\n":"Not\n");
    return 0;
}
