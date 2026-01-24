def _get_factors(number):
    """ Returns all the factors excluding the number itself.

    :param number: int a positive integer > 1
    :return: list of factors excluding the number
    """
    factors = [1] + [num for num in range(2, number//2 + 1) if number % num == 0]

    return factors


def classify(number):
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number <= 0:
        raise ValueError("Classification is only possible for positive integers.")

    if number == 1:
        return "deficient"
    
    summed_factors = sum(_get_factors(number))

    if summed_factors > number:
        return "abundant"
    
    if summed_factors == number:
        return "perfect"

    return "deficient"
