// Author:                 Kirby Dyson
// Assignment Title:       P10_0, Volume of an Egg
// Assignment Description: approximates the volume of an easter egg

// Due Date:               4/30/2024
// Date Created:           4/27/2024
// Date Last Modified:     4/27/2024

#include <iostream>
#include <iomanip>

using namespace std;

void __declspec(naked) eggVol(float, float, float&) {
    __asm {
        push    ebp                    // preserve previous base pointer
        mov     ebp, esp               // set up base pointer
        push    ebx                    // preserve ebx

        mov     eax, 6                 // move 6 into eax
        mov     [ebp + 20], eax        // load onto stack

        finit                          // initialize FPU
        fldpi                          // load pi to ST
        fidiv   DWORD PTR[ebp + 20]    // divide pi by 6
        fld     DWORD PTR[ebp + 8]     // load length
        fmul                           // pop ST and ST(1) and multiply
        fld     DWORD PTR[ebp + 12]    // load diameter
        fmul    ST(0), ST              // square diameter
        fmul                           // pop ST and ST(1) and multiply
        mov     ebx, [ebp + 16]        // move address of volume to ebx
        fstp    DWORD PTR[ebx]         // pop volume and store result in ebx

        pop     ebx                    // pop ebx
        mov     esp, ebp               // restore ebp
        pop     ebp                    // pop ebp

        sub     eax, eax               // exit with return code 0
        ret                            // return to calling code
    }
}

int main()
{
    float len, dia, vol = 0;

    // Get input and echo print
    cout << "Enter the length of the egg:" << endl;
    cin >> len;
    cout << len << endl;

    cout << "Enter the maxiumum diameter of the egg:" << endl;
    cin >> dia;
    cout << dia << endl << endl;

    // Calculate volume and output to 2 decimal places
    eggVol(len, dia, vol);

    cout << "The volume of the egg is:" << endl;
    cout << fixed << setprecision(2) << vol << endl;

    return 0;
}

