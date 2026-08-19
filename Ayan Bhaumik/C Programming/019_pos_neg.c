/*
 * Program Name: 019_pos_neg.c
 * Question: Check if positive or negative?
 * Reasoning: Uses > and < comparisons.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=-5; if(n>0) printf("Positive\n"); else if(n<0) printf("Negative\n"); else printf("Zero\n");
    return 0;
}
