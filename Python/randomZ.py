import random

def moreRandomAB(A,B):
    countDigits = int(input("Input count random numbers:"))
    arrRandomNumbers = []
    random.seed(version=2)
    for iteration in range(countDigits):
        arrRandomNumbers.append(random.randint(A,B))
    return arrRandomNumbers
