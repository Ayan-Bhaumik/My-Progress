/*
 * Program Name: 009_rect_area.cpp
 * Question: Calculate rectangle area?
 * Reasoning: Uses formula length * width.
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
    int l=4, w=5; cout << "Area: " << l*w << "\n";
    return 0;
}
