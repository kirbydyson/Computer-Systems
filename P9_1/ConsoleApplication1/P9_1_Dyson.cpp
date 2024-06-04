// Author:                 Kirby Dyson
// Assignment Title:       P9_1, Hate Odd Numbers
// Assignment Description: changes values to odd, if even

// Due Date:               4/23/2024
// Date Created:           4/22/2024
// Date Last Modified:     4/23/2024

#include <iostream>

using namespace std;

void __declspec(naked) changeOdds(short[], short&) {
    __asm {
            push    ebp                       // preserve previous base pointer
            mov     ebp, esp                  // set up base pointer
            push    eax                       // preserve eax
            push    ebx                       // preserve ebx
            push    ecx                       // preserve ecx

            mov     eax, [ebp + 8];           // load array
            mov     ebx, [ebp + 12];          // load number of odd values
            mov     ecx, 10                   // move size of array

        checkOdd:
            test    [eax], 1                  // check if number is odd
            jz      isEven                    // jump if number is even
            inc     [ebx]                     // incrememnt # of odds
            and     WORD PTR [eax], 0xFFFE    // modify the value

        isEven:
            add     eax, 2                    // go to next element in array
            loop    checkOdd                  // loop again 

            pop     ecx                       // pop ecx
            pop     ebx                       // pop ebx
            pop     eax                       // pop eax
            mov     esp, ebp                  // restore ebp
            pop     ebp                       // pop ebp

            sub     eax, eax                  // exit with return code 0
            ret                               // return to calling code
    }
}

int main()
{
    short array[10];
    short odds = 0;

    // Get input and echo print
    cout << "Please enter 10 values (-32, 768 to 32, 767):" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
        cout << array[i] << " ";
    }
    cout << endl << endl;

    changeOdds(array, odds);

    // Output new array and number of odd values
    cout << "The values, after modification, are:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl << "and there were " << odds << " odd values" << endl;

    return 0;
}
