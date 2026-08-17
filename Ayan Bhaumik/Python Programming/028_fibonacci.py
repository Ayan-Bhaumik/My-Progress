"""
Program Name: 028_fibonacci.py
Question: Print Fibonacci series?
Reasoning: Iterative variable swapping.
"""

a, b = 0, 1
for _ in range(7):
    print(a, end=" ")
    a, b = b, a + b
print()
