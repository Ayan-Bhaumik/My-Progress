Year=int(input("Enter the year:"))
if Year%400==0 or Year%4==0 and Year%100!=0:
    print("Leap Year")
else:
    print("Not a Leap year")
    