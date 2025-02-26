secret = 87

guess = ""
while guess != secret:
    print("Type in a number between 1-99: ", end="")
    guess = int(input())
    if guess != secret:
        print("Your guess is incorrect, try again...")

print("Your guess is correct!")
