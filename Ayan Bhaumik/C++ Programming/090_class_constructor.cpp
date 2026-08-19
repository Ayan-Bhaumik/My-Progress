/*
 * Program Name: 090_class_constructor.cpp
 * Question: Class with constructor?
 * Reasoning: Initializes members via constructor.
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
    class Person { public: string name; Person(string n) : name(n){} }; Person p("Alice"); cout<<p.name<<"\n";
    return 0;
}
