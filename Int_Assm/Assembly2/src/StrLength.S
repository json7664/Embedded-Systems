

.global StrLen
;1 Parameter, first string char 
;25:24, Address of first char
;R16 is our accumulator
;R17 holds the current char
StrLen:
    ldi R16, 0      ;Set count to 0
    movw R26, R24   ;X has the address of first char
NextChar:
    ld R17,X+
    cpi R17,0
    breq done
    cpi R17,32      ;Is it a space?
    breq NextChar
    inc R16
    jmp NextChar



done:
    mov R24,R16     ;Put accumulator into return
    ret

