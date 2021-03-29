import time
#Задание 1
def time_decorator(func):
    def funcWihtTime(*args, **kwargs):
        timeOld = time.time();
        result = func(*args, **kwargs)
        print(time.time() - timeOld)
        return result
    return funcWihtTime

@time_decorator
def add(x, y):
    return x+y

#print(add(1,2))
#Конец задания 1

#Задание 2 
def cryptAndDeCrytp(string, byte):
    newString = ''
    for char in string:
        newString += chr(char ^ byte)
    return newString

#x=5
string = cryptAndDeCrytp(b'AAAAaaaaBBBB',12)
print(string)
print(cryptAndDeCrytp(string.encode(),12))
#Конец задания 2

#Задание 3
def average_store(student_name, marks = [0]):
    if(type(marks) is not list or type(student_name) is not str):
            print("uncorrect input")
            return -1
    countMarks = 0
    stores = 0
    for mark in marks:
        stores += mark
        countMarks += 1
    averageStore = stores/countMarks
    print(f"Avarage store for {student_name} is {averageStore}")
    return averageStore

#average_store("Вася", [5,4,5,3,4])
#average_store("Вася")
#Конец задания 3

#Задание 4
def decor(func):
    def wrapper(*args, **kwargs):
        wrapper.count += 1
        return func(*args, **kwargs)
    wrapper.count = 0
    return wrapper

