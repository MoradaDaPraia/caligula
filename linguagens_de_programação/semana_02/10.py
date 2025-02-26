secret = "pythonic"

guess = ""
while guess != secret:
    print("Type in a guess: ", end="")
    guess = input()
    if guess != secret:
        print("Your guess is incorrect, try again...")

print("Your guess is correct!")
