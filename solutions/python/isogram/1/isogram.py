def is_isogram(string):
    char_list = [char for char in list(string.lower()) if char not in " -"]
    return len(set(char_list)) == len(char_list)