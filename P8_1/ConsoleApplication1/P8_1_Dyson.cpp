// Author:                 Kirby Dyson
// Assignment Title:       P8_1, Relocate N
// Assignment Description: moves a given index to the front of an array

// Due Date:               4/16/2024
// Date Created:           4/15/2024
// Date Last Modified:     4/16/2024

#include <iostream>

using namespace std;

void __declspec(naked) relocateN(short[], short) {
    __asm {
            push    ebp                // preserve previous base pointer
            mov     ebp, esp           // set up base pointer
            push    esi                // preserve esi

            mov     esi, [ebp + 8]	   // load first input
            mov     ax,  [ebp + 12]    // load second input
            dec     ax                 // decremement index	
            mov     cx, ax             // move index to cx	
            mov     edi, esi		   // move edi to beginning of array
            add	    eax, eax           // double eax
            add     edi, eax           // add edi and eax

            mov     bx, [edi]          // move value to bx
            mov     dx, cx             // set counter	
            sub     edi, 2             // move pointer back 2	

        relocateVal:
            cmp     dx, 0              // compare counter to 0			
            je      done               // jump to done		
            mov     cx, [edi]          // mov value to cx	
            mov     [edi + 2], cx      // shift value to right
            sub     edi, 2             // move pointer back 2
            dec     dx                 // decrememnt counter
            jmp     relocateVal        // loop again

        done:
            mov     [esi], bx          // move value to first index		
            pop     esi				   // pop esi			
            pop     ebp                // pop ebp

            sub     eax, eax           // exit with return code 0

            ret                        // return to calling code
    }
}

int main()
{
    short array[10];
    short n;

    // Get input and echo print
    cout << "Please enter ten integer values: ";
    for(int i = 0; i < 10; i++){
        cin >> array[i];
        cout << array[i] << " ";
    }
    cout << endl;

    cout << endl << "Enter which of these to move to the first position: ";
    cin >> n;
    cout << n;

    relocateN(array, n);

    // Output new array
    cout << endl << "Your list of ten values, modified, is:" << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }

    return 0;
}

