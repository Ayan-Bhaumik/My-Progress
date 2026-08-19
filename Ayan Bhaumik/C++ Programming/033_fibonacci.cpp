/*
 * Program Name: 033_fibonacci.cpp
 * Question: Print Fibonacci series?
 * Reasoning: Iterative addition of previous two terms.
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
    int t1=0, t2=1, next; cout << t1 << " " << t2 << " "; for(int i=3; i<=7; i++) { next=t1+t2; cout << next << " "; t1=t2; t2=next; } cout << "\n";
    return 0;
}
