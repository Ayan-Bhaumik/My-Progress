/*
 * Program Name: 009_rect_area.c
 * Question: Calculate rectangle area?
 * Reasoning: Uses formula length * width.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int l=4, w=5; printf("Area: %d\n", l*w);
    return 0;
}
