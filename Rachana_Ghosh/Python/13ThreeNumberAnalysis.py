a=int(input("Enter the value of a: "))
b=int(input("Enter the value of b: "))
c=int(input("Enter the value of c: "))
if a>b and a>c:
    largest=a
    if b>c:
      middle=b
      smallest=c
    else:
      middle=c
      smallest=b
elif b>a and b>c:
    largest=b
    if a>c:
       middle=a
       smallest=c
    else:
       middle=c
       smallest=a
else:
    largest=c
    if a>b:
       middle=a
       smallest=b
    else:
       middle=b
       smallest=a
print(f"Largest number: ",{largest})
print(f"Middle number : ",{middle})
print(f"Smallest number: ",{smallest})
if  largest%2==0:
  print("Largest number is even")
else:
   print("Largest number is odd")
if smallest%middle==0:
    print("Smallest number is divisible by middle number")
else:
   print("Smallest number is not divisible by middle number")
       


