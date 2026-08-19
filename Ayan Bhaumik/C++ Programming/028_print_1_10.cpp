/*
 * Program Name: 028_print_1_10.cpp
 * Question: Print numbers 1 to 10?
 * Reasoning: Demonstrates a basic for loop.
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
    for(int i=1; i<=10; i++) cout << i << " "; cout << "\n";
    return 0;
}
