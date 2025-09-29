.equ HUNDRED, 100
.equ FOUR, 4

.macro MOD_CHECK num, divisor, label
    udiv w3, \num, \divisor         // w3 = num / divisor
    msub w3, w3, \divisor, \num     // w3 = num - (w3 * divisor)
    cmp w3, #0
    b.eq \label
.endm

.data
false: .asciz "FALSE"
true: .asciz "TRUE"

.text
.globl leap_year

leap_year:
        mov w1, FOUR                // Store 4 in w1
        mov w2, HUNDRED             // Store 100 in w2
        mul w4, w2, w1              // Store 400 in w4
                
        MOD_CHECK w0, w4, is_leap   // Check % 400 == 0 -> leap year
        MOD_CHECK w0, w2, not_leap  // Check % 100 == 0 -> not leap
        MOD_CHECK w0, w1, is_leap   // Check % 4 == 0 -> leap year
not_leap:
        mov w0, false               // Fall through not leap
        ret
is_leap:
        mov w0, true                // Leap year case
        ret