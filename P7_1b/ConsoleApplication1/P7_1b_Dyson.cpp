// Author:                 Kirby Dyson
// Assignment Title:       P7_1b, Palindrome
// Assignment Description: determines if a given c-string is a palindrome

// Due Date:               4/05/2024
// Date Created:           4/04/2024
// Date Last Modified:     4/04/2024


#include <iostream>
#include <string>

using namespace std;

const short MAX = 100;

/* asmPalindrome
 * parameters:
 *      none
 * return value:
 *      void
 *
 * This function determines if a given string is a palindrome.
 */
void __declspec(naked) asmPalindrome(const char[], short, bool&) {
    __asm {
            push    ebp                       // preserve previous base pointer
            mov     ebp, esp                  // set up base pointer
            push    ebx                       // preserve ebx
            push    esi                       // preserve esi
            push    edi                       // preserve edi

            mov     esi, [ebp + 8]            // pointer to the c-string
            mov     cx, [ebp + 12]           // size of the c-string
            mov     edi, [ebp + 16]           // reference to the bool
            dec     cx                        // Decrement counter
            sub     ebx, ebx                  // Clear ebx to 0

        compare :
            cmp     cx, bx                    // Compare counter to location
            jle     isPal                     // jump if less than or equal

            mov     al, [esi + ebx]           // Get first letter in array
            mov     dl, [esi + ecx]           // Get last letter in array
            cmp     al, dl                    // Compare the letters
            jne     notPal                    // jump if not equal

            inc     ebx                       // Increment ebx
            dec     cx                        // Decrement counter
            jmp     compare                   // loop again

        notPal :
            mov     BYTE PTR[edi], 0          // Set bool to 0
            jmp     done                      // Jump to DONE

        isPal :
            mov     BYTE PTR[edi], 1          // Set bool to 1

        done :
            pop     edi                       // Pop edi off stack
            pop     esi                       // Pop esi off stack
            pop     ebx                       // Pop ebx off stack
            pop     ebp                       // Pop ebp off stack

            sub     eax, eax                  // exit with return code 0
            ret                               // return to calling code
    }
}

int main() {
    char myArray[MAX];
    bool isPalindrome = true;
    int stringSize = 0;

    // Get user input and echo print the string
    cout << "Enter a string of characters:" << endl;
    cin >> myArray;
    cout << myArray << endl << endl;

    while (myArray[stringSize] != '\0') {
        stringSize++;
    }

    // Determine if string is a palindrome
    asmPalindrome(myArray, stringSize, isPalindrome);

    // Output results
    if (!isPalindrome) {
        cout << "Your string is NOT a palindrome." << endl;
    }
    else {
        cout << "Your string is a palindrome." << endl;
    }

    return 0;
}