/*
 * Program Name: 075_string_reverse.cpp
 * Question: Reverse a string?
 * Reasoning: Uses std::reverse.
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
    string s = "abc"; reverse(s.begin(), s.end()); cout << "Reversed: " << s << "\n";
    return 0;
}
