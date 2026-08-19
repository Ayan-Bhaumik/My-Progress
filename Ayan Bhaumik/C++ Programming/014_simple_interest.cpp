/*
 * Program Name: 014_simple_interest.cpp
 * Question: Calculate simple interest?
 * Reasoning: Uses formula (P*R*T)/100.
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
    float p=1000, r=5.0, t=2; cout << "Interest: " << (p*r*t)/100 << "\n";
    return 0;
}
