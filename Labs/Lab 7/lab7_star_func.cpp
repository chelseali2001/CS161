#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

float star_factor(char* str) {
    int count = 0;

    for (int x = 0; x < strlen(str); x++) {
        if (str[x] == '*') {
            count++;
        }
    }

    return (float) count / (float) strlen(str) * 100.0;
}

int main() {
    char* arr = new char[20];

    cout << "Enter the first string: ";
    cin >> arr;

    char* newArr = new char[strlen(arr) * 2];

    strcat(newArr, arr);
    strcat(newArr, arr);

    cout << "Star percentage: " << star_factor(arr) << "%" <<endl;
    
    delete [] arr;
    delete [] newArr;

    return 0;
}