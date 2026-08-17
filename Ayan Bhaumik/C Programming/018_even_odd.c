/*
 * Program Name: 018_even_odd.c
 * Question: Check if number is even or odd?
 * Reasoning: Uses modulo 2 logic.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=4; if(n%2==0) printf("Even\n"); else printf("Odd\n");
    return 0;
}
