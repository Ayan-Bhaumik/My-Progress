/*
 * Program Name: 030_sum_n.cpp
 * Question: Sum of first N natural numbers?
 * Reasoning: Uses loop accumulation.
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
    int sum=0; for(int i=1; i<=10; i++) sum+=i; cout << "Sum: " << sum << "\n";
    return 0;
}
