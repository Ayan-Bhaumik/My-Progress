/*
 * Program Name: 061_vector_sum.cpp
 * Question: Sum of vector elements?
 * Reasoning: Uses std::accumulate.
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
    vector<int> v={1,2,3}; cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << "\n";
    return 0;
}
