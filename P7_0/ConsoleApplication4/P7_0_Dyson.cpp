// Author:                 Kirby Dyson
// Assignment Title:       P7_0, Modified Sequential Search
// Assignment Description: solution that modifies a sequential search

// Due Date:               3/29/2024
// Date Created:           3/27/2024
// Date Last Modified:     3/29/2024

#include <iostream>

using namespace std;

// Declare global variables
const short MAX = 10;
short myArray[MAX];
short key;
short ndx;

/* seqSearch
 * parameters:
 *      none
 * return value:
 *      last occurence of search key, -1 otherwise
 *
 * This function finds the index of a given key.
 */
void __declspec(naked) seqSearch() {
    __asm {
        lea    ebx, myArray + 20    // load address of last element into ebx
        mov    ax, key              // move key into ax
        mov    cx, 9                // initialize loop counter

    findKey:
        sub    ebx, 2               // move to previous element of array
        cmp    [ebx], ax            // compare element with key
        je     found                // jump if element and key are equal
        dec    cx                   // decrement counter
        jnz    findKey              // loop if key is not found

        mov    cx, -1               // ndx is -1 if key not found in array

    found:
        mov    ndx, cx              // mov index into ndx
        sub    ax, ax               // exit with return code 0
        ret		                    //return to calling code
    }
}

int main() {
    // Get user input and echo print the input
    cout << "Enter an array of ten 16-bit values:" << endl;
    for(int i = 0; i < MAX; i++){
        cin >> myArray[i];
        cout << myArray[i] << endl;
    }

    cout << "Enter a search key: ";
    cin >> key;
    cout << key << endl;

    // Search for the key
    seqSearch();

    // Output results
    if(ndx == -1){
        cout << "The last occurrence of the search key was NOT found in this list.";
    }
    else{
        cout << "The last occurrence of the search key was at index " << ndx << ".";
    }
    cout << endl;

    return 0;
}