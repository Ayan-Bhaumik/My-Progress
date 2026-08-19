/*
 * Program Name: 096_file_write.c
 * Question: Write to a file?
 * Reasoning: Uses fopen and fprintf.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    FILE *f = fopen("test.txt", "w"); if(f) { fprintf(f, "Testing file write.\n"); fclose(f); printf("File written.\n"); }
    return 0;
}
