/*
 * Program Name: 083_reference_basic.cpp
 * Question: Basic reference usage?
 * Reasoning: Uses & for reference.
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
    int n = 10; int &ref = n; ref = 20; cout << "n=" << n << "\n";
    return 0;
}
