fun name (input: string option) =
  case input of
    NONE => "One for you, one for me."
  |  SOME v => "One for " ^ v ^ ", one for me."