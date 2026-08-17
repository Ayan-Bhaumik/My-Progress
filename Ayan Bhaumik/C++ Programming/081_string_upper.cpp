/*
 * Program Name: 081_string_upper.cpp
 * Question: Convert string to uppercase?
 * Reasoning: Uses std::transform.
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
    string s = "hello"; transform(s.begin(), s.end(), s.begin(), ::toupper); cout << s << "\n";
    return 0;
}
