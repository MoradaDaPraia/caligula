print("How many numbers you'll sum? ", end="")

quantity = int(input())

sum = 0
for i in range(quantity):
    print(f"Enter number {i + 1}: ", end="")
    sum += float(input())

print(f"The total sum of the numbers is {sum}.")
