"""
Program Name: 078_reduce_function.py
Question: Use reduce()?
Reasoning: Accumulates values.
"""

from functools import reduce
nums = [1, 2, 3, 4]
print(reduce(lambda x, y: x+y, nums))
