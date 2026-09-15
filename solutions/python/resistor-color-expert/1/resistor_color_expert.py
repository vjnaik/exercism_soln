"""Exercise: Resistor Color Expert"""


def resistor_label(colors: list[str]) -> str:
    """ Calculates the total value in resistance
        plus the tolerance value """
    # Required Data
    color_val: dict[str, int] = {
        "black": 0, "brown": 1, "red": 2,
        "orange": 3, "yellow": 4, "green": 5,
        "blue": 6, "violet": 7, "grey": 8, "white": 9
    }
    
    tolerance: dict[str, float] = {
        "grey": 0.05, "violet": 0.1, "blue": 0.25,
        "green": 0.5, "brown": 1, "red": 2,
        "gold": 5, "silver": 10
    }
    
    suffix: dict[int, str] = {0: "", 1: "kilo", 2: "mega", 3: "giga"}
    
    # One band check
    if len(colors) == 1 and colors[0] == "black":
        return "0 ohms"

    # 4- or 5-band calculations
    if len(colors) == 5:
        value: int = (color_val[colors[0]] * 100 + color_val[colors[1]] * 10 + color_val[colors[2]]) * pow(10, color_val[colors[3]])
    else:
        value: int = (color_val[colors[0]] * 10 + color_val[colors[1]]) * pow(10, color_val[colors[2]])

    # Calculate the correct suffix
    count: int = 0
    prev: float | int = float(value)
    new: float = prev / 1000

    while new >= 1.0:
        prev = new
        count += 1
        new = prev / 1000
    
    # Fix integral values
    prev = int(prev) if prev.is_integer() else prev

    # Tolerance value selection
    tol: float = tolerance[colors[-1]]
    
    return f"{prev} {suffix[count]}ohms ±{tol}%"