"""
Program Name: 074_function_kwargs.py
Question: Variable keyword arguments?
Reasoning: Uses **kwargs.
"""

def info(**kwargs):
    for k, v in kwargs.items():
        print(f"{k}={v}")
info(name="Bob", age=30)
