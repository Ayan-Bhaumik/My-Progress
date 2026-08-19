/*
 * Program Name: 091_struct_basic.cpp
 * Question: Basic struct usage?
 * Reasoning: Struct defaults to public members.
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
    struct Point { int x, y; }; Point p = {10, 20}; cout << "X:" << p.x << " Y:" << p.y << "\n";
    return 0;
}
