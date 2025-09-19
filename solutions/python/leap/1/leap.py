def leap_year(year):
    return True if not (year % 400) or ((year % 100) and not (year % 4)) else False