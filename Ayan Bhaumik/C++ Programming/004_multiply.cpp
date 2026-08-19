/*
 * Program Name: 004_multiply.cpp
 * Question: How to multiply integers?
 * Reasoning: Demonstrates the multiplication (*) operator.
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
    int a=4, b=5; cout << "Product: " << a*b << "\n";
    return 0;
}
