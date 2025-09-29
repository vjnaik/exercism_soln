.text
.globl reverse

reverse:
    mov   x1, xzr           // index left
    mov   x2, xzr           // index right

length:
    ldrb  w3, [x0, x2]      // load byte
    cbz   w3, end           // check if end
    add   x2, x2, #1        // Advance index
    b     length
end:
    cbz   x2, done          // check empty string
loop:
    subs  x2, x2, #1        // decrement index right
    ldrb  w3, [x0, x1]      // load from index left
    ldrb  w4, [x0, x2]      // load from index right
    strb  w4, [x0, x1]      // store swapped data
    strb  w3, [x0, x2]
    add   x1, x1, #1        // increment index left
    cmp   x1, x2
    blt   loop              // check if not same
done:
    ret
