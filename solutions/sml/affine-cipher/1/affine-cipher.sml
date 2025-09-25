(* computes gcd *)
fun gcd(a, 0) = a
  | gcd(a, b) = gcd(b, a mod b)
(* Extended Euclidean Algorithm *)
fun extendedGCD a b =
    if b = 0 then
        (a, 1, 0)
    else
        let
            val (gcd, x1, y1) = extendedGCD b (a mod b)
            val x = y1
            val y = x1 - (a div b) * y1
        in
            (gcd, x, y)
        end

(* Modular Inverse *)
fun inverse(a, m) =
    let
        val (gcd, x, _) = extendedGCD a m
    in
        if gcd <> 1 then
            raise Fail "a and m must be coprime."  (* Inverse doesn't exist *)
        else
            (x mod m + m) mod m
    end

(* map ascii list into string *)
fun itoa ls = String.implode (List.map Char.chr ls)
(* wether ascii code is valid input or not *)
fun valid_code code = Char.isAlphaNum code 
(* map string char into ascii *)
fun filter' str = List.map Char.ord (List.filter valid_code (String.explode str))
(* General transform function *)
fun transform f code =
      if (code <= 57) then      (* digit *)
        code
      else if (code <= 90) then      (* A..Z *)
        f (code - 65) + 97
      else if (code <= 122) then      (* a..z *)
        f (code - 97) + 97
      else
        raise Fail ("Invalid code: " ^ (Int.toString code))

fun encode (key: {a: int, b: int}, phrase: string) =
  let
    val m = 26  (* Length of the roman alphabet *)
    fun encrypt i = ((#a key) * i + (#b key)) mod m
    fun group value =
      let 
        val group_size = 5
        fun group'([], _, acc) = acc
          | group'(chr::rest, index, acc) = 
                let val step = index + 1
                    val chars = if step mod group_size = 0 andalso step <> (size value) then [chr, #" "] else [chr]
                in
                    group'(rest, index + 1,acc @ chars)
                end
      in
        String.implode (group'(String.explode value, 0, []))
      end        
  in
    if gcd(#a key, m) <> 1 then
      raise Fail "a and m must be coprime."
    else
      group (itoa (List.map (transform encrypt) (filter' phrase)))
  end

fun decode (key: {a: int, b: int}, phrase: string): string =
  let
    val m = 26   (* Length of the roman alphabet *)
    fun decrypt i = inverse(#a key, m) * (i - #b key) mod m
  in
      itoa (List.map (transform decrypt) (filter' phrase))
  end