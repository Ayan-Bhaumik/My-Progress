/*
 * Program Name: 079_string_insert.cpp
 * Question: Insert into string?
 * Reasoning: Uses string::insert().
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
    string s = "Hello"; s.insert(5, " World"); cout << s << "\n";
    return 0;
}
