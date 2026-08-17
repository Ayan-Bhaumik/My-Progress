/*
 * Program Name: 073_string_concat.cpp
 * Question: Concatenate strings?
 * Reasoning: Uses + operator.
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
    string s1 = "Hello ", s2 = "World"; cout << s1 + s2 << "\n";
    return 0;
}
