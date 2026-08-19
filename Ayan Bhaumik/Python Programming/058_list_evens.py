"""
Program Name: 058_list_evens.py
Question: Filter evens with comprehension?
Reasoning: Adds conditional to comprehension.
"""

evens = [x for x in range(10) if x % 2 == 0]
print(evens)
