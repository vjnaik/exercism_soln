.equ INVALID_NUMBER, -1

.text
.globl steps

steps:
        mov x1, x0
        mov w2, #-1      //Error Flag
        cmp x1, #0
        b.le finish      //Compare if <= 0
        mov w2, wzr      //Reset Counter
loop:
        cmp x1, #1       //Final Condition
        b.eq finish
        and w3, w1, #1
        cmp w3, #1       //Check even or odd
        b.eq odd
        mov w3, #1       //Even Case
        lsr x1, x1, x3   //Divide by 2 (>> 2)
        add w2, w2, #1  
        b loop           //Loop to beginning
odd:
        mov w3, #3       //Odd Case
        mul x1, x1, x3
        add x1, x1, #1
        add w2, w2, #1
        b loop;          //Loop to beginning
finish:
        mov w0, w2       //Return Count
        ret
