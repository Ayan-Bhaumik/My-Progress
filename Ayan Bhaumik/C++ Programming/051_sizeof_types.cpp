/*
 * Program Name: 051_sizeof_types.cpp
 * Question: Size of basic types?
 * Reasoning: Uses sizeof() operator.
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
    cout << "Int: " << sizeof(int) << " Float: " << sizeof(float) << "\n";
    return 0;
}
