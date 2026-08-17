/*
 * Program Name: 084_pointer_address.c
 * Question: Print memory address?
 * Reasoning: Uses %p to print pointer.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int n=10; int *p=&n; printf("Address: %p\n", (void*)p);
    return 0;
}
