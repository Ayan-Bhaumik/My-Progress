/*
 * Program Name: 033_check_prime.c
 * Question: Check if number is prime?
 * Reasoning: Loops to check for factors.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=7, flag=1; for(int i=2; i<=n/2; i++) if(n%i==0) flag=0; printf(flag ? "Prime\n" : "Not Prime\n");
    return 0;
}
