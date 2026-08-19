/*
 * Program Name: 038_count_digits.cpp
 * Question: Count digits in an integer?
 * Reasoning: Divides by 10 continuously.
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
    int n=9876, count=0; while(n!=0) { count++; n/=10; } cout << "Count: " << count << "\n";
    return 0;
}
