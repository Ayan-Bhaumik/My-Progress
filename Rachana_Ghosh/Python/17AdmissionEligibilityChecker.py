Math=int(input("Enter the marks for maths:"))
Physics=int(input("Enter the marks for physics:"))
CS=int(input("Enter the marks for CS: "))
percentage=(Math+Physics+CS)/300*100
print(f"Percentage obtained:{percentage}")
if Math>=60 and Physics>=50 and CS>=60 and percentage>=85:
    print("Eligible for admission and scholarship.")
elif Math>=60 and Physics>=50 and CS>=60 and percentage>=65:
    print("Eligible for admission.")
else:
    print("Not Eligible for admission.")