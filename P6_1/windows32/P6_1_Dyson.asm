; Author:                 Kirby Dyson
; Assignment Title:       P6_1, Product of Positives
; Assignment Description: computes the product of positive inputs

; Due Date:               3/20/2024
; Date Created:           3/18/2024
; Date Last Modified:     3/19/2024

.586                                        ; specify 32 bit processor
.MODEL FLAT                                 ; specify memory model as flat

INCLUDE io.h                                ; header file for input/output

.STACK 4096                                 ; set size to 4096 bytes

.DATA
prompt1 BYTE    "Enter value", 0            ; message to get values
string  BYTE    20 DUP (?)                  ; buffer to store input
result  BYTE    "The product is", 0         ; message for displaying product
product DWORD   11 DUP (?), 0               ; buffer to store product
result2 BYTE    "The # of zeros are", 0     ; message for displaying # of zeros
zeros   BYTE    11 DUP (?), 0               ; buffer to store # of zeros

.CODE
_MainProc PROC
        mov     ebx, 1                      ; initialize ebx to 1
        mov     dx, 0                       ; initialize dx to 0
        mov     cx, 10                      ; initialize cx to 10

inLoop:
        input   prompt1, string, 20         ; prompt user for values
        atod    string                      ; convert to integer
        cmp     ax, 0                       ; compare value to zero
        jnz     nonZero                     ; jump if input is positive
        inc     dx                          ; increment # of zeros
        cmp     dx, 0                       ; compare # of zeros to 0
        jne     inLoop                      ; loop again if no zeros

nonZero:       
        movzx   eax, ax                     ; zero extend value
        imul    ebx, eax                    ; multiply value
        loop    inLoop                      ; loop again
       
        dtoa    product, ebx                ; convert product to ASCII
        wtoa    zeros, dx                   ; convert # of zeros to ASCII
        output  result, product             ; display the product
        output  result2, zeros              ; display the # of zeros

        sub     eax, eax                    ; exit with return code 0
        ret                                 ; return to calling code
_MainProc ENDP
END                                         ; end of source code


