"""
Program Name: 073_function_default.py
Question: Default arguments?
Reasoning: Assigns default value in signature.
"""

def greet(name="User"):
    print(f"Hello, {name}")
greet()
greet("Alice")
