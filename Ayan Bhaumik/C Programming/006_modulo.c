/*
 * Program Name: 006_modulo.c
 * Question: How to find the remainder?
 * Reasoning: Demonstrates the modulo (%) operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=10, b=3; printf("Remainder: %d\n", a%b);
    return 0;
}
