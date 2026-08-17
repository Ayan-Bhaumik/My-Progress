/*
 * Program Name: 086_pointer_add.c
 * Question: Add numbers using pointers?
 * Reasoning: Dereferences and adds.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a=5, b=10; int *p1=&a, *p2=&b; printf("Sum: %d\n", *p1 + *p2);
    return 0;
}
