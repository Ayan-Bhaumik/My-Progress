/*
 * Program Name: 026_check_digit.c
 * Question: Check if char is a digit?
 * Reasoning: Compares against ASCII 0-9.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char c="7"; if(c>="0" && c<="9") printf("Digit\n"); else printf("Not Digit\n");
    return 0;
}
