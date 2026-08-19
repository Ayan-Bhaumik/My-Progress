/*
 * Program Name: 043_automorphic.cpp
 * Question: Check Automorphic number?
 * Reasoning: Square ends with the number itself.
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
    int n=25, sq=n*n; cout << ((sq%100==n)?"Automorphic\n":"Not\n");
    return 0;
}
