/*
 * Program Name: 076_string_copy.c
 * Question: Copy string using strcpy?
 * Reasoning: Uses string.h strcpy().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char src[]="CopyMe", dest[20]; strcpy(dest, src); printf("Dest: %s\n", dest);
    return 0;
}
