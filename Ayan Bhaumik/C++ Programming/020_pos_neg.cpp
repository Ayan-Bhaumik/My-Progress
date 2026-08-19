/*
 * Program Name: 020_pos_neg.cpp
 * Question: Check if positive or negative?
 * Reasoning: Uses > and < comparisons.
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
    int n=-5; if(n>0) cout << "Positive\n"; else if(n<0) cout << "Negative\n"; else cout << "Zero\n";
    return 0;
}
