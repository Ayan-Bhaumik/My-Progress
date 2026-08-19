/*
 * Program Name: 034_check_prime.cpp
 * Question: Check if number is prime?
 * Reasoning: Loops to check for factors.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Helper functions for specific programs
int factorial_recursive(int n) { return (n <= 1) ? 1 : n * factorial_recursive(n - 1); }
void swap_refs(int &x, int &y) { int temp = x; x = y; y = temp; }

int main() {
    int n=7; bool prime=true; for(int i=2; i<=n/2; i++) if(n%i==0) prime=false; cout << (prime ? "Prime\n" : "Not Prime\n");
    return 0;
}
