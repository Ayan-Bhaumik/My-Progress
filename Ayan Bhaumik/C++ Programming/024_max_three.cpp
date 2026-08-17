/*
 * Program Name: 024_max_three.cpp
 * Question: Find max of three numbers?
 * Reasoning: Uses nested std::max.
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
    int a=5, b=9, c=2; cout << "Max: " << std::max(a, std::max(b,c)) << "\n";
    return 0;
}
