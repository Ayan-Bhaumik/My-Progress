/*
 * Program Name: 098_try_catch.cpp
 * Question: Exception handling basics?
 * Reasoning: Uses try-catch blocks.
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
    try { throw runtime_error("Error!"); } catch(const exception& e) { cout << e.what() << "\n"; }
    return 0;
}
