datatype allergen = Eggs
                  | Peanuts
                  | Shellfish
                  | Strawberries
                  | Tomatoes
                  | Chocolate
                  | Pollen
                  | Cats

fun allergicTo score agn =
  let fun hasIt value = 
        Word.toInt (Word.andb(Word.fromInt score, Word.fromInt value)) <> 0 in
    case agn of
      Eggs => hasIt 1
    | Peanuts => hasIt 2
    | Shellfish => hasIt 4
    | Strawberries => hasIt 8
    | Tomatoes => hasIt 16
    | Chocolate => hasIt 32
    | Pollen => hasIt 64
    | Cats => hasIt 128
  end

fun allergies score =
  let val agnList = [Eggs, Peanuts, Shellfish, Strawberries, Tomatoes, Chocolate, Pollen, Cats] in
    List.filter (fn x => allergicTo score x) agnList
  end