fun calc_pow'(n: int): IntInf.int =
  IntInf.pow(2, n)

fun square(n: int): string =
  if n < 1 orelse n > 64 then
    raise Fail "square must be between 1 and 64"
  else
    IntInf.toString(calc_pow'(n - 1))

fun total(): string =
  IntInf.toString(calc_pow'(64) - 1)