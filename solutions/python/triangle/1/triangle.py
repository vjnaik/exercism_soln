def check_valid(sides):
    a, b, c = sides
    check1 = a > 0 and b > 0 and c > 0
    check2 = a + b >= c and b + c >= a and a + c >= b
    return check1 and check2

def equilateral(sides):
    a, b, c = sides
    return check_valid(sides) and a == b == c

def isosceles(sides):
    a, b, c = sides
    return check_valid(sides) and (a == b or b == c or a == c)


def scalene(sides):
    a, b, c = sides
    return check_valid(sides) and a != b != c != a
