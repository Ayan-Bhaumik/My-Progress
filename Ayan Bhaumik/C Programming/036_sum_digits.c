/*
 * Program Name: 036_sum_digits.c
 * Question: Sum the digits of a number?
 * Reasoning: Extracts digits using modulo 10.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=456, sum=0; while(n!=0) { sum += n%10; n/=10; } printf("Digit Sum: %d\n", sum);
    return 0;
}
