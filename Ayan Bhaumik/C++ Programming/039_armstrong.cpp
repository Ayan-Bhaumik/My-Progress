/*
 * Program Name: 039_armstrong.cpp
 * Question: Check Armstrong number?
 * Reasoning: Sum of cubes of digits equals number.
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
    int n=153, orig=n, sum=0; while(n!=0) { int d=n%10; sum+=pow(d,3); n/=10; } cout << ((orig==sum) ? "Armstrong\n" : "Not\n");
    return 0;
}
