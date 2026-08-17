/*
 * Program Name: 012_cel_to_fah.cpp
 * Question: Convert Celsius to Fahrenheit?
 * Reasoning: Uses formula (C * 9/5) + 32.
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
    float c=32.0; cout << "Fahrenheit: " << (c*9.0/5.0)+32 << "\n";
    return 0;
}
