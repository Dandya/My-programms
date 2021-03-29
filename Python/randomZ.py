import random

def moreRandomAB(A,B):
    countDigits = int(input("Input count random numbers:"))
    arrRandomNumbers = []
    random.seed(version=2)
    for iteration in range(countDigits):
        arrRandomNumbers.append(random.randint(A,B))
    return arrRandomNumbers

a = int(input("Input two numbers A and B to return randon x in (A,B):\n"))
b = int(input())
if  a > b:
    tmp = a
    a = b
    b = tmp
print(f"result: {moreRandomAB(a,b)}")

