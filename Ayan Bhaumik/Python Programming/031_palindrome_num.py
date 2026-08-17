"""
Program Name: 031_palindrome_num.py
Question: Check if number is palindrome?
Reasoning: Compares string with its reverse.
"""

n = 121
print("Palindrome" if str(n) == str(n)[::-1] else "Not Palindrome")
