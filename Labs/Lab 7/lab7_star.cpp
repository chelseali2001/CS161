#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/*
 * Test cases:
 * ***** = 100%
 * 1*3 = 33.333%
 * asdfa = 0%
*/

int main() {
    char* arr = new char[20];
    int count = 0;

    cout << "Please enter a string (<20 chars): ";
    cin.getline(arr, 20);

    for (int x = 0; x < strlen(arr); x++) {
        if (arr[x] == '*') {
            count++;
        }
    }

    cout << "String length: " << strlen(arr) <<endl;
    cout << "Stars: " << count <<endl;
    cout << "Star-factor (percentage): " <<  (float) count / (float) strlen(arr) * 100.0 << "%" <<endl;

    delete arr;
    
    return 0;
}