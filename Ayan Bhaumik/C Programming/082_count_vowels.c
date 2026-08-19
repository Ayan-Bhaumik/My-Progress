/*
 * Program Name: 082_count_vowels.c
 * Question: Count vowels in string?
 * Reasoning: Checks each char for a,e,i,o,u.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s[]="apple"; int c=0; for(int i=0; s[i]; i++) if(strchr("aeiouAEIOU", s[i])) c++; printf("Vowels: %d\n", c);
    return 0;
}
