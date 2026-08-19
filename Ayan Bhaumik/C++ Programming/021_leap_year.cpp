/*
 * Program Name: 021_leap_year.cpp
 * Question: Check if year is a leap year?
 * Reasoning: Uses leap year divisibility rules.
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
    int y=2024; if((y%4==0 && y%100!=0) || y%400==0) cout << "Leap\n"; else cout << "Not Leap\n";
    return 0;
}
