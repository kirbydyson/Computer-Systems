// Author:                 Kirby Dyson
// Assignment Title:       P9_0, Switch Case
// Assignment Description: switches the case of all alphabetic letter

// Due Date:               4/16/2024
// Date Created:           4/15/2024
// Date Last Modified:     4/16/2024

#include <iostream>

using namespace std;

void __declspec(naked) Conv2Lower(char[]) {
    __asm {
            push    ebp			          // preserve previous base pointer
            mov     ebp, esp	          // set up base pointer
            push    eax			          // preserve eax
            push    ebx			          // preserve ebx

            mov     ebx, [ebp + 8]        // load array

        checkCase:
            mov     al, [ebx]			  // move character to al
            cmp     al, '\0'	          // check if end of string
            je      done				  // jump to done
            cmp     al, 'A'				  // compare to A in hex
            jb      invalid				  // jump if not valid letter
            cmp     al, 'z'				  // copmare to z in hex
            ja      invalid				  // jump if not valid letter
            cmp     al, 'Z'               // compare to Z in hex
            jb      swapCase              // jump if not valid letter
            cmp     al, 'a'               // compare to a in hex
            jb      invalid               // jump if not valid letter

        swapCase:
            xor     BYTE PTR[ebx], 20h    // swap the case of letter

        invalid:
            inc     ebx				  // go to next character
            jmp     checkCase		  // jump to check case

        done:
            popfd						  // pop flag bits
            pop     ebx					  // pop ebx 
            pop     eax					  // pop eax 
            mov     esp, ebp			  // restore ebp
            pop     ebp                   // pop ebp

            sub     eax, eax              // exit with return code 0
        
            ret                           // return to calling code
    }
}

int main()
{
    char array[100];

    // Get input and echo print
    cout << "Please enter a string of characters:" << endl;
    cin.getline(array, 100);
    cout << array << endl << endl;

    Conv2Lower(array);

    // Output new string
    cout << "Your string after it is converted:" << endl;
    cout << array << endl;

    return 0;
}
