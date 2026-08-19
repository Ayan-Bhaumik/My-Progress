/*
 * Program Name: 015_compound_interest.cpp
 * Question: Calculate compound interest?
 * Reasoning: Uses cmath pow() function.
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
    float p=1000, r=5.0, t=2; cout << "CI: " << p*pow((1+r/100), t)-p << "\n";
    return 0;
}
