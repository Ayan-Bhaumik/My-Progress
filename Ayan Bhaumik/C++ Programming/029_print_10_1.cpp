/*
 * Program Name: 029_print_10_1.cpp
 * Question: Print numbers 10 to 1?
 * Reasoning: Demonstrates a reverse for loop.
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
    for(int i=10; i>=1; i--) cout << i << " "; cout << "\n";
    return 0;
}
