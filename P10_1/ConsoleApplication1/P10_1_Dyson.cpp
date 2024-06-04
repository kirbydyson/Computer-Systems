// Author:                 Kirby Dyson
// Assignment Title:       P10_1, Cube Root Approximation
// Assignment Description: approximates the cube root of a real number x

// Due Date:               4/30/2024
// Date Created:           4/27/2024
// Date Last Modified:     4/29/2024


#include <iostream>
#include <iomanip>

using namespace std;

void __declspec(naked) cubeRoot(float, float, float&) {
    __asm {
            push    ebp                  // preserve previous base pointer
            mov     ebp, esp             // set up base pointer
            push    ebx                  // preserve ebx

            finit                        // initialize FPU
            sub     esp, 4               // allocate space for local variable
            mov     DWORD PTR[esp], 3    // initialize divisor to 3
            mov     ebx, [ebp + 16]      // load root

        iterateLoop:
            fld     [ebx]                // load root
            fld     [ebx]                // duplicate root
            fadd    [ebx]                // 2 * root
            fld     [ebp + 8]            // load x
            fld     [ebx]                // load root
            fmul    [ebx]                // root * root
            fdiv                         // x / (root * root)
            fadd                         // add quotient to 2 * root
            fidiv   [esp]                // divide by 3
            fst     [ebx]                // store root
            fsubr                        // root-oldRoot
            fabs                         // |root-oldRoot|
            fld     [ebp + 12]           // load smallVal
            fxch                         // exchange top 2 FPU stack registers
            fcom                         // compare |root-oldRoot| and smallVal
            fstsw   ax                   // store FPU status word in ax
            sahf                         // store flags
            fstp    ST                   // pop FPU stack
            fstp    ST                   // pop FPU stack
            jae     iterateLoop          // jump if |root-oldRoot| >= smallVal

            pop     ebx                  // pop ebx
            mov     esp, ebp             // restore ebp
            pop     ebp                  // pop ebp

            sub     eax, eax             // exit with return code 0
            ret                          // return to calling code
    }
}

int main()
{
    float x, smallVal = 0.000001, root = 1.0;

    // Get input and echo print
    cout << "Enter the value of x:" << endl;
    cin >> x;
    cout << x << endl << endl;

    // Approximate cube root and output
    cubeRoot(x, smallVal, root);
    cout << "The cube root of " << x << " is " << fixed << setprecision(2) << root << endl;

    return 0;
}

