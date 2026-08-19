/*
 * Program Name: 074_string_len_strlen.c
 * Question: String length using strlen?
 * Reasoning: Uses string.h strlen().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char str[]="Hello"; printf("Length: %zu\n", strlen(str));
    return 0;
}
