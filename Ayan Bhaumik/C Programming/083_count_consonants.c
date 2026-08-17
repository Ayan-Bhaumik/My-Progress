/*
 * Program Name: 083_count_consonants.c
 * Question: Count consonants in string?
 * Reasoning: Counts non-vowel alphabets.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s[]="cat"; int c=0; for(int i=0; s[i]; i++) if((s[i]>="a"&&s[i]<="z") && !strchr("aeiou", s[i])) c++; printf("Consonants: %d\n", c);
    return 0;
}
