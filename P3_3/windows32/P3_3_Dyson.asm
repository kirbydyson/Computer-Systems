; Author:                 Kirby Dyson
; Assignment Title:       P3_3, Subtract Two Values
; Assignment Description: calculate the difference of two numerical values

; Due Date:               2/20/2024
; Date Created:           2/17/2024
; Date Last Modified:     2/19/2024

.586                                     ; specify 32 bit processor
.MODEL FLAT                              ; specify memory model as flat

INCLUDE io.h                             ; header file for input/output

.STACK 4096                              ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter first number", 0  ; message to get the first value
prompt2 BYTE    "Enter second number", 0 ; message to get the second value
string  BYTE    20 DUP (?)               ; buffer to store the input
result  BYTE    "The difference is", 0   ; message for displaying the result
diff    BYTE    11 DUP (?), 0            ; buffer to store the difference

.CODE
_MainProc PROC
        input   prompt1, string, 20      ; prompt user for first value
        atod    string                   ; convert user input to numeric value
        mov     ebx, eax                 ; store first value in scratch

        input   prompt2, string, 20      ; prompt user for second value
        atod    string                   ; convert user input to numeric value
        sub     ebx, eax                 ; subtract first from second value
        
        dtoa    diff, ebx                ; convert difference to ASCII
        output  result, diff             ; display results to stdout

        sub     ebx, ebx                 ; exit with return code 0
        ret                              ; return to calling code
_MainProc ENDP
END                                      ; end of source code

