(* Rose tree *)
datatype 'a tree = Empty | Elem of 'a | List of 'a tree list

fun flatten tree =
  let fun helper t xs =
        case t of
          Empty => xs
        | Elem y => y::xs
        | List [] => xs
        | List (z::zs') => helper z xs @ helper (List zs') xs
  in
    helper tree []
  end