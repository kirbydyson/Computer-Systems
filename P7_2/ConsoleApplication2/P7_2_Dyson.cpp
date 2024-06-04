// Author:                 Kirby Dyson
// Assignment Title:       P7_2, Permutations
// Assignment Description: calculates the permutation of n select k

// Due Date:               4/05/2024
// Date Created:           4/04/2024
// Date Last Modified:     4/04/2024

#include <iostream>

using namespace std;

/* permutation
 * parameters:
 *      int - n
        int - k
        int& - permutation
 * return value:
 *      void
 *
 * This function calculates the permutation of n select k.
 */

void __declspec (naked) permutation(int, int, int&) {
    __asm {
            push    ebp                       // preserve previous base pointer
            mov     ebp, esp                  // set up base pointer
            push    eax                       // preserve eax
            push    ebx                       // preserve ebx
            push    ecx                       // preserve ecx
            push    esi                       // preserve esi
            push    edi                       // preserve edi

            mov     ecx, [ebp + 8]            // pointer to n
            mov     ebx, [ebp + 12]           // pointer to k
            mov     edi, [ebp + 16];          // reference to the permutation
            mov     eax, 1                    // initialize permutation to 1
            mov     esi, ecx                  // move n to esi
            sub     ecx, ebx                  // move n-1 to ecx

        math:
            cmp     esi, ecx                  // compare esi and ecx
            je      done                      // jump if equal
            mul     esi                       // multiply eax and esi
            dec     esi                       // decrement esi
            jmp     math                      // loop again
        done:
            mov     [edi], eax                // store the permutation
            pop     eax                       // pop eax
            pop     ebx                       // pop ebx
            pop     ecx                       // pop ecx
            pop     esi                       // pop esi
            pop     edi                       // pop edi
            pop     ebp                       // pop ebp

            sub eax, eax                      // exit with return call 0
            ret                               // return to calling code
    }
}


int main()
{
    int n, k, perm;

    // Get user input and echo print
    cout << "Enter positive integers n and k: ";
    cin >> n >> k;
    cout << n << " " << k << endl;

    cout << "P(" << n << "," << k << ")";

    // Output the permutation
    if (n >= 0 && k >= 0) {
        permutation(n, k, perm);
        cout << " = " << perm << endl;
    }
    else {
        cout << " is undefined" << endl;
    }

  
    return 0;
}

