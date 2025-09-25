fun score (x: real, y: real): int =
  let val hyp = Math.sqrt(x * x + y * y) in
    if hyp <= 1.0 then 10
    else if hyp > 1.0 andalso hyp <= 5.0 then 5
    else if hyp > 5.0 andalso hyp <= 10.0 then 1
    else 0
  end