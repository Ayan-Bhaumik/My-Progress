/*
 * Program Name: 078_string_compare.c
 * Question: Compare strings strcmp?
 * Reasoning: Uses string.h strcmp().
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    char s1[]="apple", s2[]="apple"; if(strcmp(s1,s2)==0) printf("Equal\n"); else printf("Not\n");
    return 0;
}
