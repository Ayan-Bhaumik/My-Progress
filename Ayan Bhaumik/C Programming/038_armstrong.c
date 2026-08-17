/*
 * Program Name: 038_armstrong.c
 * Question: Check Armstrong number?
 * Reasoning: Sum of cubes of digits equals number.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=153, orig=n, sum=0; while(n!=0) { int d=n%10; sum+=d*d*d; n/=10; } printf((orig==sum) ? "Armstrong\n" : "Not\n");
    return 0;
}
