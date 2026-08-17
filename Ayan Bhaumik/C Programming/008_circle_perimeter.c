/*
 * Program Name: 008_circle_perimeter.c
 * Question: Calculate circle circumference?
 * Reasoning: Uses formula 2 * pi * r.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float r=5.0, circ=2*3.14159*r; printf("Circumference: %.2f\n", circ);
    return 0;
}
