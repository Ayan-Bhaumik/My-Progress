"""
Program Name: 099_regex_search.py
Question: Regex search?
Reasoning: Uses re module.
"""

import re
match = re.search(r"\d+", "There are 42 apples")
print(match.group() if match else "No match")
