/*
 * Program Name: 093_struct_array.c
 * Question: Array of structs?
 * Reasoning: Creates multiple struct instances.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    struct Item { int id; }; struct Item arr[2] = {{1}, {2}}; printf("Item 2 ID: %d\n", arr[1].id);
    return 0;
}
