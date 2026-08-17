/*
 * Program Name: 005_divide.cpp
 * Question: How to perform division?
 * Reasoning: Demonstrates the division (/) operator with floats.
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
    float a=20.0, b=4.0; cout << "Quotient: " << a/b << "\n";
    return 0;
}
