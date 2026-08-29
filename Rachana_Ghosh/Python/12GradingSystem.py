Name=input("Enter the name of the student: ")
sub1=float(input("Enter the marks for sub1: "))
sub2=float(input("Enter the marks for sub2: "))
sub3=float(input("Enter the marks for sub3: "))
sub4=float(input("Enter the marks for sub4: "))
sub5=float(input("Enter the marks for sub5: "))
Total_marks=sub1+sub2+sub3+sub4+sub5
percentage=(Total_marks/500)*100
if percentage>=90:
    grade="A+"
elif percentage>=80:
    grade="A"
elif percentage>=70:
    grade="B"
elif percentage>=60:
    grade="C"
elif percentage>=50:
    grade="D"
elif percentage>=40:
    grade="E"
else:
    grade="Fail"
if sub1>=33 and sub2>=33 and sub3>=33 and sub4>=33 and sub5>=33:
    result="Passed"
else:
    result="Failed"
print("The name of the student: ",{Name})
print("The total marks obtained: ",{Total_marks})
print("The percentage obtained: ",{percentage})
print("The grade obtained: ",{grade})
print("The result obtained by the student: ",{result})