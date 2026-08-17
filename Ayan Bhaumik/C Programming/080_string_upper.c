/*
 * Program Name: 080_string_upper.c
 * Question: Convert string to uppercase?
 * Reasoning: Subtracts 32 from lowercase chars.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s[]="hello"; for(int i=0; s[i]; i++) if(s[i]>="a" && s[i]<="z") s[i]-=32; printf("%s\n", s);
    return 0;
}
