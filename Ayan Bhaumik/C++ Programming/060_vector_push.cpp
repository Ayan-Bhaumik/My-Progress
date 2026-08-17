/*
 * Program Name: 060_vector_push.cpp
 * Question: Add element to vector?
 * Reasoning: Uses push_back().
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
    vector<int> v; v.push_back(10); v.push_back(20); cout << "Size: " << v.size() << "\n";
    return 0;
}
