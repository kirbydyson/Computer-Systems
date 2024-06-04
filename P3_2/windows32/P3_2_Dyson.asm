; Author:                 Kirby Dyson
; Assignment Title:       P3_2, Add Three Values
; Assignment Description: P3_2_Dyson.asm - adds the sum of three numbers

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
prompt3 BYTE    "Entre third number", 0  ; message to get the third value
string  BYTE    20 DUP (?)               ; buffer to store the input
result  BYTE    "The sum is", 0          ; message for displaying the result
sum     BYTE    11 DUP (?), 0            ; buffer to store the sum

.CODE
_MainProc PROC
        input   prompt1, string, 20      ; prompt user for first value
        atod    string                   ; convert user input to numeric value
        mov     ebx, eax                 ; store first value to scratch

        input   prompt2, string, 20      ; prompt user for second value
        atod    string                   ; convert user input to numeric value
        add     eax, ebx                 ; add first value to second value, as sum
        mov     ebx, eax                 ; store second value to scratch

        input   prompt3, string, 20      ; prompt user for third value
        atod    string                   ; convert user input to numeric value
        add     eax, ebx                 ; add third value to the sum
        
        dtoa    sum, eax                 ; convert sum to ASCII, store in "sum"
        output  result, sum              ; display results to stdout

        sub     eax, eax                 ; exit with return code 0
        ret                              ; return to calling code
_MainProc ENDP
END                                      ; end of source code

