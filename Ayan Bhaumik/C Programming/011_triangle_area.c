/*
 * Program Name: 011_triangle_area.c
 * Question: Calculate triangle area?
 * Reasoning: Uses formula 0.5 * b * h.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float b=4.0, h=5.0; printf("Area: %.2f\n", 0.5*b*h);
    return 0;
}
