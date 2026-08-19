/*
 * Program Name: 034_reverse_num.c
 * Question: Reverse an integer?
 * Reasoning: Uses modulo and division.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=123, rev=0; while(n!=0) { rev = rev*10 + n%10; n/=10; } printf("Reversed: %d\n", rev);
    return 0;
}
