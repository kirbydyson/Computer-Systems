; Author:                 Kirby Dyson
; Assignment Title:       P4_1, Bocce Perimeter
; Assignment Description: computes the perimeter of a Bocce court

; Due Date:               2/23/2024
; Date Created:           2/20/2024
; Date Last Modified:     2/21/2024

.586                                     ; specify 32 bit processor
.MODEL FLAT                              ; specify memory model as flat

INCLUDE io.h                             ; header file for input/output

.STACK 4096                              ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter width", 0         ; message to get the width
prompt2 BYTE    "Enter length", 0        ; message to get the length
string  BYTE    20 DUP (?)               ; buffer to store the input
result  BYTE    "The perimeter is", 0    ; message for displaying the result
per     BYTE    11 DUP (?), 0            ; buffer to store the perimeter

.CODE
_MainProc PROC
        input   prompt1, string, 20      ; prompt user for first value
        atow    string                   ; convert user input to numeric value
        mov     bx, ax                   ; store first value in scratch

        input   prompt2, string, 20      ; prompt user for second value
        atow    string                   ; convert user input to numeric value
        add     ax, bx                   ; add first value to second
        add     ax, ax                   ; double the sum of the two values
        
        wtoa    per, ax                  ; convert perimeter to ASCII
        output  result, per              ; display results to stdout

        sub     ax, ax                   ; exit with return code 0
        ret                              ; return to calling code
_MainProc ENDP
END                                      ; end of source code

