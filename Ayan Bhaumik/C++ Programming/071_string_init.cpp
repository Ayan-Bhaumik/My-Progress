/*
 * Program Name: 071_string_init.cpp
 * Question: Initialize and print string?
 * Reasoning: Uses std::string.
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
    string s = "Hello C++"; cout << s << "\n";
    return 0;
}
