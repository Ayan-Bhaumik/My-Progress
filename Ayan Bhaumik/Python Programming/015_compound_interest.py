"""
Program Name: 015_compound_interest.py
Question: Calculate compound interest?
Reasoning: Formula: P(1+R/100)^T - P.
"""

p, r, t = 1000, 5, 2
print(f"CI: {p * (1 + r/100)**t - p:.2f}")
