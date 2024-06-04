// Author:                 Kirby Dyson
// Assignment Title:       P7_1, Palindrome
// Assignment Description: determines if a given c-string is a palindrome

// Due Date:               3/29/2024
// Date Created:           3/27/2024
// Date Last Modified:     3/29/2024

// Additional: ***Aars said to USE global variables and NOT pass parameters

#include <iostream>
#include <string>

using namespace std;

// Declare global variables
const short MAX = 21;
char myArray[MAX];
short stringSize = 0;
bool isPalindrome = true;

/* asmPalindrome
 * parameters:
 *      none
 * return value:
 *      void
 *
 * This function determines if a given string is a palindrome.
 */
void __declspec(naked) asmPalindrome() {
    __asm {
            push    ebp                       // preserve previous base pointer
            mov     ebp, esp                  // set up base pointer
            push    ebx                       // preserve ebx
            push    esi                       // preserve esi
            push    edi                       // preserve edi

            mov     esi, offset myArray       // load adress of array into esi
            mov     cx, stringSize            // load string size into cx
            mov     edi, offset isPalindrome  // load address of bool to edi
            dec     cx                        // Decrement counter
            sub     ebx, ebx                  // Clear ebx to 0

        compare:
            cmp     cx, bx                    // Compare counter to location
            jle     isPal                     // jump if less than or equal

            mov     al, [esi + ebx]           // Get first letter in array
            mov     dl, [esi + ecx]           // Get last letter in array
            cmp     al, dl                    // Compare the letters
            jne     notPal                    // jump if not equal

            inc     ebx                       // Increment ebx
            dec     cx                        // Decrement counter
            jmp     compare                   // loop again

        notPal:
            mov     BYTE PTR[edi], 0          // Set bool to 0
            jmp     done                      // Jump to DONE

        isPal:
            mov     BYTE PTR[edi], 1          // Set bool to 1

        done:
            pop     edi                       // Pop edi off stack
            pop     esi                       // Pop esi off stack
            pop     ebx                       // Pop ebx off stack
            pop     ebp                       // Pop ebp off stack

            sub     eax, eax                  // exit with return code 0
            ret                               // return to calling code
    }
}

int main() {
    // Get user input and echo print the string
    cout << "Enter a string of characters:" << endl;
    cin >> myArray;
    cout << myArray << endl << endl;
  

    while(myArray[stringSize] != '\0'){
        stringSize++;
    }

    // Determine if string is a palindrome
    asmPalindrome();

    // Output results
    if(!isPalindrome){
        cout << "Your string is NOT a palindrome." << endl;
    }
    else{
        cout << "Your string is a palindrome." << endl;
    }

    return 0;
}