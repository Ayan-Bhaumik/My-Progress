"""
Program Name: 043_count_vowels.py
Question: Count vowels in string?
Reasoning: List comprehension with condition.
"""

s = "apple"
print(f"Vowels: {sum(1 for c in s if c.lower() in 'aeiou')}")
