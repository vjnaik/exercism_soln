fun stripWhitespace s =
  String.implode (List.filter (fn c => not (Char.isSpace c)) (String.explode s))

fun isQuestion s =
  let val len = String.size s
  in
    len > 0 andalso String.sub(s, len - 1) = #"?"
  end

fun isShouting s =
  let
    val chars = String.explode s
    val letters = List.filter Char.isAlpha chars
  in
    not (List.null letters) andalso List.all Char.isUpper letters
  end

fun response s =
  let val smod = stripWhitespace s in
  if smod = "" then
    "Fine. Be that way!"
  else if isShouting smod andalso isQuestion smod then
    "Calm down, I know what I'm doing!"
  else if isShouting smod then
    "Whoa, chill out!"
  else if isQuestion smod then
    "Sure."
  else
    "Whatever."
  end