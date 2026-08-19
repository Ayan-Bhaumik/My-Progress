/*
 * Program Name: 068_vector_find.cpp
 * Question: Find element in vector?
 * Reasoning: Uses std::find.
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
    vector<int> v={5,1,9}; auto it = find(v.begin(), v.end(), 1); cout << (it!=v.end()?"Found\n":"Not Found\n");
    return 0;
}
