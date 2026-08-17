/*
 * Program Name: 040_perfect_num.c
 * Question: Check Perfect number?
 * Reasoning: Sum of divisors equals the number itself.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=28, sum=0; for(int i=1; i<n; i++) { if(n%i==0) sum+=i; } printf((sum==n)?"Perfect\n":"Not\n");
    return 0;
}
