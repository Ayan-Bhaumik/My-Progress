"""
Program Name: 090_file_append.py
Question: Append to a file?
Reasoning: Uses open() with 'a'.
"""

with open("test.txt", "a") as f:
    f.write(" World!")
print("Appended.")
