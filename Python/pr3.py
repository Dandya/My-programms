with open("add", "w") as f:
    print("Казнить, нельзя помиловать\n", file = f)
result = []
with open("add", "r") as f:
    result = f.read().strip().split(',')
print(result)
