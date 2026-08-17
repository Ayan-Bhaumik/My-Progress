/*
 * Program Name: 010_rect_perimeter.cpp
 * Question: Calculate rectangle perimeter?
 * Reasoning: Uses formula 2 * (l + w).
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
    int l=4, w=5; cout << "Perimeter: " << 2*(l+w) << "\n";
    return 0;
}
