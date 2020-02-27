/*****************************************************************
** Program: assign4_text.cpp
** Author: Chelsea Li
** Date: 02/23/2020
** Description: This program performs various string operations.
** Input: C-style strings and unsigned ints.
** Output: A string.
*****************************************************************/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/**************************************************************************************************************
 ** Function: check_vowel_cons
 ** Description: Checks to see if the number of vowels equals the number of consonants.
 ** Parameters: const char* s
 ** Pre-Conditions: 1 constant C-style string
 ** Post-Conditions: Returns a boolean that shows if the number of vowels equals the number of consonants.
**************************************************************************************************************/
bool check_vowel_cons(const char* s) {
    int vowels = 0, consonants = 0;

    for (int x = 0; x < strlen(s); x++) {
        if (s[x] == 'a' || s[x] == 'o' || s[x] == 'e' || s[x] == 'i' || s[x] == 'u')
            vowels++;
        else
            consonants++;
    }

    return vowels == consonants;
}

/*************************************************************************
 ** Function: letter_swap
 ** Description: Swaps the characters in the string.
 ** Parameters: char* s, const char a, const char b
 ** Pre-Conditions: 1 char*, 2 const chars
 ** Post-Conditions: Some characters are replaced in the string.
*************************************************************************/
void letter_swap(char* s, const char a, const char b) {
    for (int x = 0; x < strlen(s); x++) {
        if (s[x] == a)
            s[x] = b;
    }

    cout << "\nNew string: " << s <<endl;
}

/*************************************************************************
 ** Function: flip_str
 ** Description: Flips the string
 ** Parameters: const char* s, char* s2
 ** Pre-Conditions: 1 const char*, 1 char*
 ** Post-Conditions: Flips the string.
*************************************************************************/
void flip_str(const char* s, char* s2) {
    int count = 0;

    for (int x = strlen(s) - 1; x >= 0; x--) {
        s2[count] = s[x];

        count++;
    }
    
    s2[count] = '\0';
    
    cout << "\nThe flipped string is: " << s2 <<endl;
}

/*************************************************************************
 ** Function: count_char
 ** Description: Returns the character frequencies.
 ** Parameters: const char* s, const char* chars
 ** Pre-Conditions: 2 const char*s
 ** Post-Conditions: Returns an int array.
*************************************************************************/
int* count_char(const char* s, const char* chars) {
    int* frequency = new int[strlen(chars)];

    for (int x = 0; x < strlen(chars); x++) {
        frequency[x] = 0;
    }

    for (int x = 0; x < strlen(chars); x++) {
        for (int i = 0; i < strlen(s); i++) {
            if (chars[x] == s[i]) {
                frequency[x]++;
            }
        }
    }

    return frequency;
}

/******************************************************************************************
 ** Function: first_last
 ** Description: Prints the same string but without the first and last characters
 ** Parameters: const char* s
 ** Pre-Conditions: 1 const char*
 ** Post-Conditions: Prints the same string without the first and last characters.
******************************************************************************************/
void first_last(const char* s) {
    cout << "\nThe new string is: ";

    for (int x = 1; x < strlen(s) - 1; x++) {
        cout << s[x];
    }

    cout <<endl;
}

/******************************************************************************************
 ** Function: count_word
 ** Description: Counts the occurances of a word.
 ** Parameters: char* s, char* word
 ** Pre-Conditions: 2 char*s
 ** Post-Conditions: Returns the occurances of a word.
******************************************************************************************/
int count_word(char* s, char* word) {
    int occurances = 0, track = 0, index = 0;

    for (int x = 0; x < strlen(s); x++) {
        if (s[x] == ' ' || s[x] == '\n') {
            if (track == strlen(word)) {
                occurances++;
            }
        } else if (s[x] == word[index]) {
            track++;
        }

        index++;

        if (index == strlen(word))
            index = 0;
    }

    return occurances;
}

int main() {
    bool done = false;
    char input[1027];
    char input2[1027];
    char second_string[10];
    char word_search[1027];
    int* frequencies;

    while (!done) {
        bool right = false, input_range = false, swap_test = false, range_check = false;
        char swap_out = 'a', swap_in = 'a';
        unsigned int choice = 0;

        cout << "\n-------------------------------------------" <<endl;

        while (!input_range) {
            cout << "\nEnter a string: ";
            cin.getline(input, 1027);

            if (strlen(input) >= 1 && strlen(input) <= 1027)
                input_range = true;
            else
                cout << "Error: invalid input" <<endl;
        }

        while (!right) {
            cout << "\nEnter 0 to quit." <<endl;
            cout << "Enter 1 to check if the number of vowels equals the number of consonants" <<endl;
            cout << "Enter 2 to swap letters in the string." <<endl;
            cout << "Enter 3 to flip the string." <<endl;
            cout << "Enter 4 to compute character frequency distribution." <<endl;
            cout << "Enter 5 to reprint the string without the first and last characters." <<endl;
            cout << "Enter 6 to count the number of occurances of a word." <<endl;
            cin >> choice;

            if (choice >= 0 && choice <= 6) {
                right = true;
            } else {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Error: invalid input" <<endl;
            }
        }

        if (choice == 0) {
            done = true;
        } else if (choice == 1) {
            cout << "\nDo the number of vowels equal the number of consonants: " << check_vowel_cons(input) <<endl;
        } else if (choice == 2) {
            while (!swap_test) {
                cout << "\nWhat character do you want to swap out: ";
                cin >> swap_out;

                if (((int) swap_out >= 65 && (int) swap_out <= 90) || ((int) swap_out >= 97 && (int) swap_out <= 122))
                    swap_test = true;
                else
                    cout << "Error: invalid input" <<endl;
            }

            while (swap_test) {
                cout << "\nWhat character do you want to swap in: ";
                cin >> swap_in;

                if (((int) swap_in >= 65 && (int) swap_in <= 90) || ((int) swap_in >= 97 && (int) swap_in <= 122))
                    swap_test = false;
                else
                    cout << "Error: invalid input" <<endl;
            }

            letter_swap(input, swap_out, swap_in);
        } else if (choice == 3) {
            flip_str(input, input2);
        } else if (choice == 4) {
            while (!range_check) {
                cout << "\nWhat is the second string: ";
                cin >> second_string;
                
                if (strlen(second_string) >= 1 && strlen(second_string) <= 10)
                    range_check = true;
                else
                    cout << "Error: invalid input" <<endl;
            }

            frequencies = count_char(input, second_string);

            for (int x = 0; x < strlen(second_string); x++)
                cout << "\n" << second_string[x] << ") " << frequencies[x];
            
            delete [] frequencies;
        } else if (choice == 5) {
            first_last(input);
        } else if (choice == 6) {
            cout << "Enter the word to find: ";
            cin >> word_search;

            cout << count_word(input, word_search) << " occurance(s) of " << word_search <<endl;
        }
        
        cin.clear();
        cin.ignore(256, '\n');
    }

    return 0;
}