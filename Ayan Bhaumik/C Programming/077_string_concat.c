/*
 * Program Name: 077_string_concat.c
 * Question: Concat strings using strcat?
 * Reasoning: Uses string.h strcat().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s1[20]="Hello ", s2[]="World"; strcat(s1, s2); printf("%s\n", s1);
    return 0;
}
