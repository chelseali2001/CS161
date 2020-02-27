#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

struct umbrella {
    float length;
    string color;
};

int main() {
    static umbrella* umbrellas = new umbrella[3];
    int longest = 0;

    for (int x = 0; x < 3; x++) {
        cout << "\nEnter length for umbrella " << x << ": ";
        cin >> umbrellas[x].length;

        cout << "\nEnter the color for umbrella " << x << ": ";
        cin >> umbrellas[x].color;
    }

    for (int x = 1; x < 3; x++) {
        if (umbrellas[longest].length < umbrellas[x].length) {
            longest = x;
        }
    }

    cout << "The longest umbrella (index " << longest << ") has a length of " << umbrellas[longest].length << " and is " << umbrellas[longest].color <<endl;

    return 0;
}
