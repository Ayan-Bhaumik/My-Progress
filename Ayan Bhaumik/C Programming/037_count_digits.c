/*
 * Program Name: 037_count_digits.c
 * Question: Count digits in an integer?
 * Reasoning: Divides by 10 continuously.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=9876, count=0; while(n!=0) { count++; n/=10; } printf("Count: %d\n", count);
    return 0;
}
