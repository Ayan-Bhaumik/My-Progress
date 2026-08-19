/*
 * Program Name: 077_string_substr.cpp
 * Question: Extract substring?
 * Reasoning: Uses string::substr().
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
    string s = "hello world"; cout << "Sub: " << s.substr(6, 5) << "\n";
    return 0;
}
