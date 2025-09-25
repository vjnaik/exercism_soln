fun collatz n =
  let fun count acc num =
        case num of
          1 => acc
        | _ => let val res = if num mod 2 = 0 then num div 2 else 3 * num + 1 in
                  count (acc + 1) res
                end
  in
    if n > 0 then
      SOME (count 0 n)
    else
      NONE
  end