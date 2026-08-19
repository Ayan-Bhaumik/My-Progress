/*
 * Program Name: 067_vector_count_odd.cpp
 * Question: Count odd numbers in vector?
 * Reasoning: Uses std::count_if.
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
    vector<int> v={1,2,3,4}; int c = count_if(v.begin(), v.end(), [](int i){return i%2!=0;}); cout << "Odds: " << c << "\n";
    return 0;
}
