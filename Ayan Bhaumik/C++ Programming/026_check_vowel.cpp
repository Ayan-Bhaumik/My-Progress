/*
 * Program Name: 026_check_vowel.cpp
 * Question: Check if char is vowel?
 * Reasoning: Uses logical OR operator.
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
    char c=\'E\'; if(c==\'A\'||c==\'E\'||c==\'I\'||c==\'O\'||c==\'U\') cout << "Vowel\n"; else cout << "Consonant\n";
    return 0;
}
