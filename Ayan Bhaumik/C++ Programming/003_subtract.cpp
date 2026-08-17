/*
 * Program Name: 003_subtract.cpp
 * Question: How to subtract numbers?
 * Reasoning: Demonstrates the subtraction (-) operator.
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
    int a=15, b=5; cout << "Difference: " << a-b << "\n";
    return 0;
}
