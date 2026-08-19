/*
 * Program Name: 048_ascii_val.cpp
 * Question: Print ASCII value of char?
 * Reasoning: Casts char to int.
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
    char c=\'A\'; cout << "ASCII: " << (int)c << "\n";
    return 0;
}
