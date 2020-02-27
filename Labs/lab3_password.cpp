/*****************************************************************
 ** Program: lab3_password.cpp
 ** Authors: Chelsea and Sukhjot
 ** Date: 01/20/2020
 ** Description: Prints a random password
*****************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int done = 1;
    string lettersNumbers = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    cout << "Welcome to Password Creator!" <<endl;

    while (done == 1) {
        int chars = 0, letters = 0, upperCases = 0, lowerCases = 0, numbers = 0;
        string password = "";

        srand(time(NULL));
        
        cout << "\nHow many characters do you want the password to be (1-15)? ";
        cin >> chars;

        if (chars < 1 || chars > 15) {
            break;
        }

        cout << done <<endl;

        cout << "How many letters (out of " << chars << ")? ";
        cin >> letters;

        if (letters < 1 || letters > chars) {
            break;
        }

        cout << "How many upper-case letters (out of " << letters << ")? ";
        cin >> upperCases;

        if (upperCases < 1 || upperCases > letters) {
            break;
        }

        lowerCases = letters - upperCases;
        numbers = chars - letters;

        cout << "The rest of the letters (" << lowerCases << ") will be lower-case." <<endl;
        cout << "The rest of the characters (" << numbers << ") will be numbers" <<endl;

        for (int x = 0; x < upperCases; x++) {
            password += lettersNumbers[rand() % 26];
        }

        for (int x = 0; x < lowerCases; x++) {
            password += lettersNumbers[rand() % 26 + 26];
        }

        for (int x = 0; x < numbers; x++) {
            password += lettersNumbers[rand() % 10 + 52];
        }

        cout << "\nYour random password is: " << password <<endl;

        cout << "\nWould you like to create another password (0-no, 1-yes)? ";
        cin >> done;
    }

    cout << "Error. Bad input" <<endl;

    return 0;
} 