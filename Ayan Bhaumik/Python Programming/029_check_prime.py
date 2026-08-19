"""
Program Name: 029_check_prime.py
Question: Check if number is prime?
Reasoning: Checks divisibility up to square root.
"""

n = 7
is_prime = all(n % i != 0 for i in range(2, int(n**0.5) + 1)) and n > 1
print("Prime" if is_prime else "Not Prime")
