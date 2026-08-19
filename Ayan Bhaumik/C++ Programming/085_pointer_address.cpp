/*
 * Program Name: 085_pointer_address.cpp
 * Question: Print memory address?
 * Reasoning: Uses & operator.
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
    int n=10; int *p=&n; cout << "Address: " << p << "\n";
    return 0;
}
