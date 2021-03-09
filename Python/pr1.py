def TaskOne():
    a = float(input('Введите число: ')) 
    b = a%3 + a**2 + a**3 + (a**4 - 1.5)/5
    print(b)

def TaskTwo():
    n = int(input('Введите n: '))
    result = 0
    if (n > 0):
        for i in range(n+1):
            result += i**2
    else: 
        result = n*(n+1)*(n+2)/(n+3)
    print(result)

TaskOne()
TaskTwo()
