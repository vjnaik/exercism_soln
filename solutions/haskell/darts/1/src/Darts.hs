module Darts (score) where

score :: Float -> Float -> Int
score x y
    | hypot <= 1.0 = 10
    | hypot <= 5.0 = 5
    | hypot <= 10.0 = 1
    | otherwise = 0
    where hypot = sqrt(x * x + y * y)