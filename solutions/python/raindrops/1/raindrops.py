def convert(number):
    drops = {3:"Pling", 5:"Plang", 7:"Plong"}
    string = "".join(drops[k] if number % k == 0 else "" for k in drops)
    return string if string else str(number)