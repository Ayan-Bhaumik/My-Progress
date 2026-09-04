units=float(input("Enter the number of units:"))
if units<=100:
    bill=units*2
elif units<=300:
    bill=100*2+(units-100)*3
elif units<=500:
    bill=100*2+200*3+(units-300)*5
else:
    bill=100*2+200*3+200*5+(units-500)*7
if bill>2000:
    surcharge=bill*0.05
else:
    surcharge=0
final_bill=bill+surcharge
print(f"Units consumed: ",{units})
print(f"Basic Bill: ",{bill})
print(f"Surcharge: ",{surcharge})
print(f"Final Bill: ",{final_bill})