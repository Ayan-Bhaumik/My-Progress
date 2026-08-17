"""
Program Name: 032_sum_digits.py
Question: Sum the digits of a number?
Reasoning: Iterates over string representation.
"""

n = 456
print(f"Sum of digits: {sum(int(d) for d in str(n))}")
