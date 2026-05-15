from string import ascii_lowercase
from string import ascii_uppercase


def rotate(text, key):
    cipher_up = list(ascii_uppercase)
    len_up = len(cipher_up)
    cipher_lo = list(ascii_lowercase)
    len_lo = len(cipher_lo)
    result = []
    
    for c in text:
        if c.islower():
            result.append(cipher_lo[(cipher_lo.index(c) + key) % len_lo])
        elif c.isupper():
            result.append(cipher_up[(cipher_up.index(c) + key) % len_up])
        else:
            result.append(c)
      
    return "".join(result)