// Author:                 Kirby Dyson
// Assignment Title:       P9_2, Even Parity
// Assignment Description: changes each character to have an even parity

// Due Date:               4/23/2024
// Date Created:           4/22/2024
// Date Last Modified:     4/23/2024

#include <iostream>
#include <cstring>

using namespace std;

void __declspec(naked) changeParity(char[]) {
    __asm {
            push    ebp                     // preserve previous base pointer
            mov     ebp, esp                // set up base pointer
            push    eax                     // preserve eax
            push    ebx                     // preserve ebx
            push    ecx                     // preserve ecx

            mov     ebx, [ebp + 8]          // load array
            sub     eax, eax                // clear eax

        checkString:
            mov     al, [ebx]               // move current char into al
            cmp     al, '\0'                // check if null
            je      done                    // jump to done if null
            mov     cx, ax                  // mov character into cx
            sub     eax, eax                // clear eax

        isSet:
            cmp     cx, 0                   // check if least sig bit is set
            je      notSet                  // if not set, jump
            shr     cx, 1                   // shift right by one bit
            jnc     isSet                   // jump if bit shifted is 0
            inc     eax                     // increment number of 1s
            jmp     isSet                   // loop again

        notSet:
            test     ax, 1                  // check if number of 1s is odd
            jz       nextChar               // jump if even
            xor      BYTE PTR[ebx], 0x80    // if odd, set high bit

        nextChar:
            inc     bx                      // move to next character
            jmp     checkString             // loop again

        done:
            pop     ecx                     // pop ecx
            pop     ebx                     // pop ebx
            pop     eax                     // pop eax
            mov     esp, ebp                // restore ebp
            pop     ebp                     // pop ebp

            sub     eax, eax                // exit with return code 0
            ret                             // return to calling code
    }
}

int main()
{
    char array[80];

    // Get input and echo print
    cout << "Enter a message (<=80 characters): ";
    cin.getline(array, 80);

    cout << "The character array BEFORE we implement even partiy:" << endl;
    cout << array << endl << endl;

    // Output new array
    changeParity(array);
    cout << "The character array AFTER we implement even parity:" << endl;
    cout << array << endl;

    return 0;
}

