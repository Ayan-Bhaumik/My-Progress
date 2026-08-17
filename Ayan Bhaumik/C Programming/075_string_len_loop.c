/*
 * Program Name: 075_string_len_loop.c
 * Question: String length without strlen?
 * Reasoning: Iterates until null terminator.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char str[]="World"; int len=0; while(str[len]!="\0") len++; printf("Length: %d\n", len);
    return 0;
}
