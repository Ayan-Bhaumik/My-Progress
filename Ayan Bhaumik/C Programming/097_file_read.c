/*
 * Program Name: 097_file_read.c
 * Question: Read from a file?
 * Reasoning: Uses fopen and fgets.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    FILE *f = fopen("test.txt", "r"); char buff[50]; if(f) { if(fgets(buff, 50, f)) printf("Read: %s", buff); fclose(f); }
    return 0;
}
