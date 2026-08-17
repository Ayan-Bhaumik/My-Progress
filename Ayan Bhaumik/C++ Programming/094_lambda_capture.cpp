/*
 * Program Name: 094_lambda_capture.cpp
 * Question: Lambda capturing context?
 * Reasoning: Captures local variables by value.
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
    int factor = 2; auto scale = [factor](int x){ return x*factor; }; cout << scale(5) << "\n";
    return 0;
}
