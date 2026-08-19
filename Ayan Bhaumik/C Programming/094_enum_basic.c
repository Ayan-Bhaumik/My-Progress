/*
 * Program Name: 094_enum_basic.c
 * Question: Basic Enum usage?
 * Reasoning: Creates named integer constants.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    enum Days {MON=1, TUE, WED}; enum Days today = TUE; printf("Day: %d\n", today);
    return 0;
}
