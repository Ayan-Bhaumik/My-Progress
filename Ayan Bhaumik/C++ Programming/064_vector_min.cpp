/*
 * Program Name: 064_vector_min.cpp
 * Question: Find min in vector?
 * Reasoning: Uses std::min_element.
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
    vector<int> v={8,2,7}; cout << "Min: " << *min_element(v.begin(), v.end()) << "\n";
    return 0;
}
