"""
Program Name: 087_raise_exception.py
Question: Raise an exception?
Reasoning: Forces an error.
"""

try:
    raise ValueError("Custom Error")
except ValueError as e:
    print(e)
