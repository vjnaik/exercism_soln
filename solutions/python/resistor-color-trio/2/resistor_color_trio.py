def label(colors: list[str]) -> str:
    """ Calculates the total value in resistance
        based on the trio of colors"""
    color_val: dict[str, int] = {
    "black": 0, "brown": 1, "red": 2,
    "orange": 3, "yellow": 4, "green": 5,
    "blue": 6, "violet": 7, "grey": 8, "white": 9
    }
    suf = {0: "", 1: "kilo", 2: "mega", 3: "giga"}
    
    value: int = (color_val[colors[0]] * 10 + color_val[colors[1]]) * pow(10, color_val[colors[2]])
    
    count: int = 0
    prev: int = value
    new: int = prev // 1000
    while new != 0:
        prev = new
        count += 1
        new = prev // 1000
    
    return f"{prev} {suf[count]}ohms"