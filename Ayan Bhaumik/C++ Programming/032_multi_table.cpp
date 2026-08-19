/*
 * Program Name: 032_multi_table.cpp
 * Question: Print multiplication table?
 * Reasoning: Loops 1 to 10 for a specific number.
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
    int n=5; for(int i=1; i<=10; i++) cout << n << "x" << i << "=" << n*i << "\n";
    return 0;
}
