/*
 * Program Name: 029_sum_n.c
 * Question: Sum of first N natural numbers?
 * Reasoning: Uses loop accumulation.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int sum=0; for(int i=1; i<=10; i++) sum+=i; printf("Sum: %d\n", sum);
    return 0;
}
