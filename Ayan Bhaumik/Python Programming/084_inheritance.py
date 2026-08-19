"""
Program Name: 084_inheritance.py
Question: Class inheritance?
Reasoning: Pass parent class in parentheses.
"""

class Animal:
    def speak(self): return "Hi"
class Cat(Animal):
    def speak(self): return "Meow"
c = Cat()
print(c.speak())
