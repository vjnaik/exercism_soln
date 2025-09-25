fun isArmstrongNumber n =
  let fun intPow (base, 0) = 1
      | intPow (base, exp) = base * intPow (base, exp - 1)
      val digits = List.map (fn c => Char.ord c - Char.ord #"0") (String.explode (Int.toString n))
      val power = List.length digits
      val sumDigits = List.foldl (fn (d, acc) => acc + intPow (d, power)) 0 digits
  in
    n = sumDigits
  end