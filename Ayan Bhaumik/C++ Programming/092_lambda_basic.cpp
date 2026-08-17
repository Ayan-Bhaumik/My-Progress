/*
 * Program Name: 092_lambda_basic.cpp
 * Question: Basic lambda function?
 * Reasoning: Defines inline lambda.
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
    auto greet = [](){ cout << "Hello Lambda!\n"; }; greet();
    return 0;
}
