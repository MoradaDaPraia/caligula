def greeting(name):
    return f"Welcome to the mission, {name}!"


print("Type in your name: ", end="")

message = greeting(input())

print(message)
