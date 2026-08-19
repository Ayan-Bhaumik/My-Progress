/*
 * Program Name: 042_harshad_num.cpp
 * Question: Check Harshad number?
 * Reasoning: Divisible by sum of its digits.
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
    int n=18, sum=0, temp=n; while(temp) { sum+=temp%10; temp/=10; } cout << ((n%sum==0)?"Harshad\n":"Not\n");
    return 0;
}
