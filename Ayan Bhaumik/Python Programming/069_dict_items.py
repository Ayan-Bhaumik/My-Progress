"""
Program Name: 069_dict_items.py
Question: Iterate dict items?
Reasoning: Uses .items().
"""

d = {"a": 1, "b": 2}
for k, v in d.items():
    print(f"{k}: {v}")
