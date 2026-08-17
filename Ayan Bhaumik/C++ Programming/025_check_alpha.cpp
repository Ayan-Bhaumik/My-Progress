/*
 * Program Name: 025_check_alpha.cpp
 * Question: Check if character is alphabet?
 * Reasoning: Uses isalpha.
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
    char c=\'G\'; if(isalpha(c)) cout << "Alphabet\n"; else cout << "Not\n";
    return 0;
}
