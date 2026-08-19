"""
Program Name: 085_try_except.py
Question: Basic try-except?
Reasoning: Handles exceptions.
"""

try:
    print(1 / 0)
except ZeroDivisionError:
    print("Cannot divide by zero!")
