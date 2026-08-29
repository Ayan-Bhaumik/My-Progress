l=float(input("Enter the length : "))
b=float(input("Enter the breadth: "))
h=float(input("Enter the height: "))
volume=l*b*h
total_surface_area=2*(l*b+b*h+l*h)
print(f"Volume of the cuboid:{volume}")
print(f"Total Surface area of the cuboid:{total_surface_area}")