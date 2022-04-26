

.global StrLen
; 1 Parameter, first string char
; 25:24 25 is high byte and 24 is low byte: addr of first char
; R16 is our accumulator 
; R17 holds the current char
StrLen:                          ; Label/function
    ldi R16, 0                   ; Set count to 0
    mov R26, R24                 ; This is taking care of low byte: x has the address of first char
NextChar:
    ld R17, X+                   ; R17 has the first char (post increment X+)
    cpi R17, 0                   ; comparing R17 with 0
    breq done 
    cpi R17, 32                  ; Is it a space? skip it dont count space char
    breq NextChar
    inc R16
    jmp NextChar


done:
    mov R24, R16                ; put accumulator into return
    ret                         

