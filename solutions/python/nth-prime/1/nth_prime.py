MAX_NUM = 1000000

prime_array = []

def _generate_sieve(number):
    all_set = set(range(2, MAX_NUM))
    comp_set = { comp for val in range(2, MAX_NUM)
                       for comp in range(val * val, MAX_NUM, val)}

    return sorted(list(all_set - comp_set))


def prime(number):
    global prime_array
    
    if number == 0:
        raise ValueError("there is no zeroth prime")
    
    if len(prime_array) == 0:
        prime_array = _generate_sieve(number)
    
    for i, value in enumerate(prime_array):
        if i + 1 == number:
            return value