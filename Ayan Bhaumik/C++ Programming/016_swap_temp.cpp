/*
 * Program Name: 016_swap_temp.cpp
 * Question: Swap two variables using temp?
 * Reasoning: Standard swapping logic.
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
    int a=1, b=2, temp; temp=a; a=b; b=temp; cout << "a=" << a << ", b=" << b << "\n";
    return 0;
}
