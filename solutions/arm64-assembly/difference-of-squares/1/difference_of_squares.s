.text
.globl square_of_sum
.globl sum_of_squares
.globl difference_of_squares

square_of_sum:
        add     x1, x0, #1
        mul     x0, x0, x1
        lsr     x0, x0, #1              // n * (n + 1)/2
        mul     x0, x0, x0              // Squared
        ret
sum_of_squares:
        add     x1, x0, #1
        mul     x2, x0, x1              
        add     x0, x0, x1              
        mul     x0, x0, x2
        mov     x1, #6
        udiv    x0, x0, x1              //n * (n + 1) * (2n + 1)/6
        ret
difference_of_squares:
        add     x1, x0, #1
        add     x2, x0, x1              
        mul     x0, x0, x1
        lsr     x0, x0, #1              //n * (n + 1)/2
        mul     x2, x0, x2
        mov     x1, #3
        udiv    x2, x2, x1              
        mul     x0, x0, x0              
        sub     x0, x0, x2
        ret
