/*
 * Program Name: 020_leap_year.c
 * Question: Check if year is a leap year?
 * Reasoning: Uses leap year divisibility rules.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_ptrs(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }

int main() {
    int y=2024; if((y%4==0 && y%100!=0) || y%400==0) printf("Leap\n"); else printf("Not Leap\n");
    return 0;
}
