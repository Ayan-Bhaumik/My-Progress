/*
 * Program Name: 088_new_array.cpp
 * Question: Dynamic array alloc?
 * Reasoning: Uses new[] and delete[].
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
    int *arr = new int[3]{1,2,3}; cout << arr[1] << "\n"; delete[] arr;
    return 0;
}
