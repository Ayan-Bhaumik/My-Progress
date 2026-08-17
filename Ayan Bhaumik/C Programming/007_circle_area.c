/*
 * Program Name: 007_circle_area.c
 * Question: Calculate the area of a circle?
 * Reasoning: Uses formula pi * r^2.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    float r=5.0, area=3.14159*r*r; printf("Area: %.2f\n", area);
    return 0;
}
