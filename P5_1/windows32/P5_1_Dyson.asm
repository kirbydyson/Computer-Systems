; Author:                 Kirby Dyson
; Assignment Title:       P5_1, Weighted Average
; Assignment Description: computes the weighted average and sum of four grades

; Due Date:               3/13/2024
; Date Created:           3/10/2024
; Date Last Modified:     3/13/2024

.586                                       ; specify 32 bit processor
.MODEL FLAT                                ; specify memory model as flat

INCLUDE io.h                               ; header file for input/output

.STACK 4096                                ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter grade 1", 0         ; message to get first grade
prompt2 BYTE    "Enter weight 1", 0        ; message to get first weight
prompt3 BYTE    "Enter grade 2", 0         ; message to get second grade
prompt4 BYTE    "Enter weight 2", 0        ; message to get second weight
prompt5 BYTE    "Enter grade 3", 0         ; message to get third grade
prompt6 BYTE    "Enter weight 3", 0        ; message to get third weight
prompt7 BYTE    "Enter grade 4", 0         ; message to get fourth grade
prompt8 BYTE    "Enter weight 4", 0        ; message to get fourth weight
result  BYTE    "The result is", 0         ; message for displaying result 
string  BYTE    20 DUP (?)                 ; buffer to store the input

result2 BYTE    "The weighted sum is: "    ; message for displaying sum
sum     BYTE    11 DUP (?), 0dh            ; buffer to store the sum
result3 BYTE    "The average is: "         ; message for displaying average
avg     BYTE    11 DUP (?), 0              ; buffer to store the average

grade1  DWORD   11 DUP (?), 0              ; buffer to store grade1
grade2  DWORD   11 DUP (?), 0              ; buffer to store grade2
grade3  DWORD   11 DUP (?), 0              ; buffer to store grade3
grade4  DWORD   11 DUP (?), 0              ; buffer to store grade4


.CODE
_MainProc PROC
        input   prompt1, string, 20        ; prompt user for first grade
        atod    string                     ; convert input to integer
        mov     grade1, eax                ; store first grade in buffer

        input   prompt2, string, 20        ; prompt user for first weight
        atod    string                     ; conver input to integer
        mov     ebx, eax                   ; store first weight in scratch
        imul    eax, grade1                ; multiply grade by weight
        mov     ecx, eax                   ; store weighted sum in scratch

        input   prompt3, string, 20        ; prompt user for second grade
        atod    string                     ; convert input to integer
        mov     grade2, eax                ; store grade in buffer

        input   prompt4, string, 20        ; prompt user for second weight
        atod    string                     ; convert input to integer
        add     ebx, eax                   ; add weights
        imul    eax, grade2                ; multiply grade by weight
        add     ecx, eax                   ; add weighted sum

        input   prompt5, string, 20        ; prompt user for third grade
        atod    string                     ; convert input to integer
        mov     grade3, eax                ; store grade in buffer
        
        input   prompt6, string, 20        ; prompt user for third weight
        atod    string                     ; convert input to integer
        add     ebx, eax                   ; add weights
        imul    eax, grade3                ; multiply grade by weight
        add     ecx, eax                   ; add weighted sum

        input   prompt7, string, 20        ; prompt user for fourth grade
        atod    string                     ; convert input to integer
        mov     grade4, eax                ; store grade in buffer
         
        input   prompt8, string, 20        ; prompt user for fourth weight
        atod    string                     ; convert input to integer
        add     ebx, eax                   ; add weights
        imul    eax, grade4                ; multiply grade by weight
        add     ecx, eax                   ; add weighted sum

        mov     eax, ecx                   ; move weighted sum to eax
        cdq                                ; clear ebx
        idiv    ebx                        ; divide weighted sum by sum of weights
        dtoa    sum, ecx                   ; convert sum to ASCII characters
        dtoa    avg, eax                   ; convert average to ASCII character
   
        output   result, result2           ; display the results
      

        sub     eax, eax                   ; exit with return code 0
        ret                                ; return to calling code
_MainProc ENDP
END                                        ; end of source code

