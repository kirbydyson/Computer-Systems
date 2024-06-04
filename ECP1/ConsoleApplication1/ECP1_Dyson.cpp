// Author:                 Kirby Dyson
// Assignment Title:       ECp1, Towers of Hanoi
// Assignment Description: solves the tower of hanoi problem

// Due Date:               4/30/2024
// Date Created:           4/29/2024
// Date Last Modified:     4/30/2024

#include <iostream>

using namespace std;

void __declspec(naked) towOfHanoi(int, int&) {
    __asm {
            push    ebp                  // preserve previous base pointer
            mov     ebp, esp             // set up base pointer
            push    eax                  // preserve eax
            push    ebx                  // preserve ebx

            mov     eax, [ebp + 12]      // load moves
            mov     ebx, [ebp + 8]       // load n

        numMoves:
            shl     DWORD PTR[eax], 1    // shift eax left by 1
            loop    numMoves             // loop numMoves times
            dec     DWORD PTR[eax]       // decrement eax

            pop     ebx                  // pop ebx
            pop     eax                  // pop eax
            mov     esp, ebp             // restore base pointer
            pop     ebp                  // pop ebp

            sub     eax, eax             // exit with return code 0
            ret                          // return to calling code
    }
}

int main()
{
    int n = 0, moves = 1;

    cout << "This program will calculate an display the optimal number of ";
    cout << "moves to solve the ''Towers of Hanoi'' problem" << endl << endl;

    // Get input and echo print, if invalid print error message
    while (n < 1) {
        cout << "Enter a positive integer: ";
        cin >> n;
        cout << n << endl;

        if (n < 1) {
            cout << "ERROR: Invalid input - Try again." << endl << endl;
        }
    }

    // Output results
    towOfHanoi(n, moves);

    cout << "The optimal number of moves for n = " << n;
    cout << " disks is " << moves << "." << endl;
   

    return 0;
}

