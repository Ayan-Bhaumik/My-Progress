/*
 * Program Name: 018_swap_std.cpp
 * Question: Swap using std::swap?
 * Reasoning: Uses algorithm library.
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
    int a=5, b=9; std::swap(a, b); cout << "a=" << a << ", b=" << b << "\n";
    return 0;
}
