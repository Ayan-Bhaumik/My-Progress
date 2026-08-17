/*
 * Program Name: 072_string_len.cpp
 * Question: String length?
 * Reasoning: Uses length().
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
    string s = "Hello"; cout << "Length: " << s.length() << "\n";
    return 0;
}
