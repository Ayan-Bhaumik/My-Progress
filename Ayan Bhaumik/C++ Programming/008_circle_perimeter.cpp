/*
 * Program Name: 008_circle_perimeter.cpp
 * Question: Calculate circle circumference?
 * Reasoning: Uses formula 2 * pi * r.
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
    float r=5.0, circ=2*3.14159*r; cout << "Circumference: " << circ << "\n";
    return 0;
}
