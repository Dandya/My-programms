from math import sqrt

def FacNum(number, result = [1], lastDiv = 2):
    print(number)
    if number == 1:
        return result
    limit = int(sqrt(number)) + 1
    if limit < lastDiv:
        result.append(number)
        return result
    div = lastDiv
    while div != limit:
        if number%div == 0:
            result.append(div)
            number //= div
            return FacNum(number, result, div)
        div += 1
    result.append(number)
    return result

