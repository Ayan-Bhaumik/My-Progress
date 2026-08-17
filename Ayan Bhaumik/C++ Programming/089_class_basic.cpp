/*
 * Program Name: 089_class_basic.cpp
 * Question: Basic class usage?
 * Reasoning: Defines local class and instantiates.
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
    class Car { public: string brand; void honk(){cout<<"Beep!\n";} }; Car c; c.brand="Toyota"; c.honk();
    return 0;
}
