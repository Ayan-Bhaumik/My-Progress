/*
 * Program Name: 069_vector_sort.cpp
 * Question: Sort a vector?
 * Reasoning: Uses std::sort.
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
    vector<int> v={3,1,2}; sort(v.begin(), v.end()); for(int x:v) cout << x << " "; cout << "\n";
    return 0;
}
