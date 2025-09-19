def is_armstrong_number(number):
    num_s = str(number)
    armstrong = sum([int(x) ** len(num_s) for x in num_s])
    return armstrong == number