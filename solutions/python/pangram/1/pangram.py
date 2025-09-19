from string import ascii_lowercase

def is_pangram(sentence):
    letters = set(char for char in sentence.lower() if char in ascii_lowercase)
    return len(letters) == 26