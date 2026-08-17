/*
 * Program Name: 013_fah_to_cel.cpp
 * Question: Convert Fahrenheit to Celsius?
 * Reasoning: Uses formula (F - 32) * 5/9.
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
    float f=90.0; cout << "Celsius: " << (f-32)*5.0/9.0 << "\n";
    return 0;
}
