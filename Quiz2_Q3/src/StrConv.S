.global getVal
;1 Parameter, first string char 
;25:24, Address of first char
;R18 is our accumulator
;R17 holds the current char
getVal:
    ldi R18, 0          ;Set initial total to 0 
    movw R26, R24       ;X has the address of first char
   
    ld R17,X+
    cpi R17,57          ; Compare anything greater than 9
    brpl Error
   
    cpi R17,0
    breq done

    sub R17, 48        ; Substract 48 to convert from ASCII to decimal
    mul R18,10
    add R18, R17

    jmp getVal

Error:
    mov R17, -1         ; ret -1 on error

done:
    mov R24,R18    ;Put accumulator into return
    ret


    