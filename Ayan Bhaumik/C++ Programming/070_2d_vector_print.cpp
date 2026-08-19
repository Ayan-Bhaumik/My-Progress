/*
 * Program Name: 070_2d_vector_print.cpp
 * Question: Print 2D vector?
 * Reasoning: Nested range-based for loops.
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
    vector<vector<int>> mat={{1,2},{3,4}}; for(auto& row : mat) { for(int x : row) cout << x << " "; cout << "\n"; }
    return 0;
}
