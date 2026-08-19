/*
 * Program Name: 087_new_delete.cpp
 * Question: Dynamic memory alloc?
 * Reasoning: Uses new and delete.
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
    int *p = new int(42); cout << "Dynamic val: " << *p << "\n"; delete p;
    return 0;
}
