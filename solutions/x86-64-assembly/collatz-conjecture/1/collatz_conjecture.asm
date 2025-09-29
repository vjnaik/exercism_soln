section .text
global steps
steps:
    mov eax, -1                ; Set Error Flag
    test edi, edi              ; Get flags on edi
    jle end                    ; Error condition
loop:
    inc eax                    ; Increment counter
    cmp edi, 1                 ; Check for termination value
    je end
    lea edx, [3 * edi + 1]     ; Load address of calculation
    shr edi, 1                 ; Shift Right (carry flag set if odd)
    cmovc edi, edx             ; Update value on carry flag
    jmp loop                   ; Loop back to start
end:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif