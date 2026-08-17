/*
 * Program Name: 032_fibonacci.c
 * Question: Print Fibonacci series?
 * Reasoning: Iterative addition of previous two terms.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int t1=0, t2=1, next; printf("%d %d ", t1, t2); for(int i=3; i<=7; i++) { next=t1+t2; printf("%d ", next); t1=t2; t2=next; } printf("\n");
    return 0;
}
