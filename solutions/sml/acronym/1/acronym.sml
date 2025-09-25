fun abbreviate (phrase: string): string =
  String.implode(List.map (fn x => Char.toUpper(String.sub(x,0))) (String.tokens (fn x => x = #" " orelse x = #"-" orelse x = #"_") phrase))