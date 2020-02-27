#include <iostream>
using namespace std;

void get_input(string* s) {
    cin >> *s;
}

void hide_letters(const string& s, string* s_hidden) {
    for (int x = 0; x < s.length(); x++) {
        if (x != ' ') {
            *s_hidden += '*';
        } else {
            *s_hidden += ' ';
        }
    }
}

int guess_letter(char letter, const string& s, string* s_hidden) {
    int matches = 0;

    for (int x = 0; x < s.length(); x++) {
        if (s[x] == letter) {
            (*s_hidden)[x] = letter;
            matches++;
        }
    }

    return matches;
}

int main() {
    bool guessed = false;
    string word = "";
    string hidden = "";
    char letter;

    cout << "Enter a secret string using only lower-case letters: ";
    get_input(&word);
    hide_letters(word, &hidden);

    for (int x = 0; x < 50; x++) {
        cout << "\n" <<endl;
    }

    while (!guessed) {
        cout << "Please guess a letter: ";
        cin >> letter;
        cout << guess_letter(letter, word, &hidden) << " match(es)!" <<endl;
        cout << "Your string is: " << hidden <<endl;

        int stars = 0;

        for (int x = 0; x < hidden.length(); x++) {
            if (hidden[x] == '*') {
                stars++;
            }
        }

        if (stars == 0) {
            guessed = true;
        }
    }

    cout << "\nCongratulations! You win the game!" <<endl;

    return 0;
}