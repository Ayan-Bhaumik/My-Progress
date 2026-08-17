/*
 * Program Name: 071_2d_array_print.c
 * Question: Print 2D matrix?
 * Reasoning: Nested loops for rows and cols.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int mat[2][2]={{1,2},{3,4}}; for(int i=0;i<2;i++) { for(int j=0;j<2;j++) printf("%d ", mat[i][j]); printf("\n"); }
    return 0;
}
