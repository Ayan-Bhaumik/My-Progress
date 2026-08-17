/*
 * Program Name: 039_strong_num.c
 * Question: Check Strong number?
 * Reasoning: Sum of factorials of digits equals number.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=145, orig=n, sum=0; while(n) { int d=n%10, f=1; for(int i=1;i<=d;i++) f*=i; sum+=f; n/=10; } printf((orig==sum)?"Strong\n":"Not\n");
    return 0;
}
