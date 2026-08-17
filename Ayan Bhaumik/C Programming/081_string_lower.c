/*
 * Program Name: 081_string_lower.c
 * Question: Convert string to lowercase?
 * Reasoning: Adds 32 to uppercase chars.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s[]="HELLO"; for(int i=0; s[i]; i++) if(s[i]>="A" && s[i]<="Z") s[i]+=32; printf("%s\n", s);
    return 0;
}
