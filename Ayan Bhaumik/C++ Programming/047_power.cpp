/*
 * Program Name: 047_power.cpp
 * Question: Calculate power (base^exp)?
 * Reasoning: Uses cmath pow().
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
    double base=2.0, exp=3.0; cout << "Result: " << pow(base, exp) << "\n";
    return 0;
}
