fun get_bin num xs =
  if num = 0 then
    xs
  else
    get_bin (num div 2) ((num mod 2)::xs)

fun eggCount number =
  let val lst = get_bin number []
      fun sum ys acc =
        case ys of
          [] => acc
        | y::ys' => sum ys' (y + acc)
  in
    sum lst 0
  end