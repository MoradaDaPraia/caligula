print("Type in a number: ", end="")

number = int(input())

if number > 0:
    print(f"{number} is positive!")
elif number < 0:
    print(f"{number} is negative!")
else:
    print(f"{number} is zero!")
