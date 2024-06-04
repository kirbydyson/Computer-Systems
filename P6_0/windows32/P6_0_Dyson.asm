; Author:                 Kirby Dyson
; Assignment Title:       P6_0, Incremental Sum and Average
; Assignment Description: computes the sum and average of all grades entered

; Due Date:               3/20/2024
; Date Created:           3/18/2024
; Date Last Modified:     3/19/2024


.586                                           ; specify 32 bit processor
.MODEL FLAT                                    ; specify memory model as flat

INCLUDE io.h                                   ; header file for input/output

.STACK 4096                                    ; set the size to 4096 bytes

.DATA
prompt1 BYTE    "Enter number of grades", 0    ; message to get # of grades
prompt2 BYTE    "Enter grade", 0               ; message to get grades
string  BYTE    20 DUP (?)                     ; buffer to store input
result  BYTE    "The sum is", 0                ; message for displaying sum
sum     DWORD   11 DUP (?), 0                  ; buffer to store sum
result2 BYTE    "The average is", 0            ; message for displaying average
avg     DWORD   11 DUP (?), 0                  ; buffer to store average
nums    DWORD   11 DUP (?), 0                  ; buffer to store # of grades


.CODE
_MainProc PROC
nonZero:     
        input   prompt1, string, 20            ; prompt user for # of grades
        atod    string                         ; convert input to integer
        mov     ebx, eax                       ; store number in memory
        cmp     ebx, 0                         ; compare number to zero
        jle     nonZero                        ; loop again if number is not 
                                               ; positive

grades:        
        input   prompt2, string, 20            ; prompt user for grades
        atod    string                         ; convert input to integer
        add     sum, eax                       ; add grade to sum
        mov     ecx, sum                       ; move sum to ecx
        inc     nums                           ; increment # of grades
        mov     eax, sum                       ; move sum to eax
        cdq                                    ; clear edx
        idiv    nums                           ; divide sum by # of grades

        dtoa    string, ecx                    ; convert sum to ASCII
        output  result, string                 ; display the sum
        dtoa    string, eax                    ; convert average to ASCII
        output  result2, string                ; display the average

        cmp     nums, ebx                      ; compares # of grades
        jl      grades                         ; loop again if more grades
                                               ; should be entered

        sub     eax, eax                       ; exit with return code 0
        ret                                    ; return to calling code
_MainProc ENDP
END                                            ; end of source code

