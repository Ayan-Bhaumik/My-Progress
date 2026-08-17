/*
 * Program Name: 056_left_shift.cpp
 * Question: Left shift operator?
 * Reasoning: Applies << operator.
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
    int a=5; cout << "Left Shift: " << (a<<1) << "\n";
    return 0;
}
