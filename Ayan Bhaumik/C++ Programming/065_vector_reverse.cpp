/*
 * Program Name: 065_vector_reverse.cpp
 * Question: Reverse a vector?
 * Reasoning: Uses std::reverse.
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
    vector<int> v={1,2,3}; reverse(v.begin(), v.end()); for(int x:v) cout << x << " "; cout << "\n";
    return 0;
}
