/*
 * Program Name: 025_check_vowel.c
 * Question: Check if char is vowel?
 * Reasoning: Uses logical OR operator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char c="E"; if(c=="A"||c=="E"||c=="I"||c=="O"||c=="U") printf("Vowel\n"); else printf("Consonant\n");
    return 0;
}
