"""
Program Name: 019_leap_year.py
Question: Check if year is a leap year?
Reasoning: Uses divisibility rules.
"""

y = 2024
print("Leap" if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 else "Not Leap")
