/*
 * Program Name: 097_enum_class.cpp
 * Question: Scoped enum class?
 * Reasoning: Uses modern enum class.
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
    enum class Color { RED, GREEN }; Color c = Color::RED; if(c==Color::RED) cout<<"Red\n";
    return 0;
}
