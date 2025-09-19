def response(hey_bob):
    stripped = hey_bob.strip()

    if not stripped:
        return "Fine. Be that way!"
    
    is_question = stripped.endswith("?")
    is_shouting = any(c.isalpha() for c in stripped) and stripped.upper() == stripped

    if is_shouting and is_question:
        return "Calm down, I know what I'm doing!"
    elif is_shouting:
        return "Whoa, chill out!"
    elif is_question:
        return "Sure."
    else:
        return "Whatever."