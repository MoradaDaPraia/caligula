print("Register your password: ", end="")
password = input()

guess = ""
while guess != password:
    print("Type your password: ", end="")
    guess = input()
    if guess != password:
        print("Your password is incorrect, try again...")

print("Correct password!")
