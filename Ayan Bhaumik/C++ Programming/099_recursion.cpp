/*
 * Program Name: 099_recursion.cpp
 * Question: Calculate factorial (recursion)?
 * Reasoning: Calls custom recursive function.
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
    cout << "Factorial of 5 is " << factorial_recursive(5) << "\n";
    return 0;
}
