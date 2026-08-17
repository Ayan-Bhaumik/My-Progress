/*
 * Program Name: 023_min_two.cpp
 * Question: Find min of two numbers?
 * Reasoning: Uses std::min.
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
    int a=10, b=20; cout << "Min: " << std::min(a,b) << "\n";
    return 0;
}
