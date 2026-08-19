/*
 * Program Name: 062_vector_avg.cpp
 * Question: Average of vector elements?
 * Reasoning: Divides vector sum by size.
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
    vector<int> v={2,4,6}; float avg = accumulate(v.begin(), v.end(), 0.0) / v.size(); cout << "Avg: " << avg << "\n";
    return 0;
}
