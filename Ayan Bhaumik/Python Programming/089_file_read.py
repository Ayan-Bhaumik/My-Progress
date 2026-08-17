"""
Program Name: 089_file_read.py
Question: Read from a file?
Reasoning: Uses open() with 'r'.
"""

with open("test.txt", "w") as f: f.write("Hello")
with open("test.txt", "r") as f:
    print(f.read())
