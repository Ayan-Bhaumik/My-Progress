/*
 * Program Name: 027_check_digit.cpp
 * Question: Check if char is a digit?
 * Reasoning: Uses isdigit.
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
    char c=\'7\'; if(isdigit(c)) cout << "Digit\n"; else cout << "Not Digit\n";
    return 0;
}
