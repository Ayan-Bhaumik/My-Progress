/*
 * Program Name: 021_max_two.c
 * Question: Find max of two numbers?
 * Reasoning: Uses if-else conditions.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=10, b=20; if(a>b) printf("Max: %d\n", a); else printf("Max: %d\n", b);
    return 0;
}
