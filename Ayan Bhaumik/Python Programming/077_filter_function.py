"""
Program Name: 077_filter_function.py
Question: Use filter()?
Reasoning: Filters iterable based on condition.
"""

nums = [1, 2, 3, 4]
print(list(filter(lambda x: x%2==0, nums)))
