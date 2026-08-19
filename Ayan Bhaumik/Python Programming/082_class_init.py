"""
Program Name: 082_class_init.py
Question: Class with __init__?
Reasoning: Constructor method.
"""

class Person:
    def __init__(self, name):
        self.name = name
p = Person("Alice")
print(p.name)
