/*
 * Program Name: 091_struct_basic.c
 * Question: Basic struct usage?
 * Reasoning: Defines and prints struct members.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    struct Point { int x; int y; }; struct Point p1 = {10, 20}; printf("X:%d Y:%d\n", p1.x, p1.y);
    return 0;
}
