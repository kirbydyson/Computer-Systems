; Author:                 Kirby Dyson
; Assignment Title:       P4_0, Evaluate an Expression
; Assignment Description: evaluates the expression 5x+5y-2z

; Due Date:               2/23/2024
; Date Created:           2/20/2024
; Date Last Modified:     2/21/2024

.586                                             ; specify 32 bit processor
.MODEL FLAT                                      ; specify memory model as flat

INCLUDE io.h                                     ; header file for input/output

.STACK 4096                                      ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter the number of apples", 0  ; message to get the first value 
prompt2 BYTE    "Enter the number of oranges", 0 ; message to get the second value
prompt3 BYTE    "Enter the number of bananas", 0 ; message to get the third value
string  BYTE    20 DUP (?)                       ; buffer to store the input
result  BYTE    "The total number is", 0         ; message for displaying the result
sum     BYTE    11 DUP (?), 0                    ; buffer to store the total

.CODE
_MainProc PROC
        input   prompt1, string, 20              ; prompt user for first value
        atod    string                           ; convert user input to numeric value
        mov     ebx, eax                         ; store first value in scratch

        input   prompt2, string, 20              ; prompt user for second value
        atod    string                           ; convert user input to numeric value
        add     ebx, eax                         ; add first value to second
        mov     eax, ebx                         ; copy value to eax
        add     ebx, ebx                         ; double ebx value
        add     ebx, ebx                         ; double ebx value again
        add     ebx, eax                         ; ebx = 5(first + second)

        input   prompt3, string, 20              ; prompt user for third value
        atod    string                           ; convert user input to numeric value
        add     eax, eax                         ; double the third value
        neg     eax;                             ; eax = 5(first)+5(second)-2(third value)
        add     eax, ebx
       
        dtoa    sum, eax                         ; convert total to ASCII
        output  result, sum                      ; display results to stdout

        sub     ebx, ebx                         ; exit with return code 0
        ret                                      ; return to calling code
_MainProc ENDP                
END                                              ; end of source code

