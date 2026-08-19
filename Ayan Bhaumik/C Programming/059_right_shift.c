/*
 * Program Name: 059_right_shift.c
 * Question: Right shift operator?
 * Reasoning: Applies >> operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=5; printf("Right Shift: %d\n", a>>1);
    return 0;
}
