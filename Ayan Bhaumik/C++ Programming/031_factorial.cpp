/*
 * Program Name: 031_factorial.cpp
 * Question: Find factorial of a number?
 * Reasoning: Iterative multiplication.
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
    int n=5, fact=1; for(int i=1; i<=n; i++) fact*=i; cout << "Factorial: " << fact << "\n";
    return 0;
}
