Days=int(input("Enter the number of days: "))
years=Days//365
remaining_days=Days%365
months=remaining_days//30
remaining_days=remaining_days%30
print(f"The number of years: ",{years})
print(f"The number of months: ",{months})
print(f"The number of Remaining days: ",{remaining_days})