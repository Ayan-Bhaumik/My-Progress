/*
 * Program Name: 096_range_for_loop.cpp
 * Question: Range-based for loop?
 * Reasoning: Iterates over brace-enclosed list.
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
    for(int x : {10, 20, 30}) cout << x << " "; cout << "\n";
    return 0;
}
