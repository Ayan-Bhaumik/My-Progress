/*
 * Program Name: 046_sqrt.cpp
 * Question: Find square root?
 * Reasoning: Uses cmath sqrt().
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
    double n=16.0; cout << "Sqrt: " << sqrt(n) << "\n";
    return 0;
}
