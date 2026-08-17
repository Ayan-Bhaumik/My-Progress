/*
 * Program Name: 092_struct_pointer.c
 * Question: Pointer to struct?
 * Reasoning: Uses the -> operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    struct Node { int val; }; struct Node n = {5}; struct Node *ptr = &n; printf("Val: %d\n", ptr->val);
    return 0;
}
