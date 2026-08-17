/*
 * Program Name: 076_string_find.cpp
 * Question: Find substring?
 * Reasoning: Uses string::find().
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
    string s = "hello world"; cout << (s.find("world")!=string::npos ? "Found\n" : "Not Found\n");
    return 0;
}
