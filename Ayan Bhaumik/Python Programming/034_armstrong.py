"""
Program Name: 034_armstrong.py
Question: Check Armstrong number?
Reasoning: Sum of cubes of digits equals number.
"""

n = 153
print("Armstrong" if sum(int(d)**3 for d in str(n)) == n else "Not Armstrong")
