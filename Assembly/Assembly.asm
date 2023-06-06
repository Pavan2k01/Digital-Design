.include "/storage/self/primary/digital-design/ide/piosetup/Assembly/m328Pdef.inc"

.def    input1 = R16    ; Register to store input1
.def    input2 = R17    ; Register to store input2

.cseg
.org    0x0000          ; Reset vector
    rjmp    start

start:
    ; Initialize I/O ports
    ldi     input1, (1 << DDD2)   ; Set Pin 2 (input1) as input
    cbi     DDRD, PD2
    ldi     input2, (1 << DDD3)   ; Set Pin 3 (input2) as input
    cbi     DDRD, PD3
    ldi     r16, (1 << DDB5) ; Set Pin 13 (output) as output
    out     DDRB, r16

loop:
    ; Read input bits from Pin 2 and Pin 3
    sbic    PIND, PD2            ; Check if Pin 2 is HIGH
    rjmp    input2_low
    ldi     input2, 1             ; Set input2 bit to 1
    rjmp    input2_done
input2_low:
    ldi     input2, 0             ; Set input2 bit to 0
input2_done:
    sbic    PIND, PD3            ; Check if Pin 3 is HIGH
    rjmp    input1_low
    ldi     input1, 1             ; Set input1 bit to 1
    rjmp    input1_done
input1_low:
    ldi     input1, 0             ; Set input1 bit to 0
input1_done:

    ; Perform XOR operation
    eor     input1, input2

    ; Write result to Pin 13 (output)
    sbrc    input1, 0            ; Check if output bit 0 is set
    sbi     PORTB, PB5           ; Set Pin 13 HIGH
    sbrs    input1, 0            ; Check if output bit 0 is cleared
    cbi     PORTB, PB5           ; Set Pin 13 LOW

    rjmp    loop                ; Repeat indefinitely
