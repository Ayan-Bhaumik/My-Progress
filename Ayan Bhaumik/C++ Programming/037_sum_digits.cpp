/*
 * Program Name: 037_sum_digits.cpp
 * Question: Sum the digits of a number?
 * Reasoning: Extracts digits using modulo 10.
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
    int n=456, sum=0; while(n!=0) { sum += n%10; n/=10; } cout << "Digit Sum: " << sum << "\n";
    return 0;
}
