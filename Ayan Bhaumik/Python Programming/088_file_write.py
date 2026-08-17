"""
Program Name: 088_file_write.py
Question: Write to a file?
Reasoning: Uses open() with 'w'.
"""

with open("test.txt", "w") as f:
    f.write("Hello File!")
print("File written.")
