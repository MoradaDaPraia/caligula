print("Type in a number: ", end="")

number = int(input())

if number % 2 == 0:
    print(f"{number} is even!")
else:
    print(f"{number} is odd!")
