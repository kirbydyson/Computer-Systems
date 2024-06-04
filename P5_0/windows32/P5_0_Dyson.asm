; Author:                 Kirby Dyson
; Assignment Title:       P5_0, Calculate Average
; Assignment Description: computes the average of four exam scores

; Due Date:               3/13/2024
; Date Created:           3/10/2024
; Date Last Modified:     3/13/2024

.586                                            ; specify 32 bit processor
.MODEL FLAT                                     ; specify memory model as flat

INCLUDE io.h                                    ; header file for input/output

.STACK 4096                                     ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter first exam score", 0     ; message to get first score
prompt2 BYTE    "Enter second exam score", 0    ; message to get second score
prompt3 BYTE    "Enter third exam score", 0     ; message to get third score
prompt4 BYTE    "Enter fourth exam score", 0    ; message to get fourth score
string  BYTE    20 DUP (?), 0                   ; buffer to store the input
result  BYTE    "The result is", 0              ; message for displaying result
result2 BYTE    "The sum is: "                  ; message for displaying sum
sum     BYTE    11 DUP (?), 0dh                 ; buffer to store the sum
result3 BYTE    "The average is: "              ; message for displaying average
avg     BYTE     11 DUP (?), 0                  ; buffer to store the average


.CODE
_MainProc PROC
        input   prompt1, string, 20             ; prompt user for first score
        atod    string                          ; convert input to integer
        mov     ebx, eax                        ; store first score in scratch

        input   prompt2, string, 20             ; prompt user for second score
        atod    string                          ; convert input to integer
        add     ebx, eax                        ; add second value to sum

        input   prompt3, string, 20             ; prompt user for third score
        atod    string                          ; convert input to integer
        add     ebx, eax                        ; add third score to sum

        input   prompt4, string, 20             ; prompt user for fourth score
        atod    string                          ; convert input to integer
        add     ebx, eax                        ; add fourth score to sum

        dtoa    sum, ebx                        ; convert sum to ASCII
        add     ebx, eax                        ; double fourth score
        mov     eax, ebx                        ; move sum to eax
        cdq                                     ; clear ebx
        mov     ebx, 5                          ; set the exams to divide by
        div     ebx                             ; divide sum by # of exams

        dtoa    avg, eax                        ; convert average to ASCII
        output  result, result2                 ; display the results

        sub     eax, eax                        ; exit with return code 0
        ret                                     ; return to calling code
_MainProc ENDP
END                                             ; end of source code

