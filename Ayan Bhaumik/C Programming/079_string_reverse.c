/*
 * Program Name: 079_string_reverse.c
 * Question: Reverse a string manually?
 * Reasoning: Swaps characters from edges to center.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s[]="abc"; int l=0, r=strlen(s)-1; while(l<r) { char t=s[l]; s[l]=s[r]; s[r]=t; l++; r--; } printf("Reversed: %s\n", s);
    return 0;
}
