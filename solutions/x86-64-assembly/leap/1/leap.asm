%macro MOD_CHECK 2
    mov     ecx, %1                ; %1 is the divisor
    xor     edx, edx               ; zero out edx
    mov     eax, edi               ; get input
    div     ecx                    ; divide by ecx
    test    edx, edx               ; check remainder
    jz      %2                     ; %2 is the label
%endmacro

section .text
global leap_year
leap_year:
    MOD_CHECK 400, is_leap         ; check % 400 == 0 -> leap
    MOD_CHECK 100, not_leap        ; check % 100 == 0 -> not_leap
    MOD_CHECK 4, is_leap           ; check % 4 == 0 -> leap
not_leap:
    mov     eax, 0                 ; false value
    ret
is_leap:
    mov     eax, 1                 ; true value
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif