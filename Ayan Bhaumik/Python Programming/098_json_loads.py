"""
Program Name: 098_json_loads.py
Question: Parse JSON to dict?
Reasoning: Uses json.loads.
"""

import json
s = '{"x": 1, "y": 2}'
print(json.loads(s)["x"])
