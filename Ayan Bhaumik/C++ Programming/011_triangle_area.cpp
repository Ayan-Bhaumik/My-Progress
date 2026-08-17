/*
 * Program Name: 011_triangle_area.cpp
 * Question: Calculate triangle area?
 * Reasoning: Uses formula 0.5 * b * h.
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
    float b=4.0, h=5.0; cout << "Area: " << 0.5*b*h << "\n";
    return 0;
}
