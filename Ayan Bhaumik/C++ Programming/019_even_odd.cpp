/*
 * Program Name: 019_even_odd.cpp
 * Question: Check if number is even or odd?
 * Reasoning: Uses modulo 2 logic.
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
    int n=4; if(n%2==0) cout << "Even\n"; else cout << "Odd\n";
    return 0;
}
