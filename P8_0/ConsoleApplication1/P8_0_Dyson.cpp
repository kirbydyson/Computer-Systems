// Author:                 Kirby Dyson
// Assignment Title:       P8_0, Sort Three
// Assignment Description: sorts three values in ascending order

// Due Date:               4/05/2024
// Date Created:           4/04/2024
// Date Last Modified:     4/04/2024

#include <iostream>

using namespace std;

/* asmSortThree
 * parameters:
 *      int& - first user input
        int& - second user input
        int& - third user input
 * return value:
 *      void
 *
 * This function sorts the given input in ascending order
 */
void __declspec (naked) asmSortThree(int&, int&, int&) {
    __asm {

            push    ebp                  // preserve previous base pointer
            mov     ebp, esp             // set up base pointer
            push    edx                  // preserve edx


            mov     edx, [ebp + 8]       // load the first input
            mov     eax, [edx]           // move into eax
            mov     edx, [ebp + 12]      // load the second input
            mov     ebx, [edx]           // move into ebx
            mov     edx, [ebp + 16]      // load the third input
            mov     ecx, [edx]           // move into ecx


            cmp     eax, ebx             // compare first two inputs
            jg      swapAB               // jump if first is greater
            cmp     ebx, ecx             // compare the second and third 
            jg      swapBC               // jump if second is greater
            jmp     done                 // jump to done

        swapAB :
            xchg    eax, ebx             // swap first and second
            cmp     ebx, ecx             // compare new second and third
            jg      swapBC               // jump if second is greater
            jmp     done                 // jump to done

        swapBC :
            xchg    ebx, ecx             // swap second and third
            cmp     eax, ebx             // compare new second and third
            jg      swapAB               // swap second and third
            jmp     done                 // jump to done

        done :
            mov     edx, [ebp + 8]       // load minumum value
            mov     [edx], eax           // store minimum 
            mov     edx, [ebp + 12]      // load median value
            mov     [edx], ebx           // store median
            mov     edx, [ebp + 16]      // store maximum value
            mov     [edx], ecx           // store maximum

            pop     edx                  // pop edx
            pop     ebp                  // pop ebp

            sub eax, eax                 // exit with return call 0
            ret                          // return to calling code
    }
}

int main()
{
    int num1, num2, num3;

    // Get user input and echo print
    cout << "Please enter three integer values: ";
    cin >> num1 >> num2 >> num3;
    cout << num1 << " " << num2 << " " << num3 << endl << endl;

    // Sort numbers and output in ascending order
    asmSortThree(num1, num2, num3);

    cout << "Your three values, in ascending order:" << endl;
    cout << num1 << " " << num2 << " " << num3 << endl;

    return 0;
}
