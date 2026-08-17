/*
 * Program Name: 072_matrix_add.c
 * Question: Add two matrices?
 * Reasoning: Element-wise addition.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int a[2][2]={{1,1},{1,1}}, b[2][2]={{2,2},{2,2}}; for(int i=0;i<2;i++) for(int j=0;j<2;j++) printf("%d ", a[i][j]+b[i][j]); printf("\n");
    return 0;
}
