;This is my first assembly file
;Gonna do some basic stuff
; C7 is my led
.global Aadd3
.global TglPORTC
.global StrCount
.equ PORTC, 8
.equ DDRC, 7

;R24,R22,R20 have the parameters, R24 will have the sum
Aadd3:
    
    add R24,R22
    add R24,R20
    ret
TglPORTC:
    ;Get PORTC
    ;ldi R16,0x80
    sbi DDRC,7
    in R17,PORTC
    eor R17,R24
    out PORTC,R17
    ret
StrCount:
    ldi R19,0
    movw r26,r24
    loop:
        ld R18,X+
        cpi r18,0
        breq done
        inc R19
        jmp loop
    done:
        mov r24,r19
        ret