def is_valid(isbn):
    if 'X' in isbn and isbn[-1] != 'X':
        return False
    
    isbn_list = []
    for char in isbn:
        if char == 'X':
            isbn_list.append(10)
        elif char.isdigit():
            isbn_list.append(int(char))
        elif char != '-':
            return False

    if len(isbn_list) != 10:
        return False
    
    result = 0
    for value, mul in zip(isbn_list,range(1,11)):
        result += value * mul
    
    return result % 11 == 0
