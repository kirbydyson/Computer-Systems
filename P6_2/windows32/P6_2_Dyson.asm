; Author:                 Kirby Dyson
; Assignment Title:       P6_2, Sum Input Values
; Assignment Description: computes the sum of input values

; Due Date:               3/20/2024
; Date Created:           3/18/2024
; Date Last Modified:     3/19/2024

.586                                        ; specify 32 bit processor
.MODEL FLAT                                 ; specify memory model as flat

INCLUDE io.h                                ; header file for input/output

.STACK 4096                                 ; set size for 4096 bytes

.DATA
prompt1 BYTE    "Enter value", 0            ; message to get values
string  BYTE    20 DUP (?)                  ; buffer to store input
result  BYTE    "The sum is", 0             ; message for displaying sum
sum     WORD    11 DUP (?), 0               ; buffer to store sum
result2 BYTE    "The # of zeroes are", 0    ; message for displaying # of zeros
zeros   WORD    11 DUP (?), 0               ; buffer to store # of zeros

.CODE
_MainProc PROC
        mov     bx, 0                       ; initialize bx to 0
        mov     dx, 0                       ; initialize dx to 0

inLoop:
        input   prompt1, string, 20         ; prompt user for values
        atow    string                      ; convert input to integer
        cmp     ax, 0                       ; compare value to zero
        jnz     nonZero                     ; jump if input is positive
        inc     dx                          ; increment # of zeros
        cmp     dx, 10                      ; compare # of zeros to 10
        je      endLoop                     ; jump if there are 10 zeros

nonZero:
        add     bx, ax                      ; add value
        cmp     bx, 5000                    ; compare sum to 5000
        jge     endLoop                     ; jump if sum is greater than 5000
        loop    inLoop                      ; loop again if sum is less than 5000

endLoop:
        wtoa    sum, bx                     ; convert sum to ASCII
        wtoa    zeros, dx                   ; convert # of zeros to ASCII
        output  result, sum                 ; display the sum
        output  result2, zeros              ; display the # of zeros

        sub     eax, eax                    ; exit with return code 0
        ret                                 ; return to calling code
_MainProc ENDP
END                                         ; end of source code

