/*
 * Program Name: 074_string_compare.cpp
 * Question: Compare strings?
 * Reasoning: Uses == operator.
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
    string s1 = "apple", s2 = "apple"; cout << ((s1==s2)?"Equal\n":"Not\n");
    return 0;
}
