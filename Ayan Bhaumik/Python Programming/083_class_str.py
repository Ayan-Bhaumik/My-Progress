"""
Program Name: 083_class_str.py
Question: Class with __str__?
Reasoning: String representation method.
"""

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y
    def __str__(self):
        return f"({self.x}, {self.y})"
print(Point(1, 2))
