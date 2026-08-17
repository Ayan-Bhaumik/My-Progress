/*
 * Program Name: 017_swap_notemp.cpp
 * Question: Swap variables without temp?
 * Reasoning: Uses arithmetic addition/subtraction.
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
    int a=10, b=20; a=a+b; b=a-b; a=a-b; cout << "a=" << a << ", b=" << b << "\n";
    return 0;
}
