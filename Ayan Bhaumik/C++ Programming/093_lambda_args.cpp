/*
 * Program Name: 093_lambda_args.cpp
 * Question: Lambda with arguments?
 * Reasoning: Passes args to lambda.
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
    auto add = [](int a, int b){ return a+b; }; cout << "Sum: " << add(5, 7) << "\n";
    return 0;
}
