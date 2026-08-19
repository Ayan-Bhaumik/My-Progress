/*
 * Program Name: 078_string_replace.cpp
 * Question: Replace part of string?
 * Reasoning: Uses string::replace().
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
    string s = "I like apples"; s.replace(7, 6, "bananas"); cout << s << "\n";
    return 0;
}
