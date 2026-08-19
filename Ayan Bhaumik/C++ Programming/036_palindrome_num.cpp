/*
 * Program Name: 036_palindrome_num.cpp
 * Question: Check if number is palindrome?
 * Reasoning: Compares reversed number with original.
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
    int n=121, orig=n, rev=0; while(n!=0) { rev=rev*10 + n%10; n/=10; } cout << (orig==rev ? "Palindrome\n" : "Not\n");
    return 0;
}
